// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Tile.generated.h"

UCLASS()
class SURVIVING_GROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radious = 500);
	
private:

	bool FindEmptyLocation(FVector& OutLocation, float Radious);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint);

	bool CanSpawnAtLocation(FVector Location, float Radious);

};
