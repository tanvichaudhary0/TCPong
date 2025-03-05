// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TCPONG_API ATPongGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
    ATPongGameMode();

    virtual void BeginPlay() override;

    void ScorePoint(bool bPlayerScored); // Updates score
    void ResetBall(); // Resets ball after scoring

protected:
    int PlayerScore;
    int AIScore;
};
};
