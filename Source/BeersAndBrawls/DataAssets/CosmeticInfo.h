// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "Engine/DataAsset.h"
#include "CosmeticInfo.generated.h"

UCLASS(BlueprintType)
class BEERSANDBRAWLS_API UCosmeticInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	FName CosmeticName = TEXT("Cosmetic");
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	int Cost = 50;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	ECosmeticType CosmeticType = ECosmeticType::Boots;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	USkeletalMesh* SkeletalMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	UMaterialInterface* DefaultCosmeticMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cosmetic Info")
	FLinearColor DefaultColor = FLinearColor::Red;

#if WITH_EDITOR
	// This runs automatically in the editor whenever you change a property
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
