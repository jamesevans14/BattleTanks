// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include"Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	tank_m = GetControlledTank();

	if (!tank_m) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not available"));
	}
	else {
	UE_LOG(LogTemp, Warning, TEXT("Player Controller begin play for %s"), *tank_m->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector hitLocation; //Out Param
	

	if (GetSightRayHitLocation(hitLocation))
	{
		tank_m->AimAt(hitLocation);
	}


	//get world location linetrace through crosshair
	//if hits landscape
		//tell controlled tank to aim at this point
	//
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	FHitResult hasHit;
	
	int32 viewPortSizeX, viewPortSizeY;
	GetViewportSize(viewPortSizeX, viewPortSizeY);
	auto screenLocation = FVector2D(crosshairX_m * viewPortSizeX, crosshairY_m* viewPortSizeY);
	
	FVector lookDirection;

	if(GetLookDirection(screenLocation, lookDirection))
	{

		GetLookVectorHitLocation(lookDirection, OutHitLocation);
		return true;
	}
	

	return false;

}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector &lookDirection) const
{
	FVector cameraWorldLocation;

	return (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection));

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector& HitLocation) const
{
	FHitResult hitResult;

	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * lineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			hitResult, 
			startLocation, 
			endLocation, 
			ECollisionChannel::ECC_Visibility))
	{
		HitLocation = hitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;

}

