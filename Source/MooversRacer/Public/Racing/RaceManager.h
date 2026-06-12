// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceManager.generated.h"

class AScooterPawn;

UENUM(BlueprintType)
enum class ERaceState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	CountDown UMETA(DisplayName = "Count Down"),
	Racing UMETA(DisplayName = "Racing"),
	Finished UMETA(DisplayName = "Finished"),
	Paused UMETA(DisplayName = "Paused")
};

/**
 * Manages race state, lap timing, checkpoints, and race completion.
 */
UCLASS()
class MOOVERSRACER_API ARaceManager : public AActor
{
	GENERATED_BODY()

public:
	ARaceManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Race control
	UFUNCTION(BlueprintCallable, Category = "Race")
	void InitializeRace();

	UFUNCTION(BlueprintCallable, Category = "Race")
	void StartRace();

	UFUNCTION(BlueprintCallable, Category = "Race")
	void EndRace();

	UFUNCTION(BlueprintCallable, Category = "Race")
	void PauseRace();

	UFUNCTION(BlueprintCallable, Category = "Race")
	void ResumeRace();

	// Getters
	UFUNCTION(BlueprintCallable, Category = "Race")
	ERaceState GetRaceState() const { return CurrentRaceState; }

	UFUNCTION(BlueprintCallable, Category = "Race")
	float GetRaceTime() const { return RaceTime; }

	UFUNCTION(BlueprintCallable, Category = "Race")
	int32 GetLapCount() const { return CurrentLap; }

	UFUNCTION(BlueprintCallable, Category = "Race")
	float GetBestLapTime() const { return BestLapTime; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race")
	float RaceDuration = 180.0f; // 3 minutes for vertical slice

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race")
	int32 TotalLaps = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race")
	float CountDownDuration = 3.0f;

	// Player scooter reference
	UPROPERTY()
	AScooterPawn* PlayerScooter;

private:
	ERaceState CurrentRaceState = ERaceState::Idle;
	float RaceTime = 0.0f;
	float CountDownTime = 0.0f;
	int32 CurrentLap = 0;
	float CurrentLapTime = 0.0f;
	float BestLapTime = 9999.0f;

	void UpdateRaceState(float DeltaTime);
	void UpdateLapTiming();
};
