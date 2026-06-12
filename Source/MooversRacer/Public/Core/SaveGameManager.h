// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Core/MooversRacerSaveGame.h"
#include "SaveGameManager.generated.h"

/**
 * Central save game management system.
 * Handles loading, saving, and player progression data.
 */
UCLASS()
class MOOVERSRACER_API USaveGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Save/Load
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	bool SaveGame(const FString& SlotName = TEXT("DefaultSave"));

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	bool LoadGame(const FString& SlotName = TEXT("DefaultSave"));

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	bool DeleteSave(const FString& SlotName = TEXT("DefaultSave"));

	// Accessors
	UFUNCTION(BlueprintPure, Category = "SaveGame")
	UMooversRacerSaveGame* GetCurrentSaveGame() const;

	UFUNCTION(BlueprintPure, Category = "SaveGame")
	bool HasSaveGame(const FString& SlotName = TEXT("DefaultSave")) const;

	// Player progress updates
	UFUNCTION(BlueprintCallable, Category = "Progress")
	void GrantXP(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Progress")
	void UnlockPart(const FString& PartID);

	UFUNCTION(BlueprintCallable, Category = "Progress")
	void UnlockCosmetic(const FString& CosmeticID);

	UFUNCTION(BlueprintCallable, Category = "Progress")
	void UpdateHighScore(int32 NewScore);

	UFUNCTION(BlueprintCallable, Category = "Progress")
	void UpdateBestLapTime(float NewTime);

protected:
	UPROPERTY()
	UMooversRacerSaveGame* CurrentSaveGame;

	const FString DefaultSlotName = TEXT("DefaultSave");
	const int32 UserIndex = 0;

	// Calculate level from XP
	int32 CalculateLevel(int32 TotalXP) const;

	// Get XP required for next level
	int32 GetXPForLevel(int32 Level) const;
};
