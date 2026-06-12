// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeObstacle.h"
#include "Arcade/ArcadeScooterPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AArcadeObstacle::AArcadeObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create collision box
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetBoxExtent(FVector(50.0f, 100.0f, 50.0f));
	RootComponent = CollisionBox;

	// Create visual mesh
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootComponent);

	// Setup collision
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AArcadeObstacle::OnOverlapBegin);
}

void AArcadeObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void AArcadeObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DespawnIfBehindPlayer();
}

void AArcadeObstacle::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bHasCollided)
	{
		AArcadeScooterPawn* ScooterPawn = Cast<AArcadeScooterPawn>(OtherActor);
		if (ScooterPawn)
		{
			bHasCollided = true;
			ScooterPawn->OnObstacleHit();
			
			// Destroy after collision
			Destroy();
		}
	}
}

void AArcadeObstacle::DespawnIfBehindPlayer()
{
	// TODO: Check if obstacle is behind player, then destroy
	// This will be implemented once we have player position tracking
}
