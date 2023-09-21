// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIBallBaseController.generated.h"

/**
 * 
 */
class UBallAIPerceptionComponent;

UCLASS()
class GAMEBALL_API AAIBallBaseController : public AAIController
{
  GENERATED_BODY()
 public:
  AAIBallBaseController();

 protected:
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
  UBallAIPerceptionComponent* BallAIPerceptionComponent;
  virtual void OnPossess(APawn* InPawn) override;
};
