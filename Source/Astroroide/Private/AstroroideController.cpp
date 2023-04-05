// Fill out your copyright notice in the Description page of Project Settings.


#include "AstroroideController.h"

//Network rules
#include "Net/UnrealNetwork.h"

#include "Kismet/GameplayStatics.h"


AAstroroideController::AAstroroideController() {

	//Network replicate rules
	bReplicates = true;
	SetReplicates(true);

	SpaceshipSelected = FEPlayerSpaceships::None;
	SaveSpaceshipName = "Spaceship";

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

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saving game..."));

	SaveGameSpaceshipSelected->SpaceshipSelect = SpaceshipSelected;

	const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameSpaceshipSelected, SaveSpaceshipName, 0);

	LogIfGameWasSavedOrNot(IsSaved);

}

void AAstroroideController::LoadSpaceshipSelected() {

	USaveGame* LoadedSpaceship = UGameplayStatics::LoadGameFromSlot(SaveSpaceshipName, 0);
	SaveGameSpaceshipSelected = Cast<USaveSpaceshipSelect>(LoadedSpaceship);

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Trying to load a saved game."));

	if (!SaveGameSpaceshipSelected) {

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("No saved games found. Trying to save a new one."));

		SaveGameSpaceshipSelected = Cast<USaveSpaceshipSelect>(UGameplayStatics::CreateSaveGameObject(USaveSpaceshipSelect::StaticClass()));
		const bool IsSaved = UGameplayStatics::SaveGameToSlot(SaveGameSpaceshipSelected, SaveSpaceshipName, 0);

		SpaceshipSelected = SaveGameSpaceshipSelected->SpaceshipSelect;

		LogIfGameWasSavedOrNot(IsSaved);

	}
	else {

		SpaceshipSelected = SaveGameSpaceshipSelected->SpaceshipSelect;

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Saved game found. Loaded."));

	}

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