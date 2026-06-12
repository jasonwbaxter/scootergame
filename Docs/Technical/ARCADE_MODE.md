# Arcade Mode - 4-Lane Racing

## Vertical Slice Addition

This arcade mode adds a completely new gameplay style to Moovers Racer: a fast-paced, lane-based endless runner inspired by classic arcade racers.

### New Systems

| Component | File | Purpose |
|-----------|------|---------|
| **AArcadeScooterPawn** | `Arcade/ArcadeScooterPawn` | Lane-based scooter with speed management |
| **AArcadeRaceManager** | `Arcade/ArcadeRaceManager` | Game state, spawning, scoring, difficulty |
| **AArcadeObstacle** | `Arcade/ArcadeObstacle` | Potholes and traffic cones to avoid |
| **AArcadePowerUp** | `Arcade/ArcadePowerUp` | Speed boosts and invincibility pickups |
| **UArcadePhysicsComponent** | `Arcade/ArcadePhysicsComponent` | Health and collision tracking |
| **UArcadeHUD** | `Arcade/ArcadeHUD` | Score, multiplier, health display |
| **AArcadeGameMode** | `Arcade/ArcadeGameMode` | Arcade-specific game mode |

### Gameplay Features

**4-Lane Navigation**
- Smooth lane switching with 0.3s interpolation
- 4 lanes: Far-Left, Left-Center, Right-Center, Far-Right
- Lane width: 200 units

**Obstacles**
- Potholes and traffic cones spawn randomly in lanes
- 1 damage per hit
- Auto-despawn when off-screen
- Spawn rate increases over time (2.0s → 0.5s per object)

**Power-ups**
- Speed Ramp: 1.5x speed boost for 5 seconds
- Invincibility (Skull & Crossbones): 5 seconds of temporary invulnerability
- 30% spawn chance (70% obstacles, 30% power-ups)
- Rotating visual effect with glowing material

**Scoring System**
- Base: 10 points per second survived
- Multiplier: 1x–10x (increases on successful dodges)
- Multiplier resets to 1x on collision (unless invincible)
- High score tracking and leaderboard

**Health System**
- Start with 3 health
- 1 health lost per obstacle collision
- 1-second invulnerability after hit
- Game over at 0 health

**Difficulty Ramping**
- Spawn rate increases every 30 seconds
- Music intensity increases with difficulty
- Visual effects escalate (screen effects, colors, etc.)

### Controls

| Action | Input | Effect |
|--------|-------|--------|
| Move Left | Left Arrow | Switch to left lane |
| Move Right | Right Arrow | Switch to right lane |
| Increase Speed | A Button | Accelerate |
| Decrease Speed | B Button | Decelerate |

**Speed Range**: 20–150 units/second

### Visual Design

- **Arcade Aesthetic**: Bold colors, glowing lane markers, retro-modern UI
- **Obstacles**: Stylized potholes (gray/brown) and cones (orange/white)
- **Power-ups**: Glowing rotating gems (Speed) and skulls (Invincibility)
- **UI**: Large readable fonts, arcade-style score counter, health hearts

### Audio Design

- **Engine Hum**: Continuous background sound
- **Lane Change**: Quick beep/chime
- **Power-up Pickup**: Satisfying "whoosh" sound
- **Collision**: Sharp impact with screen shake
- **Score Multiplier**: Escalating musical stings
- **Game Over**: Classic arcade "game over" jingle

### Integration with Main Game

The arcade mode is fully integrated into the main **MooversRacerGameMode**:
- Can be launched as an alternative to traditional racing
- Shares the same audio manager and some UI systems
- Independent game state and progression

### Blueprint Extensions

For content creators and designers, the following classes are easily extensible via Blueprint:

- **BP_ArcadeScooter**: Custom scooter variants with arcade skins
- **BP_ArcadeObstacle**: Different obstacle types and visuals
- **BP_ArcadePowerUp**: New power-up types and effects
- **BP_ArcadeHUD**: Custom HUD layouts and animations

---

**Next Steps**:
1. Create Blueprint subclasses for scooter/obstacles/power-ups
2. Design and model arcade-style assets
3. Implement arcade UI in UMG with animations
4. Tune difficulty curve based on playtest feedback
5. Add visual effects (screen shake, explosions, particle systems)
6. Connect to leaderboard system
