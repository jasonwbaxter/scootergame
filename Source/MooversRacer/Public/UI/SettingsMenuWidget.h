// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/BaseMenuWidget.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "Components/ComboBoxString.h"
#include "SettingsMenuWidget.generated.h"

/**
 * Settings menu for audio, graphics, and control options.
 */
UCLASS()
class MOOVERSRACER_API USettingsMenuWidget : public UBaseMenuWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	// Audio Settings
	UPROPERTY(meta = (BindWidget))
	USlider* MasterVolumeSlider;

	UPROPERTY(meta = (BindWidget))
	USlider* MusicVolumeSlider;

	UPROPERTY(meta = (BindWidget))
	USlider* SFXVolumeSlider;

	// Graphics Settings
	UPROPERTY(meta = (BindWidget))
	UComboBoxString* QualityPreset;

	// Haptics
	UPROPERTY(meta = (BindWidget))
	class UCheckBox* HapticsToggle;

	// Buttons
	UPROPERTY(meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	UButton* DefaultsButton;

	// Callbacks
	UFUNCTION()
	void OnMasterVolumeChanged(float Value);

	UFUNCTION()
	void OnMusicVolumeChanged(float Value);

	UFUNCTION()
	void OnSFXVolumeChanged(float Value);

	UFUNCTION()
	void OnQualityPresetChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnHapticsToggled(bool bIsChecked);

	UFUNCTION()
	void OnBackClicked();

	UFUNCTION()
	void OnDefaultsClicked();

	// Load and save settings
	void LoadSettings();
	void SaveSettings();
	void ResetToDefaults();
};
