// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIBallBaseController.h"
#include "AI/AIBallBaseCharacter.h"
#include "Components/BallAIPerceptionComponent.h"

AAIBallBaseController::AAIBallBaseController()
{
  BallAIPerceptionComponent =
      CreateDefaultSubobject<UBallAIPerceptionComponent>(
          "BallAIPerceptionComponent");
  SetPerceptionComponent(*BallAIPerceptionComponent);
}

void AAIBallBaseController::OnPossess(APawn* InPawn) {

	Super::OnPossess(InPawn);

	const auto BallBaseCharacter = Cast<AAIBallBaseCharacter>(InPawn);
	if(BallBaseCharacter)
		{
          /*RunBehaviorTree(BallBaseCharacter->BehaviorTreeAsset);*/
	}
}