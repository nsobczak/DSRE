// Copyright 2020 nsocbzak. All rights reserved.

#include "HUD_Base.h"
#include "UMG/Public/UMG.h"


AHUD_Base::AHUD_Base()
{
	PrimaryActorTick.bCanEverTick = true; // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bTickEvenWhenPaused = true;
}


void AHUD_Base::BeginPlay()
{
	Super::BeginPlay();

	//hud
	if (WidgetToShowOnStart != EHudWidget::FHW_NONE)
	{
		switch (WidgetToShowOnStart)
		{
		case EHudWidget::FHW_START:
			ShowStartingWidget();
			break;
		case EHudWidget::FHW_HUD:
			ShowHUDWidget();
			break;
		case EHudWidget::FHW_PAUSE:
			ShowPauseWidget();
			break;
		case EHudWidget::FHW_END:
			ShowEndingWidget();
			break;
		default:
			break;
		}
	}
}


#pragma region Widgets
//==============================================================================================
UUserWidget* AHUD_Base::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		OldWidgetClass = CurrentWidget->GetClass();
		CurrentWidget->RemoveFromViewport();
		CurrentWidget->RemoveFromParent();
		CurrentWidget->Destruct();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
			CurrentWidgetClass = NewWidgetClass;
		}
	}

	return CurrentWidget;
}

bool AHUD_Base::IsShowingWidget(EHudWidget widgetToLookFor)
{
	switch (widgetToLookFor)
	{
	case EHudWidget::FHW_START:
		return CurrentWidgetClass == StartingWidgetClass;
		break;

	case EHudWidget::FHW_HUD:
		return CurrentWidgetClass == HUDWidget;
		break;

	case EHudWidget::FHW_PAUSE:
		return CurrentWidgetClass == PauseWidgetClass;
		break;

	case EHudWidget::FHW_END:
		return CurrentWidgetClass == EndingWidgetClass;
		break;

	default:
		return false;
		break;
	}
}

void AHUD_Base::ShowWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (NewWidgetClass != nullptr)
	{
		//OldWidgetClass = NewWidgetClass;
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AHUD_Base::ShowStartingWidget()
{
	ChangeMenuWidget(StartingWidgetClass);
}

void AHUD_Base::ShowEndingWidget()
{
	ChangeMenuWidget(EndingWidgetClass);
}

void AHUD_Base::ShowPauseWidget()
{
	ChangeMenuWidget(PauseWidgetClass);
}

void AHUD_Base::ShowHUDWidget()
{
	ChangeMenuWidget(HUDWidget);
}


void AHUD_Base::HideWidget(UUserWidget* widgetToHide)
{
	if (widgetToHide != nullptr)
	{
		widgetToHide->RemoveFromViewport();
		widgetToHide->RemoveFromParent();
		widgetToHide->Destruct();
	}
}

void AHUD_Base::HideCurrentWidget()
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget->RemoveFromParent();
		CurrentWidget->Destruct();
		CurrentWidget = nullptr;
	}
}
//==============================================================================================
#pragma endregion

void AHUD_Base::ShowCursor(APlayerController* pController, bool showCursor)
{
	if (pController)
	{
		pController->bShowMouseCursor = showCursor;
		pController->bEnableClickEvents = showCursor;
		pController->bEnableMouseOverEvents = showCursor;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is null"));
	}
}
