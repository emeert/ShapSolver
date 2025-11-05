@echo off
echo Compiling ShapeSolver...
g++ -std=c++17 -o ShapeSolver main.cpp triangle.cpp d2Common.cpp menuSystem.cpp
if %errorlevel% neq 0 (
    echo Build failed.
) else (
    echo Build complete.
)
pause