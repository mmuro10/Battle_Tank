// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank*GetControlledTank() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

private:
	//start barrel so that a shot would it where crosshair intersects the world
	void AimTowardsCrosshair();
	//return an out paramerter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
