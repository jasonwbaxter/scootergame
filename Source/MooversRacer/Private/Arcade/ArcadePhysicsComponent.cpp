// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadePhysicsComponent.h"

UArcadePhysicsComponent::UArcadePhysicsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.016f; // 60 FPS

	CurrentHealth = MaxHealth;
}

void UArcadePhysicsComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UArcadePhysicsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateInvulnerability(DeltaTime);
}

void UArcadePhysicsComponent::TakeHit(int32 Damage)
{
	if (InvulnerabilityTimer <= 0.0f)
	{
		CurrentHealth -= Damage;
		if (CurrentHealth < 0)
		{
			CurrentHealth = 0;
		}

		if (bInvulnerableAfterHit)
		{
			InvulnerabilityTimer = InvulnerabilityDuration;
		}

		// TODO: Trigger visual feedback (screen shake, flash, etc.)
	}
}

void UArcadePhysicsComponent::Heal(int32 Amount)
{
	CurrentHealth = FMath::Min(CurrentHealth + Amount, MaxHealth);
}

void UArcadePhysicsComponent::UpdateInvulnerability(float DeltaTime)
{
	if (InvulnerabilityTimer > 0.0f)
	{
		InvulnerabilityTimer -= DeltaTime;
	}
}
