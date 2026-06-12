// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PartDefinition.generated.h"

/**
 * Defines individual part stats and visuals
 */
UENUM(BlueprintType)
enum class EPartType : uint8
{
	Rim UMETA(DisplayName = "Rim"),
	Exhaust UMETA(DisplayName = "Exhaust"),
	BodyPanel UMETA(DisplayName = "Body Panel"),
	Paint UMETA(DisplayName = "Paint"),
	Decal UMETA(DisplayName = "Decal"),
	Engine UMETA(DisplayName = "Engine"),
	Suspension UMETA(DisplayName = "Suspension"),
	Mirror UMETA(DisplayName = "Mirror")
};

UENUM(BlueprintType)
enum class EPartRarity : uint8
{
	Common UMETA(DisplayName = "Common"),
	Uncommon UMETA(DisplayName = "Uncommon"),
	Rare UMETA(DisplayName = "Rare"),
	Epic UMETA(DisplayName = "Epic"),
	Legendary UMETA(DisplayName = "Legendary")
};

UENUM(BlueprintType)
enum class EScooterBrand : uint8
{
	KRONOS_MOTORS UMETA(DisplayName = "KRONOS MOTORS"),
	VELOCE_CLASSICS UMETA(DisplayName = "VELOCE CLASSICS"),
	THRUST_DYNAMICS UMETA(DisplayName = "THRUST DYNAMICS")
};

USTRUCT(BlueprintType)
struct FPartStats : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EnginePowerModifier = 0.0f; // +/- % to engine power

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HandlelingModifier = 0.0f; // +/- % to handling

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeightModifier = 0.0f; // +/- % to weight

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DurabilityModifier = 0.0f; // +/- % to durability
};

USTRUCT(BlueprintType)
struct FPart : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName PartID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PartName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPartType PartType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPartRarity Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EScooterBrand Brand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPartStats Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UMaterialInterface> VisualMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<USkeletalMesh> PartMesh; // For modular parts

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> ThumbnailImage;

	// ========== VISUAL SPECIFICATIONS ==========

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	FLinearColor PrimaryColor;  // Brand primary color

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	FLinearColor AccentColor;   // Brand accent color

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	float MetallicValue = 0.0f;  // 0.0 = Matte, 1.0 = Mirror

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	float RoughnessValue = 0.5f; // 0.0 = Polished, 1.0 = Rough

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	float GlowIntensity = 0.0f;  // For Epic/Legendary glow effects

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	bool bHasHolographicShift = false;  // For Epic/Legendary iridescent effects

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual Specs")
	bool bCanRecolor = true;  // Whether part accepts paint color

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Price = 100;
};

USTRUCT(BlueprintType)
struct FScooterCustomization
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FPart> EquippedParts;

	UPROPERTY(BlueprintReadOnly)
	float EnginePowerMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	float HandlelingMultiplier = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	float WeightMultiplier = 1.0f;

	void RecalculateStats()
	{
		EnginePowerMultiplier = 1.0f;
		HandlelingMultiplier = 1.0f;
		WeightMultiplier = 1.0f;

		for (const FPart& Part : EquippedParts)
		{
			EnginePowerMultiplier += (Part.Stats.EnginePowerModifier / 100.0f);
			HandlelingMultiplier += (Part.Stats.HandlelingModifier / 100.0f);
			WeightMultiplier += (Part.Stats.WeightModifier / 100.0f);
		}
	}
};
