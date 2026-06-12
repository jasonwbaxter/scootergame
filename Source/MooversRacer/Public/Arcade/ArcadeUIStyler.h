#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/VisualTheme.h"
#include "ArcadeUIStyler.generated.h"

/**
 * Arcade Mode Visual Styling System
 * Manages all visual elements specific to arcade mode gameplay
 * Includes: lane colors, particle effects, score visualization, UI styling
 */

USTRUCT(BlueprintType)
struct FArcadeLaneVisuals
{
	GENERATED_BODY()

	// Lane appearance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Lanes")
	FLinearColor LaneGlowColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Lanes")
	float LaneGlowIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Lanes")
	UMaterialInterface* LaneMaterial;

	// Particle effects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Lanes")
	class UParticleSystem* LaneEnterParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Lanes")
	class UParticleSystem* LaneExitParticles;
};

USTRUCT(BlueprintType)
struct FArcadeObstacleVisuals
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Obstacles")
	UStaticMesh* ObstacleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Obstacles")
	UMaterialInterface* ObstacleMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Obstacles")
	FLinearColor ObstacleColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Obstacles")
	class UParticleSystem* CollisionParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Obstacles")
	class USoundBase* CollisionSound;
};

USTRUCT(BlueprintType)
struct FArcadePowerUpVisuals
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	UStaticMesh* PowerUpMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	UMaterialInterface* PowerUpMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	FLinearColor GlowColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	float RotationSpeed;  // RPM for rotation animation

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	class UParticleSystem* PickupParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade PowerUps")
	class USoundBase* PickupSound;
};

USTRUCT(BlueprintType)
struct FArcadeHUDStyle
{
	GENERATED_BODY()

	// Fonts & Text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	class UFont* ScoreFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	class UFont* MultiplierFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	FLinearColor ScoreTextColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	FLinearColor MultiplierTextColor;

	// Health indicators
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	UTexture2D* HealthHeartIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	UTexture2D* HealthHeartEmptyIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	FVector2D HealthIconSize;

	// Multiplier display
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	float MultiplierGrowthScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	class UParticleSystem* MultiplierUpParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	class USoundBase* MultiplierUpSound;

	// Background elements
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	UTexture2D* HUDBackgroundTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Style")
	float HUDBackgroundOpacity;
};

USTRUCT(BlueprintType)
struct FArcadeVisualSettings
{
	GENERATED_BODY()

	// General arcade aesthetic
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	bool bUseNeonGlow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	float GlobalGlowIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	bool bUseScreenShake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	float MaxScreenShakeAmount;

	// Post-processing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	bool bUseRetroShader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	float RetroScanlineIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	bool bUseSpeedBloom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	float SpeedBloomScale;

	// Difficulty ramping visuals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	bool bEscalateVisualIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	FLinearColor HighDifficultyScreenTint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade Visual")
	float HighDifficultyTintIntensity;
};

/**
 * UArcadeUIStyler - Central arcade mode visual styling
 */
UCLASS(Blueprintable, BlueprintType)
class MOOVERSRACER_API UArcadeUIStyler : public UActorComponent
{
	GENERATED_BODY()

public:
	UArcadeUIStyler();

	// ========== ARCADE LANE STYLING ==========

	/** Left lanes - Cool blue colors */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|Lanes")
	FArcadeLaneVisuals LeftLaneVisuals;

	/** Right lanes - Warm orange colors */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|Lanes")
	FArcadeLaneVisuals RightLaneVisuals;

	// ========== ARCADE OBSTACLES ==========

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|Obstacles")
	FArcadeObstacleVisuals PotholeVisuals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|Obstacles")
	FArcadeObstacleVisuals ConeVisuals;

	// ========== ARCADE POWER-UPS ==========

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|PowerUps")
	FArcadePowerUpVisuals SpeedBoostVisuals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|PowerUps")
	FArcadePowerUpVisuals InvincibilityVisuals;

	// ========== ARCADE HUD ==========

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|HUD")
	FArcadeHUDStyle HUDStyle;

	// ========== GENERAL SETTINGS ==========

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade|Settings")
	FArcadeVisualSettings VisualSettings;

	// ========== METHODS ==========

	/**
	 * Initialize arcade mode styling with brand colors
	 */
	UFUNCTION(BlueprintCallable, Category = "Arcade Styling")
	void InitializeArcadeStyle(EScooterBrand Brand = EScooterBrand::KRONOS_MOTORS);

	/**
	 * Apply difficulty-based visual escalation
	 * @param DifficultyMultiplier: 1.0 = start, 2.0+ = high difficulty
	 */
	UFUNCTION(BlueprintCallable, Category = "Arcade Styling")
	void ApplyDifficultyVisuals(float DifficultyMultiplier);

	/**
	 * Get lane color based on lane index
	 */
	UFUNCTION(BlueprintPure, Category = "Arcade Styling")
	FLinearColor GetLaneColor(int32 LaneIndex) const;

	/**
	 * Get glow color for power-up type
	 */
	UFUNCTION(BlueprintPure, Category = "Arcade Styling")
	FLinearColor GetPowerUpGlowColor(bool bIsSpeedBoost) const;

	/**
	 * Get obstacle color
	 */
	UFUNCTION(BlueprintPure, Category = "Arcade Styling")
	FLinearColor GetObstacleColor() const;

	/**
	 * Apply screen shake effect
	 */
	UFUNCTION(BlueprintCallable, Category = "Arcade Styling")
	void ApplyCollisionScreenShake(float Intensity);

	/**
	 * Apply bloom effect when speed increases
	 */
	UFUNCTION(BlueprintCallable, Category = "Arcade Styling")
	void ApplySpeedBloom(float CurrentSpeed, float MaxSpeed);

	/**
	 * Reset all visual effects to default
	 */
	UFUNCTION(BlueprintCallable, Category = "Arcade Styling")
	void ResetVisualEffects();

private:
	void InitializeLaneColors();
	void InitializeObstacleVisuals();
	void InitializePowerUpVisuals();
	void InitializeHUDStyle();
};
