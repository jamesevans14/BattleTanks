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
	void Elevate(float DegreePerSecond);

	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float maxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevationDegrees = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevationDegrees = 0.f;
	
};
