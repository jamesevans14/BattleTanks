// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "AITankController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API AAITankController : public AAIController
{
	GENERATED_BODY()

private:
		virtual void Tick(float DeltaTime) override;

		virtual void BeginPlay() override;

		ATank* GetPossessedTank() const;
	
		ATank* GetPlayerTank() const;

private:

	ATank * PlayerTank = nullptr; 

	ATank* tank_m = nullptr;
};
