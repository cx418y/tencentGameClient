// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreComponent.h"

// Sets default values for this component's properties
UScoreComponent::UScoreComponent()
{

	Score = 0.0f;

	// ...
}

bool UScoreComponent::ApplyScoreChange(float Delta)
{
	Score += Delta;
	OnScoreChanged.Broadcast(nullptr, this, Score, Delta);
	return Delta != 0;
}



