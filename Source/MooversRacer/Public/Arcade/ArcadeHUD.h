// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArcadeHUD.generated.h"

class AArcadeRaceManager;

/**
 * HUD widget for arcade mode displaying score, multiplier, health, and power-up status.
 */
UCLASS()
class MOOVERSRACER_API UArcadeHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void SetArcadeManager(AArcadeRaceManager* Manager);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Arcade")
	void UpdateScore(int32 NewScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Arcade")
	void UpdateMultiplier(int32 NewMultiplier);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Arcade")
	void UpdateHealth(int32 CurrentHealth, int32 MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Arcade")
	void ShowGameOver(int32 FinalScore, int32 HighScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Arcade")
	void ShowPowerUpNotification(FString PowerUpName, float Duration);

protected:
	UPROPERTY()
	AArcadeRaceManager* ArcadeManager;

private:
	int32 LastScore = 0;
	int32 LastMultiplier = 1;
	int32 LastHealth = 3;
};
