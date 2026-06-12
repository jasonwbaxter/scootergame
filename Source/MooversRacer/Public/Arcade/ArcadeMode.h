// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * Arcade mode documentation and specification
 */

/**

# ARCADE MODE: 4-Lane Scooter Racer

## Overview
Arcade mode is a fast-paced, lane-based endless scooter game inspired by classic arcade racers. 
Navigate through 4 lanes, avoiding obstacles and collecting power-ups while accumulating points 
and multipliers. The difficulty ramps up over time as obstacles spawn faster.

## Gameplay Mechanics

### Lane System
- **4 Lanes**: Left, Left-Center, Right-Center, Right
- **Lane Switching**: Smooth interpolated movement between lanes (0.3s transition)
- **Lane Width**: 200 units for balanced navigation

### Controls
- **Left/Right Arrow Keys**: Switch lanes
- **A Button**: Increase speed
- **B Button**: Decrease speed
- **Speed Range**: 20–150 units/second (adjustable)

### Obstacles
- **Pothole**: Damage obstacle, requires 1 health
- **Traffic Cone**: Minor hazard, same damage as pothole
- **Spawn Rate**: 1 every 2 seconds (ramps up over time)
- **Health System**: 3 hits before game over
- **Invulnerability**: 1 second after hit

### Power-ups
- **Speed Ramp**: 1.5x speed boost for 5 seconds
- **Skull & Crossbones (Invincibility)**: Temporary invulnerability for 5 seconds
- **Spawn Chance**: 30% of spawned objects are power-ups (70% obstacles)
- **Visual Feedback**: Rotating mesh, glowing effect (TBD)

### Scoring System
- **Base Score**: 10 points per second survived
- **Score Multiplier**: 1x–10x (increases on successful dodges or power-up pickups)
- **Multiplier Decay**: Resets to 1x on collision (if not invincible)
- **High Score Tracking**: Persistent leaderboard

### Difficulty Progression
- **Time-Based Ramping**: Every 30 seconds, increase spawn rate
- **Dynamic Spawn Rate**: Decreases from 2.0s intervals down to 0.5s minimum
- **Visual Feedback**: Speed up music, increase visual intensity, screen effects

## Technical Implementation

### Core Classes

**AArcadeScooterPawn**
- Lane-based movement system
- Speed management (accel/decel)
- Power-up activation handlers
- Collision detection with obstacles

**AArcadeRaceManager**
- Game state machine (Menu, Playing, GameOver, Paused)
- Obstacle and power-up spawning
- Score and multiplier management
- Difficulty scaling
- High score tracking

**AArcadeObstacle**
- Collision box for scooter detection
- Visual mesh (pothole or cone)
- Auto-despawn when off-screen

**AArcadePowerUp**
- Collision detection
- Type-based activation (Speed or Invincibility)
- Rotating visual effect
- Auto-despawn

**UArcadeHUD**
- Score and multiplier display
- Health indicator (3 hearts)
- Power-up status notification
- Game over screen with high score comparison

**UArcadePhysicsComponent**
- Health tracking (0–3)
- Invulnerability timer management
- Hit feedback system

## Visual Style
- **Arcade Aesthetic**: Bright colors, bold outlines, retro-modern design
- **Lanes**: Clear lane markers with glowing edges
- **Obstacles**: Stylized potholes and cones with warning colors
- **Power-ups**: Glowing rotating gems (Speed Ramp) and skulls (Invincibility)
- **UI**: Large readable fonts, arcade-style numbers and icons

## Audio Design
- **Engine Hum**: Continuous low-frequency backdrop
- **Lane Change SFX**: Quick beep on successful lane switch
- **Power-up Activation**: Satisfying "whoosh" or "chime" sound
- **Collision Sound**: Sharp impact noise with brief screen shake
- **Score Multiplier**: Escalating musical stings for each multiplier tier
- **Game Over**: Retro arcade "game over" jingle

## Performance Targets
- **60 FPS** on flagship Android devices
- **4 lanes × dynamic object spawning** optimized with pooling
- **Minimal draw calls** for arcade visual style

## Future Enhancements
- Multiple difficulty levels (Easy, Normal, Hard, Extreme)
- Different scooter skins with arcade flair
- Combo system (consecutive dodges = bonus multiplier)
- Daily challenges and leaderboard reset
- Cosmetic rewards for high scores

*/
