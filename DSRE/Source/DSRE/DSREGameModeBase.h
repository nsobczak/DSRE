// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HUDClass/HUD_Base.h"
#include "DSREGameModeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (GameMode), meta = (BlueprintSpawnableComponent, ToolTip = "Base class for DSRE GameModes"))
class DSRE_API ADSREGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ADSREGameModeBase();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "GameMode_Parameters")
		FORCEINLINE  class AHUD_Base* GetHUDBase() const { return HUDBase; };
	
	UFUNCTION(BlueprintCallable, Category = "GameMode_Parameters")
		FORCEINLINE  class APlayerController* GetPControllerBase() const { return PControllerBase; };

	UFUNCTION(BlueprintPure, Category = "Track")
		FORCEINLINE bool GetIsGameOver() const { return bIsGameOver; };

protected:
	virtual void InitParamPointers();
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "GameMode_Flow")
		virtual void Win();
	UFUNCTION(BlueprintCallable, Category = "GameMode_Flow")
		virtual void GameOver();

	UPROPERTY(VisibleAnywhere, Category = "GameMode_Flow", AdvancedDisplay)
		bool bHasStartedPlaying = false;
	UPROPERTY(VisibleAnywhere, Category = "GameMode_Flow", AdvancedDisplay)
		bool bIsGameOver = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = "true"))
		bool DEBUG = false;

	UPROPERTY(VisibleAnywhere, Category = "Debug", AdvancedDisplay)
		class AHUD_Base* HUDBase;

	UPROPERTY(VisibleAnywhere, Category = "Debug", AdvancedDisplay)
	class APlayerController* PControllerBase;

	/** Main theme for the map*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
		class USoundBase* MapTheme;

	/** AudioComponent currently playing*/
	UPROPERTY(BlueprintReadOnly, Category = "Audio")
		class UAudioComponent* CurrentTheme_AC;
};
