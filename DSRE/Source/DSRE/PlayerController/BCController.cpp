// Copyright 2020 nsocbzak. All rights reserved.

#include "BCController.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Classes/Engine/World.h"

#include "DSRE/GameMode/GM_BasicCombat.h"
#include "DSRE/HUDClass/HUD_Base.h"
//#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

ABCController::ABCController()
{
	PrimaryActorTick.bCanEverTick = true; 
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

void ABCController::BeginPlay()
{
	Super::BeginPlay();

	////Look for hitregion to control activation
	//TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANotePianoHitRegion::StaticClass(), FoundActors);
	//HitRegions.Empty();
	//for (size_t i = 0; i < FoundActors.Num(); i++)
	//{
	//	ANotePianoHitRegion* hRegion = Cast<ANotePianoHitRegion>(FoundActors[i]);
	//	HitRegions.Add(hRegion->Pos, hRegion);
	//}

}

#pragma region Input
//_______________
// Called to bind functionality to input
void ABCController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ABCController::ActionButton1_Pressed);
	InputComponent->BindAction("Attack", EInputEvent::IE_Released, this, &ABCController::ActionButton1_Released);
	InputComponent->BindAction("Defend", EInputEvent::IE_Pressed, this, &ABCController::ActionButton2_Pressed);
	InputComponent->BindAction("Defend", EInputEvent::IE_Released, this, &ABCController::ActionButton2_Released);
	InputComponent->BindAction("Dodge", EInputEvent::IE_Pressed, this, &ABCController::ActionButton3_Pressed);
	InputComponent->BindAction("Dodge", EInputEvent::IE_Released, this, &ABCController::ActionButton3_Released);
	InputComponent->BindAction("Action", EInputEvent::IE_Pressed, this, &ABCController::ActionButton4_Pressed);
	InputComponent->BindAction("Action", EInputEvent::IE_Released, this, &ABCController::ActionButton4_Released);
	InputComponent->BindAction("Start", EInputEvent::IE_Pressed, this, &ABCController::ActionButtonStart).bExecuteWhenPaused = true;
	InputComponent->BindAction("Select", EInputEvent::IE_Pressed, this, &ABCController::ActionButtonSelect).bExecuteWhenPaused = true;
}


void ABCController::ActionButton1_Pressed()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 1 pressed from pcontroller %s"), *this->GetName());

}
void ABCController::ActionButton1_Released()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 1 released from pcontroller %s"), *this->GetName());

}

void ABCController::ActionButton2_Pressed()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 2 pressed from pcontroller %s"), *this->GetName());

}
void ABCController::ActionButton2_Released()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 2 released from pcontroller %s"), *this->GetName());

}

void ABCController::ActionButton3_Pressed()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 3 pressed from pcontroller %s"), *this->GetName());

}
void ABCController::ActionButton3_Released()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 3 released from pcontroller %s"), *this->GetName());

}

void ABCController::ActionButton4_Pressed()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 4 pressed from pcontroller %s"), *this->GetName());

}
void ABCController::ActionButton4_Released()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Button 4 released from pcontroller %s"), *this->GetName());

}


void ABCController::ActionButtonStart()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Start pressed"));

	AGM_BasicCombat* gm = Cast<AGM_BasicCombat>(UGameplayStatics::GetGameMode(GetWorld()));
	if (gm)
	{
		//if (!gm->GetHasStartedPlaying())
		//{
		//	gm->StartPlayingTrack();
		//}
		//else
		//{
			Pause();

			if (IsPaused())
			{
				gm->GetHUDBase()->ShowPauseWidget();
				gm->GetHUDBase()->ShowCursor(this, true);
			}
			else
			{
				gm->GetHUDBase()->ShowHUDWidget();
				gm->GetHUDBase()->ShowCursor(this, false);
			}
		//}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't get AGM_BasicCombat"));
	}
}

void ABCController::ActionButtonSelect()
{
	if (DEBUG)
		UE_LOG(LogTemp, Log, TEXT("Select pressed"));
}

//_______________
#pragma endregion

