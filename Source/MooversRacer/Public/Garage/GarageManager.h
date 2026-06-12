// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Customization/PartDefinition.h"
#include "GarageManager.generated.h"

class AScooterPawn;
class UGarageWidget;

/**
 * Manages garage UI, part selection, preview, and customization application.
 */
UCLASS()
class MOOVERSRACER_API AGarageManager : public AActor
{
	GENERATED_BODY()

public:
	AGarageManager();

	virtual void BeginPlay() override;

	// Garage UI control
	UFUNCTION(BlueprintCallable, Category = "Garage")
	void ShowGarage();

	UFUNCTION(BlueprintCallable, Category = "Garage")
	void HideGarage();

	UFUNCTION(BlueprintCallable, Category = "Garage")
	void SetActiveScooter(AScooterPawn* Scooter);

	// Part management
	UFUNCTION(BlueprintCallable, Category = "Garage")
	void EquipPart(const FPart& Part);

	UFUNCTION(BlueprintCallable, Category = "Garage")
	void UnequipPart(EPartType PartType);

	UFUNCTION(BlueprintCallable, Category = "Garage")
	void UpdatePreview();

	UFUNCTION(BlueprintCallable, Category = "Garage")
	void ApplyCustomization();

	// Getters
	UFUNCTION(BlueprintCallable, Category = "Garage")
	AScooterPawn* GetActiveScooter() const { return ActiveScooter; }

	UFUNCTION(BlueprintCallable, Category = "Garage")
	FScooterCustomization GetCurrentCustomization() const { return CurrentCustomization; }

	UFUNCTION(BlueprintCallable, Category = "Garage")
	TArray<FPart> GetAvailableParts(EPartType PartType) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Garage")
	TSubclassOf<UGarageWidget> GarageWidgetClass;

	UPROPERTY()
	AScooterPawn* ActiveScooter;

	UPROPERTY()
	UGarageWidget* GarageWidget;

private:
	FScooterCustomization CurrentCustomization;

	// Part database
	UPROPERTY()
	class UDataTable* PartDatabase;

	void LoadPartDatabase();
};
