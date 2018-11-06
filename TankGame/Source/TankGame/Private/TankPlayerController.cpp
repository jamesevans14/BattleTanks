// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


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


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

