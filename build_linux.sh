#!/bin/bash

# MooversRacer Build Script for Linux
# Usage: ./build_linux.sh [Configuration] [Jobs]
# Example: ./build_linux.sh Development 4

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR"
CONFIG="${1:-Development}"
JOBS="${2:-4}"

echo ""
echo "========================================"
echo "MooversRacer Build - Linux"
echo "========================================"
echo "Configuration: $CONFIG"
echo "Build Jobs: $JOBS"
echo "Project Root: $PROJECT_ROOT"
echo ""

# Check prerequisites
check_ue_installed() {
    if ! command -v UnrealEditor &> /dev/null && [ ! -d "$(find /opt -name 'UnrealEngine-*' -type d 2>/dev/null | head -1)" ]; then
        echo "WARNING: Could not find Unreal Engine in PATH"
        echo "Please ensure UE 5.4+ is installed"
        echo ""
        return 1
    fi
    return 0
}

# Step 1: Generate project files
echo "[Step 1/3] Generating project files..."
if [ -f "$PROJECT_ROOT/MooversRacer.uproject" ]; then
    if command -v GenerateProjectFiles.sh &> /dev/null; then
        GenerateProjectFiles.sh "$PROJECT_ROOT/MooversRacer.uproject" || true
    else
        echo "Note: GenerateProjectFiles.sh not found in PATH"
        echo "Project files should be generated when opening the editor"
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
    echo "This project needs to be generated first using GenerateProjectFiles.sh"
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
echo "  ./Binaries/Linux/UnrealEditor MooversRacer.uproject"
echo ""
echo "To run the game:"
echo "  ./Binaries/Linux/MooversRacer"
echo ""
