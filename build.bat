@echo off
setlocal

echo Building PointShapeSolver...

:: Ensure the executable folder exists
if not exist executable (
    mkdir executable
)

:: Compile from root, referencing organized source files
g++ -std=c++17 -o executable\PointShapeSolver.exe ^
    src\main.cpp ^
    src\shapes\triangle.cpp ^
    src\shapes\quadrilateral.cpp ^
    src\common\d2Common.cpp ^
    src\menu\menuSystem.cpp

:: Check for errors
if %errorlevel% neq 0 (
    echo Build failed.
) else (
    echo Build complete. Executable is in the 'executable' folder.
)

pause
endlocal