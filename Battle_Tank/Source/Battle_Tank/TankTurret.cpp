// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::RotateTurret(float ReletiveSpeed)
{
	// Dont think needed since turret should rotate freely
	ReletiveSpeed = FMath::Clamp<float>(ReletiveSpeed, -1, +1);
	
	//Given a max rotation speed and frame time
	auto RotationChange = ReletiveSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	SetRelativeRotation(FRotator(0, Rotation, 0));
}