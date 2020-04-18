// Copyright 2020 nsocbzak. All rights reserved.

#include "BaseController.h"

// Sets default values
ABaseController::ABaseController()
{
	//RootComponent = GetCapsuleComponent();
	PrimaryActorTick.bCanEverTick = true; // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bTickEvenWhenPaused = true;
}

// Called when the game starts or when spawned
void ABaseController::BeginPlay()
{
	Super::BeginPlay();

	ResetProperties();
}


//void ABCController::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//
//}