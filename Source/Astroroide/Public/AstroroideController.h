// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// Enumeration for spaceship selected by player
#include "EPlayerSpaceships.h"

#include "SaveSpaceshipSelect.h"

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

//Save game system
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameSpaceship", meta = (ToolTip = "Save game the spaceship selected for player"))
		USaveSpaceshipSelect* SaveGameSpaceshipSelected;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "SaveGameSpaceship")
		FString SaveSpaceshipName;


	//Functions list bellow

public:

	/**Update spaceship selected for player*/
	UFUNCTION(BlueprintCallable, Category = "SpaceshipSelected")
		void SetSpaceshipSelected(FEPlayerSpaceships Select);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "SpaceshipSelected")
		void GetSpaceshipSelected(FEPlayerSpaceships& _Spaceship_Select);

	/**Save and Load Spaceship selected for player*/
	UFUNCTION(BlueprintCallable, Category = "LoadSaveSpaceship")
		void SaveSpaceshipSelected();

	UFUNCTION(BlueprintCallable, Category = "LoadSaveSpaceship")
		void LoadSpaceshipSelected();

	UFUNCTION(BlueprintCallable, Category = "LoadSaveSpaceship")
		void CreateSaveSpaceshipSelected();

	UFUNCTION(BlueprintCallable, Category = "LoadSaveSpaceship")
		void LogIfGameWasSavedOrNot(const bool IsSaved);
};
