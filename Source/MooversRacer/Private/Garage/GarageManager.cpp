// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Garage/GarageManager.h"
#include "Vehicles/ScooterPawn.h"

AGarageManager::AGarageManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGarageManager::BeginPlay()
{
	Super::BeginPlay();

	LoadPartDatabase();

	// Find player scooter
	for (TActorIterator<AScooterPawn> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		SetActiveScooter(*ActorItr);
		break;
	}
}

void AGarageManager::ShowGarage()
{
	if (GarageWidget)
	{
		GarageWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void AGarageManager::HideGarage()
{
	if (GarageWidget)
	{
		GarageWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AGarageManager::SetActiveScooter(AScooterPawn* Scooter)
{
	ActiveScooter = Scooter;
	if (ActiveScooter)
	{
		CurrentCustomization = FScooterCustomization();
	}
}

void AGarageManager::EquipPart(const FPart& Part)
{
	// Find and replace part of same type
	for (int32 i = 0; i < CurrentCustomization.EquippedParts.Num(); ++i)
	{
		if (CurrentCustomization.EquippedParts[i].PartType == Part.PartType)
		{
			CurrentCustomization.EquippedParts[i] = Part;
			CurrentCustomization.RecalculateStats();
			return;
		}
	}

	// Add new part
	CurrentCustomization.EquippedParts.Add(Part);
	CurrentCustomization.RecalculateStats();
}

void AGarageManager::UnequipPart(EPartType PartType)
{
	for (int32 i = 0; i < CurrentCustomization.EquippedParts.Num(); ++i)
	{
		if (CurrentCustomization.EquippedParts[i].PartType == PartType)
		{
			CurrentCustomization.EquippedParts.RemoveAt(i);
			CurrentCustomization.RecalculateStats();
			break;
		}
	}
}

void AGarageManager::UpdatePreview()
{
	// Update 3D garage preview with current customization
	if (ActiveScooter)
	{
		// Preview materials and parts on scooter model
	}
}

void AGarageManager::ApplyCustomization()
{
	if (ActiveScooter)
	{
		ActiveScooter->ApplyCustomization(CurrentCustomization);
	}
}

TArray<FPart> AGarageManager::GetAvailableParts(EPartType PartType) const
{
	TArray<FPart> Result;

	if (PartDatabase)
	{
		for (auto RowItr = PartDatabase->GetRowMap().CreateConstIterator(); RowItr; ++RowItr)
		{
			const FPart* Part = reinterpret_cast<const FPart*>(RowItr.Value());
			if (Part && Part->PartType == PartType)
			{
				Result.Add(*Part);
			}
		}
	}

	return Result;
}

void AGarageManager::LoadPartDatabase()
{
	// TODO: Load from data table asset
	// PartDatabase = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/DT_Parts"));
}
