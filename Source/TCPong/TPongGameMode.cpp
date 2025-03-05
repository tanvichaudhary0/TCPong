// Fill out your copyright notice in the Description page of Project Settings.

#include "TPongGameMode.h"
#include "TPongBall.h"
#include "Kismet/GameplayStatics.h"

ATPongGameMode::ATPongGameMode()
{
    PlayerScore = 0;
    AIScore = 0;
}

void ATPongGameMode::BeginPlay()
{
    Super::BeginPlay();
    ResetBall();
}

void ATPongGameMode::ScorePoint(bool bPlayerScored)
{
    if (bPlayerScored)
    {
        PlayerScore++;
    }
    else
    {
        AIScore++;
    }
    ResetBall();
}

void ATPongGameMode::ResetBall()
{
    // Get ball reference and reset position
    ATPongBall* Ball = Cast<ATPongBall>(UGameplayStatics::GetActorOfClass(GetWorld(), ATPongBall::StaticClass()));
    if (Ball)
    {
        Ball->SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
        Ball->ResetMovement();
    }
}
