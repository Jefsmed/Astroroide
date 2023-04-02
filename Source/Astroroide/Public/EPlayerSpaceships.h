// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EPlayerSpaceships.generated.h"

UENUM(BlueprintType)
enum class FEPlayerSpaceships : uint8
{
	/**None*/
	None = 0 UMETA(DisplayName = "None"),
	/**Fighter*/
	Fighter = 1 UMETA(DisplayName = "Fighter"),
	/**Star Fighter*/
	StarFighter = 2 UMETA(DisplayName = "StarFighter"),
	/**Frigate*/
	Frigate = 3 UMETA(DisplayName = "Frigate"),
	/**Destroyer*/
	Destroyer = 4 UMETA(DisplayName = "Destroyer"),
	
};
