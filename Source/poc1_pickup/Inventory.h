// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickable.h"
#include "Inventory.generated.h"

USTRUCT(Blueprintable)
struct FInventorySlot {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	FItem Item;

	UPROPERTY(BlueprintReadOnly)
	int Count;

	FInventorySlot()
	{
		Count = 0;
	}

	FInventorySlot(FItem Item, int Count)
	{
		this->Item = Item;
		this->Count = Count;
	}
};

UCLASS()
class POC1_PICKUP_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool CanStack(APickable* Item);
	int CurrentWeight();
	bool HasSpace();
	bool HasPartialStack(APickable* Item, int* IndexOut);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddItem(APickable* Item);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxWeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SlotCount;

	UPROPERTY(BlueprintReadOnly)
	TArray<FInventorySlot> ItemList;
};
