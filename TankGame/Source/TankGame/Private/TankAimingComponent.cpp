// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}





void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet)
{
	tankBarrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * turretToSet)
{
	tankTurret = turretToSet;
	
}



void UTankAimingComponent::aimAt(FVector worldSpaceAim, float launchSpeed)
{
	auto barrelLocation = tankBarrel->GetComponentLocation();
	FVector outVelocity = FVector(0);
	FVector startLocation = tankBarrel->GetSocketLocation(FName("Projectile"));
	
	if (!tankBarrel) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Firing at speed: %f"), launchSpeed);
	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		outVelocity,
		startLocation,
		worldSpaceAim,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(),
		false)
		)
	{
		auto AimDirection = outVelocity.GetSafeNormal();
		auto tankName = GetOwner()->GetName();
		auto time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f : %s is Aiming at location %s"), time,*tankName, *AimDirection.ToString());
		AimTank(AimDirection);
	}
	//else
	//{
	//	auto tankName = GetOwner()->GetName();
	//	auto time = GetWorld()->GetTimeSeconds();
	//	//UE_LOG(LogTemp, Warning, TEXT("%f : %s has no aim solution found"),time, *tankName);
	//}
	
}

void UTankAimingComponent::AimTank(FVector AimDirection)
{

	//move the barrel.
	//rotation, pointing towards the end location

	//		UKismetMathLibrary::FindLookAtRotation(tankTurret->GetComponentLocation, AimDirection);

	auto barrelRotator = tankBarrel->GetForwardVector().Rotation();
	auto aimAsRotator = AimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;

	tankBarrel->Elevate(deltaRotator.Pitch);

	if (FMath::Abs(deltaRotator.Yaw) < 180)
	{
		tankTurret->Rotate(deltaRotator.Yaw);
	}
	else // Avoid going the long-way round
	{
		tankTurret->Rotate(-deltaRotator.Yaw);
	}
	
}
