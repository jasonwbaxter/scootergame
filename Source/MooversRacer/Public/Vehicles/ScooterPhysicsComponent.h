// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Customization/PartDefinition.h"
#include "ScooterPhysicsComponent.generated.h"

/**
 * Custom physics component for semi-realistic scooter handling.
 * Implements weight transfer, drift mechanics, clutch engagement, and turbo boost.
 */
UCLASS(ClassGroup = (Scooter), meta = (BlueprintSpawnableComponent))
class MOOVERSRACER_API UScooterPhysicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UScooterPhysicsComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Input handlers
	void SetThrottleInput(float Value);
	void SetSteeringInput(float Value);
	void EngageClutch();
	void ReleaseClutch();
	void ActivateTurbo();
	void DeactivateTurbo();

	// Customization
	void ApplyPerformanceParts(const FScooterCustomization& Customization);
	void ResetToDefaults();

	// Getters
	UFUNCTION(BlueprintCallable, Category = "Physics")
	float GetCurrentSpeed() const { return CurrentSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Physics")
	float GetCurrentRPM() const { return CurrentRPM; }

	UFUNCTION(BlueprintCallable, Category = "Physics")
	bool IsClutchEngaged() const { return bClutchEngaged; }

	UFUNCTION(BlueprintCallable, Category = "Physics")
	bool IsTurboing() const { return bTurboActive; }

protected:
	// Base physics stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float MaxSpeed = 120.0f; // km/h equivalent

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float Acceleration = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float Deceleration = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float TurnRadiusMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	float DriftFactor = 0.8f;

	// Turbo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turbo")
	float TurboMultiplier = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turbo")
	float TurboDuration = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turbo")
	float TurboCooldown = 5.0f;

	// Clutch
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clutch")
	float ClutchEngagementTime = 0.5f;

	// Customization multipliers
	float WeightMultiplier = 1.0f;
	float EnginePowerMultiplier = 1.0f;
	float HandlelingMultiplier = 1.0f;

private:
	// Current state
	float CurrentSpeed = 0.0f;
	float CurrentRPM = 0.0f;
	float ThrottleInput = 0.0f;
	float SteeringInput = 0.0f;
	bool bClutchEngaged = false;
	bool bTurboActive = false;
	float TurboTimeRemaining = 0.0f;
	float TurboCooldownRemaining = 0.0f;

	// Helper
	void UpdateMovement(float DeltaTime);
	void UpdateTurboState(float DeltaTime);
};
