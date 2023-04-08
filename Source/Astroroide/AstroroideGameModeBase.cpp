// Copyright Epic Games, Inc. All Rights Reserved.


#include "AstroroideGameModeBase.h"
#include "AstroroideController.h"
#include "SpaceshipChar.h"


// Sets default values
AAstroroideGameModeBase::AAstroroideGameModeBase() {

	DefaultPawnClass = ASpaceshipChar::StaticClass();
	PlayerControllerClass = AAstroroideController::StaticClass();

}

void AAstroroideGameModeBase::PostLogin(APlayerController* NewPlayer) {

	CurrentController = Cast<AAstroroideController>(NewPlayer);

}



// Called when the game starts or when spawned
void AAstroroideGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	

}
