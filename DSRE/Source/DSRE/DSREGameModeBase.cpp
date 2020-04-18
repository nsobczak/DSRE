#include "DSREGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ADSREGameModeBase::ADSREGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("/Game/Player/BP_StaticDummyPawn"));
	if (PlayerPawnObject.Succeeded())
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}

	static ConstructorHelpers::FClassFinder<AHUD> HUDObject(TEXT("/Script/DSRE.HUD_Base"));
	if (HUDObject.Succeeded())
	{
		HUDClass = HUDObject.Class;
	}
}


void ADSREGameModeBase::InitParamPointers()
{
	TArray<AActor*> FoundActors;

	// Look for AHUD_Base
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHUD_Base::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
		HUDBase = Cast<AHUD_Base>(FoundActors[0]);
	else
		UE_LOG(LogTemp, Error, TEXT("AHUD_Base not found in level"));

	// Look for APlayerController
	PControllerBase = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PControllerBase)
		UE_LOG(LogTemp, Error, TEXT("Could not find a PControllerBase"));

}

void ADSREGameModeBase::GameOver()
{
	UE_LOG(LogTemp, Log, TEXT("Game Over"));

	bHasStartedPlaying = false;
	bIsGameOver = true;

}

void ADSREGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	InitParamPointers();

	if (HUDBase && PControllerBase)
	{
		HUDBase->ShowCursor(PControllerBase, true);
	}
}

void ADSREGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

