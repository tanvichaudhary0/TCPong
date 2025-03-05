// Fill out your copyright notice in the Description page of Project Settings.


#include "TPongPlayerPaddle.h"

// Sets default values
ATPongPlayerPaddle::ATPongPlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATPongPlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPongPlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void ATPongPlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &ATPongPlayerPaddle::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &ATPongPlayerPaddle::MoveDown);
}

void ATPongPlayerPaddle::MoveUp()
{
	CurrentVelocity = FVector(0, 0, Speed);
}

void ATPongPlayerPaddle::MoveDown()
{
	CurrentVelocity = FVector(0, 0, -Speed);
}