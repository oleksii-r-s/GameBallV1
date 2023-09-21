// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameBallGameModeBase.h"
#include "Player/BallBaseCharacter.h"
#include "Player/BallController.h"
#include "AIController.h"

AGameBallGameModeBase::AGameBallGameModeBase() {
  DefaultPawnClass = ABallBaseCharacter::StaticClass();
  PlayerControllerClass = ABallController::StaticClass();
}

void AGameBallGameModeBase::StartPlay() 
{ Super::StartPlay();
  SpawnBots();
}
UClass*
AGameBallGameModeBase::GetDefaultPawnClassForController_Implementation(
    AController* InController) {
    if(InController && InController->IsA<AAIController>()) {
    return AIPawnClass;
    }
    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void AGameBallGameModeBase::SpawnBots() 
{
  if (!GetWorld()) return;
  for(int32 i = 0; i < GameData.PlayersNum -1; ++i)
	  {
	FActorSpawnParameters SpawnInfo;
    SpawnInfo.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        const auto BallAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);
        RestartPlayer(BallAIController);
  }
}
