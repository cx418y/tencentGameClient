// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveObj/ScoreBall.h"
#include "Components/SphereComponent.h"
#include "AttributerComponent.h"
#include "Logging/LogMacros.h"
#include "UObject/Field.h"
#include "ScoreComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AScoreBall::AScoreBall()
{

    // UE_LOG(LogTemp, Log, TEXT("Construct ball"));
    SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
    RootComponent = SphereComp;

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
    StaticMeshComp->SetupAttachment(SphereComp);

    SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AScoreBall::OnActorOverlap);

    // HitSound = LoadObject<USoundCue>(this, TEXT("SoundCue'/Game/Interface_And_Item_Sounds/Cues/Coins_01_Cue.Coins_01_Cue'"));


   // AttributeComp->OnHealthChanged.AddDynamic(this, &ASTargetDummy::OnHealthChanged);

}

// void AScoreBall::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
// {
//     // UE_LOG(LogTemp, Log, TEXT("OtherActor: %s"), GetNameSafe(OtherActor));
//     UE_LOG(LogTemp, Log, TEXT("Enter"));
//     if (OtherActor)
//     {
//         UE_LOG(LogTemp, Log, TEXT("OtherActor: %s"), GetNameSafe(OtherActor));
//         UAttributerComponent* AttributerComp = Cast<UAttributerComponent> ( OtherActor->GetComponentByClass(UAttributerComponent::StaticClass()));
//         
//         UE_LOG(LogTemp, Log, TEXT("Attri: %s"), GetNameSafe(AttributerComp)); 
//         if (AttributerComp)
//         {
//             
//             AttributerComp->ScoreChange(5);
//             Destroy();
//         }
// 
//     }
// }

void AScoreBall::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor)
    {
        UScoreComponent* ScoreComponent = Cast<UScoreComponent>(OtherActor->GetComponentByClass(UScoreComponent::StaticClass()));
        if (ScoreComponent)
        {
            ScoreComponent->ApplyScoreChange(5);
            UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
            Destroy();
        }

    }
}

