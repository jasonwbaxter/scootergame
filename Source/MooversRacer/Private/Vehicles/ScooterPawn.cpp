// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Vehicles/ScooterPawn.h"
#include "Vehicles/ScooterPhysicsComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Customization/PartDefinition.h"

AScooterPawn::AScooterPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.016f; // 60 FPS

	// Don't rotate character with camera
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create mesh component
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	// Create physics component
	PhysicsComponent = CreateDefaultSubobject<UScooterPhysicsComponent>(TEXT("PhysicsComponent"));

	// Create spring arm (rotates based on controller)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AScooterPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AScooterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AScooterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = 
		CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AScooterPawn::Move);
		}

		// Looking
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AScooterPawn::Look);
		}

		// Turbo
		if (TurboAction)
		{
			EnhancedInputComponent->BindAction(TurboAction, ETriggerEvent::Started, this, &AScooterPawn::OnTurboPressed);
			EnhancedInputComponent->BindAction(TurboAction, ETriggerEvent::Completed, this, &AScooterPawn::OnTurboReleased);
		}

		// Clutch
		if (ClutchAction)
		{
			EnhancedInputComponent->BindAction(ClutchAction, ETriggerEvent::Started, this, &AScooterPawn::OnClutchPressed);
			EnhancedInputComponent->BindAction(ClutchAction, ETriggerEvent::Completed, this, &AScooterPawn::OnClutchReleased);
		}
	}
}

void AScooterPawn::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// Find forward direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotm(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotm(YawRotation).GetUnitAxis(EAxis::Y);

		// Pass to physics component
		if (PhysicsComponent)
		{
			PhysicsComponent->SetThrottleInput(MovementVector.Y);
			PhysicsComponent->SetSteeringInput(MovementVector.X);
		}
	}
}

void AScooterPawn::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// Add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AScooterPawn::OnTurboPressed()
{
	bTurboActive = true;
	if (PhysicsComponent)
	{
		PhysicsComponent->ActivateTurbo();
	}
}

void AScooterPawn::OnTurboReleased()
{
	bTurboActive = false;
	if (PhysicsComponent)
	{
		PhysicsComponent->DeactivateTurbo();
	}
}

void AScooterPawn::OnClutchPressed()
{
	bClutchActive = true;
	if (PhysicsComponent)
	{
		PhysicsComponent->EngageClutch();
	}
}

void AScooterPawn::OnClutchReleased()
{
	bClutchActive = false;
	if (PhysicsComponent)
	{
		PhysicsComponent->ReleaseClutch();
	}
}

void AScooterPawn::ApplyCustomization(const FScooterCustomization& Customization)
{
	// Apply mesh materials and visual parts
	// This will be expanded to swap rims, exhausts, body panels, etc.
	if (PhysicsComponent)
	{
		PhysicsComponent->ApplyPerformanceParts(Customization);
	}
}

void AScooterPawn::ResetToDefaultSetup()
{
	// Reset to stock configuration
	if (PhysicsComponent)
	{
		PhysicsComponent->ResetToDefaults();
	}
}
