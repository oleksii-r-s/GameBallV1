// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/CleanerFindBallBTService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "CleanerFindBallBTService.h"
#include "Components/BallAIPerceptionComponent.h"

UCleanerFindBallBTService::UCleanerFindBallBTService() {
  NodeName = "Find Enemy";
}

void UCleanerFindBallBTService::TickNode(UBehaviorTreeComponent& OwnerComp,
                                         uint8* NodeMemory,
                                         float DeltaSeconds) 
{
  const auto Blackboard = OwnerComp.GetBlackboardComponent();
  if(Blackboard) {
    const auto Controller = OwnerComp.GetAIOwner();
    const auto PerceptionComponent =
        GetBallBaseComponent<UBallAIPerceptionComponent>(Controller);
    if(PerceptionComponent) {
      Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName,
                                   PerceptionComponent->GetClosestEnemy());
    }
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
  }
}
