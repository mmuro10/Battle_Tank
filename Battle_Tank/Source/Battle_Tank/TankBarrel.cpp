// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//movethebarrel the right amount this frame

	//Given a max elevation speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at %f at speed %f"),DegreesPerSecond);
}