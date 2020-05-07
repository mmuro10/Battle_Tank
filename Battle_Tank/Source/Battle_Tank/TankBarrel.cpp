// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Math/UnrealMathUtility.h"


void UTankBarrel::Elevate(float ReletiveSpeed)
{
	//movethebarrel the right amount this frame
	ReletiveSpeed = FMath::Clamp<float>(ReletiveSpeed, -1, +1);
	//Given a max elevation speed and frame time
	auto ElevationChange = ReletiveSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}	