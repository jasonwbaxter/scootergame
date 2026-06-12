// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeScooterPawn.h"
#include "Arcade/ArcadePhysicsComponent.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AArcadeScooterPawn::AArcadeScooterPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS

	// Create mesh component
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Create arcade physics component
	ArcadePhysics = CreateDefaultSubobject<UArcadePhysicsComponent>(TEXT("ArcadePhysics"));

	// Create camera (top-down isometric-ish view)
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(RootComponent);
	FollowCamera->SetRelativeLocation(FVector(-300.0f, 0.0f, 400.0f));
	FollowCamera->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));

	// Initialize lane position
	CurrentLane = 1;
	TargetLaneX = 0.0f;
	CurrentLaneX = 0.0f;
}

void AArcadeScooterPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			// Map inputs for arcade mode
		}
	}

	// Initial speed
	CurrentSpeed = BaseSpeed;
}

void AArcadeScooterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLanePosition(DeltaTime);
	UpdateSpeed();
	UpdatePowerUpStates(DeltaTime);

	// Move scooter forward automatically
	FVector NewLocation = GetActorLocation() + GetActorForwardVector() * CurrentSpeed * DeltaTime;
	SetActorLocation(NewLocation);
}

void AArcadeScooterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent =
		CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Left/Right arrows for lane change
		EnhancedInputComponent->BindAction(nullptr, ETriggerEvent::Started, this, &AArcadeScooterPawn::MoveLeft);
		EnhancedInputComponent->BindAction(nullptr, ETriggerEvent::Started, this, &AArcadeScooterPawn::MoveRight);

		// A/B buttons for speed
		EnhancedInputComponent->BindAction(nullptr, ETriggerEvent::Triggered, this, &AArcadeScooterPawn::SpeedUp);
		EnhancedInputComponent->BindAction(nullptr, ETriggerEvent::Triggered, this, &AArcadeScooterPawn::SlowDown);
	}
}

void AArcadeScooterPawn::ChangeLane(int32 LaneDirection)
{
	int32 TargetLane = CurrentLane + LaneDirection;

	// Clamp to valid lanes (0-3)
	if (TargetLane >= 0 && TargetLane < MaxLanes)
	{
		CurrentLane = TargetLane;
		// Calculate X position based on lane
		TargetLaneX = (CurrentLane - 1.5f) * LaneWidth;
	}
}

void AArcadeScooterPawn::IncreaseSpeed()
{
	CurrentSpeed = FMath::Min(CurrentSpeed + 5.0f, MaxSpeed);
}

void AArcadeScooterPawn::DecreaseSpeed()
{
	CurrentSpeed = FMath::Max(CurrentSpeed - 5.0f, MinSpeed);
}

void AArcadeScooterPawn::ActivateSpeedBoost(float Duration)
{
	SpeedBoostTimeRemaining = Duration;
	SpeedBoostMultiplier = 1.5f;
}

void AArcadeScooterPawn::ActivateInvincibility(float Duration)
{
	bInvincible = true;
	InvincibilityTimeRemaining = Duration;
}

void AArcadeScooterPawn::OnObstacleHit()
{
	if (!bInvincible)
	{
		// Collision detected - lose health or score
		if (ArcadePhysics)
		{
			ArcadePhysics->TakeHit();
		}
	}
}

void AArcadeScooterPawn::MoveLeft()
{
	ChangeLane(-1);
}

void AArcadeScooterPawn::MoveRight()
{
	ChangeLane(1);
}

void AArcadeScooterPawn::SpeedUp()
{
	IncreaseSpeed();
}

void AArcadeScooterPawn::SlowDown()
{
	DecreaseSpeed();
}

void AArcadeScooterPawn::UpdateLanePosition(float DeltaTime)
{
	// Smoothly interpolate lane position
	CurrentLaneX = FMath::FInterpTo(CurrentLaneX, TargetLaneX, DeltaTime, 10.0f);

	FVector CurrentLoc = GetActorLocation();
	CurrentLoc.Y = CurrentLaneX;
	SetActorLocation(CurrentLoc);
}

void AArcadeScooterPawn::UpdateSpeed()
{
	// Apply speed boost multiplier if active
	if (SpeedBoostTimeRemaining > 0.0f)
	{
		// Speed boost is applied to CurrentSpeed
	}
}

void AArcadeScooterPawn::UpdatePowerUpStates(float DeltaTime)
{
	// Update invincibility timer
	if (bInvincible)
	{
		InvincibilityTimeRemaining -= DeltaTime;
		if (InvincibilityTimeRemaining <= 0.0f)
		{
			bInvincible = false;
		}
	}

	// Update speed boost timer
	if (SpeedBoostTimeRemaining > 0.0f)
	{
		SpeedBoostTimeRemaining -= DeltaTime;
		if (SpeedBoostTimeRemaining <= 0.0f)
		{
			SpeedBoostMultiplier = 1.0f;
		}
	}
}
