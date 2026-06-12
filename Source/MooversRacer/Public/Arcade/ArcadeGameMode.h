// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcadeGameMode.generated.h"

class AArcadeRaceManager;
class AArcadeScooterPawn;
class UArcadeHUD;

/**
 * Game mode for arcade 4-lane racing.
 * Handles arcade-specific initialization, spawning, and state management.
 */
UCLASS()
class MOOVERSRACER_API AArcadeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArcadeGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void StartArcadeGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void EndArcadeGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void PauseArcadeGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ResumeArcadeGame();

	// Accessors
	AArcadeRaceManager* GetArcadeManager() const { return ArcadeManager; }
	AArcadeScooterPawn* GetPlayerScooter() const { return PlayerScooter; }

protected:
	UPROPERTY()
	AArcadeRaceManager* ArcadeManager;

	UPROPERTY()
	AArcadeScooterPawn* PlayerScooter;

	UPROPERTY()
	UArcadeHUD* ArcadeHUD;

	// Player pawn class for arcade
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arcade")
	TSubclassOf<AArcadeScooterPawn> ArcadeScooterClass;

	// HUD widget class
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arcade")
	TSubclassOf<UArcadeHUD> ArcadeHUDClass;

private:
	void InitializeArcade();
};
