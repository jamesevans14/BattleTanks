// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "UnrealMathUtility.h"


void UTankBarrel::Elevate(float relativeSpeed)
{
	auto elevationSpeed = FMath::Clamp(relativeSpeed, -1.f, 1.f);

	auto ElevationChange = elevationSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto newElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation = FMath::Clamp(newElevation, minElevationDegrees, maxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

