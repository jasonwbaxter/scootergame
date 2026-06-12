// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Racing/RaceManager.h"
#include "Vehicles/ScooterPawn.h"

ARaceManager::ARaceManager()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS
}

void ARaceManager::BeginPlay()
{
	Super::BeginPlay();

	// Find player scooter
	for (TActorIterator<AScooterPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PlayerScooter = *ActorItr;
		break;
	}
}

void ARaceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateRaceState(DeltaTime);
}

void ARaceManager::InitializeRace()
{
	CurrentRaceState = ERaceState::CountDown;
	CountDownTime = CountDownDuration;
	RaceTime = 0.0f;
	CurrentLap = 1;
	CurrentLapTime = 0.0f;
}

void ARaceManager::StartRace()
{
	if (CurrentRaceState == ERaceState::CountDown && CountDownTime <= 0.0f)
	{
		CurrentRaceState = ERaceState::Racing;
	}
}

void ARaceManager::EndRace()
{
	CurrentRaceState = ERaceState::Finished;
}

void ARaceManager::PauseRace()
{
	if (CurrentRaceState == ERaceState::Racing)
	{
		CurrentRaceState = ERaceState::Paused;
	}
}

void ARaceManager::ResumeRace()
{
	if (CurrentRaceState == ERaceState::Paused)
	{
		CurrentRaceState = ERaceState::Racing;
	}
}

void ARaceManager::UpdateRaceState(float DeltaTime)
{
	switch (CurrentRaceState)
	{
		case ERaceState::CountDown:
			CountDownTime -= DeltaTime;
			if (CountDownTime <= 0.0f)
			{
				StartRace();
			}
			break;

		case ERaceState::Racing:
			RaceTime += DeltaTime;
			CurrentLapTime += DeltaTime;

			// Check if race duration exceeded
			if (RaceTime >= RaceDuration)
			{
				EndRace();
			}
			break;

		case ERaceState::Finished:
			// Race over
			break;

		case ERaceState::Paused:
			// Time frozen
			break;

		default:
			break;
	}

	UpdateLapTiming();
}

void ARaceManager::UpdateLapTiming()
{
	// TODO: Implement lap crossing detection with checkpoint system
	// For now, track elapsed time
	if (CurrentRaceState == ERaceState::Racing)
	{
		if (CurrentLapTime > 60.0f) // Assume 60-second lap for vertical slice
		{
			if (CurrentLapTime - DeltaTime <= 60.0f)
			{
				BestLapTime = FMath::Min(BestLapTime, 60.0f);
				CurrentLap++;
				CurrentLapTime = 0.0f;
			}
		}
	}
}
