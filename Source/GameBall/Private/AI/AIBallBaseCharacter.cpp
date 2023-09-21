// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIBallBaseCharacter.h"
#include "Components/SphereComponent.h"
#include "AIController.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseOverlap, All, All);

AAIBallBaseCharacter::AAIBallBaseCharacter(
    const FObjectInitializer& ObjInit){
  AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
  AIControllerClass = AAIController::StaticClass();

  CollisionComponent =
      CreateDefaultSubobject<USphereComponent>("SphereComponent");
  CollisionComponent->InitSphereRadius(50.0f);
  CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

}

void AAIBallBaseCharacter::BeginPlay() 
{ Super::BeginPlay(); }

void AAIBallBaseCharacter::NotifyActorBeginOverlap(AActor* OtherActor) {
  Super::NotifyActorBeginOverlap(OtherActor);
  UE_LOG(LogBaseOverlap, Display, TEXT("OVERLAP"));
  if(OtherActor == nullptr) {
    Destroy();
  }
 }

void AAIBallBaseCharacter::Tick(float DeltaTime) {}



