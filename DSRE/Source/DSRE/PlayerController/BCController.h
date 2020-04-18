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


protected:
	virtual void BeginPlay() override;

	///**Whether to block inputs or not*/
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Info")
	//	bool ShouldInputBeEnabled = false;

};
