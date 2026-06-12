// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MooversRacerGameMode.generated.h"

class ARaceManager;
class AGarageManager;
class AAudioManager;

/**
 * Main game mode for Moovers Racer vertical slice.
 * Manages transitions between race, garage, and arcade modes.
 */

UENUM(BlueprintType)
enum class EGameMode : uint8
{
	MainMenu UMETA(DisplayName = "Main Menu"),
	Racing UMETA(DisplayName = "Racing"),
	Arcade UMETA(DisplayName = "Arcade"),
	Garage UMETA(DisplayName = "Garage")
};

UCLASS()
class MOOVERSRACER_API AMooversRacerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMooversRacerGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Game state transitions
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void StartRace();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void StartArcadeMode();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void ExitToGarage();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void EndRace();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
	EGameMode GetCurrentGameMode() const { return CurrentGameMode; }

	// Accessors
	ARaceManager* GetRaceManager() const { return RaceManager; }
	AGarageManager* GetGarageManager() const { return GarageManager; }
	AAudioManager* GetAudioManager() const { return AudioManager; }

protected:
	UPROPERTY()
	ARaceManager* RaceManager;

	UPROPERTY()
	AGarageManager* GarageManager;

	UPROPERTY()
	AAudioManager* AudioManager;

	UPROPERTY()
	class AArcadeGameMode* ArcadeGameMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GameMode")
	TSubclassOf<class AArcadeGameMode> ArcadeGameModeClass;

private:
	EGameMode CurrentGameMode = EGameMode::MainMenu;

	void InitializeManagers();
};
