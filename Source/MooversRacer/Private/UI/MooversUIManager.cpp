// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/MooversUIManager.h"
#include "UI/BaseMenuWidget.h"
#include "UI/LoadingScreenWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMooversUIManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bGamePaused = false;
}

void UMooversUIManager::Deinitialize()
{
	// Clean up any remaining UI
	if (CurrentMenu)
	{
		CurrentMenu->RemoveFromParent();
		CurrentMenu = nullptr;
	}

	if (LoadingScreen)
	{
		LoadingScreen->RemoveFromParent();
		LoadingScreen = nullptr;
	}

	MenuStack.Empty();
	Super::Deinitialize();
}

void UMooversUIManager::PushMenu(TSubclassOf<UBaseMenuWidget> MenuClass, bool bPauseGame)
{
	if (!MenuClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("UMooversUIManager::PushMenu - MenuClass is null"));
		return;
	}

	APlayerController* PC = GetLocalPlayer<APlayerController>();
	if (!IsValid(PC))
	{
		UE_LOG(LogTemp, Warning, TEXT("UMooversUIManager::PushMenu - PlayerController is invalid"));
		return;
	}

	// Save current menu to stack
	if (CurrentMenu)
	{
		MenuStack.Add(CurrentMenu->GetClass());
	}

	// Remove current menu from viewport
	if (CurrentMenu)
	{
		CurrentMenu->RemoveFromParent();
		CurrentMenu = nullptr;
	}

	// Create new menu
	CurrentMenu = CreateWidget<UBaseMenuWidget>(PC, MenuClass);
	if (!IsValid(CurrentMenu))
	{
		UE_LOG(LogTemp, Error, TEXT("UMooversUIManager::PushMenu - Failed to create menu widget"));
		return;
	}

	// Add to viewport
	CurrentMenu->AddToViewport(100);

	// Connect close callback
	CurrentMenu->OnMenuClosed.AddDynamic(this, &UMooversUIManager::OnMenuClosed);

	// Handle pause state
	if (bPauseGame && !bGamePaused)
	{
		SetPauseState(true);
	}
}

void UMooversUIManager::PopMenu()
{
	if (MenuStack.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("UMooversUIManager::PopMenu - Menu stack is empty"));
		return;
	}

	// Remove current menu
	if (CurrentMenu)
	{
		CurrentMenu->RemoveFromParent();
		CurrentMenu = nullptr;
	}

	// Pop previous menu
	TSubclassOf<UBaseMenuWidget> PreviousMenuClass = MenuStack.Pop();
	
	if (PreviousMenuClass)
	{
		PushMenu(PreviousMenuClass, false);
	}
}

void UMooversUIManager::ClearMenuStack()
{
	MenuStack.Empty();
	
	if (CurrentMenu)
	{
		CurrentMenu->RemoveFromParent();
		CurrentMenu = nullptr;
	}

	SetPauseState(false);
}

void UMooversUIManager::ReturnToMainMenu()
{
	ClearMenuStack();
	
	if (MainMenuClass)
	{
		PushMenu(MainMenuClass, false);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UMooversUIManager::ReturnToMainMenu - MainMenuClass not set"));
	}
}

void UMooversUIManager::ShowLoadingScreen(const FString& TipText, float MinimumDuration)
{
	APlayerController* PC = GetLocalPlayer<APlayerController>();
	if (!IsValid(PC))
	{
		return;
	}

	if (!LoadingScreenClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("UMooversUIManager::ShowLoadingScreen - LoadingScreenClass not set"));
		return;
	}

	if (!LoadingScreen)
	{
		LoadingScreen = CreateWidget<ULoadingScreenWidget>(PC, LoadingScreenClass);
		if (!IsValid(LoadingScreen))
		{
			return;
		}
		LoadingScreen->AddToViewport(200);
	}

	LoadingScreen->ShowLoading(TipText, MinimumDuration);
}

void UMooversUIManager::HideLoadingScreen()
{
	if (LoadingScreen)
	{
		LoadingScreen->HideLoading();
	}
}

bool UMooversUIManager::IsMenuOpen() const
{
	return IsValid(CurrentMenu);
}

bool UMooversUIManager::IsGamePaused() const
{
	return bGamePaused;
}

UBaseMenuWidget* UMooversUIManager::GetCurrentMenu() const
{
	return CurrentMenu;
}

void UMooversUIManager::OnMenuClosed()
{
	if (bGamePaused)
	{
		SetPauseState(false);
	}

	if (MenuStack.IsEmpty())
	{
		if (CurrentMenu)
		{
			CurrentMenu->RemoveFromParent();
			CurrentMenu = nullptr;
		}
	}
	else
	{
		PopMenu();
	}
}

void UMooversUIManager::SetPauseState(bool bPaused)
{
	bGamePaused = bPaused;

	APlayerController* PC = GetLocalPlayer<APlayerController>();
	if (!IsValid(PC))
	{
		return;
	}

	if (UWorld* World = GetWorld())
	{
		if (bPaused)
		{
			World->PauseGamePlay(PC);
		}
		else
		{
			World->UnPauseGamePlay(PC);
		}
	}
}
