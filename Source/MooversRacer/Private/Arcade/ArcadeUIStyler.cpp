#include "Arcade/ArcadeUIStyler.h"
#include "Core/VisualTheme.h"

UArcadeUIStyler::UArcadeUIStyler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UArcadeUIStyler::InitializeArcadeStyle(EScooterBrand Brand)
{
	InitializeLaneColors();
	InitializeObstacleVisuals();
	InitializePowerUpVisuals();
	InitializeHUDStyle();

	// Apply brand-specific styling
	switch (Brand)
	{
		case EScooterBrand::KRONOS_MOTORS:
			// Tech aesthetic - cool blues and cyans
			VisualSettings.bUseNeonGlow = true;
			VisualSettings.GlobalGlowIntensity = 1.0f;
			break;

		case EScooterBrand::VELOCE_CLASSICS:
			// Vintage aesthetic - warmer tones
			VisualSettings.bUseRetroShader = true;
			VisualSettings.RetroScanlineIntensity = 0.3f;
			break;

		case EScooterBrand::THRUST_DYNAMICS:
			// Street aesthetic - high contrast, bold
			VisualSettings.GlobalGlowIntensity = 1.2f;
			break;
	}
}

void UArcadeUIStyler::InitializeLaneColors()
{
	// ========== LEFT LANES - COOL BLUE ==========
	LeftLaneVisuals.LaneGlowColor = FLinearColor(0.0f, 0.5f, 1.0f, 1.0f);  // Sky blue
	LeftLaneVisuals.LaneGlowIntensity = 0.8f;

	// ========== RIGHT LANES - WARM ORANGE ==========
	RightLaneVisuals.LaneGlowColor = FLinearColor(1.0f, 0.3f, 0.0f, 1.0f);  // Orange
	RightLaneVisuals.LaneGlowIntensity = 0.8f;
}

void UArcadeUIStyler::InitializeObstacleVisuals()
{
	// ========== POTHOLE VISUALS ==========
	PotholeVisuals.ObstacleColor = FLinearColor(0.3f, 0.3f, 0.3f, 1.0f);  // Dark gray

	// ========== CONE VISUALS ==========
	ConeVisuals.ObstacleColor = FLinearColor(1.0f, 0.65f, 0.0f, 1.0f);    // Orange-yellow
}

void UArcadeUIStyler::InitializePowerUpVisuals()
{
	// ========== SPEED BOOST - NEON GREEN ==========
	SpeedBoostVisuals.GlowColor = FLinearColor(0.0f, 1.0f, 0.5f, 1.0f);
	SpeedBoostVisuals.RotationSpeed = 360.0f;  // 360 degrees per second = 1 rotation

	// ========== INVINCIBILITY - PURPLE/MAGENTA ==========
	InvincibilityVisuals.GlowColor = FLinearColor(1.0f, 0.0f, 1.0f, 1.0f);
	InvincibilityVisuals.RotationSpeed = 180.0f;  // Slower rotation for skull
}

void UArcadeUIStyler::InitializeHUDStyle()
{
	// ========== TEXT COLORS ==========
	HUDStyle.ScoreTextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);        // White
	HUDStyle.MultiplierTextColor = FLinearColor(1.0f, 0.84f, 0.0f, 1.0f);  // Gold

	// ========== HEALTH INDICATOR STYLING ==========
	HUDStyle.HealthIconSize = FVector2D(40.0f, 40.0f);

	// ========== MULTIPLIER SETTINGS ==========
	HUDStyle.MultiplierGrowthScale = 1.1f;  // Grows to 110% on level-up

	// ========== BACKGROUND ==========
	HUDStyle.HUDBackgroundOpacity = 0.7f;  // Semi-transparent for readability
}

FLinearColor UArcadeUIStyler::GetLaneColor(int32 LaneIndex) const
{
	// Lanes 0-1: Left side (blue)
	// Lanes 2-3: Right side (orange)
	if (LaneIndex < 2)
	{
		return LeftLaneVisuals.LaneGlowColor;
	}
	else
	{
		return RightLaneVisuals.LaneGlowColor;
	}
}

FLinearColor UArcadeUIStyler::GetPowerUpGlowColor(bool bIsSpeedBoost) const
{
	if (bIsSpeedBoost)
	{
		return SpeedBoostVisuals.GlowColor;
	}
	else
	{
		return InvincibilityVisuals.GlowColor;
	}
}

FLinearColor UArcadeUIStyler::GetObstacleColor() const
{
	return PotholeVisuals.ObstacleColor;
}

void UArcadeUIStyler::ApplyDifficultyVisuals(float DifficultyMultiplier)
{
	if (!VisualSettings.bEscalateVisualIntensity)
	{
		return;
	}

	// Escalate visual intensity based on difficulty
	float TintIntensity = FMath::Clamp(DifficultyMultiplier * 0.15f, 0.0f, 1.0f);

	// At higher difficulties, add a red screen tint
	VisualSettings.HighDifficultyTintIntensity = TintIntensity;
}

void UArcadeUIStyler::ApplyCollisionScreenShake(float Intensity)
{
	if (!VisualSettings.bUseScreenShake)
	{
		return;
	}

	float ShakeAmount = FMath::Clamp(Intensity * VisualSettings.MaxScreenShakeAmount, 0.0f, 1.0f);
	// Implementation would call camera shake in actual game

	UE_LOG(LogTemp, Warning, TEXT("Screen shake: %.2f"), ShakeAmount);
}

void UArcadeUIStyler::ApplySpeedBloom(float CurrentSpeed, float MaxSpeed)
{
	if (!VisualSettings.bUseSpeedBloom)
	{
		return;
	}

	float SpeedRatio = FMath::Clamp(CurrentSpeed / MaxSpeed, 0.0f, 1.0f);
	float BloomScale = 1.0f + (SpeedRatio * VisualSettings.SpeedBloomScale);

	// Implementation would apply post-process bloom in actual game
	UE_LOG(LogTemp, Warning, TEXT("Speed bloom scale: %.2f"), BloomScale);
}

void UArcadeUIStyler::ResetVisualEffects()
{
	VisualSettings.HighDifficultyTintIntensity = 0.0f;
	VisualSettings.SpeedBloomScale = 1.0f;
	// Reset other visual effects as needed
}
