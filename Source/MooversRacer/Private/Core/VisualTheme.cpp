#include "Core/VisualTheme.h"

UVisualTheme::UVisualTheme()
{
	InitializeTheme();
}

void UVisualTheme::InitializeTheme()
{
	InitializeBrandPalettes();
	InitializeRaritySpecs();
	InitializeUITheme();
}

void UVisualTheme::InitializeBrandPalettes()
{
	// ========== KRONOS MOTORS - Deep Metallic Blue ==========
	KronosPalette.PrimaryColor = FLinearColor(0.1f, 0.3f, 0.48f, 1.0f);      // Deep metallic blue #1a4d7a
	KronosPalette.SecondaryColor = FLinearColor(0.75f, 0.75f, 0.75f, 1.0f);   // Silver #c0c0c0
	KronosPalette.AccentColor = FLinearColor(0.0f, 0.83f, 1.0f, 1.0f);        // Electric cyan #00d4ff
	KronosPalette.TrimColor = FLinearColor(0.1f, 0.1f, 0.1f, 1.0f);           // Black #1a1a1a

	// ========== VELOCE CLASSICS - Fire Red & Cream ==========
	VelocePalette.PrimaryColor = FLinearColor(0.83f, 0.12f, 0.12f, 1.0f);     // Fire red #d41f1f
	VelocePalette.SecondaryColor = FLinearColor(0.96f, 0.87f, 0.70f, 1.0f);   // Cream #f5deb3
	VelocePalette.AccentColor = FLinearColor(1.0f, 0.84f, 0.0f, 1.0f);        // Gold #ffd700
	VelocePalette.TrimColor = FLinearColor(0.63f, 0.32f, 0.18f, 1.0f);        // Mahogany brown #a0522d

	// ========== THRUST DYNAMICS - Vibrant Orange ==========
	ThrustPalette.PrimaryColor = FLinearColor(1.0f, 0.55f, 0.0f, 1.0f);       // Vibrant orange #ff8c00
	ThrustPalette.SecondaryColor = FLinearColor(0.1f, 0.1f, 0.1f, 1.0f);      // Matte black #1a1a1a
	ThrustPalette.AccentColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);         // Pure white #ffffff
	ThrustPalette.TrimColor = FLinearColor(0.29f, 0.08f, 0.55f, 1.0f);        // Deep purple #4a148c
}

void UVisualTheme::InitializeRaritySpecs()
{
	// ========== COMMON - Matte finishes ==========
	CommonRarity.MetallicValue = 0.0f;           // Completely matte
	CommonRarity.RoughnessValue = 0.8f;          // Rough surface
	CommonRarity.GlowIntensity = 0.0f;           // No glow
	CommonRarity.bHasHolographicShift = false;
	CommonRarity.EmissiveMultiplier = 0.0f;

	// ========== UNCOMMON - Semi-gloss with single accent ==========
	UncommonRarity.MetallicValue = 0.4f;         // Partial metallic
	UncommonRarity.RoughnessValue = 0.5f;        // Medium gloss
	UncommonRarity.GlowIntensity = 0.0f;
	UncommonRarity.bHasHolographicShift = false;
	UncommonRarity.EmissiveMultiplier = 0.0f;

	// ========== RARE - Chrome and metallic finishes ==========
	RareRarity.MetallicValue = 0.8f;             // Highly metallic
	RareRarity.RoughnessValue = 0.2f;            // Very polished
	RareRarity.GlowIntensity = 0.0f;
	RareRarity.bHasHolographicShift = false;
	RareRarity.EmissiveMultiplier = 0.0f;

	// ========== EPIC - Pearlescent and holographic effects ==========
	EpicRarity.MetallicValue = 0.9f;             // Near-mirror
	EpicRarity.RoughnessValue = 0.1f;            // Highly polished
	EpicRarity.GlowIntensity = 0.3f;             // Subtle glow
	EpicRarity.bHasHolographicShift = true;      // Color-shifting effect
	EpicRarity.EmissiveMultiplier = 0.4f;        // Emissive shimmer

	// ========== LEGENDARY - Holographic with animation ==========
	LegendaryRarity.MetallicValue = 0.95f;       // Nearly perfect mirror
	LegendaryRarity.RoughnessValue = 0.05f;      // Extremely polished
	LegendaryRarity.GlowIntensity = 0.8f;        // Strong glow
	LegendaryRarity.bHasHolographicShift = true;
	LegendaryRarity.EmissiveMultiplier = 1.0f;   // Full emissive power
}

void UVisualTheme::InitializeUITheme()
{
	// Workshop ambient - Dark gray base for industrial aesthetic
	WorkshopDarkGray = FLinearColor(0.15f, 0.15f, 0.15f, 1.0f);

	// UI Accents
	UIAccentPrimary = FLinearColor(0.0f, 0.83f, 1.0f, 1.0f);        // Electric cyan (KRONOS accent)
	UIAccentSecondary = FLinearColor(1.0f, 0.55f, 0.0f, 1.0f);      // Orange (THRUST accent)

	// UI Text
	UITextPrimary = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);           // White - readable
	UITextSecondary = FLinearColor(0.8f, 0.8f, 0.8f, 1.0f);         // Light gray - muted

	// Arcade Mode Colors
	ArcadeLeftLaneColor = FLinearColor(0.0f, 0.5f, 1.0f, 0.3f);     // Blue lanes
	ArcadeRightLaneColor = FLinearColor(1.0f, 0.3f, 0.0f, 0.3f);    // Orange lanes
	ArcadePowerUpColor = FLinearColor(0.0f, 1.0f, 0.5f, 1.0f);      // Neon green
	ArcadeObstacleColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);     // Gray
}

FBrandColorPalette UVisualTheme::GetBrandPalette(EScooterBrand Brand) const
{
	switch (Brand)
	{
		case EScooterBrand::KRONOS_MOTORS:
			return KronosPalette;
		case EScooterBrand::VELOCE_CLASSICS:
			return VelocePalette;
		case EScooterBrand::THRUST_DYNAMICS:
			return ThrustPalette;
		default:
			return KronosPalette;
	}
}

FRarityVisualSpec UVisualTheme::GetRaritySpec(EPartRarity Rarity) const
{
	switch (Rarity)
	{
		case EPartRarity::Common:
			return CommonRarity;
		case EPartRarity::Uncommon:
			return UncommonRarity;
		case EPartRarity::Rare:
			return RareRarity;
		case EPartRarity::Epic:
			return EpicRarity;
		case EPartRarity::Legendary:
			return LegendaryRarity;
		default:
			return CommonRarity;
	}
}
