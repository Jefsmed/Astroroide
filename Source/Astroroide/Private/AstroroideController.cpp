// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroroideController.h"

//Network rules
#include "Net/UnrealNetwork.h"


AAstroroideController::AAstroroideController() {

	//Network replicate rules
	bReplicates = true;
	SetReplicates(true);

	SpaceshipSelected = FEPlayerSpaceships::None;

}

// Network replicate rules
void AAstroroideController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAstroroideController, SpaceshipSelected);

}
