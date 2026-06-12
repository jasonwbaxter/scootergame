// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/MooversMainMenuWidget.h"
#include "UI/SettingsMenuWidget.h"
#include "UI/MooversUIManager.h"
#include "Kismet/GameplayStatics.h"

void UMooversMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button events
	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnPlayClicked);
	}

	if (GarageButton)
	{
		GarageButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnGarageClicked);
	}

	if (LeaderboardButton)
	{
		LeaderboardButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnLeaderboardClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnSettingsClicked);
	}

	if (CreditsButton)
	{
		CreditsButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnCreditsClicked);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UMooversMainMenuWidget::OnQuitClicked);
	}
}

void UMooversMainMenuWidget::OnPlayClicked()
{
	// TODO: Show track selection menu or load default track
	// For now, load arcade mode demo
	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PC = GetOwningPlayer())
		{
			if (UMooversUIManager* UIManager = PC->GetLocalPlayer()->GetSubsystem<UMooversUIManager>())
			{
				UIManager->ShowLoadingScreen(TEXT("Starting race..."), 2.0f);
			}
		}
		UGameplayStatics::OpenLevel(World, FName("ArcadeLevel"));
	}
}

void UMooversMainMenuWidget::OnGarageClicked()
{
	// TODO: Open garage customization
	UE_LOG(LogTemp, Warning, TEXT("Garage not yet implemented"));
}

void UMooversMainMenuWidget::OnLeaderboardClicked()
{
	// TODO: Open leaderboard view
	UE_LOG(LogTemp, Warning, TEXT("Leaderboards not yet implemented"));
}

void UMooversMainMenuWidget::OnSettingsClicked()
{
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (UMooversUIManager* UIManager = PC->GetLocalPlayer()->GetSubsystem<UMooversUIManager>())
		{
			if (SettingsMenuClass)
			{
				UIManager->PushMenu(SettingsMenuClass, false);
			}
		}
	}
}

void UMooversMainMenuWidget::OnCreditsClicked()
{
	// TODO: Show credits
	UE_LOG(LogTemp, Warning, TEXT("Credits not yet implemented"));
}

void UMooversMainMenuWidget::OnQuitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}
