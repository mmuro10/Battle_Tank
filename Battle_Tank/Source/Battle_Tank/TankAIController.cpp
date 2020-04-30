// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can not find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector OutHitLocation;
	if (GetPlayerTank())
	{
		//TODO Move towards the player
		//aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank*ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if(!PlayerPawn) { return PlayerPawn; }
	if (!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}
