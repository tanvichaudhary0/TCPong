// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TPongAIPaddle.generated.h"

UCLASS()
class TCPONG_API ATPongAIPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATPongAIPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float Speed = 400.0f; // AI Paddle speed

	class ATPongBall* Ball; // Reference to the ball
};