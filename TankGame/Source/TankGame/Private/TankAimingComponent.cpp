// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "TankBarrel.h"
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

void UTankAimingComponent::SetTankReference(UStaticMeshComponent * turretToSet)
{
	tankTurret = turretToSet;
	
}



void UTankAimingComponent::aimAt(FVector worldSpaceAim, float launchSpeed)
{
	auto barrelLocation = tankBarrel->GetComponentLocation();
	FVector outVelocity;
	FVector startLocation = tankBarrel->GetSocketLocation(FName("Projectile"));
	
	if (!tankBarrel) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Firing at speed: %f"), launchSpeed);
	
	if (UGameplayStatics::SuggestProjectileVelocity(this, outVelocity, startLocation, worldSpaceAim, launchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::TraceFullPath, FCollisionResponseParams::DefaultResponseParam, TArray<AActor*>(), true))
	{
		auto AimDirection = outVelocity.GetSafeNormal();
		auto tankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s is Aiming At: %s"),*tankName, *AimDirection.ToString());
		MoveBarrel(AimDirection);

		
	}
	
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{

	//move the barrel.
	//rotation, pointing towards the end location

	//		UKismetMathLibrary::FindLookAtRotation(tankTurret->GetComponentLocation, AimDirection);

	auto barrelRotator = tankBarrel->GetForwardVector().Rotation();
	auto aimAsRotator = AimDirection.Rotation();
	auto deltaRotator = aimAsRotator - barrelRotator;

	tankBarrel->Elevate(5);

}