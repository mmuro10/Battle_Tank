// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Stop distance from goal
	float AcceptanceRadius = 3000;

	void BeginPlay() override;
};
