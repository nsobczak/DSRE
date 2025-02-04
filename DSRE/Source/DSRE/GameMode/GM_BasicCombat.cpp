// Copyright 2020 nsocbzak. All rights reserved.

#include "GM_BasicCombat.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "DSRE/PlayerController/BCController.h"
#include "Components/AudioComponent.h"


AGM_BasicCombat::AGM_BasicCombat()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("/Game/Player/BP_MainCharacter"));
	if (PlayerPawnObject.Succeeded())
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}

	//static ConstructorHelpers::FClassFinder<AHUD> HUDObject(TEXT("/Game/HUD/BPHUD_Main"));
	//if (HUDObject.Succeeded())
	//{
	//	HUDClass = HUDObject.Class;
	//}

	static ConstructorHelpers::FClassFinder<APlayerController> PCObject(TEXT("/Game/PlayerController/BP_BCController"));
	if (PCObject.Succeeded())
	{
		PlayerControllerClass = PCObject.Class;
	}

}


void AGM_BasicCombat::InitParamPointers()
{
	Super::InitParamPointers();

	TArray<AActor*> FoundActors;

	// Look for controller
	PController = Cast<ABCController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PController)
		UE_LOG(LogTemp, Error, TEXT("Could not find a PianoController"));

}


void AGM_BasicCombat::Win()
{
	Super::Win();

	if (PController && HUDBase && !HUDBase->IsShowingWidget(EHudWidget::FHW_END_WIN))
	{
		PController->SetInputMode(FInputModeUIOnly());
		PController->SetCinematicMode(true, false, false, true, true);
		HUDBase->ShowEndingWidget();
		HUDBase->ShowCursor(PController, true);
	}
}

void AGM_BasicCombat::GameOver()
{
	Super::GameOver();

	if (PController && HUDBase && !HUDBase->IsShowingWidget(EHudWidget::FHW_END_GO))
	{
		PController->SetInputMode(FInputModeUIOnly());
		PController->SetCinematicMode(true, false, false, true, true);
		HUDBase->ShowGameOverWidget();
		HUDBase->ShowCursor(PController, true);
	}
}

void AGM_BasicCombat::BeginPlay()
{
	//Super::BeginPlay();

	InitParamPointers();

	// Stop if there is an error
	if (!PController)
	{
		UE_LOG(LogTemp, Log, TEXT("Game can't be played, exiting"));
		GameOver();
	}
	else
	{
		bHasStartedPlaying = true;
		bIsGameOver = false;
		PController->SetInputMode(FInputModeGameOnly());
		HUDBase->ShowCursor(PController, true);
	}

	//audio
	if (MapTheme)
	{
		CurrentTheme_AC = UGameplayStatics::SpawnSound2D(GetWorld(), MapTheme);
		CurrentTheme_AC->SetUISound(true);
		CurrentTheme_AC->FadeIn(1.f, 1.f);
	}
}

void AGM_BasicCombat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// win?
	if (PController && PController->GetPickup() >= 4
		&& PController->GetCurrentArea().EqualTo(PController->GetFinalArea())
		&& bHasStartedPlaying && !bIsGameOver)
	{
		Win();
	}

	// game over?
	if (PController && PController->GetLife() <= 0 && bHasStartedPlaying && !bIsGameOver)
	{
		GameOver();
	}
}
