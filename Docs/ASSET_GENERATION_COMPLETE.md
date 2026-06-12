# Moovers Racer - Complete Asset Generation Specifications

This document provides comprehensive specifications for all visual assets required for the game, with guidance for generation using Blender, Substance Designer, AI tools, and manual creation.

---

## PART 1: SCOOTER MODELS & BODY GEOMETRY

### KRONOS MOTORS Fleet

#### 1.1 FALCON-7 (High-Performance)
**Visual Specifications:**
- Frame: Mid-sized, sporty proportions
- Body Lines: Sharp, aggressive, angular bodywork
- Silhouette: Aerodynamic, sleek profile
- Distinctive Features:
  - Sharp front end with integrated LED headlights
  - Aerodynamic body panels with air vents
  - Futuristic digital dashboard visible through windscreen
  - Sleek curved mirrors
  - Sport suspension with visible dampers
- Color Options: Midnight Blue (#1a4d7a), Titanium Gray (#757575), Pearl White (#f5f5f5)

**Generation Method:**
- Blender 3D Modeling: Create geometric base model using CAD-style workflow
- Reference: Modern racing scooters (Vespa Primavera Sport styling with aggressive modifications)
- Modeling Time Estimate: 40-60 hours for detailed high-poly, 10-15 hours for game-ready LOD
- File Format: FBX with skeleton rig for customization

**Customization Points:**
- Body panels (front, side, rear can be replaced)
- Rims (standard 15mm hub)
- Exhaust system mounting
- Mirror slots
- Paint/decal zones (3 zones: hood, side panels, rear)
- Engine bay visible area
- Suspension dampers

---

#### 1.2 APEX-3 (Entry/Beginner)
**Visual Specifications:**
- Frame: Compact, lightweight profile
- Body Lines: Rounded edges, approachable, modern design
- Silhouette: Simplified, safe, child-friendly
- Distinctive Features:
  - Round circular headlight
  - Minimal graphics, clean surfaces
  - Soft curves, no sharp edges
  - Beginner-friendly customization points
- Color Options: Signal Blue (#0066FF), Polar White (#FFFFFF), Sunset Orange (#FF7F00)

**Generation Method:**
- Blender Modeling: Simplified geometry, smooth curves
- Modeling Time: 20-30 hours detailed, 5-8 hours game-ready
- Style: Modern/minimalist, similar to Vespa Primavera basic model

---

### VELOCE CLASSICS Fleet

#### 2.1 VESPA-ICONIC (Heritage/Vintage)
**Visual Specifications:**
- Frame: Classic proportions, iconic rounded silhouette
- Body Lines: Curved, ornate, timeless design
- Silhouette: Instantly recognizable vintage profile
- Distinctive Features:
  - Round headlight and taillight
  - Leg shield with classic curves
  - Whitewall tires (optional customization)
  - Ornate mirror design
  - Vintage-style dashboard
  - Chrome accents, polished details
- Color Options: Fire Red (#D41F1F), Cream (#F5DEB3), British Racing Green (#004225)

**Generation Method:**
- Blender Modeling: Reference authentic Vespa 1960s designs
- Modeling Time: 50-70 hours detailed, 15-20 hours game-ready
- Materials: Aged/weathered paint, polished chrome, leather seat accents
- Challenge: Accurate silhouette matching - prioritize iconic curves

---

#### 2.2 SPRINT-HERITAGE (Retro-Modern)
**Visual Specifications:**
- Frame: Medium frame with vintage silhouette
- Body Lines: Mix of curves and angular lines
- Silhouette: Retro with modern updates
- Distinctive Features:
  - Square/rectangular headlight with modern LED ring
  - Mixed curves and angles
  - Visible chrome engine elements
  - Classic proportions with updated materials
- Color Options: Rust Orange (#B7410E), Matte Black (#1A1A1A), Cream White (#FFFDD0)

---

### THRUST DYNAMICS Fleet

#### 3.1 TURBO-GT (Performance/Street)
**Visual Specifications:**
- Frame: Mid-sized, muscular proportions
- Body Lines: Bold, aggressive, sharp angles
- Silhouette: High-visibility, street-culture aesthetic
- Distinctive Features:
  - Angular, sharp lines throughout
  - Prominent side graphics/stripe areas
  - High-visibility paint zones
  - Chunky, aggressive stance
  - Customizable graphics package
- Color Options: Neon Orange (#FF8C00), Deep Black (#0A0A0A), Electric Purple (#8B00FF)

---

#### 3.2 URBAN-PRO (Practical/Daily)
**Visual Specifications:**
- Frame: Compact but functional
- Body Lines: Balance of style and practicality
- Silhouette: Modern, approachable
- Distinctive Features:
  - Practical storage integration
  - Versatile design language
  - Clear visibility of mechanical elements
  - Good customization mounting points
- Color Options: Charcoal Gray (#36454F), Navy Blue (#000080), Forest Green (#228B22)

---

## PART 2: CUSTOMIZABLE PARTS

### RIMS / WHEELS

#### Common Tier - KRONOS R1 "TechVortex"
**Specifications:**
- Design: 5-spoke angular geometry
- Material: Matte black aluminum
- Diameter: 15" equivalent
- Finish: Flat matte, no shine
- Metallic Value: 0.0 (Substance Designer parameter)
- Roughness Value: 0.8 (Substance Designer parameter)

**Generation:**
- Substance Designer: Create 5-spoke parametric geometry
- Texture: Procedural matte aluminum with light weathering
- Export: 2K texture maps (BaseColor, Normal, Roughness, Metallic, AO)

---

#### Uncommon Tier - KRONOS R2 "CyberFlow"
**Specifications:**
- Design: 7-spoke organic curves
- Material: Polished aluminum with blue tint
- Diameter: 16" equivalent
- Finish: Semi-gloss with blue accent lighting effect
- Features: LED channel rendering

**Generation:**
- Blender Model: Organic 7-spoke design
- Substance Designer: Polished aluminum with iridescent blue layer
- Special: Emissive layer for LED effect visualization
- Export: 2K maps + emissive texture

---

#### Rare Tier - KRONOS R3 "DeltaRace"
**Specifications:**
- Design: 9-spoke interlocking delta pattern
- Material: Polished chrome with black accent
- Diameter: 17" equivalent
- Finish: Mirror shine with black racing stripes
- Features: Floating center cap appearance

**Generation:**
- Blender: Complex 9-spoke geometry with intersecting patterns
- Substance: Chrome material (high metallic 0.9, low roughness 0.1)
- Black accent stripes as decal layer
- Center cap: Separate model with floating effect

---

#### Epic Tier - KRONOS R4 "NeoSync"
**Specifications:**
- Design: 11-spoke radial gradient pattern
- Material: Dual-tone chrome + matte black
- Diameter: 18" equivalent
- Finish: Pearlescent blue shift visible from multiple angles
- Features: Subtle glow in dim lighting, holographic sheen

**Generation:**
- Blender: Radial gradient 11-spoke design
- Substance: Pearlescent paint layer over chrome
- Emissive layer: Subtle glow effect
- Animation-ready rig for motorized cap effect
- Texture: 2K base + 2K pearlescent layer

---

#### Legendary Tier - KRONOS R5 "HorizonLux"
**Specifications:**
- Design: 13-spoke holographic pattern (intricate multi-segmented)
- Material: Holographic chrome
- Diameter: 18" equivalent
- Finish: Full rainbow color-shifting reflections
- Features: High-tech glow, illuminated center cap with animation

**Generation:**
- Blender: Complex 13-spoke multi-segment design
- Substance: Holographic chrome shader
  - Base: Mirror chrome (metallic 0.95, roughness 0.05)
  - Layer: Rainbow holographic overlay with color-shifting
  - Emissive: Glow effect that responds to lighting
- Animation: Rotating center cap (FBX skeletal animation, 4 RPM)
- Advanced: Consider real-time holographic shader in UE5 material

---

### EXHAUST SYSTEMS

#### Common Tier - KRONOS E1 "StockFlow"
**Specifications:**
- Design: Simple cylindrical pipe
- Material: Raw metal, slight weathering
- Diameter: 45mm single pipe
- Finish: Matte gray metal
- Length: ~150mm visible

**Generation:**
- Blender: Simple cylinder with age wear textures
- Substance: Raw steel material with rust spots
- Colors: Steel Gray, Matte Black
- Mounting bracket: Simple L-bracket metal

---

#### Uncommon Tier - KRONOS E2 "PerformanceX"
**Specifications:**
- Design: Dual pipes with flared tips
- Material: Polished stainless steel + carbon trim
- Diameter: Dual 50mm pipes
- Finish: Polished metal, black trim ring
- Heat shield: Carbon fiber appearance band

**Generation:**
- Blender: Dual parallel cylinder pipes with flared ends
- Substance: Polished steel (metallic 0.8, roughness 0.2)
- Carbon fiber band: 2K weave texture
- Mounting: Dual bracket system

---

#### Rare Tier - KRONOS E3 "TurboGate"
**Specifications:**
- Design: Turbo-mounted system with visible turbine housing
- Material: Chrome, black heat wrap
- Diameter: 55mm primary + turbo manifold
- Special: Visible turbo shroud, colored intake manifold
- Colors: Chrome with Blue, Chrome with Cyan, Chrome with Black accents

**Generation:**
- Blender: Complex turbocharger assembly
  - Turbo turbine housing (spinning turbine mesh visible)
  - Exhaust manifold routing
  - Heat wrap coils
- Substance: Chrome with colored accent overlay
- Turbo turbine: Separate animated element (FBX rig, 8000 RPM theoretical spin)
- Challenge: Balance detail vs. performance

---

#### Epic Tier - KRONOS E4 "NeonJet"
**Specifications:**
- Design: Tri-pipe futuristic system with neon channel
- Material: High-gloss chrome + neon tube mounting
- Diameter: Triple 48mm pipes in artistic arrangement
- Special: Neon glow channel, emissive effect
- Colors: Neon Cyan Glow, Neon Purple Glow, Neon Pink Glow

**Generation:**
- Blender: Three artistic pipes with LED mounting channel
- Neon tube: Separate mesh with emissive material
- Substance: Triple-layer material
  - Base chrome layer
  - Neon glow channel with color variation
  - Emissive override for glow effect
- Animation: Optional subtle pulsing glow effect

---

#### Legendary Tier - KRONOS E5 "VortexSingular"
**Specifications:**
- Design: Multi-phase vortex chamber system
- Material: Multi-chrome with holographic accents
- Diameter: 52mm flowing channels in spiral geometry
- Special: Animated vortex effect, holographic shimmer
- Colors: Holographic Vortex, Holographic Cyan

**Generation:**
- Blender: Complex spiral/vortex geometry
  - Flowing exhaust paths
  - Vortex chamber interior (visible detail)
  - Holographic accent panels
- Substance: Holographic material system
  - Base: Chrome (metallic 0.95, roughness 0.05)
  - Overlay: Rainbow holographic with color-shift
  - Emissive: Sci-fi glow effect
- Animation: Optional subtle vortex spin effect in engine bay

---

### BODY PANELS

#### Common Tier - Standard Panels
**Specifications:**
- Material: High-gloss molded plastic composite
- Finish: Smooth, aerodynamic surfaces
- Model-specific colors (Midnight Blue for FALCON-7, etc.)
- No custom geometry - factory default

---

#### Uncommon Tier - KRONOS BP1 "AeroTrim"
**Specifications:**
- Parts: Front cowling accents, side vents
- Material: Brushed aluminum inserts
- Paint: Matte black base with metallic silver accents
- Special: Integrated air vent graphics

**Generation:**
- Blender: Accent pieces that overlay scooter body
  - Front splitter section
  - Side vent inserts (2x)
- Substance: Brushed aluminum + matte black
- Mounting: 3-4 connection points to body

---

#### Rare Tier - KRONOS BP2 "CyberShell"
**Specifications:**
- Parts: Full custom front panel, redesigned leg shield, rear section
- Material: Carbon fiber composite (visual)
- Paint: Carbon weave pattern visible
- Special: RGB accent lighting grooves
- Impact: Complete aesthetic transformation

**Generation:**
- Blender: 3 major body replacement pieces
  - Front panel replacement
  - Leg shield redesign
  - Rear section replacement
- Substance: Carbon fiber weave texture (2K)
  - BaseColor: Black with subtle weave
  - Normal: Carbon fiber bumps
  - Roughness: Carbon texture variation
- RGB Grooves: Separate emissive channel for lighting effect

---

#### Epic Tier - KRONOS BP3 "QuantumEdge"
**Specifications:**
- Parts: Complete body kit overhaul (all exterior panels)
- Material: Exotic composite with pearlescent finish
- Paint: Multi-layer pearlescent blue with silver geometric patterns
- Special: Illuminated panel edges, holographic accent patterns
- Impact: Premium, high-tech, statement-making

**Generation:**
- Blender: Complete body replacement model
- Substance: Multi-layer pearlescent system
  - Base: Deep blue
  - Pearlescent layer: Blue-purple-silver shift
  - Geometric pattern overlay: Silver metallic accents
- Emissive: Panel edge lighting system

---

#### Legendary Tier - KRONOS BP4 "SingularityWrap"
**Specifications:**
- Parts: Complete body transformation
- Material: Fictional exotic alloy (visual)
- Paint: Holographic full-body wrap with animated patterns
- Special: Holographic shimmer across all panels
- Impact: Unmistakable, exclusive, transformative

**Generation:**
- Blender: Artistic full-body redesign
- Substance: Holographic wrapper system
  - Base: Dark blue-black
  - Holographic overlay: Rainbow color-shift
  - Pattern layer: Animated-ready geometric patterns
  - Emissive: Full holographic glow
- Advanced: Consider if animated holographic effects needed

---

### PAINT FINISHES

#### Solid Colors
**Matte Finishes:**
- Matte Black: PBR values Metallic: 0.0, Roughness: 0.85
- Matte Gun Metal: Gray-toned matte
- Matte Charcoal: Deep matte

**Gloss Finishes:**
- Gloss Midnight Blue: Reflective, metallic 0.6, roughness 0.2
- Gloss Silver: Bright, shiny, metallic 0.7, roughness 0.15
- Gloss Black: Jet black with shine, metallic 0.6, roughness 0.25

#### Metallic Finishes
- Titanium Silver: Subtle shimmer
- Metallic Blue: Brand signature
- Metallic Charcoal: Depth effect

#### Pearlescent Finishes
- Pearl Blue Shift: Blue to purple shift
- Pearl Silver Shift: White to gray shift
- Pearl Gray Shift: Subtle gray depth

#### Holographic Finishes
- Holographic Rainbow: Full spectrum shift
- Holographic Cyan: Blue-green shift
- Holographic Purple: Purple-pink-blue shift

#### Neon Finishes
- Neon Cyan: High saturation, glow effect
- Neon Purple: Vibrant magenta-purple
- Neon Pink: Hot pink with glow

**Generation Method:**
- Substance Designer: Create master material for each finish type
- Parametric color variation: Allow color picker input
- Metallic/Roughness: Adjust per finish type
- Emissive: For neon/holographic variants
- Export as UE5 material instances with parameters

---

## PART 3: BACKGROUND & ENVIRONMENT SCENES

### Urban Racing Track Scene
**Components:**
1. **Road Surface**
   - Asphalt texture: weathered, with tire marks
   - Markings: Lane dividers, racing lines
   - 4K texture dimensions

2. **Trackside Environment**
   - Street buildings: 2-3 varied architectural styles
   - Shops: Customizable storefront designs
   - Audience barriers, signage
   - Trees, street lights, urban props

3. **Sky & Lighting**
   - Dynamic sky box (day/night/sunset variants)
   - HDR environment maps for realistic reflections
   - Stadium/track lighting

**Generation:**
- Blender: Environment modeling
- Substance Painter: Weathering and material details
- Textures: 4K for hero assets, 2K for secondary
- Sky: Substance / AI generation tools (Skybox AI)

---

### Garage/Workshop Scene
**Components:**
1. **Workshop Interior**
   - Concrete floor with oil stains, wear patterns
   - Metal workbenches, tool racks
   - Shelving units with spare parts
   - Fluorescent lighting rigs

2. **Ambient Elements**
   - Posters/brand signage on walls
   - Tools hanging on pegboards
   - Work lights, inspection rig
   - Customization preview platform

**Generation:**
- Blender: Modular workshop pieces
- Substance: Weathered metals, concrete
- Lighting: Key for mood (industrial aesthetic)

---

### Arcade Mode Background
**Components:**
1. **Stylized Road/Track**
   - Lane markers with neon glow
   - Repeating road pattern (fast-moving effect)
   - Retro arcade aesthetic
   - Bold color lanes

2. **Parallax Scrolling Elements**
   - Distant buildings/scenery scrolling slower
   - Mid-ground elements
   - Foreground road
   - 3 parallax layers minimum

3. **Visual Effects Layer**
   - Speed trails
   - Boost particle effects
   - Collision explosions
   - Score text effects

**Generation:**
- Illustrator/Procreate: Vector art for clean arcade style
- Substance: Fast-moving texture generation
- Particle systems: UE5 Niagara

---

## PART 4: UI ASSETS & HUD ELEMENTS

### Main Menu Assets
- Logo: KRONOS, VELOCE, THRUST brand logos (3 versions)
- Background: Garage workshop ambience
- Menu buttons: Metallic, sleek design
- Brand selection screen backgrounds

### Garage UI
- Part display shelves (3D visualization)
- Stat comparison charts
- Part rarity indicators (color-coded)
- Brand badges and logos

### HUD (In-Race)
- Speed indicator: Digital gauge
- Multiplier display: Score tracker
- Health/damage indicators: Visual feedback
- Minimap: Track overview
- Lap counter: Race progress

### Arcade HUD
- Lane indicators: Visual guides
- Score multiplier: Large readable text
- Health hearts: Simple icon system
- Power-up indicators: Visual previews

**Generation:**
- Figma/Adobe XD: UI layout design
- Substance/Photoshop: Icon creation
- Illustrator: Vector graphics
- UE5 Slate/UMG: Implementation

---

## PART 5: VEHICLE DETAIL PARTS

### Mirrors

#### Common Tier - KRONOS M1 "ClassicTech"
- Simple rectangular, matte black plastic
- Mounting: Circular base
- Material: Matte (metallic 0.0, roughness 0.8)

#### Legendary Tier - KRONOS M3 "SingularMirror"
- Asymmetrical teardrop shape
- Holographic chrome backing
- Animated rotation effect
- Material: Holographic (full color-shift)

---

### Engines (Visual Component - Garage Display)
- Showcase models showing engine complexity
- Visible turbo housings, manifolds
- Color variations per tier
- Animation: Optional spin/startup effect

---

## PART 6: ASSET GENERATION PIPELINE

### Recommended Tools & Workflow

#### 3D Modeling
- **Blender**: FREE, open-source, full modeling/texturing
  - Learning curve: Medium
  - Community: Excellent
  - Tutorials: Abundant YouTube resources
  - Scooter modeling guide: 40-100 hours per detailed vehicle

- **Substance Designer**: Parametric 3D generation
  - Cost: $20/month subscription
  - Ideal for: Procedural parts, wheels, technical elements
  - Scooter wheels: Can generate 80% of variety parametrically

#### Texturing & Materials
- **Substance Painter**: Direct-to-mesh texturing
  - Cost: $20/month
  - Workflow: Paint on 3D model directly
  - Output: PBR materials for UE5

- **Substance Alchemist**: Convert images to PBR
  - Useful for: Asphalt, weathering effects

#### AI Image Generation
- **Midjourney / Stable Diffusion**: Concept art & reference
  - Prompts for scooter concept: "Modern Italian scooter, aggressive racing, Vespa-inspired, cyberpunk aesthetic, photorealistic"
  - Use for: Concept refinement, color palette testing

- **AI Image to 3D**: Convert renders to models
  - Experimental but improving rapidly

#### Procedural Generation
- **SpeedTree**: Plant/vegetation assets
- **World Creator**: Landscape/terrain generation

### Recommended Workflow
1. **Concept Phase** (AI/Figma)
   - Generate reference images with Midjourney
   - Create mood boards
   - Lock down color palettes

2. **Modeling Phase** (Blender)
   - Build base geometry
   - Create LOD versions (high-poly → game-ready)
   - 2-4 weeks for full vehicle fleet

3. **Texturing Phase** (Substance Painter)
   - Apply PBR textures
   - Weather/age assets
   - Create material variations
   - 1-2 weeks

4. **Implementation Phase** (UE5)
   - Import FBX + materials
   - Set up customization system
   - Test visual quality
   - Performance optimization

5. **Polish Phase**
   - VFX (particles, glows)
   - Animation (turbo spin, animations)
   - Optimization pass

---

## PART 7: ASSET FOLDER STRUCTURE (Content/)

```
Content/
├── Vehicles/
│   ├── KRONOS/
│   │   ├── FALCON-7/
│   │   │   ├── Meshes/
│   │   │   │   ├── FALCON7_Body_LOD0
│   │   │   │   ├── FALCON7_Body_LOD1
│   │   │   │   └── FALCON7_Skeleton
│   │   │   └── Materials/
│   │   │       ├── MI_FALCON7_Blue
│   │   │       ├── MI_FALCON7_Gray
│   │   │       └── MI_FALCON7_White
│   │   └── APEX-3/
│   ├── VELOCE/
│   │   ├── VESPA-ICONIC/
│   │   └── SPRINT-HERITAGE/
│   └── THRUST/
│       ├── TURBO-GT/
│       └── URBAN-PRO/
├── Parts/
│   ├── Rims/
│   │   ├── KRONOS/
│   │   │   ├── R1_TechVortex/
│   │   │   ├── R2_CyberFlow/
│   │   │   ├── R3_DeltaRace/
│   │   │   ├── R4_NeoSync/
│   │   │   └── R5_HorizonLux/
│   │   └── [VELOCE & THRUST similar structure]
│   ├── Exhausts/
│   │   └── [Similar brand/tier structure]
│   ├── BodyPanels/
│   ├── Mirrors/
│   ├── Engines/
│   └── Suspension/
├── Materials/
│   ├── BaseMaterials/
│   │   ├── M_MetallicBase
│   │   ├── M_MatteBase
│   │   ├── M_PerlescentBase
│   │   ├── M_HolographicBase
│   │   └── M_NeonBase
│   └── Paints/
│       ├── MI_Paint_Matte_Black
│       ├── MI_Paint_Holographic_Rainbow
│       └── [All paint variants]
├── Environments/
│   ├── Track_Urban_01/
│   │   ├── Meshes/
│   │   ├── Materials/
│   │   └── Lighting/
│   ├── Garage_Workshop/
│   └── Arcade_Track/
├── UI/
│   ├── Textures/
│   └── Icons/
└── VFX/
    ├── Particles/
    ├── Materials/
    └── Overlays/
```

---

## PART 8: PRIORITY GENERATION ORDER

### PHASE 1 - CRITICAL PATH (Weeks 1-2)
- [ ] 1x Scooter model (KRONOS FALCON-7) with basic paint
- [ ] 5x Rim models (1 per tier: Common → Legendary)
- [ ] 5x Exhaust models (1 per tier)
- [ ] Urban track basic environment
- [ ] Material system implementation

### PHASE 2 - EXPANSION (Weeks 3-4)
- [ ] Remaining 5 scooter models
- [ ] All paint finish variations
- [ ] All body panel kits
- [ ] Mirror and engine showcase models
- [ ] Garage environment

### PHASE 3 - POLISH (Weeks 5+)
- [ ] Arcade background artwork
- [ ] VFX and particle systems
- [ ] UI assets and menu design
- [ ] Additional track environments
- [ ] Performance optimization

---

## FINAL NOTES

- All textures should be PBR (Physically Based Rendering) for UE5
- Target 2K resolution for main assets, 4K for hero pieces
- LOD models required for performance (LOD0, LOD1, LOD2)
- Metallic/Roughness/AO/Normal maps required
- All assets should feel "worn" and lived-in (avoid sterile perfection)
- Brand identity must be immediately recognizable
- Rarity tiers should be visually distinct at a glance
