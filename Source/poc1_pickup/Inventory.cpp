// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"


// Sets default values
AInventory::AInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AInventory::CanStack(APickable* Item) 
{
	return Item->IsStackable;
}

int AInventory::CurrentWeight() 
{
	int Weight = 0;
	for (auto& ItemSlot : ItemList)
	{
		Weight += ItemSlot.Count;
	}
	return Weight;
}

bool AInventory::HasSpace()
{
	return CurrentWeight() < MaxWeight && ItemList.Num() < SlotCount;
}

bool AInventory::HasPartialStack(APickable* Item,  int* IndexOut)
{
	auto It = ItemList.CreateConstIterator();
	bool found = false;
	for (int32 Index = 0; Index < ItemList.Num() && !found; ++Index)
	{
		if (ItemList[Index].Item.Name == Item->Name && ItemList[Index].Count < Item->MaxStackCapacity) {
			*IndexOut = Index;
			found = true;
			break;
		}
	}
	return found;
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInventory::AddItem(APickable* Item)
{
	int AddToIndex;
	if (CanStack(Item) && HasPartialStack(Item, &AddToIndex))
	{
		ItemList[AddToIndex].Count += 1;
		Item->Destroy();
	}
	else if (HasSpace())
	{
		ItemList.Add(FInventorySlot(Item->GetItem(), 1));
		Item->Destroy();
	}
}

