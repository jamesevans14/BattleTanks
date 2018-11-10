// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override; //virtual here doesnt do anything, because BeginPlay first defined in AActor

	virtual void Tick(float DeltaTime) override;

	//move the tank barrel so a shot would hit where reticle is aiming
	void AimTowardsCrosshair();

	

private:
	ATank * tank_m = nullptr;
	UPROPERTY(EditAnywhere)
	float crosshairX_m = 0.5f;

	UPROPERTY(EditAnywhere)
	float crosshairY_m = 0.3333f;

	UPROPERTY(EditAnywhere)
	float lineTraceRange = 1000000.f;


	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D screenLocation, FVector &lookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& HitLocation) const;




};
