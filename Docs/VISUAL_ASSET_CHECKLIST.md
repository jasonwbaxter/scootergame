# Moovers Racer - Visual Asset Implementation Checklist

This is a comprehensive checklist for all visual assets required to make the game fully playable. Items are organized by priority and component type.

---

## PHASE 1: CRITICAL PATH (Required for Game Launch)

### Scooter 3D Models - REQUIRED

#### KRONOS MOTORS
- [ ] **FALCON-7 (High-Performance)** - Main showcase vehicle
  - [ ] High-poly model (LOD0)
  - [ ] Game-ready model (LOD1)
  - [ ] Ultra-LOD model (LOD2)
  - [ ] Skeletal rig for customization
  - [ ] UV mapping optimized
  - [ ] 3 color variants (Midnight Blue, Titanium Gray, Pearl White)

- [ ] **APEX-3 (Entry/Beginner)**
  - [ ] High-poly model
  - [ ] Game-ready model
  - [ ] LOD1, LOD2
  - [ ] 3 color variants

#### VELOCE CLASSICS
- [ ] **VESPA-ICONIC (Heritage)**
  - [ ] High-poly model with iconic curves
  - [ ] Game-ready LOD
  - [ ] Round headlight/taillight details
  - [ ] Chrome detail modeling
  - [ ] 3 color variants

#### THRUST DYNAMICS
- [ ] **TURBO-GT (Street Performance)**
  - [ ] High-poly model with aggressive lines
  - [ ] Game-ready model
  - [ ] 3 color variants

**Subtotal**: 4 scooter models × 3 LODs × 3 colors = 36 model variants
**Time Estimate**: 6-8 weeks (requires experienced 3D artist)

---

### Customizable Parts - RIMS (Required for Garage)

#### KRONOS RIMS (5 tiers)
- [ ] **R1 "TechVortex"** (Common)
  - [ ] 3D model (5-spoke)
  - [ ] PBR Material (Metallic: 0.0, Roughness: 0.8)
  - [ ] 2 color options
  - [ ] Thumbnail image
  - [ ] Preview model at 2K texture

- [ ] **R2 "CyberFlow"** (Uncommon)
  - [ ] 3D model (7-spoke with curves)
  - [ ] PBR Material (Metallic: 0.4, Roughness: 0.5)
  - [ ] LED channel visualization
  - [ ] 3 color options
  - [ ] Emissive layer for LED effect

- [ ] **R3 "DeltaRace"** (Rare)
  - [ ] 3D model (9-spoke complex pattern)
  - [ ] Chrome PBR (Metallic: 0.8, Roughness: 0.2)
  - [ ] Black racing stripe decal layer
  - [ ] Floating center cap effect
  - [ ] 3 color options

- [ ] **R4 "NeoSync"** (Epic)
  - [ ] 3D model (11-spoke radial pattern)
  - [ ] Dual-tone material system
  - [ ] Pearlescent blue shift shader
  - [ ] Glow effect layer
  - [ ] 4 color options

- [ ] **R5 "HorizonLux"** (Legendary)
  - [ ] 3D model (13-spoke intricate design)
  - [ ] Holographic material system
  - [ ] Rainbow color-shift shader
  - [ ] Animated center cap rig
  - [ ] Emissive glow system
  - [ ] 2 color options

**Subtotal**: 5 rim models × variants = ~15 unique meshes
**Materials**: 5 master materials + color variants
**Time Estimate**: 2-3 weeks

---

### Materials & Shaders - PHASE 1

**Master Material Library:**
- [ ] `M_Base_Matte` - Foundation for common parts
- [ ] `M_Base_Gloss` - Glossy finishes
- [ ] `M_Base_Metallic` - Metallic finishes
- [ ] `M_Base_Pearlescent` - Pearl color-shift
- [ ] `M_Base_Holographic` - Holographic rainbow effect
- [ ] `M_Base_Neon` - Neon glow/emissive

**Paint Finish Instances:**
- [ ] `MI_Paint_MatteBlack`
- [ ] `MI_Paint_GlossMidnightBlue`
- [ ] `MI_Paint_MetallicTitanium`
- [ ] `MI_Paint_PearlBlueShift`
- [ ] `MI_Paint_NeonCyan`
- [ ] `MI_Paint_HolographicRainbow`

**Master Textures Required:**
- [ ] Metallic flakes texture (2K)
- [ ] Chrome reflection map (2K)
- [ ] Weathered paint overlay (2K)
- [ ] Carbon fiber weave (2K)
- [ ] Holographic rainbow (2K)
- [ ] Neon glow map (2K)

**Time Estimate**: 1-2 weeks

---

### UI & Menu Assets - PHASE 1

#### Main Menu
- [ ] Workshop background image (1920x1080, JPEG)
- [ ] Garage ambient screenshot
- [ ] Brand logo marks:
  - [ ] KRONOS MOTORS logo (PNG, transparent)
  - [ ] VELOCE CLASSICS logo
  - [ ] THRUST DYNAMICS logo
- [ ] Menu button textures
- [ ] Start button overlay graphics

#### Garage Screen
- [ ] Part display shelf background
- [ ] Rarity indicator icons (5 tiers: common→legendary)
- [ ] Brand badges (3 versions)
- [ ] Stat comparison UI elements
- [ ] Color rarity legend graphic

#### HUD (In-Race)
- [ ] Speed gauge graphic
- [ ] Multiplier counter display
- [ ] Health heart icons (4 states: full, 75%, 50%, empty)
- [ ] Lap counter background
- [ ] Boost indicator bar
- [ ] Minimap frame

#### Arcade HUD
- [ ] Score multiplier text background
- [ ] Lane change indicator arrows
- [ ] Power-up icons:
  - [ ] Speed boost icon
  - [ ] Invincibility skull icon
- [ ] Health hearts (smaller version)
- [ ] Game Over overlay

**Time Estimate**: 1 week

---

### Track Environment - Urban Race

- [ ] **Road Surface**
  - [ ] Asphalt base texture (4K)
  - [ ] Lane divider markings (separate material)
  - [ ] Tire marks overlay (procedural or painted)
  - [ ] Weathering/dirt pattern (2K)

- [ ] **Trackside Props** (Minimal set for vertical slice)
  - [ ] Street lamp model + material
  - [ ] Guardrail section model
  - [ ] Building facades (2-3 variations, simple blocks)
  - [ ] Tree models (simplified for performance)

- [ ] **Sky**
  - [ ] Day sky cube map (Substance/AI generated)
  - [ ] Evening sky cube map
  - [ ] Night sky cube map
  - [ ] HDR environment maps for reflections (3 sets)

**Time Estimate**: 2-3 weeks

---

### Arcade Mode Background

- [ ] **Parallax Background Layers** (3 layers minimum)
  - [ ] Layer 1 (Distant): City buildings scrolling slow
    - [ ] Illustration/vector art (3840x2160)
    - [ ] Material with slow scroll offset
  - [ ] Layer 2 (Mid-ground): Street elements
    - [ ] Illustration (3840x2160)
    - [ ] Medium scroll speed material
  - [ ] Layer 3 (Foreground): Road detail
    - [ ] High-detail road pattern (4K)
    - [ ] Fast scroll material

- [ ] **Arcade Road Track**
  - [ ] 4 lane markers with neon glow
  - [ ] Repeating road pattern texture
  - [ ] Lane guide material with slight transparency

- [ ] **VFX Elements**
  - [ ] Particle system for speed trails
  - [ ] Particle system for collision explosions
  - [ ] Boost glow/bloom effect
  - [ ] Score popup text material

**Time Estimate**: 1-2 weeks

---

## PHASE 2: EXPANSION (Content Variety)

### Additional Scooter Models

- [ ] **VELOCE SPRINT-HERITAGE** (Retro-Modern)
  - [ ] Full model + LODs
  - [ ] 3 color variants
  - [ ] Chrome details modeling

- [ ] **THRUST URBAN-PRO** (Practical)
  - [ ] Full model + LODs
  - [ ] 3 color variants

**Time Estimate**: 3-4 weeks

---

### Additional Parts - Exhausts

#### KRONOS EXHAUSTS (5 tiers)
- [ ] **E1 "StockFlow"** (Common)
  - [ ] Simple cylinder model
  - [ ] Steel material
  - [ ] 2 color options

- [ ] **E2 "PerformanceX"** (Uncommon)
  - [ ] Dual pipe model
  - [ ] Polished + carbon trim material
  - [ ] 3 color options

- [ ] **E3 "TurboGate"** (Rare)
  - [ ] Turbo assembly model
  - [ ] Complex material system
  - [ ] Visible turbine (animated rig)
  - [ ] 3 color options

- [ ] **E4 "NeonJet"** (Epic)
  - [ ] Triple-pipe artistic model
  - [ ] Neon glow system
  - [ ] Emissive material
  - [ ] 3 neon color options

- [ ] **E5 "VortexSingular"** (Legendary)
  - [ ] Complex vortex chamber geometry
  - [ ] Holographic material
  - [ ] Animated vortex effect rig
  - [ ] 2 holographic colors

**Time Estimate**: 3 weeks

---

### Body Panels

#### KRONOS BODY PANELS (4 tiers)
- [ ] **BP1 "AeroTrim"** (Uncommon)
- [ ] **BP2 "CyberShell"** (Rare)
- [ ] **BP3 "QuantumEdge"** (Epic)
- [ ] **BP4 "SingularityWrap"** (Legendary)

**Time Estimate**: 4-5 weeks

---

### Mirrors & Additional Parts

- [ ] **Mirror Models** (3 tiers: Common, Rare, Legendary)
- [ ] **Engine Display Models** (5 tiers)
  - For garage showroom display
  - Showcase engine complexity
- [ ] **Suspension Models** (3 tiers)

**Time Estimate**: 2-3 weeks

---

### Additional Paint Finishes

- [ ] **Metallics** (5 variants) - Substance Designer
- [ ] **Pearlescents** (4 variants) - Shader-based
- [ ] **Holographics** (3 variants) - Advanced shaders
- [ ] **Neons** (5 variants) - Emissive shaders
- [ ] **Custom Patterns** (optional, procedural)

**Time Estimate**: 1 week (shader-heavy, content-light)

---

### Decals & Graphics

#### Racing Decals (KRONOS)
- [ ] Center racing stripe decal texture (2K)
- [ ] Offset stripe pattern (2K)
- [ ] Number plate template (2K)
- [ ] Logo repeat pattern (2K)

#### Geometric Decals (KRONOS)
- [ ] Hexagon mesh pattern (2K)
- [ ] Grid pattern (2K)
- [ ] Wave pattern (2K)
- [ ] Angular accents (2K)

#### Artistic Decals (Rare+)
- [ ] Digital vortex pattern (2K)
- [ ] Cyber glyph symbols (2K)
- [ ] Neon pulse pattern (2K)
- [ ] Tech abstract design (2K)

**Time Estimate**: 1-2 weeks

---

### Additional Environments

- [ ] **Track 2: Mountain/Scenic Route**
  - Sky, terrain, props, lighting setup
  
- [ ] **Track 3: City Night Racing**
  - Night lighting, neon signs, urban details

- [ ] **Garage Workshop Enhanced**
  - Tool racks, workbenches, storage
  - Lighting rigs for customization preview

**Time Estimate**: 3-4 weeks

---

## PHASE 3: POLISH & OPTIMIZATION

### VFX & Particle Systems
- [ ] Turbo boost particle trail
- [ ] Engine bloom glow
- [ ] Exhaust smoke
- [ ] Collision spark effects
- [ ] Speed trail (arcade)
- [ ] Power-up pickup effects
- [ ] Obstacle collision explosions
- [ ] Multiplier increase indicators
- [ ] Drift smoke

**Time Estimate**: 1-2 weeks

---

### Animations
- [ ] Scooter suspension bounce (LOD0 detail)
- [ ] Exhaust turbo spin animation (turbo models)
- [ ] Rim rotation animation (when moving)
- [ ] Mirror rotation during turning
- [ ] Headlight flicker (damage state)
- [ ] Engine startup animation (garage)

**Time Estimate**: 1 week

---

### UI Polish
- [ ] Button hover/pressed states
- [ ] Loading screen artwork
- [ ] Transition screen backgrounds
- [ ] Achievement badges
- [ ] Rarity tier visual progression
- [ ] Seasonal content banners

**Time Estimate**: 1 week

---

## ASSET SPECIFICATIONS SUMMARY

### Total Models Needed
- **Scooter Models**: 6 base models
- **Rim Models**: 5 unique designs
- **Exhaust Models**: 5 unique designs
- **Body Panel Kits**: 12 models (3 per brand × 4 tiers)
- **Mirror Models**: 3 designs
- **Engine Models**: 5 showcase designs
- **Suspension Models**: 3 designs
- **Environmental**: ~20 props (trees, signs, buildings)
- **UI Elements**: ~50 icons/graphics

**Total**: ~100+ model assets

### Textures Required
- **PBR Maps**: All models need BaseColor, Normal, Roughness, Metallic, AO
- **Resolutions**: 4K (hero), 2K (standard), 1K (background)
- **Special Maps**: Emissive (for neon/epic), Holographic overlays

**Total**: ~300+ texture files

### Materials & Shaders
- **Master Materials**: 10-15 core material systems
- **Material Instances**: 50+ variations for customization
- **Custom Shaders**: 5-7 (holographic, neon, pearlescent, etc.)

---

## RESOURCE REQUIREMENTS

### Team Composition (Recommended)
- **3D Modelers**: 2-3 people (scooters, parts, props)
- **Texture Artists**: 1-2 people (PBR texturing, substance designer)
- **VFX Artist**: 1 person (particles, shader effects)
- **UI Artist**: 1 person (icons, menu design)
- **Art Director**: 1 person (consistency, brand identity)

**Total**: 6-8 artists for 8-12 week timeline

### Software
- **Blender**: FREE (modeling, texturing, animation)
- **Substance Designer**: $20/month (procedural materials)
- **Substance Painter**: $20/month (PBR texturing)
- **Unreal Engine 5**: FREE (game engine, Material Editor)
- **Figma/Adobe XD**: For UI design
- **Procreate/Photoshop**: For concept art

### Hardware
- Recommended: High-end workstation (RTX 3090+, 32GB+ RAM)
- For team: Network storage for asset management

---

## GENERATION TOOL RECOMMENDATIONS

### For Scooter Modeling
- **Blender**: Primary modeling tool
  - Follow Vespa reference models (low-poly first approach)
  - Use modifiers for symmetry and bevels
  - Export FBX with skeleton rig

### For Part Generation
- **Substance Designer**: Wheels, metallic parts (75% faster)
  - Create parametric designs
  - Generate multiple variants from single graph
  - Export 2K maps per variant

### For Texturing
- **Substance Painter**: Direct-to-mesh painting
  - Drag-and-drop smart materials
  - Procedural wear/weathering
  - Export UE5-ready materials

### For Environments
- **World Creator** or **Substance World**: Procedural environment generation
- **Skybox AI**: Generate custom sky HDRs

### For UI/Concepts
- **Midjourney/Stable Diffusion**: Reference generation
  - Prompt: "Cyberpunk scooter, aggressive racing style, neon accents"
  - Generate concept variations for art direction

---

## ESTIMATED PRODUCTION TIMELINE

| Phase | Duration | Key Deliverables |
|-------|----------|------------------|
| Phase 1 (Critical) | 6-8 weeks | 1 scooter, 5 rims, materials, UI, arcade bg |
| Phase 2 (Expansion) | 6-8 weeks | 5 more scooters, exhausts, bodies, environments |
| Phase 3 (Polish) | 2-3 weeks | VFX, animations, UI polish, optimization |
| **Total** | **14-19 weeks** | **Full visual package** |

---

## NEXT STEPS

1. **Immediate**: Set up Blender project file with brand color palette and reference assets
2. **Week 1**: Complete KRONOS FALCON-7 scooter model
3. **Week 2-3**: Generate rim and exhaust variations using Substance
4. **Week 4**: Create core materials and shader systems
5. **Week 5-6**: Build track environment and arcade background
6. **Week 7+**: Expand with additional vehicles and parts

---

**Status**: ⏳ Awaiting artist team assignment
**Last Updated**: 2026-06-12
