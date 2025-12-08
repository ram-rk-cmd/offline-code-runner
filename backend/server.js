

const express = require('express');
const cors = require('cors');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');
const bodyParser = require('body-parser');

const app = express();
const PORT = process.env.PORT || 3001;

app.use(cors());
app.use(bodyParser.json());

// Serve Static Frontend (for production)
const FRONTEND_DIST = path.join(__dirname, '../frontend/dist');
if (fs.existsSync(FRONTEND_DIST)) {
    app.use(express.static(FRONTEND_DIST));
}

const PROGRAMS_DIR = path.join(__dirname, '../programs'); // Programs are one level up

const TEMP_DIR = path.join(__dirname, 'temp');
if (!fs.existsSync(TEMP_DIR)){
    fs.mkdirSync(TEMP_DIR);
}

// Helper to extract metadata
const extractMetadata = (content) => {
    let description = '';
    let preview = '';
    let contentForPreview = content;

    // Try to find first block comment /* ... */
    const blockCommentMatch = content.match(/\/\*([\s\S]*?)\*\//);
    if (blockCommentMatch) {
        description = blockCommentMatch[1].trim().split('\n').map(l => l.trim().replace(/^\*\s?/, '')).join('\n');
        // If the block comment is at the start (likely a header), remove it from preview
        if (content.trim().startsWith('/*')) {
             contentForPreview = content.replace(blockCommentMatch[0], '').trim();
        }
    } else {
        // Try top consecutive line comments //
        const lines = content.split('\n');
        let dLines = [];
        let commentEndIndex = 0;
        
        for (let i = 0; i < lines.length; i++) {
            let line = lines[i].trim();
            if (line.startsWith('//')) {
                dLines.push(line.substring(2).trim());
            } else if (line.length > 0) {
                commentEndIndex = i;
                break; 
            }
        }
        if (dLines.length > 0) {
            description = dLines.join('\n');
            // Remove these lines from preview if they were at the top
            if (commentEndIndex > 0 || (dLines.length > 0 && commentEndIndex === 0)) {
                 contentForPreview = lines.slice(dLines.length).join('\n').trim();
            }
        }
    }

    // Preview: First 12 lines of the CLEANED content
    preview = contentForPreview.split('\n').slice(0, 12).join('\n');
    
    return { description, preview };
};

// 1. List Files
app.get('/api/programs', (req, res) => {
    const programs = [];
    
    const scanDir = (dir, relativePath) => {
        try {
            const items = fs.readdirSync(dir, { withFileTypes: true });
            items.forEach(item => {
                const fullPath = path.join(dir, item.name);
                const relPath = path.join(relativePath, item.name);
                
                if (item.isDirectory()) {
                    scanDir(fullPath, relPath);
                } else {
                    if (item.name.endsWith('.c') || item.name.endsWith('.java')) {
                        const content = fs.readFileSync(fullPath, 'utf8');
                        const meta = extractMetadata(content);
                        programs.push({
                            name: item.name,
                            path: relPath.replace(/\\/g, '/'),
                            type: item.name.endsWith('.c') ? 'c' : 'java',
                            description: meta.description,
                            preview: meta.preview
                        });
                    }
                }
            });
        } catch (e) {
            console.error("Error scanning dir:", dir, e);
        }
    };

    try {
        scanDir(PROGRAMS_DIR, '');
        res.json(programs);
    } catch (e) {
         res.status(500).json({ error: 'Error scanning files: ' + e.message });
    }
});

// 2. Read File Content
app.get('/api/programs/:filename(*)', (req, res) => {
    const filename = req.params.filename;
    const filePath = path.join(PROGRAMS_DIR, filename);

    if (!filePath.startsWith(PROGRAMS_DIR)) {
        return res.status(403).json({ error: 'Access denied' });
    }

    fs.readFile(filePath, 'utf8', (err, data) => {
        if (err) {
            return res.status(404).json({ error: 'File not found' });
        }
        res.json({ content: data });
    });
});

// 3. Run Program
app.post('/api/run', (req, res) => {
    const { filename, type, content, input } = req.body;
    
    // Support raw content execution
    let filePath;
    let fileDir;
    let cleanup = false;

    if (content) {
        // Run raw content
        const timestamp = Date.now();
        const ext = type === 'c' ? 'c' : 'java';
        const tempFilename = `Run_${timestamp}.${ext}`;
        fileDir = TEMP_DIR;
        filePath = path.join(TEMP_DIR, tempFilename);
        
        try {
            fs.writeFileSync(filePath, content);
            cleanup = true;
        } catch (e) {
            return res.status(500).json({ error: 'Failed to write temp file: ' + e.message });
        }
    } else {
        // Run existing file
        if (!filename || !type) return res.status(400).json({ error: 'Missing filename/type' });
        filePath = path.join(PROGRAMS_DIR, filename);
        fileDir = path.dirname(filePath);
        if (!filePath.startsWith(PROGRAMS_DIR)) return res.status(403).json({ error: 'Access denied' });
    }

    const baseName = path.basename(filePath, path.extname(filePath));
    let command = '';
    
    if (type === 'c') {
        const exePath = path.join(fileDir, `${baseName}.exe`);
        command = `gcc "${filePath}" -o "${exePath}" && "${exePath}"`;
    } else if (type === 'java') {
        command = `java "${filePath}"`;
    } else {
        if (cleanup) try { fs.unlinkSync(filePath); } catch (e){}
        return res.status(400).json({ error: 'Unsupported type' });
    }

    const child = exec(command, { cwd: fileDir, timeout: 5000 }, (error, stdout, stderr) => {
        // Cleanup temp files
        if (cleanup) {
            try { 
                fs.unlinkSync(filePath);
                if (type === 'c') fs.unlinkSync(path.join(fileDir, `${baseName}.exe`));
            } catch (e) {}
        }

        if (error) {
            res.json({ 
                success: false, 
                output: stdout + '\n' + stderr + (error.killed ? '\n[Execution timed out]' : ''),
                error: error.message
            });
        } else {
            res.json({ 
                success: true, 
                output: stdout 
            });
        }
    });

    if (input) {
        child.stdin.write(input);
        child.stdin.end();
    }
});

// Serve React App for any other route
app.get('*', (req, res) => {
    if (fs.existsSync(path.join(FRONTEND_DIST, 'index.html'))) {
        res.sendFile(path.join(FRONTEND_DIST, 'index.html'));
    } else {
        res.status(404).send('Frontend not built. Run "npm run build" in frontend directory.');
    }
});

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
