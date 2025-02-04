// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DSRE/Utils/GameEnums.h"
#include "BaseController.generated.h"

/**
 *
 */
UCLASS(Blueprintable, ClassGroup = (PlayerController), meta = (BlueprintSpawnableComponent, ToolTip = "Base controller for the different GameModes"))
class DSRE_API ABaseController : public APlayerController
{
	GENERATED_BODY()

public:
	ABaseController();
	//virtual void Tick(float DeltaTime) override;

	/**Called to bind functionality to input*/
	virtual void SetupInputComponent() override { Super::SetupInputComponent(); };

#pragma region Properties
	UFUNCTION(BlueprintPure, Category = "Properties")
		FORCEINLINE float GetLife() const { return Life; };
	UFUNCTION(BlueprintPure, Category = "Properties")
		FORCEINLINE float GetMaxLife() const { return MaxLifeValue; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void AddLife(float amountToAdd = -10.f) { Life += amountToAdd; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void ResetLife() { Life = MaxLifeValue; };

	UFUNCTION(BlueprintPure, Category = "Properties")
		FORCEINLINE int32 GetPickup() const { return Pickup; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void AddPickup(int32 amountToAdd = 1) { Pickup += amountToAdd; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void ResetPickup() { Pickup = 0; };

	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		FORCEINLINE float GetAttackNormalDamage() const { return AttackNormalDamage; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		FORCEINLINE float GetAttackStrongDamage() const { return AttackStrongDamage; };

	UFUNCTION(BlueprintCallable, Category = "Properties")
		void ResetProperties() { ResetLife(); ResetPickup(); };
#pragma endregion


protected:
	virtual void BeginPlay() override;

	/** True to print log*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = "true"))
		bool DEBUG = false;

	UPROPERTY(EditAnywhere, Category = "Life")
		float MaxLifeValue = 100.f;
	UPROPERTY(VisibleAnywhere, Category = "Life")
		float Life = 0;
	UPROPERTY(VisibleAnywhere, Category = "Pickups")
		uint32 Pickup = 0;

	//TODO: move damage to character or even to sword
	UPROPERTY(EditAnywhere, Category = "Combat")
		float AttackNormalDamage = -20.f;
	UPROPERTY(EditAnywhere, Category = "Combat")
		float AttackStrongDamage = -20.f;
};
