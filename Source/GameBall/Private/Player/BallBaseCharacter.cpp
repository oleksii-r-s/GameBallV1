// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BallBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"

// Sets default values
ABallBaseCharacter::ABallBaseCharacter()
{
   /* static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Assets/Meshes/BallMesh.BallMesh"));
    Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
    RootComponent = Ball*/;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ABallBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this,
                                        &ABallBaseCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this,
                                        &ABallBaseCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ABallBaseCharacter::LookUp);
    PlayerInputComponent->BindAxis("TurnAround", this,
                                   &ABallBaseCharacter::TurnAround);



}

void ABallBaseCharacter::MoveForward(float Amount) 
{
        AddMovementInput(GetActorForwardVector(), Amount);
}

void ABallBaseCharacter::MoveRight(float Amount) 
{
        AddMovementInput(GetActorRightVector(), Amount);
}

void ABallBaseCharacter::LookUp(float Amount) 
{
        AddControllerPitchInput(Amount);
}

void ABallBaseCharacter::TurnAround(float Amount) 
{
    AddControllerYawInput(Amount);
}

