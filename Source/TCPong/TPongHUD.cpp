// Fill out your copyright notice in the Description page of Project Settings.


#include "TPongHUD.h"
#include "Engine/Canvas.h"
#include "TPongGameMode.h"

void ATPongHUD::DrawHUD()
{
    Super::DrawHUD();

    ATPongGameMode* GameMode = Cast<ATPongGameMode>(GetWorld()->GetAuthGameMode());

    if (GameMode)
    {
        FString PlayerScoreText = FString::Printf(TEXT("%d"), GameMode->PlayerScore);
        FString AIScoreText = FString::Printf(TEXT("%d"), GameMode->AIScore);

        DrawText(PlayerScoreText, FColor::Orange, 50, 50, nullptr, 2.0f);
        DrawText(AIScoreText, FColor::Orange, Canvas->SizeX - 100, 50, nullptr, 2.0f);
    }
}
