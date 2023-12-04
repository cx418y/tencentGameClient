// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnScoreChanged, AActor*, InstigatorActor, UScoreComponent*, OwningComp, float, NewScore, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UScoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreComponent();

	UFUNCTION()
	bool ApplyScoreChange(float Delta);
	
	UPROPERTY(BlueprintAssignable)
	FOnScoreChanged OnScoreChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category="Attributes")
	float Score;

		
};
