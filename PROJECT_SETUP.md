# Moovers Racer - Project Setup Complete ✓

## Project Structure Overview

This is a **vertical slice** for Moovers Racer, an Unreal Engine 5 Android racing game inspired by Vespa parts culture and workshop aesthetics.

### Directory Layout

```
Source/MooversRacer/
├── Public/                          # Header files
│   ├── Core/                        # Game mode and base classes
│   ├── Vehicles/                    # Scooter pawn and physics
│   ├── Racing/                      # Race management and logic
│   ├── Garage/                      # Customization system
│   ├── Customization/               # Part definitions and data
│   └── Audio/                       # Audio management
├── Private/                         # Implementation files
└── MooversRacer.Build.cs           # Module build configuration

Content/
├── Vehicles/                        # Vehicle models and animations
├── Garage/                          # Garage scene and UI assets
├── Tracks/                          # Race track level and props
├── UI/                              # HUD and menu widgets
├── Audio/                           # Engine sounds, music, Foley
└── Materials/                       # PBR materials and decals

Docs/
├── Design/                          # Design specifications
├── Technical/                       # Technical architecture
└── Art/                             # Art direction and asset inventory
```

## Core Systems

### 1. **Vehicle Physics (ScooterPhysicsComponent)**
- Semi-realistic low-speed drift handling
- Turbo boost system with cooldown
- Clutch engagement mechanics
- Customization stat application (engine, handling, weight)

### 2. **Race Management (RaceManager)**
- Race state machine (Idle → CountDown → Racing → Finished)
- Lap timing and best lap tracking
- 3-minute race duration for vertical slice
- Pause/resume functionality

### 3. **Garage System (GarageManager)**
- Part equipping/unequipping
- Live 3D preview with customization
- Part database integration
- Stat recalculation

### 4. **Audio Manager (AudioManager)**
- Engine sound pitch modulation based on RPM
- Foley effects (clutch click, exhaust pop, turbo whine)
- Adaptive music intensity tied to race progress

### 5. **Customization System**
- 8 part types: Rims, Exhausts, Body Panels, Paint, Decals, Engines, Suspension, Mirrors
- 5 rarity tiers: Common → Uncommon → Rare → Epic → Legendary
- Stat multipliers for parts (engine power, handling, weight, durability)

## Input Scheme

- **Move (Analog)**: Throttle / Steering
- **Look (Analog)**: Camera rotation (pitch/yaw)
- **Turbo (Action)**: Press to activate boost
- **Clutch (Action)**: Press to engage/disengage

## Performance Targets

- **Target**: 60 FPS on flagship Android devices (Snapdragon 8 Gen 2+)
- **Fallback**: Scalable presets for mid-range hardware
- **Initial Storage**: ≤ 2.5 GB with texture streaming

## Vertical Slice Deliverables

✓ Project structure scaffolded  
✓ Core C++ classes implemented  
- [ ] One city track created  
- [ ] 3 scooter base models  
- [ ] 6+ customizable parts  
- [ ] Garage UI and preview  
- [ ] Race HUD and menus  
- [ ] Audio assets and systems  
- [ ] Performance optimization pass  

## Next Steps

1. **Create Blueprint subclasses** for easier content iteration
2. **Design and model 3 base scooters** (stock, sport, custom)
3. **Create part variants** with visual and stat differences
4. **Build garage level** with interactive 3D preview
5. **Design one city circuit** with checkpoints
6. **Implement HUD** with speed, turbo, and damage indicators
7. **Polish physics** for responsive, predictable handling
8. **Optimize for Android** with LODs and texture streaming

## Build Instructions

```bash
# Generate Visual Studio project files
cd /workspaces/scootergame
/path/to/UnrealEngine/Engine/Build/BatchFiles/GenerateProjectFiles.sh MooversRacer.uproject

# Compile
make MooversRacerEditor

# Launch
./Binaries/Linux/UnrealEditor MooversRacer.uproject
```

---

**Team**: Technical Director, Lead Designer, Lead Artist, Audio Lead, Network Engineer, QA  
**Timeline**: Vertical slice (Sprints 0–4, Weeks 0–8)  
**Engine**: Unreal Engine 5.4+  
**Target Platform**: Android (primary), Windows/Mac/Linux (dev)
