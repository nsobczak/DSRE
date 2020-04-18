// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameConstants.generated.h"

/**
 *
 */
UCLASS(Const, NotBlueprintable, NotPlaceable, meta = (ToolTip = "Class with all game const"))
class DSRE_API UGameConstants : public UObject
{
	GENERATED_BODY()

public:
	UGameConstants() {};

	//static const FColor COLOR_TEXT_LIGHT_GRAY;
	//static const FColor COLOR_DEBUG_ARROW_PURPLE;

	static const FName COLLISION_NO_COL;
	static const FName COLLISION_PLAYER;
	static const FName COLLISION_ENEMY;
	static const FName COLLISION_PICKUP;

};
