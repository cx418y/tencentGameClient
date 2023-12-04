// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Misc/AssertionMacros.h"
#include "AttributerComponent.h"
#include "Logging/LogMacros.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"

// Sets default values
AProjectileBase::AProjectileBase()
{

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentHit.AddDynamic(this, &AProjectileBase::OnActorHit);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AProjectileBase::OnActorOverlap);
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(RootComponent);

	AudioComp = CreateDefaultSubobject<UAudioComponent>("AudioComp");
	AudioComp->SetupAttachment(RootComponent);

	MoveComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMoveComp");
	MoveComp->bRotationFollowsVelocity = true;
	MoveComp->bInitialVelocityInLocalSpace = true;
	MoveComp->ProjectileGravityScale = 0.0f;
	MoveComp->InitialSpeed = 8000;

	InitialLifeSpan = 3.0f;

	DamageAmount = 20;

}

void AProjectileBase::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	//UE_LOG(LogTemp, Log, TEXT("enter onActorHit"));
	
// 	if (OtherActor && OtherActor != GetInstigator())
// 	{
// 		// UE_LOG(LogTemp, Log, TEXT("OtherActor is exist"));
// 		// UE_LOG(LogTemp, Warning, TEXT("The Actor's name is %s"), *GetNameSafe(OtherActor));
// 		UAttributerComponent* AttributerComp = Cast<UAttributerComponent>(OtherActor->GetComponentByClass(UAttributerComponent::StaticClass()));
// 		if (AttributerComp)
// 		{
// 			AttributerComp->ApplyHealthChange(-DamageAmount);
// 			Destroy();
// 		}
// 	}
	Explode();
}

// _Implementation from it being marked as BlueprintNativeEvent
void AProjectileBase::Explode_Implementation()
{
	// Check to make sure we aren't already being 'destroyed'
	// Adding ensure to see if we encounter this situation at all
	if (ensure(!IsPendingKill()))
	{
// 		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
// 
// 		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());

		// UGameplayStatics::PlayWorldCameraShake(this, ImpactShake, GetActorLocation(), ImpactShakeInnerRadius, ImpactShakeOuterRadius);

		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
		Destroy();
	}
}

void AProjectileBase::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Log,TEXT("enter onActorOverlap"));
	UE_LOG(LogTemp, Warning, TEXT("The Instigateor's name is %s"), *GetNameSafe(GetInstigator()));
	if (OtherActor && OtherActor != GetInstigator())
	{
		UAttributerComponent* AttributeComp = Cast<UAttributerComponent>(OtherActor->GetComponentByClass(UAttributerComponent::StaticClass()));
		if (AttributeComp)
		{
			UE_LOG(LogTemp, Log, TEXT("enter DamageAmount"));
			// minus in front of DamageAmount to apply the change as damage, not healing
			AttributeComp->ApplyHealthChange(-DamageAmount);

			// Only explode when we hit something valid
			Explode();
		}
	}
}

