// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeGameMode.h"
#include "Arcade/ArcadeRaceManager.h"
#include "Arcade/ArcadeScooterPawn.h"
#include "Arcade/ArcadeHUD.h"

AArcadeGameMode::AArcadeGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS

	// Note: DefaultPawnClass should be set in Blueprint or Editor using EditDefaultsOnly property
	// Don't set it here as ArcadeScooterClass will not be initialized yet
	// DefaultPawnClass = ArcadeScooterClass;
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
	
	// Validate manager was created
	if (!ArcadeManager)
	{
		UE_LOG(LogTemp, Error, TEXT("AArcadeGameMode: Failed to spawn ArcadeManager!"));
		return;
	}

	// Get player scooter
	for (TActorIterator<AArcadeScooterPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		PlayerScooter = *ActorItr;
		break;
	}
	
	if (!PlayerScooter)
	{
		UE_LOG(LogTemp, Warning, TEXT("AArcadeGameMode: No player scooter found in level!"));
	}

	// Create and show arcade HUD
	if (ArcadeHUDClass)
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			ArcadeHUD = CreateWidget<UArcadeHUD>(PlayerController, ArcadeHUDClass);
			if (ArcadeHUD)
			{
				ArcadeHUD->AddToViewport();
				if (ArcadeManager)
				{
					ArcadeHUD->SetArcadeManager(ArcadeManager);
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("AArcadeGameMode: Failed to create ArcadeHUD widget!"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AArcadeGameMode: No player controller found!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AArcadeGameMode: ArcadeHUDClass not set in editor!"));
	}
}
