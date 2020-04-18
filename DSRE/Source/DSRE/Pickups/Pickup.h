#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS(Blueprintable, ClassGroup = (Pickup), meta = (BlueprintSpawnableComponent, ToolTip = "Base class for pickups, not abstract, can be spawned"))
class DSRE_API APickup : public AActor
{
	GENERATED_BODY()

public:
	APickup();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** return the mesh for the pickup*/
	UFUNCTION(BlueprintPure, Category = "Mesh")
		FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintPure, Category = "Pickup")
		FORCEINLINE bool IsActive() const { return bIsActive; };

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool newPickupState);

	/**function to call when the pickup is collected*/
	UFUNCTION(BlueprintNativeEvent)
		void WasCollected();
	virtual void WasCollected_Implementation();

protected:
	virtual void BeginPlay() override;

	/** true when pickup is used, and false when it is deactivated*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
		bool bIsActive;

	/** Static mesh to represent the pickup in the level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
		void PickedUpEffect();
};
