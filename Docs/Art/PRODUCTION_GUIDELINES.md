# Moovers Racer - Art Production Guidelines

## Quick Reference for Asset Creation

---

## Brand Quick Reference

```
KRONOS MOTORS (Tech/Performance)
├── Colors: Metallic Blue, Silver, Cyan
├── Logo Style: Geometric speed
├── Scooters: FALCON-7 (aggressive), APEX-3 (entry)
└── Personality: High-tech, modern

VELOCE CLASSICS (Heritage/Vintage)
├── Colors: Fire Red, Cream, Gold
├── Logo Style: Elegant script
├── Scooters: VESPA-ICONIC (classic), SPRINT-HERITAGE (retro-modern)
└── Personality: Timeless, crafted

THRUST DYNAMICS (Street/Balanced)
├── Colors: Vibrant Orange, Black, White
├── Logo Style: Chevron arrows
├── Scooters: TURBO-GT (performance), URBAN-PRO (practical)
└── Personality: Bold, dynamic, fun
```

---

## 3D Modeling Guidelines

### Scooter Assembly Structure

```
ScooterBase
├── Chassis (welded metal, primary LOD)
├── Engine (visible when customized)
├── Wheels (rim attachment points)
├── Body_Front
│   ├── Headlight_Housing
│   ├── Windscreen
│   └── Front_Panel
├── Body_Mid
│   ├── Leg_Shield
│   ├── Side_Panels_L & R
│   └── Engine_Cover
├── Body_Rear
│   ├── Seat
│   ├── Tail_Panel
│   ├── Taillight_Housing
│   └── Rear_Panel
├── Mirrors_L & R (swappable)
├── Exhaust_System (swappable)
├── Suspension (swappable, LOD0 only)
└── Decal_Planes (transparency planes for decal system)
```

### Attachment Points (Standard Across All Models)

| Component | Attachment Method | Rotation Axis | Scale Range |
|-----------|-------------------|---------------|-------------|
| Rims | Wheel hub socket | Y-axis | 0.9 - 1.1 |
| Mirrors | Side-mount brackets | Custom | 0.8 - 1.2 |
| Exhaust | Engine flange + tail bracket | None (fixed) | - |
| Body Panels | Clip/bolt points | None (fixed) | - |
| Suspension | Lower mount points | None (visual height change) | - |
| Decals | Overlay planes | Z-axis (rotation) | 0.5 - 1.5 |
| Paint | Material override | N/A | - |

### Pivot Point Standards

- **Wheels**: Center of hub
- **Mirrors**: Bracket attachment point
- **Body Panels**: Panel edge midpoint
- **Decals**: Center of object
- **Suspension**: Lower attachment bracket
- **Engine**: Center of crankcase

---

## Material & Texture Standards

### Texture Resolution by Use Case

| Asset Type | Showcase | Gameplay | UI Thumbnail |
|------------|----------|----------|--------------|
| Scooter Body | 4K | 2K | 1K |
| Parts (large) | 4K | 2K | 1K |
| Parts (small) | 2K | 1K | 512 |
| Wheels | 4K | 2K | 1K |
| Decals | 2K | 1K | 512 |
| Environment | 2K | 1K | 512 |

### PBR Texture Map Requirements

All textures must include:

1. **Albedo/Diffuse (sRGB)**
   - Color only, no lighting
   - Gamma-corrected for game engine
   - Alpha channel: Opaque (1.0) for solid parts, alpha masks for decals

2. **Normal Map (Linear)**
   - OpenGL format (if needed: convert to DirectX)
   - 8-bit per channel minimum
   - Detail scale: 0.5-2.0 normalized

3. **Roughness (Linear)**
   - 0 (glossy mirror) to 1 (completely matte)
   - Chrome: 0.1-0.3
   - Polished metal: 0.2-0.4
   - Paint: 0.3-0.5
   - Matte surfaces: 0.7-1.0

4. **Metallic (Linear)**
   - 0 (non-metal) to 1 (pure metal)
   - Binary for most parts (either 0 or 1)
   - Gradient (0.3-0.7) for weathered/painted metal

5. **Ambient Occlusion (Linear)**
   - Baked crevice shadows
   - Multiply with albedo for visual enhancement
   - Range: 0.5-1.0 (full white = no occlusion)

6. **Detail Map (Optional, Linear)**
   - Micro-textures: scratches, dust, wear
   - Tiling: 4-16x base texture scale
   - Alpha: Controls blend strength (0-1)

### Material Finish Specifications

#### Chrome Finishes
- Albedo: Very light gray (180, 180, 185)
- Roughness: 0.1-0.2
- Metallic: 1.0
- Reflection: Mirror-like in showcase lighting

#### Painted Surfaces
- Albedo: Brand-specific colors per section
- Roughness: 0.3-0.5 (depends on finish type)
- Metallic: 0.1-0.3 (subtle clearcoat effect)
- Layers: Base color + detail overlay

#### Carbon Fiber Effect
- Albedo: Dark gray with weave pattern
- Normal: Directional weave texture
- Roughness: 0.4-0.6
- Metallic: 0.2-0.3 (subtle reflectivity)
- Detail: Fine scratch overlay

#### Weathered/Worn
- Albedo: Base color + dirt/rust overlay
- Roughness: Increases with wear (0.3 → 0.8)
- Metallic: Decreases with wear (1.0 → 0.3)
- Detail: Procedural corrosion/dirt patterns

---

## Decal System Specifications

### Decal Sheet Format

- **Resolution**: 2048x2048 (gameplay), 4096x4096 (showcase)
- **Format**: PNG with transparency (RGBA)
- **Color Space**: sRGB
- **Individual Decal Size**: 256x256 to 512x512 pixels
- **Margin**: 16 pixels between decals (bleed prevention)

### Decal Types & Placement

| Type | Placement | Size Range | Example |
|------|-----------|-----------|---------|
| Racing Stripes | Hood, Side, Tail | 512×128 to 512×512 | Center stripe, offset stripe |
| Numbers | Fender, Leg Shield | 256×256 | Race plate style |
| Geometric | Body Panels | 256×256 to 512×512 | Hexagon patterns, grids |
| Sponsor Logo | Leg Shield, Body | 256×256 | Brand names (fictional) |
| Artistic | Hood, Tail | 256×256 to 512×512 | Tribal, abstract, custom |
| Text | Visible Panels | 128×64 to 256×256 | Player name, custom text |

### Decal Application Workflow

1. **Create decal asset** as PNG with transparent background
2. **Apply to overlay planes** positioned on scooter surface
3. **Allow rotation** within ±45 degrees around Z-axis
4. **Allow scale** from 0.5x to 1.5x original size
5. **Blend mode**: Multiply or Overlay (depends on effect)
6. **Normal influence**: Optional subtle normal detail

---

## Animation & VFX Guidelines

### Engine Showcase Animation

When displaying customized scooters in the garage:

- **Rotation Speed**: 0.5 rotations per second
- **Bob Animation**: Gentle vertical bobbing (±2cm), 2 second cycle
- **Lighting Rotation**: Secondary light rotates (60° arc), 3 second cycle
- **Idle Vibration**: Subtle engine vibration (0.1cm amplitude, irregular)

### Part Highlight Effects

- **Glow**: Emissive bloom on newly equipped part
- **Pulse**: Opacity pulse (100% → 70% → 100%), 2 second cycle
- **Scale**: Gentle scale animation (1.0 → 1.02 → 1.0), 2 second cycle
- **Duration**: 3 cycles then fade to normal

### Particle Effects

#### Engine Showcase
- Exhaust smoke: Light wisps, realistic physics
- Turbo glow: Cyan/purple particles for TURBOVOLT engines
- Oil drip: Procedural drops from engine components

#### Damage State (Future)
- Scratch particles: Metallic shards on impact
- Spark effects: Engine component illumination
- Smoke puffs: Overheating indicators

### Wear & Weathering System

#### Procedural Dirt Application
- **Intensity Slider**: 0 (clean) to 1.0 (filthy)
- **Affected Maps**: Albedo (multiply), Roughness (increase)
- **Dirt Pattern**: Procedural based on surface normal and vertex position
- **High-wear Areas**: Wheel wells, undercarriage, exhaust outlet

#### Damage Visualization
- **Paint Scratches**: Normal map distortion, roughness increase
- **Rust**: Orange/brown overlay on metal, roughness increase
- **Dents**: Local normal perturbation
- **Fade**: Albedo desaturation over time

---

## Brand-Specific Design Language

### KRONOS MOTORS

**Design Principles:**
- Sharp angles, geometric forms
- High-tech aesthetic, visible tech components
- Symmetrical, futuristic silhouettes
- LED/digital style lighting elements

**Modeling Focus:**
- Angular body lines
- Integrated headlight design
- Visible suspension/tech elements
- Minimalist, clean surfaces
- Glossy finish surfaces

**Color Application:**
- Primary: Metallic Blue gradients
- Secondary: Silver accents, black trim
- Accents: Cyan glow on tech elements
- Effect: Chrome details, LED highlights

### VELOCE CLASSICS

**Design Principles:**
- Curved, organic forms
- Heritage, timeless design
- Symmetrical, elegant proportions
- Chrome and vintage details prominent

**Modeling Focus:**
- Smooth, flowing curves
- Round headlight and taillight
- Decorative mirror and hardware
- Ornate details, visible chrome
- Curved body panels

**Color Application:**
- Primary: Fire Red or deep cream
- Secondary: Gold accents, chrome details
- Accents: Leather brown trim (seat)
- Effect: Polished chrome, classic patina

### THRUST DYNAMICS

**Design Principles:**
- Bold, street-inspired forms
- Modern, accessible design
- Balanced curves and angles
- Prominent graphic styling

**Modeling Focus:**
- Mix of curves and sharp edges
- Angular headlight with modern housing
- Visible graphics/stripe attachment points
- Practical, functional design
- Modern material finishes

**Color Application:**
- Primary: Vibrant Orange or Black
- Secondary: White/gray accents
- Accents: Custom graphics, neon highlights
- Effect: Metallic finishes, graphic overlays

---

## Rendering Settings for Showcase

### Lighting Setup

**Three-Light Setup:**
1. **Key Light**: 45° angle, warm (3200K), 800 lumens, 0.8 intensity
2. **Fill Light**: Opposite side, cool (6000K), 400 lumens, 0.4 intensity
3. **Backlight**: Behind subject, bright (5600K), 600 lumens, 0.6 intensity

### Camera Setup

**Default Showcase Camera:**
- **Field of View**: 50° (50mm equivalent lens)
- **Distance**: 3.5 units from scooter
- **Height**: Scooter center + 0.3 units
- **Rotation**: Continuous slow orbit (0.5 rot/sec)

### Post-Process Effects

- **Bloom**: Intensity 0.8, threshold 0.7
- **Contrast**: +0.1
- **Saturation**: +0.15 (enhances brand colors)
- **Depth of Field**: Subtle, f/2.8 focus on scooter center
- **Vignette**: Subtle, 10% strength

---

## Optimization Guidelines

### LOD Strategy

| LOD Level | Usage | Poly Target | Texture Res | Draw Calls |
|-----------|-------|------------|-------------|-----------|
| LOD0 | Showcase/Close-up | 100k-150k | 4K | 15-20 |
| LOD1 | Garage/Preview | 30-50k | 2K | 8-10 |
| LOD2 | Mid-distance gameplay | 10-15k | 1K | 4-6 |
| LOD3 | Far distance/multi | 3-5k | 512 | 2-3 |

### Texture Atlas Packing

- **Atlas Size**: 2048x2048 (gameplay), 4096x4096 (showcase)
- **Padding**: 4 pixels between assets
- **Mipmap**: Generate full mipmap chains
- **Compression**: BC1/BC3 (DirectX) or equivalent

### Performance Budgets

- **Showcase/Customize**: 60 FPS target, single scooter
- **Gameplay**: 60 FPS target, multiple scooters + environment
- **UI**: 60 FPS constant
- **Memory**: Max 500MB loaded (including streaming)

---

## File Organization

```
Content/
├── Vehicles/
│   ├── KRONOS/
│   │   ├── FALCON-7/
│   │   │   ├── SM_FALCON7_Body_LOD0.uasset
│   │   │   ├── SM_FALCON7_Body_LOD1.uasset
│   │   │   └── M_FALCON7_Paint_Base.uasset
│   │   └── APEX-3/
│   ├── VELOCE/
│   └── THRUST/
├── Parts/
│   ├── Rims/
│   │   ├── SM_Rim_ClassicChrome_01.uasset
│   │   └── M_Rim_Chrome_Master.uasset
│   ├── Exhausts/
│   ├── BodyPanels/
│   ├── Mirrors/
│   ├── Decals/
│   └── Suspension/
├── Materials/
│   ├── M_Chrome_Master.uasset
│   ├── M_Paint_Base.uasset
│   ├── M_Decal_Overlay.uasset
│   └── M_CarbonFiber_Master.uasset
└── Textures/
    ├── Paint/
    ├── Metal/
    ├── Detail/
    └── Decals/
```

---

## Quality Checklist

### Per Model
- [ ] All LODs created and optimized
- [ ] Materials assigned and previewed in game
- [ ] Attachment points tested for parts
- [ ] Pivot points correctly positioned
- [ ] No Z-fighting or clipping issues
- [ ] Normal maps preview correctly
- [ ] Seams between panels invisible
- [ ] Performance targets met

### Per Part
- [ ] Clean topology with proper edge loops
- [ ] UV mapping optimized for texture atlases
- [ ] Attachment points verified to fit scooter
- [ ] Material blend modes tested
- [ ] Scale variations tested (0.8x to 1.2x)
- [ ] Rarity tiers visually distinct

### Per Texture Set
- [ ] All channels (Albedo, Normal, Roughness, Metallic, AO) present
- [ ] No visible seams or tiling artifacts
- [ ] Color accuracy verified in engine
- [ ] Specular highlights look natural
- [ ] No compression artifacts visible
- [ ] File sizes optimized per budget

---

## Common Issues & Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| Shiny parts look dull | Roughness too high | Adjust roughness map, target 0.2-0.3 for chrome |
| Metallic not reflecting | Metallic map all black | Ensure metallic is pure white (255,255,255) for metal |
| Seams visible | UV seams in texture | Add padding around UV seams, soften edges |
| Normal detail wrong direction | Inverted green channel | Re-export with correct normal map format |
| Parts clipping through body | Attachment points misaligned | Verify pivot points match mounting brackets |
| Texture too blurry | Mipmaps missing | Regenerate full mipmap chain in engine |
| LOD pops noticeable | Distance thresholds wrong | Test transitions at gameplay distances, adjust thresholds |

---

## Next Art Production Phases

### Phase 1: Concept & High-Poly
- Create high-poly sculpts for each scooter model
- Design rim, exhaust, and mirror variations
- Develop texture material library

### Phase 2: Low-Poly & Baking
- Retopologize high-poly models
- Create LOD variants
- Bake normal maps from high-poly
- Optimize for target poly counts

### Phase 3: Materials & Textures
- Create base material templates
- Paint PBR texture maps
- Build decal library
- Test in engine with real lighting

### Phase 4: Integration & Polish
- Test parts attachment system
- Validate customization UI visuals
- Optimize materials and shaders
- Performance pass on all assets

---

## Tools & Software Requirements

- **Modeling**: Blender, Maya, or 3DS Max
- **Texturing**: Substance Painter, Substance Designer
- **Normal Map Gen**: Marmoset Toolbag, Substance Designer
- **Engine**: Unreal Engine 5 with mobile optimization plugins
- **Version Control**: Git-LFS for large asset files

