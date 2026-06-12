@echo off
REM MooversRacer Build Script for Windows
REM Usage: build_windows.bat [Configuration] [Target]
REM Example: build_windows.bat Development Win64

setlocal enabledelayedexpansion

set CONFIG=%1
set PLATFORM=%2

if "%CONFIG%"=="" set CONFIG=Development
if "%PLATFORM%"=="" set PLATFORM=Win64

echo.
echo ========================================
echo MooversRacer Build - Windows
echo ========================================
echo Configuration: %CONFIG%
echo Platform: %PLATFORM%
echo.

REM Check if UE is available
where uproject >nul 2>&1
if errorlevel 1 (
    echo WARNING: Could not find Unreal Engine in PATH
    echo Please ensure UE 5.4+ is installed and registered
    echo.
)

REM Step 1: Generate project files
echo [Step 1/3] Generating project files...
call "%cd%\MooversRacer.uproject" 2>nul
if not exist "%cd%\MooversRacer.sln" (
    echo Attempting to generate via UE command...
    REM Note: This requires UE to be in PATH or manually specified
)

REM Step 2: Build the project
echo [Step 2/3] Building project...
if exist "%cd%\MooversRacer.sln" (
    msbuild MooversRacer.sln /p:Configuration=%CONFIG% /p:Platform=%PLATFORM% /m
    if errorlevel 1 (
        echo ERROR: Build failed!
        exit /b 1
    )
) else (
    echo ERROR: MooversRacer.sln not found!
    echo Please run GenerateProjectFiles.bat first
    exit /b 1
)

REM Step 3: Success
echo [Step 3/3] Build complete!
echo.
echo To launch the editor:
echo   .\Binaries\%PLATFORM%\UnrealEditor.exe MooversRacer.uproject
echo.
echo To run the game:
echo   .\Binaries\%PLATFORM%\MooversRacer.exe
echo.

endlocal
