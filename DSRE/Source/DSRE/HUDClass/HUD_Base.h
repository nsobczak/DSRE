// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_Base.generated.h"

UENUM(BlueprintType)
enum class EHudWidget : uint8
{
	FHW_NONE UMETA(DisplayName = "Null"),
	FHW_START UMETA(DisplayName = "Start widget"),
	FHW_HUD UMETA(DisplayName = "HUD widget"),
	FHW_PAUSE UMETA(DisplayName = "Pause widget"),
	FHW_END_GO UMETA(DisplayName = "End widget game over"),
	FHW_END_WIN UMETA(DisplayName = "End widget win")
};


/**
 *
 */
UCLASS(meta = (ToolTip = "Hud class is used to handle widget display"))
class DSRE_API AHUD_Base : public AHUD
{
	GENERATED_BODY()

public:
	AHUD_Base();

	//virtual void Tick(float DeltaTime) override;

#pragma region widget functions
	/** The widget instance that we are using. */
	UFUNCTION(BlueprintPure, Category = "Widget_Functions")
		FORCEINLINE UUserWidget* GetCurrentWidget() { return CurrentWidget; }

	UFUNCTION(BlueprintPure, Category = "Widget_Functions", Meta = (BlueprintProtected = "true"))
		FORCEINLINE TSubclassOf<UUserWidget> GetCurrentWidgetClass() { return CurrentWidgetClass; }

	/** Remove the current menu widget (if not null) and create a new one from the specified class, if provided. Show cursor if true.*/
	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		UUserWidget* ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	UFUNCTION(BlueprintPure, Category = "Widget_Functions", Meta = (BlueprintProtected = "true"))
		bool IsShowingWidget(EHudWidget widgetToLookFor);

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowHUDWidget() { ChangeMenuWidget(HUDWidget); };

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowStartingWidget() { ChangeMenuWidget(StartingWidgetClass); };

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowGameOverWidget() { ChangeMenuWidget(GameOverWidgetClass); };

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowEndingWidget() { ChangeMenuWidget(EndingWidgetClass); };

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void ShowPauseWidget() { ChangeMenuWidget(PauseWidgetClass); };

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void HideWidget(UUserWidget* widgetToHide);

	UFUNCTION(BlueprintCallable, Category = "Widget_Functions")
		void HideCurrentWidget();
#pragma endregion

	UFUNCTION(BlueprintCallable, Category = "Cursor_Functions")
		void ShowCursor(class APlayerController* pController, bool showCursor = true);

protected:
	virtual void BeginPlay() override;

#pragma region Widgets
	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		EHudWidget WidgetToShowOnStart = EHudWidget::FHW_NONE;

	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/**widget to use for our HUD screen*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> HUDWidget;

	/** The widget class we will use as our menu when the game is paused. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> PauseWidgetClass;

	/** The widget class we will use as our menu when the game ends with a defeat. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> GameOverWidgetClass;

	/** The widget class we will use as our menu when the game ends with a victory. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets")
		TSubclassOf<UUserWidget> EndingWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets_Debug")
		UUserWidget* CurrentWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets_Debug")
		TSubclassOf<UUserWidget> CurrentWidgetClass;

	/** The widget instance that we used. (useful for return buttons) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets_Debug")
		TSubclassOf<UUserWidget> OldWidgetClass;

#pragma endregion

};
