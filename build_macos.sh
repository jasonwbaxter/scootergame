#!/bin/bash

# MooversRacer Build Script for macOS
# Usage: ./build_macos.sh [Configuration] [Jobs]
# Example: ./build_macos.sh Development 4

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR"
CONFIG="${1:-Development}"
JOBS="${2:-4}"

echo ""
echo "========================================"
echo "MooversRacer Build - macOS"
echo "========================================"
echo "Configuration: $CONFIG"
echo "Build Jobs: $JOBS"
echo "Project Root: $PROJECT_ROOT"
echo ""

# Check prerequisites
echo "Checking prerequisites..."
if ! command -v clang &> /dev/null; then
    echo "ERROR: Clang not found. Install Xcode Command Line Tools:"
    echo "  xcode-select --install"
    exit 1
fi

# Step 1: Generate project files
echo "[Step 1/3] Generating project files..."
if [ -f "$PROJECT_ROOT/MooversRacer.uproject" ]; then
    if command -v GenerateProjectFiles.sh &> /dev/null; then
        GenerateProjectFiles.sh "$PROJECT_ROOT/MooversRacer.uproject" || true
    else
        echo "Note: GenerateProjectFiles.sh will run when you open the editor"
    fi
else
    echo "ERROR: MooversRacer.uproject not found at $PROJECT_ROOT"
    exit 1
fi

echo ""
echo "[Step 2/3] Building project..."
if [ -f "$PROJECT_ROOT/Makefile" ]; then
    cd "$PROJECT_ROOT"
    make MooversRacerEditor -j$JOBS
    BUILD_RESULT=$?
else
    echo "ERROR: Makefile not found!"
    echo "This project needs to be generated first"
    exit 1
fi

if [ $BUILD_RESULT -ne 0 ]; then
    echo "ERROR: Build failed with exit code $BUILD_RESULT"
    exit $BUILD_RESULT
fi

echo ""
echo "[Step 3/3] Build complete!"
echo ""
echo "To launch the editor:"
echo "  ./Binaries/Mac/UnrealEditor.app/Contents/MacOS/UnrealEditor MooversRacer.uproject"
echo ""
