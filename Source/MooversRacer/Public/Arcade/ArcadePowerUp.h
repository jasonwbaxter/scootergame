// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadePowerUp.generated.h"

class AArcadeScooterPawn;

UENUM(BlueprintType)
enum class EPowerUpType : uint8
{
	SpeedRamp UMETA(DisplayName = "Speed Ramp"),
	Invincibility UMETA(DisplayName = "Invincibility (Skull & Crossbones)")
};

/**
 * Power-up pickup actor for arcade mode.
 */
UCLASS()
class MOOVERSRACER_API AArcadePowerUp : public AActor
{
	GENERATED_BODY()

public:
	AArcadePowerUp();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	EPowerUpType GetPowerUpType() const { return PowerUpType; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetLane() const { return LaneIndex; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void SetLane(int32 Lane) { LaneIndex = Lane; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void RotateMesh(float DeltaTime);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	EPowerUpType PowerUpType = EPowerUpType::SpeedRamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float PowerUpDuration = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	int32 ScoreReward = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float RotationSpeed = 180.0f; // degrees per second

private:
	int32 LaneIndex = 0;
	bool bHasBeenCollected = false;

	void DespawnIfBehindPlayer();
};
