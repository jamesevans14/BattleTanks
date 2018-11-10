// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include"Engine/World.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller has found player tank %s"), *PlayerTank->GetName());
	}
	tank_m = GetPossessedTank();
}

ATank* AAITankController::GetPossessedTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank * AAITankController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!playerPawn) { return nullptr; }

	return Cast<ATank>(playerPawn);
}


void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank)
		tank_m->AimAt(PlayerTank->GetActorLocation());

}



