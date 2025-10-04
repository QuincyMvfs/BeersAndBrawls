// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/DataAssets/CosmeticInfo.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "BeersAndBrawls/Structs/FBoneSizes.h"
#include "Components/ActorComponent.h"
#include "CustomizationComponent.generated.h"


class ABeersAndBrawlsCharacter;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomizationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Size Changes")
	FBoneSizes M_BoneSizes;
	
// Selected Cosmetics
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Gloves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Teeth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Beard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Eyebrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Shirt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Pants;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Color Customization")
	TArray<FLinearColor> CosmeticColors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Color Customization")
	TArray<FLinearColor> Default_CosmeticColors;
	
	UFUNCTION(BlueprintCallable, Category = "Customization Cosmetics")
	void UpdateAllCosmetics();

	UFUNCTION(BlueprintCallable, Category = "Customization Cosmetics")
	void TemporarilySwapCosmetics(UCosmeticInfo* CosmeticInfo);

	UFUNCTION(BlueprintCallable, Category = "Customization Cosmetics")
	void ResetCosmetic(ECosmeticType CosmeticType);
	
	UFUNCTION(BlueprintCallable, Category = "Customization Cosmetics")
	void SwapCosmetic(UCosmeticInfo* NewMesh);

	UFUNCTION(BlueprintCallable)
	void ChangeCosmeticColor(ECosmeticType CosmeticType, FLinearColor NewColor);

	UFUNCTION(BlueprintCallable)
	void TemporarilyChangeCosmeticColor(ECosmeticType CosmeticType, FLinearColor GivenColor);

	UFUNCTION(BlueprintCallable)
	void ResetCosmeticColor(ECosmeticType CosmeticType);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FLinearColor GetSelectedCosmeticColor(ECosmeticType CosmeticType);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Customization Cosmetics")
	bool IsWearingCosmetic(UCosmeticInfo* CosmeticInfo);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UMaterialInterface* CustomMaterial;
	
	ABeersAndBrawlsCharacter* PlayerRef;
	
};
