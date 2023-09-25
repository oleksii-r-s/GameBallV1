// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "BallAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAMEBALL_API UBallAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
	public:
		AActor* GetClosestEnemy() const;
};
