// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Blueprint/UserWidget.h"
#include "MooversUIManager.generated.h"

class APlayerController;
class UMooversMainMenuWidget;
class UBaseMenuWidget;
class ULoadingScreenWidget;

/**
 * Central UI management system for all menus and HUD elements.
 * Handles menu navigation, transitions, and input routing.
 */
UCLASS(Config = Game)
class MOOVERSRACER_API UMooversUIManager : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// Menu Navigation
	UFUNCTION(BlueprintCallable, Category = "UI")
	void PushMenu(TSubclassOf<UBaseMenuWidget> MenuClass, bool bPauseGame = false);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void PopMenu();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ClearMenuStack();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void ReturnToMainMenu();

	// Loading Screen
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ShowLoadingScreen(const FString& TipText = FString(), float MinimumDuration = 2.0f);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void HideLoadingScreen();

	// Query
	UFUNCTION(BlueprintPure, Category = "UI")
	bool IsMenuOpen() const;

	UFUNCTION(BlueprintPure, Category = "UI")
	bool IsGamePaused() const;

	UFUNCTION(BlueprintPure, Category = "UI")
	UBaseMenuWidget* GetCurrentMenu() const;

protected:
	// Menu classes to instantiate
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UMooversMainMenuWidget> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<ULoadingScreenWidget> LoadingScreenClass;

	// Current active menu
	UPROPERTY()
	UBaseMenuWidget* CurrentMenu;

	UPROPERTY()
	ULoadingScreenWidget* LoadingScreen;

	// Menu stack for back navigation
	UPROPERTY()
	TArray<TSubclassOf<UBaseMenuWidget>> MenuStack;

	// Pause state
	bool bGamePaused;

	// Handle menu close callback
	UFUNCTION()
	void OnMenuClosed();

	void SetPauseState(bool bPaused);
};
