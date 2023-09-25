// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CleanerFindBallBTService.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBALL_API UCleanerFindBallBTService : public UBTService
{
	GENERATED_BODY()

		public:
        UCleanerFindBallBTService();

		protected:
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
        FBlackboardKeySelector EnemyActorKey;
	
		virtual void TickNode(UBehaviorTreeComponent& OwnerComp,
                              uint8* NodeMemory, float DeltaSeconds) override;

		public:
			template <typename T>
			static T* GetBallBaseComponent(AActor* PlayerPawn) {
                   if (!PlayerPawn) return nullptr;

				   const auto Component =
                       PlayerPawn->GetComponentByClass(T::StaticClass());
                   return Cast<T>(Component);
				}
};
