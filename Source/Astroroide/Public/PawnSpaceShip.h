// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnSpaceShip.generated.h"

UCLASS()
class ASTROROIDE_API APawnSpaceShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnSpaceShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:

	//Components list bellow

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* Root;



	//Variables list Bellow.

public:

	/*Bullet Rate*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Details", meta = (ToolTip = "It will determine the rate of fire that the spacecraft will fire for a given time."))
		float BulletRate;

	/*Acceleration*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Details", meta = (ToolTip = "Responsible for the acceleration time from the point of inertia to maximum speed when the player moves the spaceship."))
		float Acceleration;

	/*Velocity*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Details", meta = (ToolTip = "Responsible for the displacement speed when the player moves the spaceship."))
		float Velocity;

	/*Health points*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Details", meta = (ToolTip = "Determines the amount of hit points the spaceship has before being eliminated."))
		int Health;

	/*Default damage*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Details", meta = (ToolTip = "Determines the amount of damage the spaceship has when it has no power up."))
		int InitialDamage;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BasicMovement")
		float X_ForwardBackward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BasicMovement")
		float Y_RightLeft;

public:

	//Functions list bellow.

	UFUNCTION(BlueprintCallable, Category = "BasicMovement")
		void MoveForwardBackward(float AxisValue);

	UFUNCTION(BlueprintCallable, Category  = "BasicMovement")
		void MoveRightLeft(float AxisValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "BasicMovement")
		void RotationForwardVector(FVector& Value);
};