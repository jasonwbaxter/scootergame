// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeRaceManager.h"
#include "Arcade/ArcadeScooterPawn.h"
#include "Arcade/ArcadeObstacle.h"
#include "Arcade/ArcadePowerUp.h"

AArcadeRaceManager::AArcadeRaceManager()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS
}

void AArcadeRaceManager::BeginPlay()
{
	Super::BeginPlay();

	// Find player scooter
	for (TActorIterator<AArcadeScooterPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PlayerScooter = *ActorItr;
		break;
	}

	// Load high score from save (TODO: Implement save system)
	HighScore = 0;
}

void AArcadeRaceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateGameState(DeltaTime);
	CheckGameOver();
}

void AArcadeRaceManager::StartGame()
{
	CurrentGameState = EArcadeGameState::Playing;
	CurrentScore = 0;
	ScoreMultiplier = 1;
	ElapsedTime = 0.0f;
	TimeSinceLastObstacle = 0.0f;
	CurrentObstacleSpawnRate = ObstacleSpawnRate;
}

void AArcadeRaceManager::EndGame()
{
	CurrentGameState = EArcadeGameState::GameOver;

	// Update high score
	if (CurrentScore > HighScore)
	{
		HighScore = CurrentScore;
		// TODO: Save high score
	}
}

void AArcadeRaceManager::PauseGame()
{
	if (CurrentGameState == EArcadeGameState::Playing)
	{
		CurrentGameState = EArcadeGameState::Paused;
		GetWorld()->GetFirstPlayerController()->SetPause(true);
	}
}

void AArcadeRaceManager::ResumeGame()
{
	if (CurrentGameState == EArcadeGameState::Paused)
	{
		CurrentGameState = EArcadeGameState::Playing;
		GetWorld()->GetFirstPlayerController()->SetPause(false);
	}
}

void AArcadeRaceManager::AddScore(int32 Points)
{
	CurrentScore += Points * ScoreMultiplier;
}

void AArcadeRaceManager::IncreaseMultiplier()
{
	ScoreMultiplier = FMath::Min(ScoreMultiplier + 1, 10); // Cap at 10x
}

void AArcadeRaceManager::ResetMultiplier()
{
	ScoreMultiplier = 1;
}

void AArcadeRaceManager::SpawnObstacle()
{
	if (!ObstacleClass) return;

	// Random lane
	int32 RandomLane = FMath::RandRange(0, 3);
	FVector LaneOffset(0.0f, (RandomLane - 1.5f) * LaneWidth, 0.0f);
	FVector SpawnPos = SpawnLocation + LaneOffset;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AArcadeObstacle* NewObstacle = GetWorld()->SpawnActor<AArcadeObstacle>(ObstacleClass, SpawnPos, FRotator::ZeroRotator, SpawnParams);
	if (NewObstacle)
	{
		NewObstacle->SetLane(RandomLane);
	}
}

void AArcadeRaceManager::SpawnPowerUp()
{
	if (!PowerUpClass) return;

	// Random lane
	int32 RandomLane = FMath::RandRange(0, 3);
	FVector LaneOffset(0.0f, (RandomLane - 1.5f) * LaneWidth, 0.0f);
	FVector SpawnPos = SpawnLocation + LaneOffset;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AArcadePowerUp* NewPowerUp = GetWorld()->SpawnActor<AArcadePowerUp>(PowerUpClass, SpawnPos, FRotator::ZeroRotator, SpawnParams);
	if (NewPowerUp)
	{
		NewPowerUp->SetLane(RandomLane);
	}
}

void AArcadeRaceManager::UpdateGameState(float DeltaTime)
{
	if (CurrentGameState != EArcadeGameState::Playing)
	{
		return;
	}

	ElapsedTime += DeltaTime;
	TimeSinceLastObstacle += DeltaTime;

	// Spawn obstacles/power-ups
	if (TimeSinceLastObstacle >= CurrentObstacleSpawnRate)
	{
		TimeSinceLastObstacle = 0.0f;

		// Determine if power-up or obstacle
		if (FMath::FRand() < PowerUpSpawnRate)
		{
			SpawnPowerUp();
		}
		else
		{
			SpawnObstacle();
		}
	}

	UpdateDifficulty();
}

void AArcadeRaceManager::UpdateDifficulty()
{
	// Increase spawn rate over time
	int32 DifficultyLevel = static_cast<int32>(ElapsedTime / DifficultyRampTime);
	CurrentObstacleSpawnRate = FMath::Max(ObstacleSpawnRate - (DifficultyLevel * 0.2f), 0.5f);
}

void AArcadeRaceManager::CheckGameOver()
{
	if (CurrentGameState != EArcadeGameState::Playing)
	{
		return;
	}

	if (PlayerScooter && !PlayerScooter->GetWorld()->FindFirstPlayerController()->IsValid())
	{
		EndGame();
	}

	// Check if player health is 0
	// (This will be implemented once we connect arcade physics)
}
