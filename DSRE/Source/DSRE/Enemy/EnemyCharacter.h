// nsobczak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DSRE_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

#pragma region Properties
	UFUNCTION(BlueprintPure, Category = "Properties")
		FORCEINLINE float GetLife() const { return Life; };
	UFUNCTION(BlueprintPure, Category = "Properties")
		FORCEINLINE float GetMaxLife() const { return MaxLifeValue; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void AddLife(float amountToAdd = -10.f);
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void ResetLife() { Life = MaxLifeValue; };

	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		FORCEINLINE float GetAttackDamage() const { return AttackDamage; };

	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		FORCEINLINE bool GetCanHit() const { return CanHit; };
	UFUNCTION(Exec, BlueprintCallable, Category = "Properties")
		void SetCanHit(bool val) { CanHit = val; };

	UFUNCTION(BlueprintCallable, Category = "Properties")
		void ResetProperties() { ResetLife(); };
#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override{Super::SetupPlayerInputComponent(PlayerInputComponent);};

	UPROPERTY(EditAnywhere, Category = "Life")
		float MaxLifeValue = 40.f;
	UPROPERTY(VisibleAnywhere, Category = "Life")
		float Life;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
		float AttackDamage = -20.f;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
		bool CanHit = false;
};
