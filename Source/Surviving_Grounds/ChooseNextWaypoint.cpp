// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"



 EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	 //UE_LOG(LogTemp, Warning, TEXT("AI in C++"));



	 //Get patrol points

	 auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	 auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	 if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	 auto PatrolPoints = PatrolRoute->GetPAtrolPoint();
	 if (PatrolPoints.Num() == 0) 
	 {
		 UE_LOG(LogTemp, Warning, TEXT("A guard is mising patrol points"));
		 return EBTNodeResult::Failed;
	 }

	 //Set Next Waypoint

	 auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	 auto index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	 BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[index]);

	 //Cycle Index

	 auto NextIndex = (index + 1) % PatrolPoints.Num();
	 BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);



	 

	 UE_LOG(LogTemp, Warning, TEXT("waypoint index: %i"), index);
	 return EBTNodeResult::Succeeded;
}

