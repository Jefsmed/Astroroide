// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipChar.h"
//Network rules
#include "Net/UnrealNetwork.h"

// Sets default values
ASpaceshipChar::ASpaceshipChar ()
{
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Network replicate rules
	bReplicates = true;
	SetReplicates(true);


}


// Network replicate rules
void ASpaceshipChar::GetLifetimeReplicatedProps(TArray< FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASpaceshipChar, Health);

}

// Called when the game starts or when spawned
void ASpaceshipChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceshipChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceshipChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

