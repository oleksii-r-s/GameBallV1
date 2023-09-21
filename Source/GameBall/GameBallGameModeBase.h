// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BallType.h"
#include "GameBallGameModeBase.generated.h"

/**
 * 
 */
class AAIController;
UCLASS()
class GAMEBALL_API AGameBallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
		public:
        AGameBallGameModeBase();

        virtual void StartPlay() override;
        virtual UClass* GetDefaultPawnClassForController_Implementation(
            AController* InController) override;

                protected:
        UPROPERTY(EditDefaultsOnly, Category = "Game")
        TSubclassOf<AAIController> AIControllerClass;

        UPROPERTY(EditDefaultsOnly, Category = "Game")
        TSubclassOf<APawn> AIPawnClass;

        UPROPERTY(EditDefaultsOnly, Category = "Game")
        FGameData GameData;

        private:
        void SpawnBots();
};
