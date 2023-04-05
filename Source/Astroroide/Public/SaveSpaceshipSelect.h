// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "EPlayerSpaceships.h"

#include "SaveSpaceshipSelect.generated.h"

/**
 * 
 */
UCLASS()
class ASTROROIDE_API USaveSpaceshipSelect : public USaveGame
{
	GENERATED_BODY()

public:

	USaveSpaceshipSelect();

	UPROPERTY(BlueprintReadWrite)
		FEPlayerSpaceships SpaceshipSelect;
	
};
