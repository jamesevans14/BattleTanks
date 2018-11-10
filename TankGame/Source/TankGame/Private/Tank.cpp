// Fill out your copyright notice in the Description page of Project Settings.



#include "Tank.h"



void ATank::SetBarrelReference(UTankBarrel * barrelToSet)
{
	aimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UStaticMeshComponent * turretToSet)
{
	aimingComponent->SetTankReference(turretToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	aimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	aimingComponent->aimAt(HitLocation, LaunchSpeed);
	
}

