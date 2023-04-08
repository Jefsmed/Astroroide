// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AstroroideGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASTROROIDE_API AAstroroideGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this Game Mode's properties
	AAstroroideGameModeBase();

	virtual void PostLogin(APlayerController* NewPlayer);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "PlayerController")
		APlayerController* CurrentController;

};
