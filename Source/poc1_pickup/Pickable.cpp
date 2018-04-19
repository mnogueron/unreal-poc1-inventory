// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickable.h"


// Sets default values
APickable::APickable(): ReachDistance(300.f), MaxStackCapacity(10), Name("DefaultItem"), Weight(1), IsStackable(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
	//FVector CameraLocation = CameraManager->GetCameraLocation();
	//FRotator CameraRotation = CameraManager->GetCameraRotation();
	//FVector LineEndVector = UKismetMathLibrary::GetForwardVector(CameraRotation) * ReachDistance + CameraLocation;

	//FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true);
	//TraceParams.bTraceComplex = true;
	//TraceParams.bReturnPhysicalMaterial = false;

	//FName TraceTag("PickableTrace");

	//GetWorld()->DebugDrawTraceTag = TraceTag;
	//TraceParams.TraceTag = TraceTag;

	//FHitResult HitOut = FHitResult(ForceInit);

	//GetWorld()->LineTraceSingleByChannel(
	//	HitOut,
	//	CameraLocation,
	//	LineEndVector,
	//	ECC_Visibility,
	//	TraceParams
	//);

	//if (HitOut.GetActor()) {
	//	APickable* HitActor = Cast<APickable>(HitOut.GetActor());
	//	if (HitActor == this) {
	//		// TODO actually do the process
	//		//Cast<>(UGameplayStatics::GetPlayerPawn(this, 0));

	//	}
	//}
}

