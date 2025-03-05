// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TPongHUD.generated.h"

/**
 * 
 */
UCLASS()
class TCPONG_API ATPongHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;
};