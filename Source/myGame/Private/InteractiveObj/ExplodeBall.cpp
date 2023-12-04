// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObj/ExplodeBall.h"
#include "AttributerComponent.h"
#include "Components/SphereComponent.h"
#include "Components/AudioComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AExplodeBall::AExplodeBall()
{
    SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
    RootComponent = SphereComp;

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
    StaticMeshComp->SetupAttachment(SphereComp);

    SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AExplodeBall::OnActorOverlap);

    // HitSound = LoadObject<USoundCue>(this, TEXT("SoundCue'/Game/Interface_And_Item_Sounds/Cues/Error_Buzz_05_Cue.Error_Buzz_05_Cue'"));

}

void AExplodeBall::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        UAttributerComponent* AttributerComp = Cast<UAttributerComponent>(OtherActor->GetComponentByClass(UAttributerComponent::StaticClass()));
        if (AttributerComp)
        {
            AttributerComp->ApplyHealthChange(-20);
            // UGameplayStatics::PlaySoundAtLocation(this, ImpactSound->Sound, GetActorLocation(), GetActorRotation(), 1, 1, 0, nullptr, nullptr, nullptr);
            UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
            Destroy();
        }

    }
}


