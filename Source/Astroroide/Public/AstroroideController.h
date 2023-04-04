// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// Enumeration for spaceship selected by player
#include "EPlayerSpaceships.h"

#include "GameFramework/PlayerController.h"
#include "AstroroideController.generated.h"


UCLASS()
class ASTROROIDE_API AAstroroideController : public APlayerController
{
	GENERATED_BODY()

public:

	AAstroroideController();

public:

	//Network replicates rules
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps) const override;


//Variables list bellow

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta = (ToolTip = "Enumerator will determine which spaceship was chosen by the player."))
		FEPlayerSpaceships SpaceshipSelected;
	
};
