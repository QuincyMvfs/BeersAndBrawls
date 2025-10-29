// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "GameFramework/Actor.h"
#include "CustomizableCharacter.generated.h"

UCLASS()
class BEERSANDBRAWLS_API ACustomizableCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomizableCharacter();

	// Customization Mesh's
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_BaseMesh_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Boots_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Gloves_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Head_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Teeth_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Beard_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Hair_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Eyes_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Eyebrows_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Shirt_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Pants_Component;

	// Mesh Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshs", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedWeaponComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEnemyInfoStruct EnemyInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UMaterialInterface* CustomMaterial;

	UFUNCTION(BlueprintCallable, Category = "Customization Cosmetics")
	void SetupCosmetics(FEnemyInfoStruct NewEnemyInfo);
	
	void UpdateCosmetics();
	void UpdateCosmeticColors(ECosmeticType CosmeticType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
