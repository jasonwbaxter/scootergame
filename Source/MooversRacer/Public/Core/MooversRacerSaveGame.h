// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Customization/PartDefinition.h"
#include "MooversRacerSaveGame.generated.h"

/**
 * Player progress and save data.
 */
USTRUCT(BlueprintType)
struct FPlayerProgressData
{
	GENERATED_BODY()

	UPROPERTY()
	int32 PlayerLevel = 1;

	UPROPERTY()
	int32 TotalXP = 0;

	UPROPERTY()
	TArray<FString> UnlockedParts;

	UPROPERTY()
	TArray<FString> UnlockedCosmetics;

	UPROPERTY()
	FString CurrentScooterModel;

	UPROPERTY()
	int32 ArcadeHighScore = 0;

	UPROPERTY()
	float BestLapTime = 999999.0f;
};

/**
 * Save game data structure.
 */
UCLASS()
class MOOVERSRACER_API UMooversRacerSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	FPlayerProgressData ProgressData;

	UPROPERTY()
	float MasterVolume = 0.8f;

	UPROPERTY()
	float MusicVolume = 0.7f;

	UPROPERTY()
	float SFXVolume = 0.9f;

	UPROPERTY()
	FString QualityPreset = TEXT("High");

	UPROPERTY()
	bool bHapticsEnabled = true;

	UPROPERTY()
	FString ColorblindMode = TEXT("None");

	// Metadata
	UPROPERTY()
	FDateTime LastSaveTime;

	UPROPERTY()
	int32 PlaySessionCount = 0;
};
