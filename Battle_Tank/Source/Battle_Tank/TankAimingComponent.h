// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward decleration
class UTankBarrel; 
class UTankTurret;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//Hold barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	

	UFUNCTION(BluePrintCallable, Category = Setup)
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector OutHitLocation);

protected:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UPROPERTY(BluePrintReadOnly, Category = State)
		EFiringState FiringState = EFiringState::Aiming;
private:	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;
};
