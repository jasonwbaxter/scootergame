// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "ScooterPawn.generated.h"

class UChaosVehicleMovementComponent;
class UScooterPhysicsComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

/**
 * Main scooter vehicle pawn. Handles input, physics, and customization visuals.
 */
UCLASS()
class MOOVERSRACER_API AScooterPawn : public APawn
{
	GENERATED_BODY()

public:
	AScooterPawn();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Accessors
	USkeletalMeshComponent* GetMeshComponent() const { return MeshComponent; }
	UScooterPhysicsComponent* GetPhysicsComponent() const { return PhysicsComponent; }

	// Customization
	UFUNCTION(BlueprintCallable, Category = "Scooter")
	void ApplyCustomization(const struct FScooterCustomization& Customization);

	UFUNCTION(BlueprintCallable, Category = "Scooter")
	void ResetToDefaultSetup();

protected:
	// Core components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scooter")
	USkeletalMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scooter")
	UChaosVehicleMovementComponent* VehicleMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scooter")
	UScooterPhysicsComponent* PhysicsComponent;

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	// Input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* TurboAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* ClutchAction;

	// Input callbacks
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void OnTurboPressed();
	void OnTurboReleased();
	void OnClutchPressed();
	void OnClutchReleased();

private:
	// Input state
	FVector CurrentInputDirection;
	bool bTurboActive = false;
	bool bClutchActive = false;
};
