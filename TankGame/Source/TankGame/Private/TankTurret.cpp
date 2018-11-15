// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "UnrealMathUtility.h"

void UTankTurret::Rotate(float relativeSpeed)
{
	auto RotationSpeed = FMath::Clamp(relativeSpeed, -1.f, 1.f);

	auto RotationChange = RotationSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto newRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, newRotation, 0));



	UE_LOG(LogTemp, Warning, TEXT("Rotating with a relative Speed of %f"), relativeSpeed);

}