// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/BaseMenuWidget.h"
#include "Components/Button.h"
#include "MooversMainMenuWidget.generated.h"

class USettingsMenuWidget;

/**
 * Main menu widget. Entry point for the game.
 */
UCLASS()
class MOOVERSRACER_API UMooversMainMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* GarageButton;

	UPROPERTY(meta = (BindWidget))
	UButton* LeaderboardButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CreditsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<USettingsMenuWidget> SettingsMenuClass;

	// Button callbacks
	UFUNCTION()
	void OnPlayClicked();

	UFUNCTION()
	void OnGarageClicked();

	UFUNCTION()
	void OnLeaderboardClicked();

	UFUNCTION()
	void OnSettingsClicked();

	UFUNCTION()
	void OnCreditsClicked();

	UFUNCTION()
	void OnQuitClicked();
};
