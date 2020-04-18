// Copyright 2020 nsocbzak. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameEnums.generated.h"

#pragma region Game
UENUM(BlueprintType)
enum class EGameDifficulty : uint8
{
	EGD_EASY UMETA(DisplayName = "Easy"),
	EGD_MEDIUM UMETA(DisplayName = "Medium"),
	EGD_HARD UMETA(DisplayName = "Hard"),
	EGD_EXPERT UMETA(DisplayName = "Expert")
};

#pragma endregion

/**
 *
 */
UCLASS(NotBlueprintable, NotPlaceable, meta = (ToolTip = "GameEnums"))
class DSRE_API UGameEnums : public UObject
{
	GENERATED_BODY()

public:
	UGameEnums() {};

	UFUNCTION(BlueprintPure, Category = "GameEnums")
		static EGameDifficulty GetEGameDifficultyFromInt(int32 n)
	{
		EGameDifficulty diff;
		switch (n)
		{
		case 1:
			diff = EGameDifficulty::EGD_EASY;
			break;
		case 2:
			diff = EGameDifficulty::EGD_MEDIUM;
			break;
		case 3:
			diff = EGameDifficulty::EGD_HARD;
			break;
		case 4:
			diff = EGameDifficulty::EGD_EXPERT;
			break;
		default:
			diff = EGameDifficulty::EGD_MEDIUM;
			break;
		}
		return diff;
	}
};
