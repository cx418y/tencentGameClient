// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MyFirstAIController.h"

void AMyFirstAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
}
