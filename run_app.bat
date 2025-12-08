@echo off
echo Starting Offline Code Runner...

:: Start Backend
start "OfflineCodeRunner Backend" cmd /k "cd backend && npm start"

:: Start Frontend
start "OfflineCodeRunner Frontend" cmd /k "cd frontend && npm run dev"

:: Wait a moment for servers to spin up
timeout /t 5

:: Open Browser (Assuming running on port 5173 by default, but checking user logs it was 5174 sometimes)
:: We can try opening 5173. 
start http://localhost:5173

echo.
echo Application started! 
echo If the page doesn't load, check the Frontend terminal for the correct port (e.g. 5174).
echo.
pause
