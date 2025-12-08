import { useState, useEffect, useRef, useCallback } from 'react'
import './App.css'
import ProgramTile from './components/ProgramTile'

const API_Base = 'http://localhost:3001/api';

function App() {
  const [programs, setPrograms] = useState([]);
  const [filteredPrograms, setFilteredPrograms] = useState([]);
  
  // State
  const [search, setSearch] = useState('');
  const [selectedLang, setSelectedLang] = useState('all');
  const [activeProgram, setActiveProgram] = useState(null); // The program selected from list
  const [editorContent, setEditorContent] = useState(''); // Text in editor
  const [userInput, setUserInput] = useState(''); // USER INPUT
  const [consoleLogs, setConsoleLogs] = useState([]);
  const [isPanelOpen, setIsPanelOpen] = useState(true);
  
  // Resizing State
  const [rightPanelWidth, setRightPanelWidth] = useState(50); // percentage
  const [isResizing, setIsResizing] = useState(false);

  // Panel Visibility State
  const [showInput, setShowInput] = useState(false);
  const [showOutput, setShowOutput] = useState(true);
  
  const consoleEndRef = useRef(null);

  // Auto-detect Input needs
  useEffect(() => {
    // Simple heuristic: check for scanf (C) or Scanner/System.in (Java)
    const needsInput = /scanf|Scanner|System\.in/.test(editorContent);
    setShowInput(needsInput);
  }, [editorContent]);

  // Resize Handlers
  const startResizing = useCallback((mouseDownEvent) => {
    setIsResizing(true);
  }, []);

  const stopResizing = useCallback(() => {
    setIsResizing(false);
  }, []);

  const resize = useCallback((mouseMoveEvent) => {
    if (isResizing) {
      const newWidth = ((window.innerWidth - mouseMoveEvent.clientX) / window.innerWidth) * 100;
      if (newWidth > 20 && newWidth < 80) { // Min/Max constraints
          setRightPanelWidth(newWidth);
      }
    }
  }, [isResizing]);

  useEffect(() => {
    window.addEventListener("mousemove", resize);
    window.addEventListener("mouseup", stopResizing);
    return () => {
      window.removeEventListener("mousemove", resize);
      window.removeEventListener("mouseup", stopResizing);
    };
  }, [resize, stopResizing]);

  // Poll for programs
  useEffect(() => {
    const fetchPrograms = async () => {
      try {
        const res = await fetch(`${API_Base}/programs`);
        if (res.ok) {
          const data = await res.json();
          setPrograms(data);
        }
      } catch (err) {
        console.error("Failed to fetch programs", err);
      }
    };
    fetchPrograms();
    const interval = setInterval(fetchPrograms, 3000); // Poll every 3s
    return () => clearInterval(interval);
  }, []);

  // Filter Logic
  useEffect(() => {
    let result = programs;
    
    // Search filter
    if (search) {
        result = result.filter(p => p.name.toLowerCase().includes(search.toLowerCase()));
    }
    
    // Lang filter
    if (selectedLang !== 'all') {
        result = result.filter(p => p.type === selectedLang);
    }
    
    setFilteredPrograms(result);
  }, [programs, search, selectedLang]);

  // Auto-scroll console
  useEffect(() => {
    if (showOutput) {
        consoleEndRef.current?.scrollIntoView({ behavior: "smooth" });
    }
  }, [consoleLogs, showOutput]);

  const addToConsole = (text, type = 'info') => {
    setConsoleLogs(prev => [...prev, { text, type, time: new Date().toLocaleTimeString() }]);
    setShowOutput(true); // Auto-open output on log
  };

  const handleProgramClick = async (program) => {
      setActiveProgram(program);
      setIsPanelOpen(true);
      
      // Load content
      try {
        const res = await fetch(`${API_Base}/programs/${encodeURIComponent(program.path)}`);
        const data = await res.json();
        setEditorContent(data.content || '');
      } catch (err) {
        setEditorContent('// Failed to load content');
      }
  };

  const handleRun = async () => {
    if (!editorContent.trim()) return;

    // If active program exists, use its type/name context, OR defaults
    // If running "custom" code (modified or new), backend supports `content` param.
    // If existing program is safe, we run safe. 
    // BUT user requirement: "copy and paste external c or java program it should work".
    // So we basically ALWAYS run the editor content as a temp file? 
    // Or if it matches original file content, run file?
    // Let's always run 'content' for simplicity and consistency with "Code Runner" feel.
    // We need to know the TYPE (C or Java). 
    // If activeProgram selected, use its type. If not (new file?), we need a selector?
    // For now, assume activeProgram provides context. If no active program, maybe default to C?
    // Let's use activeProgram.type or default to 'c'.
    
    const type = activeProgram ? activeProgram.type : 'c'; 
    // TODO: UI to select type for new custom code if no program selected? 
    // For now we rely on selecting a tile first or default C.

    addToConsole(`> Compiling and running (${type})...`, 'info');
    
    try {
      const res = await fetch(`${API_Base}/run`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ 
            filename: activeProgram ? activeProgram.path : 'custom.c', 
            type: type,
            content: editorContent,
            input: userInput
        })
      });
      const data = await res.json();
      
      if (data.success) {
        addToConsole(data.output || '[No Output]', 'success');
      } else {
        addToConsole(data.output || data.error || 'Unknown Error', 'error');
      }
    } catch (err) {
      addToConsole(`Error running program: ${err.message}`, 'error');
    }
  };
  
  const togglePanel = () => setIsPanelOpen(!isPanelOpen);

  return (
    <div className="app-container">
      <header className="app-header">
        <div style={{display:'flex', alignItems:'center', gap:'1rem'}}>
            <h1 className="app-title">Offline Code Runner</h1>
            <select 
                className="lang-filter" 
                value={selectedLang} 
                onChange={e => setSelectedLang(e.target.value)}
            >
                <option value="all">All Languages</option>
                <option value="c">C / C++</option>
                <option value="java">Java</option>
            </select>
        </div>
        
        <div className="header-actions">
             <input 
              type="text" 
              placeholder="Search programs..." 
              className="search-bar"
              value={search}
              onChange={(e) => setSearch(e.target.value)}
            />
            <button 
                className="btn-primary icon-btn" 
                onClick={togglePanel}
                title={isPanelOpen ? "Collapse Panel" : "Expand Panel"}
            >
                {isPanelOpen ? '>>' : '<<'}
            </button>
        </div>
      </header>
      
      <div className="split-layout" onMouseMove={isResizing ? (e) => e.preventDefault() : null}>
        {/* Left Panel */}
        <div className="left-panel" style={{ flex: 1 }}>
            <main className="programs-grid">
                {filteredPrograms.map((prog) => (
                    <ProgramTile 
                    key={prog.name} 
                    program={prog} 
                    isActive={activeProgram?.name === prog.name}
                    onClick={handleProgramClick}
                    />
                ))}
                {filteredPrograms.length === 0 && (
                    <div className="no-results">No programs found</div>
                )}
            </main>
        </div>

        {/* Resizer Handle */}
        {isPanelOpen && (
             <div 
                className="resizer"
                onMouseDown={startResizing}
             />
        )}

        {/* Right Panel */}
        <div 
            className={`right-panel ${isPanelOpen ? '' : 'collapsed'}`}
            style={{ width: isPanelOpen ? `${rightPanelWidth}%` : '0%' }}
        >
             <div className="editor-header">
                <div className="file-info">
                    <h2>{activeProgram ? activeProgram.name : 'Untitled'}</h2>
                    <span className="file-path">{activeProgram ? activeProgram.path : 'Select a file or type code'}</span>
                </div>
                <div style={{display:'flex', gap:'0.5rem'}}>
                    <button className="btn-primary" onClick={() => navigator.clipboard.writeText(editorContent)}>Copy</button>
                    <button className="btn-primary" onClick={handleRun}>Run Code</button>
                </div>
             </div>
             
             <div className="editor-content">
                <textarea 
                    className="code-editor"
                    value={editorContent}
                    onChange={(e) => setEditorContent(e.target.value)}
                    spellCheck="false"
                    placeholder="// Select a program or start typing C/Java code..."
                />
             </div>

             {showInput && (
                 <div className="input-panel">
                    <div className="input-header" style={{display:'flex', justifyContent:'space-between', alignItems:'center'}}>
                        <span>Program Input (Stdin)</span>
                        <button className="close-btn" onClick={() => setShowInput(false)}>×</button>
                    </div>
                    <textarea 
                        className="input-area"
                        value={userInput}
                        onChange={(e) => setUserInput(e.target.value)}
                        placeholder="Type input here before running..." 
                        spellCheck="false"
                    />
                 </div>
             )}

             {showOutput && (
                 <div className="output-panel">
                    <div className="output-header" style={{display:'flex', justifyContent:'space-between', alignItems:'center'}}>
                        <span>Terminal Output</span>
                        <button className="close-btn" onClick={() => setShowOutput(false)}>×</button>
                    </div>
                    <div className="output-logs">
                        {consoleLogs.map((log, i) => (
                            <div key={i} className={`log-entry ${log.type}`}>
                            <span style={{opacity:0.5}}>[{log.time}]</span> {log.text}
                            </div>
                        ))}
                        <div ref={consoleEndRef} />
                    </div>
                 </div>
             )}
        </div>
      </div>
    </div>
  )
}

export default App
