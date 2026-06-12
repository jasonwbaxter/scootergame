# Moovers Racer - Technical Architecture

## Engine and Platform
- **Engine**: Unreal Engine 5.4+
- **Primary Platform**: Android (Vulkan, optimized for flagship devices)
- **Secondary Targets**: Windows, macOS, Linux (dev builds)
- **Min Spec**: Snapdragon 8 Gen 2 / Mali-G78+ (60 FPS)
- **Target Spec**: Snapdragon 8 Gen 3 / Mali-G715 (120 FPS potential)

## Core Systems

### Vehicle Physics
**File**: `Source/MooversRacer/Public/Vehicles/ScooterPhysicsComponent.h`

**Features**:
- Throttle and steering input handling
- Speed ramping with acceleration/deceleration curves
- Turbo boost system with cooldown management
- Clutch engagement mechanics
- Customization-based stat multipliers

**Key Parameters**:
- Max Speed: 120 km/h (scalable per scooter)
- Acceleration: 15 units/s²
- Turbo Multiplier: 1.5x speed boost
- Drift Factor: 0.8 (weight transfer on high-speed turns)

### Race Management
**File**: `Source/MooversRacer/Public/Racing/RaceManager.h`

**State Machine**:
```
Idle → CountDown → Racing → Finished
               ↓ (pause)
              Paused ↻ (resume)
```

**Features**:
- 3-minute race duration (vertical slice)
- Lap timing and best lap tracking
- Race time accumulation
- Checkpoint system (TODO)

### Garage and Customization
**File**: `Source/MooversRacer/Public/Garage/GarageManager.h`

**Features**:
- Part equipping/unequipping with replacement logic
- Live 3D preview integration
- Part database (DataTable) loading
- Stat recalculation based on equipped parts

**Part Structure** (`PartDefinition.h`):
- PartID, Name, Description
- Type enum (Rim, Exhaust, etc.)
- Rarity enum (Common–Legendary)
- Stat modifiers (engine power, handling, weight, durability)
- Visual material and mesh references
- Price for economy system

### Audio System
**File**: `Source/MooversRacer/Public/Audio/AudioManager.h`

**Features**:
- Engine sound with RPM-based pitch modulation
- Foley effects (clutch click, exhaust pop, turbo whine)
- Adaptive race music with intensity modulation
- Spatial audio with attenuation

**Audio Components**:
- Engine (looping, pitch-driven)
- Music (looping, intensity-driven)
- Foley (one-shot effects)

## Game Mode and Pawn Structure

### MooversRacerGameMode
**File**: `Source/MooversRacer/Public/Core/MooversRacerGameMode.h`

**Responsibilities**:
- Spawn and manage RaceManager, GarageManager, AudioManager
- Handle state transitions (race ↔ garage)
- Coordinate manager lifecycle

### ScooterPawn
**File**: `Source/MooversRacer/Public/Vehicles/ScooterPawn.h`

**Components**:
- `SkeletalMeshComponent`: Vehicle mesh with rigged parts
- `ScooterPhysicsComponent`: Custom physics logic
- `SpringArmComponent`: Camera boom for dynamic follow
- `CameraComponent`: Third-person chase camera

**Input Mapping**:
- Enhanced Input System with InputMappingContext
- Move (analog): Throttle/steering
- Look (analog): Camera rotation
- Turbo (action): Boost activation
- Clutch (action): Transmission control

## Data Tables and Assets

### Part Database
- Location: `/Content/Data/DT_Parts`
- Type: DataTable (FPart struct rows)
- Contents: All customizable parts with stats and visuals

### Audio Assets
- Engine loops: `/Content/Audio/Engine_*`
- Foley: `/Content/Audio/Foley_*`
- Music: `/Content/Audio/Music_RaceAdaptive`

### Material Library
- PBR base materials: `/Content/Materials/Base_*`
- Paint variants: `/Content/Materials/Paint_*`
- Decal materials: `/Content/Materials/Decal_*`

## Performance Optimization

### LOD Strategy
- **Vehicle LODs**: Full detail (near), simplified (mid), impostor (far)
- **Environment LODs**: Full props (near), simplified geometry (mid), baked shadows (far)
- **Texture Streaming**: Mip-levels for dynamic streaming on Android

### Scalability Presets
1. **Ultra** (Snapdragon 8 Gen 3): Full visuals, 120 FPS target
2. **High** (Snapdragon 8 Gen 2): 60 FPS, reduced shadow complexity
3. **Medium** (Snapdragon 7+ Gen 1): 60 FPS, simplified geometry, lower resolution
4. **Low** (Mid-range): 30 FPS, stripped effects, minimal detail

### Memory Budget
- Initial install: ≤ 2.5 GB
- Runtime heap: ≤ 1.5 GB on flagship devices
- Streaming pool: 512 MB (dynamic management)

## Build Configuration

### Module Structure
**Module**: `MooversRacer`
**Type**: Runtime
**Dependencies**:
- Engine (core UE5)
- CoreUObject, InputCore
- EnhancedInput (modern input system)
- ChaosVehicles (vehicle physics framework)
- UMG (UI)
- Slate/SlateCore (low-level UI)

### Android-Specific Settings
- Vulkan preferred graphics API (OpenGL fallback disabled)
- ARM64 architecture
- Enabled permissions: INTERNET (leaderboards)

## File Organization

```
Source/MooversRacer/
├── Public/
│   ├── Core/MooversRacerGameMode.h
│   ├── Vehicles/ScooterPawn.h
│   ├── Vehicles/ScooterPhysicsComponent.h
│   ├── Racing/RaceManager.h
│   ├── Garage/GarageManager.h
│   ├── Customization/PartDefinition.h
│   └── Audio/AudioManager.h
└── Private/
    ├── Core/MooversRacerGameMode.cpp
    ├── Vehicles/ScooterPawn.cpp
    ├── Vehicles/ScooterPhysicsComponent.cpp
    ├── Racing/RaceManager.cpp
    ├── Garage/GarageManager.cpp
    └── Audio/AudioManager.cpp
```

---

**Next Architectural Tasks**:
- Implement checkpoint system with spatial queries
- Design networked leaderboard sync
- Create Blueprint subclasses for scooter variants
- Develop UI framework with UMG widgets
