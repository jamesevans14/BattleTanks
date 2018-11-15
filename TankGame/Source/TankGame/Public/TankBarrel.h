// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max down, +1 is max upwards
	void Elevate(float RelativeSpeed);

	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 5.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevationDegrees = 0.f;
	
};
