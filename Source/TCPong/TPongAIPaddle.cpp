// Fill out your copyright notice in the Description page of Project Settings.


#include "TPongAIPaddle.h"
#include "TPongBall.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATPongAIPaddle::ATPongAIPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATPongAIPaddle::BeginPlay()
{
	Super::BeginPlay();
	Ball = Cast<ATPongBall>(UGameplayStatics::GetActorOfClass(GetWorld(), ATPongBall::StaticClass()));
}

// Called every frame
void ATPongAIPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (Ball)
    {
        FVector BallLocation = Ball->GetActorLocation();
        FVector PaddleLocation = GetActorLocation();

        float DeltaY = BallLocation.Z - PaddleLocation.Z;

        if (FMath::Abs(DeltaY) > 10.0f) // Only move if ball is not perfectly aligned
        {
            float Direction = (DeltaY > 0) ? 1.0f : -1.0f;
            SetActorLocation(PaddleLocation + FVector(0, 0, Direction * Speed * DeltaTime));
        }
    }

}


