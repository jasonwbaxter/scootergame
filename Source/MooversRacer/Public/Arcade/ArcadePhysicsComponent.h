// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ActorComponent.h"
#include "ArcadePhysicsComponent.generated.h"

/**
 * Simplified physics for arcade mode with health/hit tracking.
 */
UCLASS(ClassGroup = (Arcade), meta = (BlueprintSpawnableComponent))
class MOOVERSRACER_API UArcadePhysicsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UArcadePhysicsComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Health management
	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void TakeHit(int32 Damage = 1);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	void Heal(int32 Amount = 1);

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	int32 GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable, Category = "Arcade")
	bool IsAlive() const { return CurrentHealth > 0; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	int32 MaxHealth = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	bool bInvulnerableAfterHit = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arcade")
	float InvulnerabilityDuration = 1.0f;

private:
	int32 CurrentHealth = 3;
	float InvulnerabilityTimer = 0.0f;

	void UpdateInvulnerability(float DeltaTime);
};
