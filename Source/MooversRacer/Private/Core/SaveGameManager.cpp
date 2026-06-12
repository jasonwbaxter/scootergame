// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Core/SaveGameManager.h"
#include "Kismet/GameplayStatics.h"

void USaveGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Try to load existing save game
	if (!LoadGame(DefaultSlotName))
	{
		// Create new save game if none exists
		CurrentSaveGame = NewObject<UMooversRacerSaveGame>();
		CurrentSaveGame->PlayerName = TEXT("Player");
		CurrentSaveGame->LastSaveTime = FDateTime::Now();
		SaveGame(DefaultSlotName);

		UE_LOG(LogTemp, Warning, TEXT("Created new save game"));
	}
}

bool USaveGameManager::SaveGame(const FString& SlotName)
{
	if (!CurrentSaveGame)
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameManager::SaveGame - No save game loaded"));
		return false;
	}

	CurrentSaveGame->LastSaveTime = FDateTime::Now();

	bool bSaved = UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SlotName, UserIndex);

	if (bSaved)
	{
		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::SaveGame - Saved to slot: %s"), *SlotName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameManager::SaveGame - Failed to save to slot: %s"), *SlotName);
	}

	return bSaved;
}

bool USaveGameManager::LoadGame(const FString& SlotName)
{
	if (!UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::LoadGame - No save game exists at slot: %s"), *SlotName);
		return false;
	}

	USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex);
	CurrentSaveGame = Cast<UMooversRacerSaveGame>(LoadedGame);

	if (!CurrentSaveGame)
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameManager::LoadGame - Failed to load save game from slot: %s"), *SlotName);
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::LoadGame - Loaded from slot: %s"), *SlotName);
	return true;
}

bool USaveGameManager::DeleteSave(const FString& SlotName)
{
	bool bDeleted = UGameplayStatics::DeleteGameInSlot(SlotName, UserIndex);

	if (bDeleted)
	{
		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::DeleteSave - Deleted slot: %s"), *SlotName);
		CurrentSaveGame = nullptr;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameManager::DeleteSave - Failed to delete slot: %s"), *SlotName);
	}

	return bDeleted;
}

UMooversRacerSaveGame* USaveGameManager::GetCurrentSaveGame() const
{
	return CurrentSaveGame;
}

bool USaveGameManager::HasSaveGame(const FString& SlotName) const
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex);
}

void USaveGameManager::GrantXP(int32 Amount)
{
	if (!CurrentSaveGame)
	{
		return;
	}

	int32 OldLevel = CalculateLevel(CurrentSaveGame->ProgressData.TotalXP);
	CurrentSaveGame->ProgressData.TotalXP += Amount;
	int32 NewLevel = CalculateLevel(CurrentSaveGame->ProgressData.TotalXP);

	if (NewLevel > OldLevel)
	{
		CurrentSaveGame->ProgressData.PlayerLevel = NewLevel;
		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::GrantXP - Player leveled up to %d"), NewLevel);
	}

	SaveGame();
}

void USaveGameManager::UnlockPart(const FString& PartID)
{
	if (!CurrentSaveGame)
	{
		return;
	}

	CurrentSaveGame->ProgressData.UnlockedParts.AddUnique(PartID);
	SaveGame();

	UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::UnlockPart - Unlocked part: %s"), *PartID);
}

void USaveGameManager::UnlockCosmetic(const FString& CosmeticID)
{
	if (!CurrentSaveGame)
	{
		return;
	}

	CurrentSaveGame->ProgressData.UnlockedCosmetics.AddUnique(CosmeticID);
	SaveGame();

	UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::UnlockCosmetic - Unlocked cosmetic: %s"), *CosmeticID);
}

void USaveGameManager::UpdateHighScore(int32 NewScore)
{
	if (!CurrentSaveGame)
	{
		return;
	}

	if (NewScore > CurrentSaveGame->ProgressData.ArcadeHighScore)
	{
		CurrentSaveGame->ProgressData.ArcadeHighScore = NewScore;
		SaveGame();

		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::UpdateHighScore - New high score: %d"), NewScore);
	}
}

void USaveGameManager::UpdateBestLapTime(float NewTime)
{
	if (!CurrentSaveGame)
	{
		return;
	}

	if (NewTime < CurrentSaveGame->ProgressData.BestLapTime)
	{
		CurrentSaveGame->ProgressData.BestLapTime = NewTime;
		SaveGame();

		UE_LOG(LogTemp, Warning, TEXT("SaveGameManager::UpdateBestLapTime - New best lap: %.2f"), NewTime);
	}
}

int32 USaveGameManager::CalculateLevel(int32 TotalXP) const
{
	// Simple level formula: Level = sqrt(TotalXP / 100)
	// Adjust as needed for your progression curve
	int32 Level = FMath::Max(1, FMath::Sqrt(TotalXP / 100.0f));
	return FMath::Min(Level, 100); // Cap at level 100
}

int32 USaveGameManager::GetXPForLevel(int32 Level) const
{
	// Inverse of CalculateLevel: XP = (Level^2 * 100)
	return Level * Level * 100;
}
