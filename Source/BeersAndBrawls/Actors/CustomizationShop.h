// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "GameFramework/Actor.h"
#include "CustomizationShop.generated.h"

class UCosmeticInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCosmeticUnlocked, ECosmeticType, CosmeticTypeUnlocked, UCosmeticInfo*, UnlockedCosmetic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCosmeticLocked, ECosmeticType, CosmeticTypeUnlocked, UCosmeticInfo*, LockedCosmetic);

UCLASS(Blueprintable)
class BEERSANDBRAWLS_API ACustomizationShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomizationShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnCosmeticUnlocked OnCosmeticUnlockedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnCosmeticLocked OnCosmeticLockedEvent;
	
	// Unlocked Mesh's
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Gloves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Heads;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Teeth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Beards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Eyebrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Shirts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unlocked Cosmetics")
	TArray<UCosmeticInfo*> Unlocked_Pants;

	// Locked Mesh's
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Gloves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Heads;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Teeth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Beards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Eyebrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Shirts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Locked Cosmetics")
	TArray<UCosmeticInfo*> Locked_Pants;

	// Functions
	UFUNCTION(BlueprintCallable)
	void UnlockCosmetic(ECosmeticType Type, UCosmeticInfo* NewMeshInfo);

	UFUNCTION(BlueprintCallable)
	void GetCosmetics(ECosmeticType Type, TArray<UCosmeticInfo*> &UnlockedCosmetics, TArray<UCosmeticInfo*> &LockedCosmetics);

};
