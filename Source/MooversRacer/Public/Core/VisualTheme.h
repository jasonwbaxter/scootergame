#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "VisualTheme.generated.h"

/**
 * Central visual theme system for Moovers Racer
 * Implements brand colors, UI styling, and material specifications
 * Based on VISUAL_IDENTITY_GUIDE.md
 */

UENUM(BlueprintType)
enum class EScooterBrand : uint8
{
	KRONOS_MOTORS,      // Tech/Premium - Deep blue, silver, cyan
	VELOCE_CLASSICS,    // Heritage/Vintage - Red, cream, gold
	THRUST_DYNAMICS,    // Street/Bold - Orange, black, white
	MAX
};

UENUM(BlueprintType)
enum class EPartRarity : uint8
{
	Common,        // Matte black/gray
	Uncommon,      // Semi-gloss, single accent
	Rare,          // Chrome, dual-tone, metallic
	Epic,          // Pearlescent, holographic
	Legendary,     // Custom bespoke, unique
	MAX
};

USTRUCT(BlueprintType)
struct FBrandColorPalette
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Colors")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Colors")
	FLinearColor SecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Colors")
	FLinearColor AccentColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brand Colors")
	FLinearColor TrimColor;
};

USTRUCT(BlueprintType)
struct FRarityVisualSpec
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	float MetallicValue;    // 0.0 = Matte, 1.0 = Mirror

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	float RoughnessValue;   // 0.0 = Polished, 1.0 = Rough

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	float GlowIntensity;    // For Epic/Legendary

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	bool bHasHolographicShift;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	float EmissiveMultiplier;
};

/**
 * UVisualTheme - Central theme configuration
 */
UCLASS(Blueprintable, BlueprintType)
class MOOVERSRACER_API UVisualTheme : public UObject
{
	GENERATED_BODY()

public:
	UVisualTheme();

	// ============ BRAND COLOR PALETTES ============

	/** KRONOS MOTORS - Tech/Premium Aesthetic */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brands|KRONOS")
	FBrandColorPalette KronosPalette;

	/** VELOCE CLASSICS - Heritage/Vintage Aesthetic */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brands|VELOCE")
	FBrandColorPalette VelocePalette;

	/** THRUST DYNAMICS - Street/Bold Aesthetic */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Brands|THRUST")
	FBrandColorPalette ThrustPalette;

	// ============ RARITY SPECIFICATIONS ============

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	FRarityVisualSpec CommonRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	FRarityVisualSpec UncommonRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	FRarityVisualSpec RareRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	FRarityVisualSpec EpicRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rarity")
	FRarityVisualSpec LegendaryRarity;

	// ============ UI THEME COLORS ============

	/** Workshop ambient background */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Background")
	FLinearColor WorkshopDarkGray;

	/** UI accent - primary action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Accents")
	FLinearColor UIAccentPrimary;

	/** UI accent - secondary action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Accents")
	FLinearColor UIAccentSecondary;

	/** Text - primary readable */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Text")
	FLinearColor UITextPrimary;

	/** Text - secondary/muted */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Text")
	FLinearColor UITextSecondary;

	// ============ ARCADE MODE COLORS ============

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcade|Colors")
	FLinearColor ArcadeLeftLaneColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcade|Colors")
	FLinearColor ArcadeRightLaneColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcade|Colors")
	FLinearColor ArcadePowerUpColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcade|Colors")
	FLinearColor ArcadeObstacleColor;

	// ============ METHODS ============

	/** Get brand color palette */
	UFUNCTION(BlueprintPure, Category = "Visual Theme")
	FBrandColorPalette GetBrandPalette(EScooterBrand Brand) const;

	/** Get rarity visual specification */
	UFUNCTION(BlueprintPure, Category = "Visual Theme")
	FRarityVisualSpec GetRaritySpec(EPartRarity Rarity) const;

	/** Initialize theme with default values */
	UFUNCTION(BlueprintCallable, Category = "Visual Theme")
	void InitializeTheme();

private:
	void InitializeBrandPalettes();
	void InitializeRaritySpecs();
	void InitializeUITheme();
};
