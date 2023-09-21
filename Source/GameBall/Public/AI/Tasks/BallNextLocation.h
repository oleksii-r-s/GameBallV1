#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BallNextLocation.generated.h"

UCLASS()
class GAMEBALL_API UBallNextLocation : public UBTTaskNode
{
	GENERATED_BODY()
 public:
        UBallNextLocation();
  virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
                                          uint8* NodeMemory) override;

  /*virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
                                          uint8* NodeMemory) override;*/

 protected:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
  float Radius = 1000.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
  FBlackboardKeySelector AimLocationKey;
};