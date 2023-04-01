// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EEnemyType.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class ASTROROIDE_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Components list bellow

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* Mesh;
		
//Variables list bellow

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
		Bool IsAlien;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
		EEnemyType Type;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config")
		int PointsForDestroyingIt;
		

};
