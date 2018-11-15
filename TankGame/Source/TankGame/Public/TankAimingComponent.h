// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//forward declaration
class UTankBarrel; 
class UTankTurret;

//Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	void SetBarrelReference(UTankBarrel* barrelToSet);

	void SetTurretReference(UTankTurret* turretToSet);

	void aimAt(FVector worldSpaceAim, float launchSpeed);

protected:
	// Called when the game starts

private:
	UTankBarrel* tankBarrel = nullptr;
	UTankTurret* tankTurret = nullptr;

	void AimTank(FVector AimDirection);
};
