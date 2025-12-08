# Base image
FROM node:18-bullseye

# 1. Install System Dependencies (GCC & Java)
RUN apt-get update && \
    apt-get install -y gcc default-jdk && \
    rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# 2. Setup Frontend
COPY frontend/package*.json ./frontend/
RUN cd frontend && npm install
COPY frontend/ ./frontend/
RUN cd frontend && npm run build

# 3. Setup Backend
COPY backend/package*.json ./backend/
RUN cd backend && npm install
COPY backend/ ./backend/
# Create temp directory for execution
RUN mkdir -p backend/temp

# 4. Copy Programs (Make sure to include some default ones)
COPY programs/ ./programs/

# Expose Render's default port (it sets PORT env var automatically)
EXPOSE 3001

# Start the server
CMD ["node", "backend/server.js"]
