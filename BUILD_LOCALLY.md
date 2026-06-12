# Building MooversRacer Locally

This guide will help you build and test the MooversRacer game on your local machine.

## Prerequisites

### Required
- **Unreal Engine 5.4** (or later)
  - Download from Epic Games Launcher or build from source
  - Engine must be installed and its path registered with `ue4cli` or similar
- **C++ Development Tools**
  - Visual Studio 2022 (Windows) with C++ workload
  - Xcode with Command Line Tools (Mac)
  - GCC/Clang + build-essential (Linux)
- **Sufficient Disk Space**: ~100+ GB available

### Optional (for Android builds)
- Android SDK and NDK
- Android Studio (recommended)

## Quick Start (3 Steps)

### Step 1: Generate Project Files

**Windows (PowerShell):**
```powershell
cd C:\path\to\scootergame
& "C:\Program Files\Epic Games\UE_5.4\Engine\Build\BatchFiles\GenerateProjectFiles.bat" MooversRacer.uproject
```

**macOS/Linux (Bash):**
```bash
cd /path/to/scootergame
/path/to/UnrealEngine/UE_5.4/Engine/Build/BatchFiles/GenerateProjectFiles.sh MooversRacer.uproject
```

### Step 2: Compile the Project

**Windows (Visual Studio):**
```powershell
cd C:\path\to\scootergame
msbuild MooversRacer.sln /p:Configuration=Development /p:Platform=Win64
# Or build in Visual Studio GUI:
# 1. Open MooversRacer.sln
# 2. Set Configuration: Development
# 3. Set Platform: Win64
# 4. Build > Build Solution
```

**macOS:**
```bash
cd /path/to/scootergame
make MooversRacerEditor
```

**Linux:**
```bash
cd /path/to/scootergame
make MooversRacerEditor
```

### Step 3: Launch the Editor

**Windows:**
```powershell
.\Binaries\Win64\UnrealEditor.exe MooversRacer.uproject
```

**macOS:**
```bash
./Binaries/Mac/UnrealEditor.app/Contents/MacOS/UnrealEditor MooversRacer.uproject
```

**Linux:**
```bash
./Binaries/Linux/UnrealEditor MooversRacer.uproject
```

## Testing the Game

Once the editor opens:

### 1. **Test Racing Mode**
- Click **Play** (Alt+P) to run in the editor
- Drive around the track with WASD (or gamepad)
- Test acceleration, braking, and boost mechanics
- Access the garage from the main menu

### 2. **Test Arcade Mode**
- Select "Arcade Mode" from the main menu
- Test lane-switching with Arrow Keys
- Test obstacle avoidance
- Verify score and health systems

### 3. **Build a Standalone Executable**

**Windows:**
```powershell
cd C:\path\to\scootergame
& "C:\Program Files\Epic Games\UE_5.4\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun `
  -project="C:\path\to\scootergame\MooversRacer.uproject" `
  -platform=Win64 `
  -configuration=Development `
  -build `
  -cook `
  -stage `
  -package `
  -archive `
  -archivedirectory="C:\Builds"
```

**macOS/Linux:**
```bash
cd /path/to/scootergame
/path/to/UnrealEngine/UE_5.4/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun \
  -project=/path/to/scootergame/MooversRacer.uproject \
  -platform=Linux \
  -configuration=Development \
  -build \
  -cook \
  -stage \
  -package \
  -archive \
  -archivedirectory=/path/to/Builds
```

### 4. **Build for Android (APK)**

```bash
cd /path/to/scootergame

# Make sure you have Android SDK/NDK configured in your engine
/path/to/UnrealEngine/UE_5.4/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun \
  -project=/path/to/scootergame/MooversRacer.uproject \
  -platform=Android \
  -configuration=Development \
  -build \
  -cook \
  -stage \
  -package \
  -archive \
  -archivedirectory=/path/to/Builds \
  -targetplatform=Android
```

The APK will be available at `/path/to/Builds/Android/` for sideloading.

## Troubleshooting

### "Engine not found"
- Verify UE 5.4 is installed and the path is correct
- On Windows, associate the .uproject with the engine: Right-click MooversRacer.uproject → "Switch Unreal Engine version..." → Select UE 5.4

### Compilation errors
- Delete `Intermediate/` and `Binaries/` folders, then regenerate project files
- Ensure you have the latest C++ build tools installed
- Check that all source files are present in `Source/MooversRacer/`

### Out of memory during compilation
- Close other applications
- Try compiling in Release mode instead of Development (faster, less memory)
- Use `make -j4` (or lower number) to limit parallel compilation

### Editor crashes on startup
- Delete `Saved/` folder
- Verify all Content assets are present
- Check the log file: `Saved/Logs/MooversRacer.log`

## Build Configurations

| Config | Best For | Performance |
|--------|----------|-------------|
| **Debug** | Bug hunting | Slow (symbols, no optimization) |
| **Development** | Testing features | Good (optimized, full debugging) |
| **Shipping** | Final release | Excellent (max optimization) |

For testing, use **Development**.

## Next Steps After Building

1. ✅ Verify both Racing and Arcade modes load
2. ✅ Test all controls (steering, acceleration, boost)
3. ✅ Test garage customization system
4. ✅ Test audio (engine sounds, music)
5. ✅ Profile performance (Target: 60 FPS)
6. ✅ Create a build report in the root directory

## Useful Console Commands

In-game, press **`** (backtick) to open the console:

```
stat fps              # Show current FPS
stat unit             # Show render/game/GPU times
r.ScreenPercentage 50 # Performance testing (50% resolution)
show collision        # Visualize collision bounds
show physics          # Visualize physics bodies
```

## Documentation

- [Design Spec](Docs/Design/DESIGN_SPEC.md)
- [Technical Architecture](Docs/Technical/ARCHITECTURE.md)
- [Arcade Mode Details](Docs/Technical/ARCADE_MODE.md)
- [Visual Style Guide](Docs/Design/VISUAL_IDENTITY_GUIDE.md)

---

**Questions?** Check the logs in `Saved/Logs/MooversRacer.log` for detailed error messages.
