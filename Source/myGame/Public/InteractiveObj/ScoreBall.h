// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreBall.generated.h"

UCLASS()
class MYGAME_API AScoreBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreBall();


protected:

		UPROPERTY(VisibleAnywhere, Category = "Components")
	    class USphereComponent* SphereComp;

		UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* StaticMeshComp;

		UPROPERTY(EditAnywhere, Category= "Audio")
		class USoundCue* HitSound;

// 		UFUNCTION()
// 		virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

		UFUNCTION()
		void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



};
