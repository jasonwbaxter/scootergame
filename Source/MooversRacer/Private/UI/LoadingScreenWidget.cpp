// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/LoadingScreenWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void ULoadingScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Set initial state
	bIsLoading = false;
	bShouldHide = false;
	ElapsedLoadingTime = 0.0f;
	MinimumLoadingDuration = 2.0f;

	// Initialize progress bar
	if (ProgressBar)
	{
		ProgressBar->SetPercent(0.0f);
	}

	// Set initial visibility
	SetVisibility(ESlateVisibility::Hidden);
}

void ULoadingScreenWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (bIsLoading)
	{
		ElapsedLoadingTime += InDeltaTime;

		// Update progress bar
		if (ProgressBar)
		{
			float Progress = FMath::Min(ElapsedLoadingTime / MinimumLoadingDuration, 1.0f);
			ProgressBar->SetPercent(Progress);
		}

		// Hide when time reached and should hide flag is set
		if (ElapsedLoadingTime >= MinimumLoadingDuration && bShouldHide)
		{
			HideLoading();
		}
	}
}

void ULoadingScreenWidget::ShowLoading(const FString& TipText, float MinimumDuration)
{
	bIsLoading = true;
	bShouldHide = false;
	ElapsedLoadingTime = 0.0f;
	MinimumLoadingDuration = MinimumDuration;

	// Show widget
	SetVisibility(ESlateVisibility::Visible);

	// Set tip text
	if (TipText.Len() > 0)
	{
		if (UTextBlock* TipTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TipText"))))
		{
			TipTextBlock->SetText(FText::FromString(TipText));
		}
	}
	else
	{
		// Use random tip
		if (UTextBlock* TipTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TipText"))))
		{
			TipTextBlock->SetText(FText::FromString(GetRandomTip()));
		}
	}

	// Reset progress
	if (ProgressBar)
	{
		ProgressBar->SetPercent(0.0f);
	}
}

void ULoadingScreenWidget::HideLoading()
{
	if (bIsLoading)
	{
		bIsLoading = false;
		SetVisibility(ESlateVisibility::Hidden);
		ElapsedLoadingTime = 0.0f;
	}
}

FString ULoadingScreenWidget::GetRandomTip() const
{
	if (LoadingTips.IsEmpty())
	{
		return TEXT("Loading...");
	}

	int32 RandomIndex = FMath::RandRange(0, LoadingTips.Num() - 1);
	return LoadingTips[RandomIndex];
}
