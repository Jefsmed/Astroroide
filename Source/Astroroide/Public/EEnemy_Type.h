// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EEnemy_Type.generated.h"


UENUM(BlueprintType)
enum class FEEnemy_Type : uint8
{
	/**None*/
	None = 0 UMETA(DisplayName = "None"),

	/**Minion*/
	Minion = 1 UMETA(DisplayName = "Minion"),

	/**Smaller - Menor*/
	Smaller = 2 UMETA(DisplayName = "Smaller"),

	/**Medium - Medio*/
	Medium = 3 UMETA(DisplayName = "Medium"),

	/**Big - Grande*/
	Big = 4 UMETA(DisplayName = "Medium"),
	
};
