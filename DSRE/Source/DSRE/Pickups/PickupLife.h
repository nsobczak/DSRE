#pragma once

#include "CoreMinimal.h"
#include "DSRE/Pickups/Pickup.h"
#include "PickupLife.generated.h"

/**
 *
 */
UCLASS(Blueprintable, ClassGroup = (Pickup), meta = (BlueprintSpawnableComponent, ToolTip = "Life pickup"))
class DSRE_API APickupLife : public APickup
{
	GENERATED_BODY()


public:
	APickupLife() {};

	/**Override the wasCollected function, use Implementation cause it's a blueprint native event*/
	void WasCollected_Implementation() override { Super::WasCollected_Implementation(); };

	UFUNCTION(BlueprintPure, Category = "Life")
		FORCEINLINE float GetLifeAmount()const { return LifeAmount; };

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
		float LifeAmount = 20.0f;

};
