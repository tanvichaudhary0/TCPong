// Fill out your copyright notice in the Description page of Project Settings.


#include "TPongBall.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TPongGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATPongBall::ATPongBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize movement direction
	Direction = FVector(1.0f, 0.0f, 0.5f).GetSafeNormal();
}

// Called when the game starts or when spawned
void ATPongBall::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<ATPongGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

}

// Called every frame
void ATPongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation() + (Direction * Speed * DeltaTime);
	SetActorLocation(NewLocation);
}

void ATPongBall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor->IsA(ATPongPlayerPaddle::StaticClass()) || OtherActor->IsA(ATPongAIPaddle::StaticClass()))
    {
        Direction = FVector(-Direction.X, 0.0f, Direction.Z + FMath::FRandRange(-0.3f, 0.3f)).GetSafeNormal();
        Speed += SpeedIncrement;
    }
    else if (OtherActor->IsA(ABorder::StaticClass())) // If it hits top/bottom walls
    {
        Direction.Z = -Direction.Z;
    }
    else if (OtherActor->IsA(AGoal::StaticClass())) // If it hits left or right goal
    {
        if (GameMode)
        {
            GameMode->ScorePoint(OtherActor->GetName().Contains("PlayerGoal"));
        }
    }
}

void ATPongBall::ResetMovement()
{
    Speed = 600.0f;
    SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
    Direction = FVector((FMath::RandBool() ? 1 : -1), 0.0f, FMath::RandRange(-0.5f, 0.5f)).GetSafeNormal();
}