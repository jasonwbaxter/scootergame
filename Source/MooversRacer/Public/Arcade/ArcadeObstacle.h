// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadeObstacle.generated.h"

class AArcadeScooterPawn;

UENUM(BlueprintType)
enum class EObstacleType : uint8
{
	Pothole UMETA(DisplayName = "Pothole"),
	TrafficCone UMETA(DisplayName = "Traffic Cone")
};

/**
 * Obstacle actor that damages or blocks arcade scooter.
 * Spawned in lanes ahead of the player.
 */
UCLASS()
class MOOVERSRACER_API AArcadeObstacle : public AActor
{
	GENERATED_BODY()

public:
	AArcadeObstacle();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	EObstacleType GetObstacleType() const { return ObstacleType; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetLane() const { return LaneIndex; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void SetLane(int32 Lane) { LaneIndex = Lane; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcade")
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	EObstacleType ObstacleType = EObstacleType::Pothole;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	int32 Damage = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float DespawnDistance = -500.0f; // Despawn behind player

private:
	int32 LaneIndex = 0;
	bool bHasCollided = false;

	void DespawnIfBehindPlayer();
};
