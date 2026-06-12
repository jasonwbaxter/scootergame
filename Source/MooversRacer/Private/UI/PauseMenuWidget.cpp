// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/PauseMenuWidget.h"
#include "UI/SettingsMenuWidget.h"
#include "UI/MooversUIManager.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button events
	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnResumeClicked);
	}

	if (RestartButton)
	{
		RestartButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnRestartClicked);
	}

	if (SettingsButton)
	{
		SettingsButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnSettingsClicked);
	}

	if (QuitButton)
	{
		QuitButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnQuitClicked);
	}
}

void UPauseMenuWidget::OnResumeClicked()
{
	CloseMenu();
}

void UPauseMenuWidget::OnRestartClicked()
{
	// Reload current level
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::OpenLevel(World, FName(*World->GetMapName()));
	}
}

void UPauseMenuWidget::OnSettingsClicked()
{
	// Open settings menu
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

void UPauseMenuWidget::OnQuitClicked()
{
	// Return to main menu
	if (APlayerController* PC = GetOwningPlayer())
	{
		if (UMooversUIManager* UIManager = PC->GetLocalPlayer()->GetSubsystem<UMooversUIManager>())
		{
			UIManager->ReturnToMainMenu();
		}
	}
}
