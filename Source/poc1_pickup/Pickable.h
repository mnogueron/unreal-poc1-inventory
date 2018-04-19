// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include <string>
#include "Pickable.generated.h"

UCLASS()
class POC1_PICKUP_API APickable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float ReachDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxStackCapacity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Weight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsStackable;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UTexture2D* Image;
	
};
