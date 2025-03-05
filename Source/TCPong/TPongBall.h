// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPongBall.generated.h"

UCLASS()
class TCPONG_API ATPongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATPongBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float Speed = 600.0f;

	UPROPERTY(EditAnywhere)
	FVector Direction;

	UPROPERTY(EditAnywhere)
	float SpeedIncrement = 50.0f; // Ball gets faster over time

	class ATPongGameMode* GameMode; // Reference to the game mode
};
