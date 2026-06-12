# Moovers Racer

A high-fidelity Android racing game inspired by Vespa parts culture and workshop aesthetics. Featuring two distinct gameplay modes:

## 🏁 Racing Mode
**Vertical Slice** - Classic circuit racing with authentic scooter handling, deep customization, and garage progression.

- **Semi-realistic Physics**: Weight transfer, drift mechanics, clutch and turbo engagement
- **Modular Customization**: Swap rims, exhausts, body panels, paint, and performance parts
- **3D Garage Preview**: Interactive customization with stat feedback
- **Career Progression**: Multi-lap races with best-lap tracking

## 🎮 Arcade Mode
**4-Lane Endless Runner** - Fast-paced, lane-based arcade racing inspired by classic arcade games.

- **4-Lane Navigation**: Smooth lane switching with intuitive controls
- **Dynamic Obstacles**: Potholes and traffic cones to avoid
- **Power-ups**: Speed boosts and temporary invincibility
- **Scoring System**: Points with 1x–10x multiplier
- **Progressive Difficulty**: Obstacles spawn faster over time
- **Health System**: 3 hits before game over

### Arcade Controls
- **Left/Right Arrows**: Change lanes
- **A Button**: Increase speed
- **B Button**: Decrease speed

## Features

### Racing Mode
✓ Playable 3-minute race  
✓ Interactive garage with 6+ customizable parts  
✓ Live 3D preview with stat recalculation  
✓ Adaptive music and Foley audio  
✓ 60 FPS on flagship Android devices  

### Arcade Mode
✓ 4-lane endless runner  
✓ Obstacle spawning and avoidance  
✓ Power-up collection system  
✓ Score tracking with multiplier  
✓ Progressive difficulty ramping  
✓ Health and collision feedback  

## Project Structure

```
Source/MooversRacer/
├── Public/Core/              # Game mode and base systems
├── Public/Vehicles/          # Racing mode vehicles
├── Public/Arcade/            # Arcade mode systems
├── Public/Racing/            # Race management
├── Public/Garage/            # Customization
├── Public/Customization/     # Part definitions
└── Public/Audio/             # Audio management

Content/
├── Vehicles/                 # Vehicle models
├── Garage/                   # Garage scenes
├── Tracks/                   # Race tracks
├── Arcade/                   # Arcade assets
└── UI/                       # HUD and menus

Docs/
├── Design/DESIGN_SPEC.md     # Game design
├── Technical/ARCHITECTURE.md # Technical overview
├── Technical/ARCADE_MODE.md  # Arcade mode details
└── Technical/ROADMAP.md      # Development timeline
```

## Technical Details

**Engine**: Unreal Engine 5.4+  
**Platform**: Android (primary), Windows/Mac/Linux (dev)  
**Graphics**: Vulkan, Nanite, Lumen  
**Physics**: Chaos Vehicles Framework  
**Performance**: 60 FPS on Snapdragon 8 Gen 2+  
**Storage**: ≤ 2.5 GB (texture streaming enabled)  

## Quick Start

1. **Generate Project Files**
   ```bash
   cd /workspaces/scootergame
   /path/to/UnrealEngine/Engine/Build/BatchFiles/GenerateProjectFiles.sh MooversRacer.uproject
   ```

2. **Compile**
   ```bash
   make MooversRacerEditor
   ```

3. **Launch**
   ```bash
   ./Binaries/Linux/UnrealEditor MooversRacer.uproject
   ```

## Documentation

- [Design Specification](Docs/Design/DESIGN_SPEC.md)
- [Technical Architecture](Docs/Technical/ARCHITECTURE.md)
- [Arcade Mode Guide](Docs/Technical/ARCADE_MODE.md)
- [Development Roadmap](Docs/Technical/ROADMAP.md)

## Development Status

**Vertical Slice**: In Progress (Sprints 0–4, Weeks 0–8)

See [ROADMAP.md](Docs/Technical/ROADMAP.md) for full development timeline.

---

**Team**: Technical Director, Lead Designer, Lead Artist, Audio Lead, Network Engineer, QA  
**Brand**: Inspired by Moovers Speed Shop (partnership pending)  
**Target Audience**: Scooter and retro vehicle enthusiasts, mobile racing fans
