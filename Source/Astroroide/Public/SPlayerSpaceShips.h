// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPlayerSpaceShips.generated.h"


USTRUCT(BlueprintType)
struct ASTROROIDE_API FSPlayerSpaceShips  {

public: 

	GENERATED_BODY()

		//The following member variable will be accessible by Blueprint Graphs.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpaceshipMesh")
		USkeletalMesh* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
		float BulletRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
		float Acceleration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
		int HealthPoints;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
		int InitialDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Details")
		int PointForUnlock;

	FSPlayerSpaceShips();
	~FSPlayerSpaceShips();

	UPROPERTY()
		UObject* SafeObjectPointer;
	
};
