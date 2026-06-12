# MooversRacer Build Checklist

Use this checklist to verify your local build is working correctly.

## Pre-Build Setup ✓

- [ ] Unreal Engine 5.4+ installed
- [ ] Visual Studio 2022 (Windows) / Xcode (Mac) / GCC (Linux) installed
- [ ] C++ workload/tools configured
- [ ] At least 100GB free disk space
- [ ] Project cloned to local machine

## Build Process ✓

- [ ] Ran `GenerateProjectFiles.bat/sh` successfully
- [ ] Project files (.sln/.xcworkspace) generated
- [ ] Compilation started without errors
- [ ] No out-of-memory errors during compilation
- [ ] Build completed successfully (no red errors)

## Editor Launch ✓

- [ ] Unreal Editor opened without crashing
- [ ] Project loaded completely (may take 2-5 minutes first time)
- [ ] Content Browser visible with asset folders
- [ ] Viewport renders without errors
- [ ] Console shows no critical errors

## Racing Mode Testing ✓

- [ ] Main menu loads
- [ ] "Start Race" button works
- [ ] Race level loads with track visible
- [ ] Scooter spawns and is visible
- [ ] **Controls Work:**
  - [ ] WASD moves the scooter
  - [ ] Mouse/gamepad rotates camera
  - [ ] Spacebar/Shift boosts
  - [ ] Can accelerate and brake
- [ ] **HUD displays:**
  - [ ] Speed indicator
  - [ ] Lap timer
  - [ ] Boost bar
  - [ ] Minimap (if implemented)
- [ ] **Physics work:**
  - [ ] Scooter responds to terrain
  - [ ] Collision with obstacles works
  - [ ] Boost increases speed noticeably
  - [ ] No glitching through terrain

## Arcade Mode Testing ✓

- [ ] "Arcade Mode" accessible from menu
- [ ] Game starts without crashing
- [ ] **Controls work:**
  - [ ] Arrow keys change lanes
  - [ ] A/D increases/decreases speed
  - [ ] Game responds to input
- [ ] **Gameplay:**
  - [ ] Obstacles spawn in lanes
  - [ ] Can avoid obstacles
  - [ ] Power-ups appear
  - [ ] Score increases
  - [ ] Health decreases on collision
  - [ ] Game ends at 0 health

## Garage/Customization ✓

- [ ] Garage menu accessible
- [ ] 3D preview displays scooter
- [ ] Can equip different parts
- [ ] Stats update when parts change
- [ ] Visual customization shows in preview
- [ ] Part categories visible (rims, exhausts, body, etc.)

## Audio System ✓

- [ ] Engine sound plays during acceleration
- [ ] Pitch changes with speed
- [ ] Boost sound triggers
- [ ] Background music plays in menus/race
- [ ] Collision/impact sounds trigger
- [ ] Volume controls work

## Performance ✓

- [ ] Game runs at 60 FPS on desktop
- [ ] No stuttering during gameplay
- [ ] Frame time is consistent (<16.7ms for 60 FPS)
- [ ] Memory usage stable (no leaks)
- [ ] No GPU/CPU bottlenecks obvious
- [ ] Editor runs smoothly during editing

## Build Artifacts ✓

- [ ] Binaries folder created
  - [ ] `Binaries/Win64/` (Windows) or
  - [ ] `Binaries/Mac/` (macOS) or
  - [ ] `Binaries/Linux/` (Linux)
- [ ] Intermediate folder created with .obj files
- [ ] Saved folder created with logs
- [ ] `MooversRacer.sln` generated (Windows)

## Standalone Build (Optional) ✓

- [ ] Packaged game executable created
- [ ] Standalone game launches
- [ ] All features work in standalone
- [ ] No editor-only features present

## Android Build (Optional) ✓

- [ ] Android SDK/NDK configured
- [ ] APK built successfully
- [ ] APK sideloaded to device
- [ ] Game runs on Android 12+
- [ ] Touch controls work correctly
- [ ] Performance acceptable on device

## Documentation ✓

- [ ] Reviewed [Design Spec](Docs/Design/DESIGN_SPEC.md)
- [ ] Reviewed [Technical Architecture](Docs/Technical/ARCHITECTURE.md)
- [ ] Reviewed [Arcade Mode](Docs/Technical/ARCADE_MODE.md)
- [ ] Understood core systems (Physics, AI, Customization)

## Troubleshooting Notes

If any step failed, record the issue:

| Step | Issue | Resolution |
|------|-------|-----------|
| | | |
| | | |
| | | |

---

## Next Steps After Successful Build

1. **Create a test report** documenting all features tested
2. **Note any bugs or issues** for the dev team
3. **Test on target device** if building for Android
4. **Performance profile** to identify bottlenecks
5. **Verify all content assets** are rendering correctly

**Build Date:** _______________  
**Tester Name:** _______________  
**Platform:** [ ] Windows [ ] macOS [ ] Linux [ ] Android  
**Status:** [ ] ✅ PASS [ ] ⚠️ WARNINGS [ ] ❌ FAILED
