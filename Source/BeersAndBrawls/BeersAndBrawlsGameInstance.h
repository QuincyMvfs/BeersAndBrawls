// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BeersAndBrawlsGameInstance.generated.h"

class UCosmeticInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePlayerBeerBux, int, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePlayerExp, int, NewValue);

UCLASS()
class BEERSANDBRAWLS_API UBeersAndBrawlsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnUpdatePlayerBeerBux OnUpdatePlayerBeerBuxEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnUpdatePlayerExp OnUpdatePlayerExpEvent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int M_PlayerExp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int M_PlayerBeerBux;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Gloves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Heads;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Teeth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Beards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Eyebrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Shirts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics")
	TArray<UCosmeticInfo*> Pants;

	// Colors
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Boot_ColorPalette;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Shirt_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Pants_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Gloves_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Hair_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Skin_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Hat_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Eye_ColorPalette;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cosmetics Colors")
	TArray<FLinearColor> Teeth_ColorPalette;
	
	void UpdatePlayerBeerBux(int NewValue);
	
	void UpdatePlayerExp(int NewValue);

	
};
