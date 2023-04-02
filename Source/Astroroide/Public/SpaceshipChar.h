// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceshipChar.generated.h"


UCLASS()
class ASTROROIDE_API ASpaceshipChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceshipChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Network replicates rules
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps) const override;



	//Variables list Bellow.

public:

	/*Bullet Rate*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Configuration|Details", meta = (ToolTip = "It will determine the rate of fire that the spacecraft will fire for a given time."))
		float BulletRate;

	/*Acceleration*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Configuration|Details", meta = (ToolTip = "Responsible for the acceleration time from the point of inertia to maximum speed when the player moves the spaceship."))
		float Acceleration;

	/*Health points*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Configuration|Details", meta = (ToolTip = "Determines the amount of hit points the spaceship has before being eliminated."))
		int Health;

	/*Default damage*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Configuration|Details", meta = (ToolTip = "Determines the amount of damage the spaceship has when it has no power up."))
		int InitialDamage;




};
