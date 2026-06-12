# Moovers Racer - Visual System Quick Reference Card

## Brand Colors at a Glance

### KRONOS MOTORS
```
Primary:     #1a4d7a  (Deep Blue)
Secondary:   #c0c0c0  (Silver)
Accent:      #00d4ff  (Cyan)
Trim:        #1a1a1a  (Black)
Aesthetic:   Tech, futuristic, sleek
```

### VELOCE CLASSICS
```
Primary:     #d41f1f  (Fire Red)
Secondary:   #f5deb3  (Cream)
Accent:      #ffd700  (Gold)
Trim:        #a0522d  (Mahogany)
Aesthetic:   Vintage, heritage, classic
```

### THRUST DYNAMICS
```
Primary:     #ff8c00  (Orange)
Secondary:   #1a1a1a  (Black)
Accent:      #ffffff  (White)
Trim:        #4a148c  (Purple)
Aesthetic:   Street, bold, aggressive
```

---

## Rarity Tier Visual Properties

| Tier | Metallic | Roughness | Glow | Effect |
|------|----------|-----------|------|--------|
| Common | 0.0 | 0.8 | 0.0 | Matte, utilitarian |
| Uncommon | 0.4 | 0.5 | 0.0 | Semi-gloss |
| Rare | 0.8 | 0.2 | 0.0 | Chrome-like |
| Epic | 0.9 | 0.1 | 0.3 | Pearlescent |
| Legendary | 0.95 | 0.05 | 1.0 | Holographic |

---

## Arcade Mode Colors

```
Left Lane:   #0080ff  (Blue)
Right Lane:  #ff3000  (Orange)
Speed Boost: #00ff80  (Green)
Invincible:  #ff00ff  (Magenta)
Obstacle:    #808080  (Gray)
```

---

## Material Parameter Names

### Core PBR
- `Metallic` (0.0-1.0)
- `Roughness` (0.0-1.0)
- `PrimaryColor` (RGB)
- `SecondaryColor` (RGB)

### Special Effects
- `GlowIntensity` (0.0-1.0)
- `bHolographic` (0/1)
- `bPearlescent` (0/1)
- `EmissiveIntensity` (0.0-1.0)

---

## Code Snippets

### Get Brand Palette
```cpp
UVisualTheme* Theme = NewObject<UVisualTheme>();
FBrandColorPalette Palette = Theme->GetBrandPalette(EScooterBrand::KRONOS_MOTORS);
```

### Apply Rarity to Material
```cpp
FRarityVisualSpec Spec = Theme->GetRaritySpec(EPartRarity::Epic);
DynMaterial->SetScalarParameterValue(FName("Metallic"), Spec.MetallicValue);
DynMaterial->SetScalarParameterValue(FName("GlowIntensity"), Spec.GlowIntensity);
```

### Set Part Visuals
```cpp
Part.PrimaryColor = BrandPalette.PrimaryColor;
Part.AccentColor = BrandPalette.AccentColor;
Part.MetallicValue = RaritySpec.MetallicValue;
Part.RoughnessValue = RaritySpec.RoughnessValue;
```

### Get Arcade Lane Color
```cpp
FLinearColor LaneColor = ArcadeStyler->GetLaneColor(LaneIndex);
// Returns blue for lanes 0-1, orange for lanes 2-3
```

---

## Asset File Naming Convention

### Scooter Models
```
SM_KRONOS_FALCON7_LOD0
SK_KRONOS_FALCON7_Skeleton
```

### Parts
```
SM_KRONOS_R1_TechVortex
SM_KRONOS_E2_PerformanceX
SM_KRONOS_BP1_AeroTrim
```

### Materials
```
M_Base_Metallic_Master
MI_Paint_Holographic_Rainbow
M_Arcade_Lane_Glow
```

### Textures
```
T_KRONOS_R1_BaseColor
T_KRONOS_R1_Normal
T_KRONOS_R1_Roughness
T_KRONOS_R1_Metallic
```

---

## Rarity Color Indicators (UI)

```
Common:       Gray       #808080
Uncommon:     Blue       #0080ff
Rare:         Gold       #ffd700
Epic:         Purple     #a020f0
Legendary:    Red/Orange #ff4500
```

---

## Scooter Models Summary

| Brand | Model | Class | Colors |
|-------|-------|-------|--------|
| KRONOS | FALCON-7 | Performance | Blue, Gray, White |
| KRONOS | APEX-3 | Beginner | Signal Blue, Polar White, Sunset Orange |
| VELOCE | VESPA-ICONIC | Heritage | Fire Red, Cream, Racing Green |
| VELOCE | SPRINT-HERITAGE | Retro-Modern | Rust Orange, Matte Black, Cream |
| THRUST | TURBO-GT | Street | Neon Orange, Deep Black, Electric Purple |
| THRUST | URBAN-PRO | Daily | Charcoal Gray, Navy Blue, Forest Green |

---

## Customizable Parts Count

- **Rims**: 5 designs × 3 brands = 15 unique models
- **Exhausts**: 5 designs × 3 brands = 15 unique models
- **Body Panels**: 4 kits × 3 brands = 12 unique models
- **Paint Finishes**: 15+ variants across all rarity tiers
- **Decals**: 20+ designs across all rarity tiers
- **Mirrors**: 3 designs
- **Engines**: 5 showcase models
- **Suspension**: 3 kits

**Total**: 80+ asset models

---

## Particle System Integration Points

### Arcade Mode
- Lane change particles (spawn at lane transition)
- Power-up pickup particles (glow matching color)
- Collision explosion particles (gray/white)
- Speed boost trail (green glow)
- Multiplier increase particles (gold)

### Customization
- Turbo spin animation
- Engine glow effects
- Mirror reflections
- Part equip/unequip transition

---

## Performance Targets

- **Scooter LOD0**: 10k-20k polys
- **Scooter LOD1**: 5k-10k polys
- **Scooter LOD2**: 2k-5k polys
- **Part Models**: 1k-5k polys each
- **Textures**: 2K resolution (4K for hero assets)
- **Material Instances**: Dynamically created per customization
- **Target Frame Rate**: 60 FPS on mobile target hardware

---

## Key Implementation Files

```
✅ Source/MooversRacer/Public/Core/VisualTheme.h
✅ Source/MooversRacer/Private/Core/VisualTheme.cpp
✅ Source/MooversRacer/Public/Customization/PartDefinition.h (enhanced)
✅ Source/MooversRacer/Public/Arcade/ArcadeUIStyler.h
✅ Source/MooversRacer/Private/Arcade/ArcadeUIStyler.cpp

📚 Docs/ASSET_GENERATION_COMPLETE.md
📚 Docs/VISUAL_ASSET_CHECKLIST.md
📚 Docs/VISUAL_STYLE_IMPLEMENTATION.md
📚 Docs/VISUAL_SYSTEM_SUMMARY.md
```

---

## Visual Tier Progression Example

### KRONOS Rims
```
R1 TechVortex (Common)
   ↓ Matte black, simple 5-spoke
   ↓
R2 CyberFlow (Uncommon)
   ↓ Semi-gloss, 7-spoke with curves
   ↓
R3 DeltaRace (Rare)
   ↓ Chrome polish, complex 9-spoke
   ↓
R4 NeoSync (Epic)
   ↓ Pearlescent blue, 11-spoke with glow
   ↓
R5 HorizonLux (Legendary)
   ↓ Holographic rainbow, 13-spoke, animated center cap
```

---

## Customization System Capabilities

✅ Recolor individual parts
✅ Swap body panels
✅ Mix brands and rarity tiers
✅ Apply decals (up to 3 per vehicle)
✅ Select paint finishes
✅ Mix and match any components
✅ Save/load custom configurations
✅ Preview before equipping
✅ Compare stats before customizing
✅ Track rarity tier visually

---

## Common Integration Tasks

### Apply Brand Color to UI Element
```cpp
FBrandColorPalette Palette = Theme->GetBrandPalette(Brand);
UIElement->SetTintColor(FSlateColor(Palette.PrimaryColor));
```

### Create Rarity-Based Material
```cpp
FRarityVisualSpec Spec = Theme->GetRaritySpec(Rarity);
DynMat->SetScalarParameterValue(FName("Metallic"), Spec.MetallicValue);
DynMat->SetScalarParameterValue(FName("Roughness"), Spec.RoughnessValue);
```

### Display Part in Garage
```cpp
// Apply brand colors
ApplyBrandColors(Part, Brand);
// Apply rarity effects
ApplyRaritySpecs(Part, Rarity);
// Render in showcase
DisplayPartInPreviewUI(Part);
```

---

## Debugging Helpers

### Check Colors Are Valid
```cpp
check(Color.R >= 0.0f && Color.R <= 1.0f);
check(Color.G >= 0.0f && Color.G <= 1.0f);
check(Color.B >= 0.0f && Color.B <= 1.0f);
```

### Validate Metallic/Roughness
```cpp
check(Metallic >= 0.0f && Metallic <= 1.0f);
check(Roughness >= 0.0f && Roughness <= 1.0f);
```

### Log Theme Info
```cpp
UE_LOG(LogTemp, Log, TEXT("Brand Primary: R=%.2f G=%.2f B=%.2f"),
    Palette.PrimaryColor.R, Palette.PrimaryColor.G, Palette.PrimaryColor.B);
```

---

## Resource Links

- **Blender**: Free 3D modeling (https://www.blender.org/)
- **Substance Designer**: Procedural texturing ($20/month)
- **Substance Painter**: Direct mesh texturing ($20/month)
- **UE5 Documentation**: Material system (https://docs.unrealengine.com/)
- **Unreal Materials**: PBR best practices in official docs

---

## Team Communication

**For 3D Artists**: Reference `ASSET_GENERATION_COMPLETE.md`
**For Programmers**: Reference `VISUAL_STYLE_IMPLEMENTATION.md`
**For UI Designers**: Reference rarity color indicators above
**For Art Director**: Reference brand color palettes above

---

## Status Dashboard

- ✅ Visual Theme System: Complete
- ✅ Part Definition System: Complete
- ✅ Arcade Mode Styling: Complete
- ✅ Documentation: Complete
- ✅ Code Framework: Ready for integration
- ⏳ Asset Creation: Awaiting artist team
- ⏳ Integration Testing: After assets are ready
- ⏳ Performance Optimization: Final phase

---

## One-Page Checklist

- [ ] Review brand color palettes
- [ ] Understand rarity tiers and properties
- [ ] Examine asset generation specifications
- [ ] Review file naming conventions
- [ ] Study code implementation examples
- [ ] Load VisualTheme in your game mode
- [ ] Test brand color application
- [ ] Verify rarity material parameters
- [ ] Create first customized scooter
- [ ] Profile performance
- [ ] Iterate and refine

---

**Last Updated**: 2026-06-12
**Version**: 1.0
**Status**: Ready for Artist Team Integration
