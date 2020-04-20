// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DSRE/PlayerController/BaseController.h"
#include "BCController.generated.h"

/**
 *
 */
UCLASS(Blueprintable, ClassGroup = (PlayerController), meta = (BlueprintSpawnableComponent, ToolTip = "Controller for basic combat mode"))
class DSRE_API ABCController : public ABaseController
{
	GENERATED_BODY()

public:
	ABCController();

#pragma region Input
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton1_Pressed();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton1_Released();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton2_Pressed();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton2_Released();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton3_Pressed();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton3_Released();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton4_Pressed();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButton4_Released();

	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButtonStart();
	UFUNCTION(BlueprintCallable, exec, Category = "Controller")
		void ActionButtonSelect();
#pragma endregion

	UFUNCTION(BlueprintPure, Category = "State")
		FORCEINLINE bool GetCanHit() const { return bCanHit; };
	UFUNCTION(Exec, BlueprintCallable, Category = "State")
		void SetCanHit(bool canHit) { bCanHit = canHit; };

	UFUNCTION(BlueprintPure, Category = "State")
		FORCEINLINE bool GetCanBeHit() const { return bCanBeHit; };
	UFUNCTION(Exec, BlueprintCallable, Category = "State")
		void SetCanBeHit(bool canBeHit) { bCanBeHit = canBeHit; };

	UFUNCTION(BlueprintPure, Category = "State")
		FORCEINLINE FText GetCurrentArea() const { return CurrentArea; };
	UFUNCTION(Exec, BlueprintCallable, Category = "State")
		void SetCurrentArea(FText name) { UE_LOG(LogTemp, Log, TEXT("SetCurrentArea called")); CurrentArea = name; };

protected:
	virtual void BeginPlay() override;

	/**Whether to enable damage on enemy or not*/
	UPROPERTY(VisibleAnywhere, Category = "State")
		bool bCanHit = false;
	/**Whether to enable damage on self or not*/
	UPROPERTY(VisibleAnywhere, Category = "State")
		bool bCanBeHit = true;

	UPROPERTY(VisibleAnywhere, Category = "State")
		FText CurrentArea = FText::FromString("Area Name");
};
