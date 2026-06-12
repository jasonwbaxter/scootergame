// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadePowerUp.h"
#include "Arcade/ArcadeScooterPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AArcadePowerUp::AArcadePowerUp()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create collision box
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = CollisionBox;

	// Create visual mesh
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	// Setup collision
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AArcadePowerUp::OnOverlapBegin);
}

void AArcadePowerUp::BeginPlay()
{
	Super::BeginPlay();
}

void AArcadePowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateMesh(DeltaTime);
	DespawnIfBehindPlayer();
}

void AArcadePowerUp::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bHasBeenCollected)
	{
		AArcadeScooterPawn* ScooterPawn = Cast<AArcadeScooterPawn>(OtherActor);
		if (ScooterPawn)
		{
			bHasBeenCollected = true;

			// Apply power-up effect
			if (PowerUpType == EPowerUpType::SpeedRamp)
			{
				ScooterPawn->ActivateSpeedBoost(PowerUpDuration);
			}
			else if (PowerUpType == EPowerUpType::Invincibility)
			{
				ScooterPawn->ActivateInvincibility(PowerUpDuration);
			}

			// TODO: Increase score, play sound effect, spawn visual effect

			Destroy();
		}
	}
}

void AArcadePowerUp::RotateMesh(float DeltaTime)
{
	if (VisualMesh)
	{
		FRotator CurrentRotation = VisualMesh->GetRelativeRotation();
		CurrentRotation.Yaw += RotationSpeed * DeltaTime;
		VisualMesh->SetRelativeRotation(CurrentRotation);
	}
}

void AArcadePowerUp::DespawnIfBehindPlayer()
{
	// TODO: Check if power-up is behind player, then destroy
}
