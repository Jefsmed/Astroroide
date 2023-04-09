// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroroideController.h"

//Network rules
#include "Net/UnrealNetwork.h"

#include "Kismet/GameplayStatics.h"


AAstroroideController::AAstroroideController() {

	//Network replicate rules
	bReplicates = true;
	SetReplicates(true);

	//Checks if there are any data slots saved from the spaceship selection previously chosen by the player.
		/**Configure save name*/
	SaveSpaceshipName = "Spaceship";

	LoadSpaceshipSelected();

	if (SpaceshipSelected == FEPlayerSpaceships::None) {

		CreateSaveSpaceshipSelected();

	}

}

// Network replicate rules
void AAstroroideController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAstroroideController, SpaceshipSelected);

}


void AAstroroideController::SetSpaceshipSelected(FEPlayerSpaceships Select) {

	SpaceshipSelected = Select;

	SaveSpaceshipSelected();

}

void AAstroroideController::GetSpaceshipSelected(FEPlayerSpaceships& _SpaceshipSelect) {

	LoadSpaceshipSelected();

	_SpaceshipSelect = SpaceshipSelected;

}


// Save and Load spaceship selected for player
void AAstroroideController::SaveSpaceshipSelected() {

	//Print string---> GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saving game..."));

	if (SaveGameSpaceshipSelected == nullptr){

		CreateSaveSpaceshipSelected();
	}

	SaveGameSpaceshipSelected->SaveSpaceshipSelect = SpaceshipSelected;

	const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameSpaceshipSelected, SaveSpaceshipName, 0);

	//- Print string-> LogIfGameWasSavedOrNot(IsSaved);

}

void AAstroroideController::LoadSpaceshipSelected() {
	
	USaveGame* LoadedSpaceship = UGameplayStatics::LoadGameFromSlot(SaveSpaceshipName, 0);
	SaveGameSpaceshipSelected = Cast<USaveSpaceshipSelect>(LoadedSpaceship);

	//Print string---> GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Trying to load a saved game. SaveGameSpaceshipSelected->SpaceshipSelect"));

	if (LoadedSpaceship!=SaveGameSpaceshipSelected) {

		CreateSaveSpaceshipSelected();

		//Print string---> GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("No saved games found. Trying to save a new one."));

	}
	else {

		SpaceshipSelected = SaveGameSpaceshipSelected->SaveSpaceshipSelect;

		//Print string---> GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saved game found. Loaded."));
	}
		
}

void AAstroroideController::CreateSaveSpaceshipSelected() {

	SaveGameSpaceshipSelected = Cast<USaveSpaceshipSelect>(UGameplayStatics::CreateSaveGameObject(USaveSpaceshipSelect::StaticClass()));
	SaveGameSpaceshipSelected->SaveSpaceshipSelect = SpaceshipSelected;
	const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameSpaceshipSelected, SaveSpaceshipName, 0);

	SpaceshipSelected = SaveGameSpaceshipSelected->SaveSpaceshipSelect;

	//- Print string-> LogIfGameWasSavedOrNot(IsSaved);

}

void AAstroroideController::LogIfGameWasSavedOrNot(const bool IsSaved) {

	if (IsSaved)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Game saved."));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Cannot save the game."));
	}

}