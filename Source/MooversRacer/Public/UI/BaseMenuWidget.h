// Copyright 2026 Moovers Racer. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseMenuWidget.generated.h"

/**
 * Base class for all menu widgets.
 * Handles common menu functionality like navigation and animations.
 */
UCLASS(Abstract)
class MOOVERSRACER_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// Menu lifecycle
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Menu")
	void OpenMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Menu")
	void CloseMenu();

	// Events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMenuClosed);
	UPROPERTY(BlueprintAssignable, Category = "Menu")
	FOnMenuClosed OnMenuClosed;

protected:
	// Animation
	UPROPERTY(Transient, meta = (BindWidgetOptional))
	class UCanvasPanel* RootPanel;

	// Play open animation
	UFUNCTION(BlueprintImplementableEvent, Category = "Menu")
	void PlayOpenAnimation();

	// Play close animation
	UFUNCTION(BlueprintImplementableEvent, Category = "Menu")
	void PlayCloseAnimation();

	// Call this when close animation finishes
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void FinishClosing();
};
