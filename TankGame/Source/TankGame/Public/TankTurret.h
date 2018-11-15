// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max down, +1 is max upwards
	void Rotate(float RelativeSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 5.f;
	
};
