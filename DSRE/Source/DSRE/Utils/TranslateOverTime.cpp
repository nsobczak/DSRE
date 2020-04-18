// Copyright 2020 nsocbzak. All rights reserved.

#include "TranslateOverTime.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UTranslateOverTime::UTranslateOverTime()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UTranslateOverTime::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOwner()->AddActorLocalOffset(TranslationVectorPerSecond * DeltaTime, false, nullptr, ETeleportType::TeleportPhysics);
}

