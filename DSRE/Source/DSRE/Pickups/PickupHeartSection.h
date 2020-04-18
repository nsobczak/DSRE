// nsobczak

#pragma once

#include "CoreMinimal.h"
#include "DSRE/Pickups/Pickup.h"
#include "PickupHeartSection.generated.h"

/**
 *
 */
UCLASS(Blueprintable, ClassGroup = (Pickup), meta = (BlueprintSpawnableComponent, ToolTip = "Heart section pickup"))
class DSRE_API APickupHeartSection : public APickup
{
	GENERATED_BODY()


public:
	APickupHeartSection() {};

	/**Override the wasCollected function, use Implementation cause it's a blueprint native event*/
	void WasCollected_Implementation() override { Super::WasCollected_Implementation(); };

	UFUNCTION(BlueprintPure, Category = "HeartSection")
		FORCEINLINE int32 GetHSectionAmount() const { return HSectionAmount; };

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartSection")
		int32 HSectionAmount = 1;
};
