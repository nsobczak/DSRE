// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TranslateOverTime.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DSRE_API UTranslateOverTime : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTranslateOverTime();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Translastion")
		FVector TranslationVectorPerSecond = FVector(100.0f, 0, 0);
};
