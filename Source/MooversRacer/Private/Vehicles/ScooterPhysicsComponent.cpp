// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Vehicles/ScooterPhysicsComponent.h"

UScooterPhysicsComponent::UScooterPhysicsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.016f; // 60 FPS
}

void UScooterPhysicsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UScooterPhysicsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateMovement(DeltaTime);
	UpdateTurboState(DeltaTime);
}

void UScooterPhysicsComponent::SetThrottleInput(float Value)
{
	ThrottleInput = FMath::Clamp(Value, -1.0f, 1.0f);
}

void UScooterPhysicsComponent::SetSteeringInput(float Value)
{
	SteeringInput = FMath::Clamp(Value, -1.0f, 1.0f);
}

void UScooterPhysicsComponent::EngageClutch()
{
	bClutchEngaged = true;
}

void UScooterPhysicsComponent::ReleaseClutch()
{
	bClutchEngaged = false;
}

void UScooterPhysicsComponent::ActivateTurbo()
{
	if (TurboCooldownRemaining <= 0.0f)
	{
		bTurboActive = true;
		TurboTimeRemaining = TurboDuration;
	}
}

void UScooterPhysicsComponent::DeactivateTurbo()
{
	bTurboActive = false;
}

void UScooterPhysicsComponent::ApplyPerformanceParts(const FScooterCustomization& Customization)
{
	// Apply modifiers from performance parts
	EnginePowerMultiplier = Customization.EnginePowerMultiplier;
	HandlelingMultiplier = Customization.HandlelingMultiplier;
	WeightMultiplier = Customization.WeightMultiplier;
}

void UScooterPhysicsComponent::ResetToDefaults()
{
	WeightMultiplier = 1.0f;
	EnginePowerMultiplier = 1.0f;
	HandlelingMultiplier = 1.0f;
}

void UScooterPhysicsComponent::UpdateMovement(float DeltaTime)
{
	if (!GetOwner()) return;

	// Calculate effective max speed with turbo
	float EffectiveMaxSpeed = MaxSpeed * EnginePowerMultiplier;
	if (bTurboActive)
	{
		EffectiveMaxSpeed *= TurboMultiplier;
	}

	// Update speed based on throttle input
	if (ThrottleInput > 0.0f)
	{
		CurrentSpeed = FMath::Min(CurrentSpeed + Acceleration * EnginePowerMultiplier * ThrottleInput * DeltaTime, EffectiveMaxSpeed);
	}
	else if (ThrottleInput < 0.0f)
	{
		CurrentSpeed = FMath::Max(CurrentSpeed - Acceleration * ThrottleInput * DeltaTime, -EffectiveMaxSpeed * 0.5f);
	}
	else
	{
		// Passive deceleration
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, 0.0f, DeltaTime, Deceleration);
	}

	// Update RPM
	CurrentRPM = (CurrentSpeed / EffectiveMaxSpeed) * 7000.0f; // Approximate RPM

	// Apply movement to owner
	if (AActor* Owner = GetOwner())
	{
		FVector ForwardDir = Owner->GetActorForwardVector();
		FVector NewLocation = Owner->GetActorLocation() + ForwardDir * CurrentSpeed * DeltaTime;

		// Apply steering rotation
		FRotator CurrentRotation = Owner->GetActorRotation();
		float TurnAmount = SteeringInput * HandlelingMultiplier * (1.0f - FMath::Abs(DriftFactor * (CurrentSpeed / EffectiveMaxSpeed)));
		FRotator NewRotation = CurrentRotation + FRotator(0.0f, TurnAmount * DeltaTime * 180.0f, 0.0f);

		Owner->SetActorLocation(NewLocation);
		Owner->SetActorRotation(NewRotation);
	}
}

void UScooterPhysicsComponent::UpdateTurboState(float DeltaTime)
{
	if (bTurboActive)
	{
		TurboTimeRemaining -= DeltaTime;
		if (TurboTimeRemaining <= 0.0f)
		{
			bTurboActive = false;
			TurboCooldownRemaining = TurboCooldown;
		}
	}

	if (TurboCooldownRemaining > 0.0f)
	{
		TurboCooldownRemaining -= DeltaTime;
	}
}
