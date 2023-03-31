// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnSpaceShip.h"

// Sets default values
APawnSpaceShip::APawnSpaceShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Components attachments

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	Root->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APawnSpaceShip::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APawnSpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnSpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



//Basic Movements - Replicated Network

void APawnSpaceShip::MoveForwardBackward(float AxisValue) {

	X_ForwardBackward = 1 * AxisValue;
	AddActorLocalOffset(FVector(X_ForwardBackward, 0, 0));

}

void APawnSpaceShip::MoveRightLeft(float AxisValue) {

	Y_RightLeft = 1 * AxisValue;
	AddActorLocalOffset(FVector(0, Y_RightLeft, 0));

}

void APawnSpaceShip::RotationForwardVector(FVector& Value) {
	
	Value = FVector(FMath::Clamp(X_ForwardBackward, -1.0f, 1.0f), FMath::Clamp(Y_RightLeft, -1.0f, 1.0f), 0);

}