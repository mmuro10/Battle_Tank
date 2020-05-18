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

	

	void BeginPlay() override;
	
protected:

	//Stop distance from goal
	UPROPERTY(EditAnywhere, Category = "Setup") //Consider EditDefaultOnly
	float AcceptanceRadius = 8000;
};
