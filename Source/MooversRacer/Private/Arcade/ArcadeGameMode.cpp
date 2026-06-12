// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeGameMode.h"
#include "Arcade/ArcadeRaceManager.h"
#include "Arcade/ArcadeScooterPawn.h"
#include "Arcade/ArcadeHUD.h"

AArcadeGameMode::AArcadeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS

	// Use arcade scooter as default pawn
	DefaultPawnClass = ArcadeScooterClass;
}

void AArcadeGameMode::BeginPlay()
{
	Super::BeginPlay();

	InitializeArcade();
}

void AArcadeGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AArcadeGameMode::StartArcadeGame()
{
	if (ArcadeManager)
	{
		ArcadeManager->StartGame();
	}
}

void AArcadeGameMode::EndArcadeGame()
{
	if (ArcadeManager)
	{
		ArcadeManager->EndGame();
	}
}

void AArcadeGameMode::PauseArcadeGame()
{
	if (ArcadeManager)
	{
		ArcadeManager->PauseGame();
	}
}

void AArcadeGameMode::ResumeArcadeGame()
{
	if (ArcadeManager)
	{
		ArcadeManager->ResumeGame();
	}
}

void AArcadeGameMode::InitializeArcade()
{
	// Spawn arcade manager
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ArcadeManager = GetWorld()->SpawnActor<AArcadeRaceManager>(SpawnParams);

	// Get player scooter
	for (TActorIterator<AArcadeScooterPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PlayerScooter = *ActorItr;
		break;
	}

	// Create and show arcade HUD
	if (ArcadeHUDClass)
	{
		ArcadeHUD = CreateWidget<UArcadeHUD>(GetWorld()->GetFirstPlayerController(), ArcadeHUDClass);
		if (ArcadeHUD)
		{
			ArcadeHUD->AddToViewport();
			ArcadeHUD->SetArcadeManager(ArcadeManager);
		}
	}
}
