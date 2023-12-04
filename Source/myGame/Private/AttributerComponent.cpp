// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributerComponent.h"

// Sets default values for this component's properties
UAttributerComponent::UAttributerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	HealthMax = 100.0f;
	Health = HealthMax;
}

bool UAttributerComponent::ApplyHealthChange(float Delta)
{
	float OldHealth = Health;

	Health = FMath::Clamp(Health + Delta, 0.0f, HealthMax);  // clamp可以将值限制在某个范围


	float ActualDelta = Health - OldHealth;

	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);
	return ActualDelta != 0;
}

bool UAttributerComponent::IsAlive() const
{
	return Health > 0.0f;
}

