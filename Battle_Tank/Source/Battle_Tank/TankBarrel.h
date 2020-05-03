// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is downward movement + is max up movement
	void Elevate(float ReletiveSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5.0; //Max speed movement per tick

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30.0; //Max elevation for barrel

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 2.5; //Min elevation for barrel
};
