// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadeRaceManager.generated.h"

class AArcadeScooterPawn;
class AArcadeObstacle;
class AArcadePowerUp;

UENUM(BlueprintType)
enum class EArcadeGameState : uint8
{
	MainMenu UMETA(DisplayName = "Main Menu"),
	Playing UMETA(DisplayName = "Playing"),
	GameOver UMETA(DisplayName = "Game Over"),
	Paused UMETA(DisplayName = "Paused")
};

/**
 * Manages arcade race state, score, obstacle spawning, and power-up distribution.
 */
UCLASS()
class MOOVERSRACER_API AArcadeRaceManager : public AActor
{
	GENERATED_BODY()

public:
	AArcadeRaceManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Game control
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void EndGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void PauseGame();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ResumeGame();

	// Getters
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	EArcadeGameState GetGameState() const { return CurrentGameState; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetScore() const { return CurrentScore; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetMultiplier() const { return ScoreMultiplier; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	float GetElapsedTime() const { return ElapsedTime; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetHighScore() const { return HighScore; }

	// Score management
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void AddScore(int32 Points);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void IncreaseMultiplier();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ResetMultiplier();

	// Spawning
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void SpawnObstacle();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void SpawnPowerUp();

protected:
	// Game parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float ObstacleSpawnRate = 2.0f; // Spawn every 2 seconds

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float PowerUpSpawnRate = 0.3f; // 30% chance of power-up instead of obstacle

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	int32 BaseScore = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float DifficultyRampTime = 30.0f; // Increase difficulty every 30 seconds

	// References
	UPROPERTY()
	AArcadeScooterPawn* PlayerScooter;

	// Spawning
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	TSubclassOf<AArcadeObstacle> ObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	TSubclassOf<AArcadePowerUp> PowerUpClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	FVector SpawnLocation = FVector(5000.0f, 0.0f, 100.0f); // Ahead of player

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float LaneWidth = 200.0f;

private:
	EArcadeGameState CurrentGameState = EArcadeGameState::MainMenu;
	int32 CurrentScore = 0;
	int32 HighScore = 0;
	int32 ScoreMultiplier = 1;
	float ElapsedTime = 0.0f;
	float TimeSinceLastObstacle = 0.0f;
	float CurrentObstacleSpawnRate = 2.0f;

	void UpdateGameState(float DeltaTime);
	void UpdateDifficulty();
	void CheckGameOver();
};
