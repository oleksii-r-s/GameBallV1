// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/BallBaseCharacter.h"
#include "AIBallBaseCharacter.generated.h"

/**
 * 
 */
class USphereComponent;
UCLASS()
class GAMEBALL_API AAIBallBaseCharacter : public ABallBaseCharacter
{
	GENERATED_BODY()
 public:
        AAIBallBaseCharacter(const FObjectInitializer& ObjInit);
		protected:
        UPROPERTY(VisibleAnywhere, Category = "ChangeCollor")
        USphereComponent* CollisionComponent;

        virtual void BeginPlay() override;
        virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

       public:
           virtual void Tick(float DeltaTime) override;
};
