// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DSRE/DSREGameModeBase.h"
#include "GM_BasicCombat.generated.h"

/**
 *
 */
UCLASS(Blueprintable, ClassGroup = (GameMode), meta = (BlueprintSpawnableComponent, ToolTip = "For basic combat mode"))
class DSRE_API AGM_BasicCombat : public ADSREGameModeBase
{
	GENERATED_BODY()

public:
	AGM_BasicCombat();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "GameMode_Parameters")
		FORCEINLINE class ABCController* GetPController() const { return PController; };

protected:
	virtual void InitParamPointers() override;
	virtual void BeginPlay() override;
	virtual void Win() override;
	virtual void GameOver() override;

	UPROPERTY(VisibleAnywhere, Category = "Debug", AdvancedDisplay)
		class ABCController* PController;

	/** Static mesh plane for fog*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FogOfWar")
		class UStaticMeshComponent* FogPlane;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FogOfWar")
		float UnfogRadius = 5.f;
};
