// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	M_SelectedWeapon = M_DefaultSelectedWeapon;
	M_Items = M_DefaultItems;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	M_SelectedWeapon = M_DefaultSelectedWeapon;
	M_Items = M_DefaultItems;

	
	// ...
	
}

