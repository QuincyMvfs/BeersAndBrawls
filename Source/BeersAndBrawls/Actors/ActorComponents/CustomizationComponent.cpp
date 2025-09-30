// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"

#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(GetOwner());
}


// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCustomizationComponent::SwapCosmetic(ECosmeticType CosmeticType, UCosmeticInfo* NewMesh)
{
	if (!PlayerRef) return;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			C_Selected_Boots = NewMesh;
			PlayerRef->SK_Boots_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Gloves:
			C_Selected_Gloves = NewMesh;
			PlayerRef->SK_Gloves_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Head:
			C_Selected_Head = NewMesh;
			PlayerRef->SK_Head_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Teeth:
			C_Selected_Teeth = NewMesh;
			PlayerRef->SK_Teeth_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Beard:
			C_Selected_Beard = NewMesh;
			PlayerRef->SK_Beard_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Hair:
			C_Selected_Hair = NewMesh;
			PlayerRef->SK_Hair_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Eyebrows:
			C_Selected_Eyebrows = NewMesh;
			PlayerRef->SK_Eyebrows_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Eyes:
			C_Selected_Eyes = NewMesh;
			PlayerRef->SK_Eyes_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Shirt:
			C_Selected_Shirt = NewMesh;
			PlayerRef->SK_Shirt_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		case ECosmeticType::Pants:
			C_Selected_Pants = NewMesh;
			PlayerRef->SK_Pants_Component->SetSkeletalMesh(NewMesh->SkeletalMesh);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			break;
	}
}