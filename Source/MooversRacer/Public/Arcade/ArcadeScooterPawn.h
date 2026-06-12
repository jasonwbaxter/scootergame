// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ArcadeScooterPawn.generated.h"

class UArcadePhysicsComponent;
class USkeletalMeshComponent;
class UCameraComponent;

/**
 * Arcade-mode scooter pawn with lane-based movement.
 * Simplified controls: lane switching and speed management.
 */
UCLASS()
class MOOVERSRACER_API AArcadeScooterPawn : public APawn
{
	GENERATED_BODY()

public:
	AArcadeScooterPawn();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Lane management (0-3, left to right)
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ChangeLane(int32 LaneDirection); // -1 (left), +1 (right)

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetCurrentLane() const { return CurrentLane; }

	// Speed management
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void IncreaseSpeed();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void DecreaseSpeed();

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	float GetCurrentSpeed() const { return CurrentSpeed; }

	// Power-up states
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ActivateSpeedBoost(float Duration);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void ActivateInvincibility(float Duration);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	bool IsInvincible() const { return bInvincible; }

	// Collision / obstacle detection
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void OnObstacleHit();

	USkeletalMeshComponent* GetMeshComponent() const { return MeshComponent; }

protected:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	UArcadePhysicsComponent* ArcadePhysics;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	// Arcade parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float BaseSpeed = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float MaxSpeed = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float MinSpeed = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float LaneWidth = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float LaneSwitchDuration = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	int32 MaxLanes = 4;

private:
	// State
	int32 CurrentLane = 1; // 0-3
	float CurrentSpeed = 50.0f;
	float TargetLaneX = 0.0f;
	float CurrentLaneX = 0.0f;
	bool bInvincible = false;
	float InvincibilityTimeRemaining = 0.0f;
	float SpeedBoostTimeRemaining = 0.0f;
	float SpeedBoostMultiplier = 1.0f;

	// Input callbacks
	void MoveLeft();
	void MoveRight();
	void SpeedUp();
	void SlowDown();

	// Helper functions
	void UpdateLanePosition(float DeltaTime);
	void UpdateSpeed();
	void UpdatePowerUpStates(float DeltaTime);
};
