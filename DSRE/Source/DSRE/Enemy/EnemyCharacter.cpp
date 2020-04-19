// nsobczak


#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	ResetProperties();
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyCharacter::AddLife(float amountToAdd)
{
	Life += amountToAdd;
	if (Life <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Life <= 0, destroying %s"), *GetName());
		Destroy();
	}
};
