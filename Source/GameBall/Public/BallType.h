// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BallType.generated.h"

USTRUCT(BlueprintType)
struct FGameData
	{
  GENERATED_USTRUCT_BODY()
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game",
            meta = (ClampMin = "1", ClampMax = "10"))
  int32 PlayersNum = 2;
};