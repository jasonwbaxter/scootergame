// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Core/MooversRacerGameMode.h"
#include "Racing/RaceManager.h"
#include "Garage/GarageManager.h"
#include "Audio/AudioManager.h"

AMooversRacerGameMode::AMooversRacerGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS
}

void AMooversRacerGameMode::BeginPlay()
{
	Super::BeginPlay();
	InitializeManagers();
}

void AMooversRacerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMooversRacerGameMode::StartRace()
{
	CurrentGameMode = EGameMode::Racing;
	if (RaceManager)
	{
		RaceManager->InitializeRace();
	}
}

void AMooversRacerGameMode::StartArcadeMode()
{
	CurrentGameMode = EGameMode::Arcade;
	// Arcade mode will be handled by its own game mode
	// Transition can be implemented via level change or blueprint
}

void AMooversRacerGameMode::ExitToGarage()
{
	CurrentGameMode = EGameMode::Garage;
	if (RaceManager)
	{
		RaceManager->EndRace();
	}
	if (GarageManager)
	{
		GarageManager->ShowGarage();
	}
}

void AMooversRacerGameMode::EndRace()
{
	if (RaceManager)
	{
		RaceManager->EndRace();
	}
}

void AMooversRacerGameMode::InitializeManagers()
{
	// Spawn RaceManager
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	RaceManager = GetWorld()->SpawnActor<ARaceManager>(SpawnParams);
	GarageManager = GetWorld()->SpawnActor<AGarageManager>(SpawnParams);
	AudioManager = GetWorld()->SpawnActor<AAudioManager>(SpawnParams);
}
