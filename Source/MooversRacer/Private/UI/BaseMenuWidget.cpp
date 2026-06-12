// Copyright 2026 Moovers Racer. All Rights Reserved.

#include "UI/BaseMenuWidget.h"
#include "Components/CanvasPanel.h"

void UBaseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	OpenMenu();
}

void UBaseMenuWidget::NativeDestruct()
{
	OnMenuClosed.Clear();
	Super::NativeDestruct();
}

void UBaseMenuWidget::OpenMenu_Implementation()
{
	PlayOpenAnimation();
}

void UBaseMenuWidget::CloseMenu_Implementation()
{
	PlayCloseAnimation();
}

void UBaseMenuWidget::FinishClosing()
{
	OnMenuClosed.Broadcast();
	RemoveFromParent();
}
