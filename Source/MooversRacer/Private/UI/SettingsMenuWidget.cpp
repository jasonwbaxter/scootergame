// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/SettingsMenuWidget.h"
#include "Components/CheckBox.h"
#include "Kismet/GameplayStatics.h"

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button events
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnBackClicked);
	}

	if (DefaultsButton)
	{
		DefaultsButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnDefaultsClicked);
	}

	// Bind slider events
	if (MasterVolumeSlider)
	{
		MasterVolumeSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::OnMasterVolumeChanged);
	}

	if (MusicVolumeSlider)
	{
		MusicVolumeSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::OnMusicVolumeChanged);
	}

	if (SFXVolumeSlider)
	{
		SFXVolumeSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::OnSFXVolumeChanged);
	}

	// Bind quality preset
	if (QualityPreset)
	{
		QualityPreset->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::OnQualityPresetChanged);
		QualityPreset->AddOption(TEXT("Low"));
		QualityPreset->AddOption(TEXT("Medium"));
		QualityPreset->AddOption(TEXT("High"));
		QualityPreset->AddOption(TEXT("Ultra"));
	}

	// Bind haptics checkbox
	if (HapticsToggle)
	{
		HapticsToggle->OnCheckStateChanged.AddDynamic(this, &USettingsMenuWidget::OnHapticsToggled);
	}

	// Load current settings
	LoadSettings();
}

void USettingsMenuWidget::OnMasterVolumeChanged(float Value)
{
	UGameplayStatics::SetSoundMixClassVolume(GetWorld(), nullptr, Value);
	SaveSettings();
}

void USettingsMenuWidget::OnMusicVolumeChanged(float Value)
{
	SaveSettings();
}

void USettingsMenuWidget::OnSFXVolumeChanged(float Value)
{
	SaveSettings();
}

void USettingsMenuWidget::OnQualityPresetChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::Direct)
	{
		return; // Ignore programmatic changes
	}

	// Apply quality settings
	int32 QualityLevel = 1; // Default to medium
	if (SelectedItem == TEXT("Low"))
	{
		QualityLevel = 0;
	}
	else if (SelectedItem == TEXT("Medium"))
	{
		QualityLevel = 1;
	}
	else if (SelectedItem == TEXT("High"))
	{
		QualityLevel = 2;
	}
	else if (SelectedItem == TEXT("Ultra"))
	{
		QualityLevel = 3;
	}

	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f); // Reset any time dilation
	SaveSettings();
}

void USettingsMenuWidget::OnHapticsToggled(bool bIsChecked)
{
	SaveSettings();
}

void USettingsMenuWidget::OnBackClicked()
{
	CloseMenu();
}

void USettingsMenuWidget::OnDefaultsClicked()
{
	ResetToDefaults();
	SaveSettings();
}

void USettingsMenuWidget::LoadSettings()
{
	// TODO: Load from save game
	// For now, set defaults
	if (MasterVolumeSlider)
	{
		MasterVolumeSlider->SetValue(0.8f);
	}

	if (MusicVolumeSlider)
	{
		MusicVolumeSlider->SetValue(0.7f);
	}

	if (SFXVolumeSlider)
	{
		SFXVolumeSlider->SetValue(0.9f);
	}

	if (QualityPreset)
	{
		QualityPreset->SetSelectedOption(TEXT("High"));
	}

	if (HapticsToggle)
	{
		HapticsToggle->SetIsChecked(true);
	}
}

void USettingsMenuWidget::SaveSettings()
{
	// TODO: Save to game save system
}

void USettingsMenuWidget::ResetToDefaults()
{
	if (MasterVolumeSlider)
	{
		MasterVolumeSlider->SetValue(0.8f);
	}

	if (MusicVolumeSlider)
	{
		MusicVolumeSlider->SetValue(0.7f);
	}

	if (SFXVolumeSlider)
	{
		SFXVolumeSlider->SetValue(0.9f);
	}

	if (QualityPreset)
	{
		QualityPreset->SetSelectedOption(TEXT("High"));
	}

	if (HapticsToggle)
	{
		HapticsToggle->SetIsChecked(true);
	}
}
