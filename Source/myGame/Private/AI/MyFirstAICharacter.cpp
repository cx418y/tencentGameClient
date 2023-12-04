// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/MyFirstAICharacter.h"
#include "AttributerComponent.h"
#include "AIController.h"
#include "BrainComponent.h"
#include "GameFramework/Pawn.h"

// Sets default values
AMyFirstAICharacter::AMyFirstAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttributeComp = CreateDefaultSubobject<UAttributerComponent>(TEXT("AttributeComp"));

}

// Called when the game starts or when spawned
void AMyFirstAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyFirstAICharacter::OnHealthChanged(AActor* InstigatorActor, UAttributerComponent* OwningComp, float NewHealth, float Delta)
{
	if (NewHealth <= 0.0f && Delta < 0.0f)
	{
		AAIController* AIC = Cast<AAIController>(GetController());
		if (AIC)
		{
			AIC->GetBrainComponent()->StopLogic("Killed");
		}

		GetMesh()->SetAllBodiesSimulatePhysics(true);
		GetMesh()->SetCollisionProfileName("Ragdoll");
		Destroy();

		// SetLifeSpan(5.0f);

	}
}

void AMyFirstAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	AttributeComp->OnHealthChanged.AddDynamic(this, &AMyFirstAICharacter::OnHealthChanged);
}

// Called every frame
void AMyFirstAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFirstAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

