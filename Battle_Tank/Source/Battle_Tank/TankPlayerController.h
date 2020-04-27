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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginPlay() override;

private:

	ATank*GetControlledTank() const;


	//start barrel so that a shot would it where crosshair intersects the world
	void AimTowardsCrosshair();

	//return an out paramerter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnyWhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnyWhere)
		float CrossHairYLocation = 0.33333;
};
