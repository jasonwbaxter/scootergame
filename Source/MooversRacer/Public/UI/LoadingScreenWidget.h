// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadingScreenWidget.generated.h"

class UProgressBar;
class UTextBlock;
class UImage;

/**
 * Loading screen widget with tips and progress indication.
 */
UCLASS()
class MOOVERSRACER_API ULoadingScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Loading")
	void ShowLoading(const FString& TipText = FString(), float MinimumDuration = 2.0f);

	UFUNCTION(BlueprintCallable, Category = "Loading")
	void HideLoading();

protected:
	// UI Components
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TipText;

	UPROPERTY(meta = (BindWidget))
	UImage* LoadingIcon;

	// Loading state
	float MinimumLoadingDuration;
	float ElapsedLoadingTime;
	bool bIsLoading;
	bool bShouldHide;

	// Tips pool
	UPROPERTY(EditDefaultsOnly, Category = "Loading")
	TArray<FString> LoadingTips = {
		TEXT("Tip: Use turbo strategically to boost past obstacles!"),
		TEXT("Tip: Customize your scooter for better performance."),
		TEXT("Tip: Check the leaderboards to see how you rank."),
		TEXT("Tip: Collect power-ups for speed boosts and invincibility."),
		TEXT("Tip: Earn XP to unlock new cosmetics and parts."),
		TEXT("Tip: Practice different tracks to master the handling."),
		TEXT("Tip: Try the Garage to compare part stats."),
		TEXT("Tip: Daily challenges reward bonus XP!")
	};

	// Select random tip
	FString GetRandomTip() const;
};
