// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVING_GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray <AActor*> GetPAtrolPoint() const;


private:
	UPROPERTY(EditAnywhere, Category = "Patrol Points")
		TArray <AActor*> PatrolPoints;
	
};
