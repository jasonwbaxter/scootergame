// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "Arcade/ArcadeHUD.h"
#include "Arcade/ArcadeRaceManager.h"

void UArcadeHUD::NativeConstruct()
{
	Super::NativeConstruct();
}

void UArcadeHUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!ArcadeManager)
	{
		return;
	}

	// Update score display
	if (LastScore != ArcadeManager->GetScore())
	{
		LastScore = ArcadeManager->GetScore();
		UpdateScore(LastScore);
	}

	// Update multiplier display
	if (LastMultiplier != ArcadeManager->GetMultiplier())
	{
		LastMultiplier = ArcadeManager->GetMultiplier();
		UpdateMultiplier(LastMultiplier);
	}
}

void UArcadeHUD::SetArcadeManager(AArcadeRaceManager* Manager)
{
	ArcadeManager = Manager;
}
