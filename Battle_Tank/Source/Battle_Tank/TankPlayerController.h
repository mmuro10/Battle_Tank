// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

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
protected:

	UFUNCTION(BluePrintCallable, Category = Setup)
		ATank*GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	


	//start barrel so that a shot would it where crosshair intersects the world
	void AimTowardsCrosshair();

	//return an out paramerter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditAnyWhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnyWhere)
		float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
};
