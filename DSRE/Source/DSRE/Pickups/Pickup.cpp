#include "Pickup.h"
#include "Components/StaticMeshComponent.h"
#include "DSRE/Utils/GameConstants.h"
#include "DSRE/Utils/RotateOverTime.h"

APickup::APickup()
{
	PrimaryActorTick.bCanEverTick = false;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = (USceneComponent*)PickupMesh;
	PickupMesh->SetGenerateOverlapEvents(true);
	PickupMesh->SetCollisionProfileName(UGameConstants::COLLISION_PICKUP);

	bIsActive = true;

	URotateOverTime* rotationComponent = CreateDefaultSubobject<URotateOverTime>(TEXT("RotationOverTime"));
	AddOwnedComponent(rotationComponent);
}

void APickup::BeginPlay()
{
	Super::BeginPlay();

}

void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APickup::SetActive(bool newPickupState)
{
	bIsActive = newPickupState;

	//Destroy if not active
	if (!bIsActive)
	{
		Destroy();
	}
}

void APickup::WasCollected_Implementation()
{
	FString pickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("Player collected %s"), *pickupDebugString);
	PickedUpEffect();
}
