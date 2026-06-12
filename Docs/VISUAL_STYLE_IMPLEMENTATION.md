# Moovers Racer - Visual Style Implementation Guide for Developers

This guide explains how to apply the brand visual identity and styling to the game code and assets.

---

## QUICK REFERENCE: VISUAL SYSTEM ARCHITECTURE

```
UVisualTheme (Core/VisualTheme.h)
├── Brand Color Palettes
│   ├── KRONOS_MOTORS (Deep Blue, Silver, Cyan)
│   ├── VELOCE_CLASSICS (Red, Cream, Gold)
│   └── THRUST_DYNAMICS (Orange, Black, White)
├── Rarity Specifications
│   ├── Common (Matte 0.0, Rough 0.8)
│   ├── Uncommon (Metallic 0.4, Rough 0.5)
│   ├── Rare (Metallic 0.8, Rough 0.2)
│   ├── Epic (Metallic 0.9, Rough 0.1, Holographic)
│   └── Legendary (Metallic 0.95, Rough 0.05, Full Glow)
└── UI Theme Colors

FPartVisualData (Customization/PartDefinition.h)
├── Visual Assets (Mesh, Material, Thumbnail)
├── PBR Parameters (Metallic, Roughness, Glow)
├── Brand & Rarity Info
└── Stat Effects

UArcadeUIStyler (Arcade/ArcadeUIStyler.h)
├── Lane Colors & Visuals
├── Obstacle & PowerUp Styling
├── HUD Style Elements
└── Difficulty Escalation Effects
```

---

## PART 1: USING THE VISUAL THEME IN CODE

### Step 1: Create a Visual Theme Asset

1. In Unreal Editor, go to: `Content Browser` → `New Asset`
2. Select `Miscellaneous` → `Data Asset`
3. Choose `VisualTheme` as the data type
4. Name it: `DA_VisualTheme_KRONOS`

### Step 2: Access the Theme in C++

```cpp
#include "Core/VisualTheme.h"

// In your gameplay code
void AYourGameMode::SetupVisuals()
{
    // Load the visual theme asset
    UVisualTheme* Theme = LoadObject<UVisualTheme>(
        nullptr, 
        TEXT("DataAsset'/Game/Data/DA_VisualTheme_KRONOS.DA_VisualTheme_KRONOS'")
    );

    if (!Theme)
    {
        // Initialize with defaults
        Theme = NewObject<UVisualTheme>();
        Theme->InitializeTheme();
    }

    // Get brand palette
    FBrandColorPalette KronosPalette = Theme->GetBrandPalette(EScooterBrand::KRONOS_MOTORS);
    
    // Use colors for UI or materials
    FLinearColor PrimaryColor = KronosPalette.PrimaryColor;  // Deep blue #1a4d7a
}
```

### Step 3: Apply Rarity Visual Specs to Parts

```cpp
// In a part customization system
void UCustomizationManager::ApplyPartRarity(FPart& Part, EPartRarity Rarity)
{
    UVisualTheme* Theme = GetVisualTheme();
    FRarityVisualSpec RaritySpec = Theme->GetRaritySpec(Rarity);

    // Apply material parameters
    if (Part.VisualMaterial)
    {
        UMaterialInstanceDynamic* DynMaterial = 
            UMaterialInstanceDynamic::Create(Part.VisualMaterial, this);

        DynMaterial->SetScalarParameterValue(FName("Metallic"), RaritySpec.MetallicValue);
        DynMaterial->SetScalarParameterValue(FName("Roughness"), RaritySpec.RoughnessValue);
        DynMaterial->SetScalarParameterValue(FName("GlowIntensity"), RaritySpec.GlowIntensity);

        if (RaritySpec.bHasHolographicShift)
        {
            DynMaterial->SetScalarParameterValue(FName("bHolographic"), 1.0f);
        }

        Part.VisualMaterial = DynMaterial;
    }
}
```

---

## PART 2: APPLYING BRAND COLORS TO SCOOTERS

### Visual Theme for Vehicle Customization

```cpp
// In AScooterPawn or customization system
void AScooterPawn::ApplyBrandSkin(EScooterBrand Brand)
{
    UVisualTheme* Theme = GetVisualTheme();
    FBrandColorPalette BrandPalette = Theme->GetBrandPalette(Brand);

    // Apply primary color to body material
    if (USkeletalMeshComponent* BodyMesh = GetMesh())
    {
        for (int32 i = 0; i < BodyMesh->GetNumMaterials(); ++i)
        {
            UMaterialInstanceDynamic* DynMat = 
                Cast<UMaterialInstanceDynamic>(BodyMesh->GetMaterial(i));

            if (!DynMat)
            {
                DynMat = UMaterialInstanceDynamic::Create(
                    BodyMesh->GetMaterial(i), this
                );
            }

            // Apply brand colors
            DynMat->SetVectorParameterValue(
                FName("PrimaryColor"), 
                BrandPalette.PrimaryColor
            );
            DynMat->SetVectorParameterValue(
                FName("AccentColor"), 
                BrandPalette.AccentColor
            );

            BodyMesh->SetMaterial(i, DynMat);
        }
    }
}
```

---

## PART 3: IMPLEMENTING RARITY VISUAL TIERS

### Material Parameter Mapping for Each Rarity

```cpp
void UCustomizationManager::SetPartRarityMaterial(
    FPart& Part, 
    EPartRarity Rarity,
    UVisualTheme* Theme)
{
    FRarityVisualSpec Spec = Theme->GetRaritySpec(Rarity);

    // Create dynamic material from the base part material
    UMaterialInstanceDynamic* RarityMaterial = 
        UMaterialInstanceDynamic::Create(Part.VisualMaterial, this);

    // ========== RARITY-SPECIFIC PARAMETERS ==========

    switch (Rarity)
    {
        case EPartRarity::Common:
            // Matte finish - low metallic, high roughness
            RarityMaterial->SetScalarParameterValue(FName("Metallic"), 0.0f);
            RarityMaterial->SetScalarParameterValue(FName("Roughness"), 0.8f);
            RarityMaterial->SetScalarParameterValue(FName("bGlowing"), 0.0f);
            break;

        case EPartRarity::Uncommon:
            // Semi-gloss with accent color
            RarityMaterial->SetScalarParameterValue(FName("Metallic"), 0.4f);
            RarityMaterial->SetScalarParameterValue(FName("Roughness"), 0.5f);
            RarityMaterial->SetVectorParameterValue(
                FName("AccentColor"), 
                Part.AccentColor
            );
            break;

        case EPartRarity::Rare:
            // Chrome-like finish
            RarityMaterial->SetScalarParameterValue(FName("Metallic"), 0.8f);
            RarityMaterial->SetScalarParameterValue(FName("Roughness"), 0.2f);
            break;

        case EPartRarity::Epic:
            // Pearlescent with glow
            RarityMaterial->SetScalarParameterValue(FName("Metallic"), 0.9f);
            RarityMaterial->SetScalarParameterValue(FName("Roughness"), 0.1f);
            RarityMaterial->SetScalarParameterValue(FName("GlowIntensity"), 0.4f);
            RarityMaterial->SetScalarParameterValue(FName("bPearlescent"), 1.0f);
            break;

        case EPartRarity::Legendary:
            // Full holographic with animation
            RarityMaterial->SetScalarParameterValue(FName("Metallic"), 0.95f);
            RarityMaterial->SetScalarParameterValue(FName("Roughness"), 0.05f);
            RarityMaterial->SetScalarParameterValue(FName("GlowIntensity"), 1.0f);
            RarityMaterial->SetScalarParameterValue(FName("bHolographic"), 1.0f);
            break;
    }

    Part.VisualMaterial = RarityMaterial;
}
```

---

## PART 4: UI STYLING WITH THE VISUAL THEME

### Color-Coded Rarity Indicators

```cpp
// In garage UI or part selection
FLinearColor UCustomizationUI::GetRarityColor(EPartRarity Rarity) const
{
    switch (Rarity)
    {
        case EPartRarity::Common:
            return FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);      // Gray
        case EPartRarity::Uncommon:
            return FLinearColor(0.0f, 0.5f, 1.0f, 1.0f);      // Blue
        case EPartRarity::Rare:
            return FLinearColor(1.0f, 0.84f, 0.0f, 1.0f);     // Gold
        case EPartRarity::Epic:
            return FLinearColor(0.627f, 0.125f, 0.941f, 1.0f);  // Purple
        case EPartRarity::Legendary:
            return FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);      // Red/Orange
        default:
            return FLinearColor::White;
    }
}
```

### Brand Logo Display in UI

```cpp
// In menu or brand selection
void UBrandSelectionUI::DisplayBrand(EScooterBrand Brand)
{
    UVisualTheme* Theme = GetVisualTheme();
    FBrandColorPalette BrandColors = Theme->GetBrandPalette(Brand);

    // Set background color to brand primary
    if (UImage* BrandBackground = GetBrandBackgroundImage())
    {
        BrandBackground->SetColorAndOpacity(FSlateColor(BrandColors.PrimaryColor * 0.5f));
    }

    // Set accent colors
    if (UImage* AccentElement = GetAccentElement())
    {
        AccentElement->SetColorAndOpacity(FSlateColor(BrandColors.AccentColor));
    }
}
```

---

## PART 5: ARCADE MODE STYLING

### Initializing Arcade Visual Styling

```cpp
void AArcadeGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Create and initialize the arcade styler
    if (!ArcadeStyler)
    {
        ArcadeStyler = NewObject<UArcadeUIStyler>(this);
        ArcadeStyler->InitializeArcadeStyle(CurrentBrand);
    }

    // Apply difficulty-based visuals
    ArcadeStyler->ApplyDifficultyVisuals(CurrentDifficulty);
}
```

### Using Arcade Lane Colors

```cpp
// In arcade HUD rendering
void AArcadeHUD::DrawLaneIndicators()
{
    UArcadeUIStyler* Styler = GetArcadeStyler();

    for (int32 LaneIdx = 0; LaneIdx < 4; ++LaneIdx)
    {
        FLinearColor LaneColor = Styler->GetLaneColor(LaneIdx);

        // Draw lane with color
        DrawRectWithColor(LanePositions[LaneIdx], LaneColor);
    }
}
```

### Arcade Power-Up Visualization

```cpp
void AArcadePowerUp::SetupVisuals()
{
    UArcadeUIStyler* Styler = GetGameMode()->GetArcadeStyler();
    
    FLinearColor PowerUpGlow = Styler->GetPowerUpGlowColor(bIsSpeedBoost);

    if (UStaticMeshComponent* Mesh = GetMesh())
    {
        UMaterialInstanceDynamic* GlowMaterial = 
            UMaterialInstanceDynamic::Create(Mesh->GetMaterial(0), this);

        GlowMaterial->SetVectorParameterValue(FName("GlowColor"), PowerUpGlow);
        GlowMaterial->SetScalarParameterValue(FName("GlowIntensity"), 1.0f);

        Mesh->SetMaterial(0, GlowMaterial);

        // Rotate mesh for visual effect
        GetWorldTimerManager().SetTimer(
            RotationTimerHandle,
            [this, Styler]()
            {
                if (UStaticMeshComponent* Mesh = GetMesh())
                {
                    float RotationSpeed = Styler->GetPowerUpGlowColor(bIsSpeedBoost).R > 0.5f 
                        ? 360.0f : 180.0f;  // Different speeds based on power-up type
                    Mesh->AddWorldRotation(FRotator(0.0f, RotationSpeed * 0.016f, 0.0f));
                }
            },
            0.016f,  // ~60 FPS
            true
        );
    }
}
```

---

## PART 6: PAINT SYSTEM IMPLEMENTATION

### Dynamic Paint Recoloring

```cpp
// In customization system
void UCustomizationManager::ApplyPaintFinish(
    AScooterPawn* Scooter,
    const FPaintFinish& Paint)
{
    if (!Scooter || !Scooter->GetMesh())
    {
        return;
    }

    // Apply paint to all body materials
    for (int32 MaterialIdx = 0; MaterialIdx < Scooter->GetMesh()->GetNumMaterials(); ++MaterialIdx)
    {
        UMaterialInstanceDynamic* PaintMaterial = 
            UMaterialInstanceDynamic::Create(Scooter->GetMesh()->GetMaterial(MaterialIdx), this);

        // Set paint parameters
        PaintMaterial->SetVectorParameterValue(
            FName("PaintColor"), 
            Paint.PrimaryColor
        );
        PaintMaterial->SetVectorParameterValue(
            FName("SecondaryColor"), 
            Paint.SecondaryColor
        );
        PaintMaterial->SetScalarParameterValue(FName("Metallic"), Paint.Metallic);
        PaintMaterial->SetScalarParameterValue(FName("Roughness"), Paint.Roughness);

        if (Paint.bIsEmissive)
        {
            PaintMaterial->SetScalarParameterValue(
                FName("EmissiveIntensity"), 
                Paint.EmissiveIntensity
            );
        }

        if (Paint.bIsHolographic)
        {
            PaintMaterial->SetScalarParameterValue(FName("bHolographic"), 1.0f);
        }

        Scooter->GetMesh()->SetMaterial(MaterialIdx, PaintMaterial);
    }
}
```

---

## PART 7: DECAL & GRAPHICS SYSTEM

### Applying Decals to Scooter

```cpp
// In customization system
void UCustomizationManager::ApplyDecal(
    AScooterPawn* Scooter,
    const FString& DecalID,
    FVector DecalPosition,
    FRotator DecalRotation,
    FVector DecalSize)
{
    if (!Scooter)
    {
        return;
    }

    // Load decal material
    UMaterialInterface* DecalMaterial = LoadObject<UMaterialInterface>(
        nullptr,
        *FString::Printf(TEXT("Material'/Game/Materials/Decals/%s.%s'"), *DecalID, *DecalID)
    );

    if (!DecalMaterial)
    {
        UE_LOG(LogTemp, Error, TEXT("Decal material not found: %s"), *DecalID);
        return;
    }

    // Create decal actor
    ADecalActor* Decal = GetWorld()->SpawnActor<ADecalActor>(
        DecalPosition, 
        DecalRotation
    );

    if (Decal)
    {
        Decal->SetDecalMaterial(DecalMaterial);
        Decal->GetDecalComponent()->DecalSize = DecalSize;
        Decal->AttachToActor(Scooter, FAttachmentTransformRules::KeepWorldTransform);
    }
}
```

---

## PART 8: MATERIAL PARAMETER REFERENCE

### Standard PBR Parameters in Master Materials

These parameters should be available in your `M_Base_*` materials:

```
// Surface Properties
- PrimaryColor (Vector) - Main material color
- SecondaryColor (Vector) - Accent/secondary color
- Metallic (Scalar, 0.0-1.0) - How reflective (0=matte, 1=mirror)
- Roughness (Scalar, 0.0-1.0) - Surface smoothness (0=polished, 1=rough)
- Ambient Occlusion (Scalar, 0.0-1.0) - Crevice shadowing

// Special Effects
- GlowIntensity (Scalar) - Emissive strength for Epic/Legendary
- bHolographic (Boolean) - Enable holographic color-shift
- bPearlescent (Boolean) - Enable pearlescent finish
- bEmissive (Boolean) - Enable emissive layer
- EmissiveIntensity (Scalar) - How bright emissive glows

// Decals & Overlays
- DecalBlendMode (Enum) - How decals blend
- DecalOpacity (Scalar, 0.0-1.0) - Decal transparency
```

---

## PART 9: CREATING NEW PAINT FINISHES

### Step-by-Step: Add a New Paint Finish

1. **Create Material Master**
   ```
   Content/Materials/Paints/M_Paint_Custom
   ```

2. **Set Up Parameters** (in material editor)
   - Add vector parameters for colors
   - Add scalar parameters for metallic/roughness
   - Add emissive channel if needed

3. **Register in PartDefinition.h**
   ```cpp
   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Paints|Custom")
   FPaintFinish Paint_Custom_NewFinish;
   ```

4. **Initialize in Code**
   ```cpp
   void UPartDefinition::InitializePaintLibrary()
   {
       // ... existing paints ...

       Paint_Custom_NewFinish.FinishName = TEXT("Holographic Gold");
       Paint_Custom_NewFinish.PrimaryColor = FLinearColor(1.0f, 0.84f, 0.0f, 1.0f);
       Paint_Custom_NewFinish.Metallic = 0.95f;
       Paint_Custom_NewFinish.Roughness = 0.05f;
       Paint_Custom_NewFinish.bIsHolographic = true;
   }
   ```

---

## PART 10: DEBUGGING & TESTING VISUALS

### Console Commands for Visual Testing

```cpp
// In your game console
// Test brand colors
stat unit  // Check frame rate while rendering

// Toggle visual effects in arcade
r.PostProcessing 0/1  // Disable/enable post-processing

// Material parameter inspection
r.Textures 1  // Show texture streaming

// Visual theme debugging
ShowDebug CustomShader  // View shader parameters
```

### Visual Theme Validation Function

```cpp
void UVisualTheme::ValidateTheme()
{
    // Ensure all colors are valid (0.0-1.0 range)
    check(KronosPalette.PrimaryColor.R >= 0.0f && KronosPalette.PrimaryColor.R <= 1.0f);

    // Ensure metallic values are valid
    check(CommonRarity.MetallicValue >= 0.0f && CommonRarity.MetallicValue <= 1.0f);
    check(LegendaryRarity.MetallicValue >= 0.0f && LegendaryRarity.MetallicValue <= 1.0f);

    // Ensure rarity tiers progress visually
    check(CommonRarity.MetallicValue < UncommonRarity.MetallicValue);
    check(UncommonRarity.MetallicValue < RareRarity.MetallicValue);
    check(RareRarity.MetallicValue < EpicRarity.MetallicValue);
    check(EpicRarity.MetallicValue < LegendaryRarity.MetallicValue);

    UE_LOG(LogTemp, Log, TEXT("Visual theme validation: PASSED"));
}
```

---

## CHECKLIST: VISUAL INTEGRATION

- [ ] `UVisualTheme` created and initialized with brand colors
- [ ] `EScooterBrand` enum integrated into `FPart` struct
- [ ] Part rarity visual specs applied to materials
- [ ] Brand color palettes used in UI rendering
- [ ] `UArcadeUIStyler` initialized in arcade mode
- [ ] Paint finish system implemented for recoloring
- [ ] Decal system integrated with material instances
- [ ] Master materials created for each rarity tier
- [ ] All 6 scooter models support brand customization
- [ ] Arcade lane colors and effects applied
- [ ] Visual debugging tools tested
- [ ] Performance validated (frame rate, LOD, materials)

---

## NEXT STEPS

1. Create master material templates in Substance Designer
2. Generate texture maps for all parts
3. Import FBX models with proper LOD setup
4. Test material parameter changes in editor
5. Profile performance with all visual systems active
6. Iterate on visual feedback based on playtests

