// Fill out your copyright notice in the Description page of Project Settings.


#include "CosmeticInfo.h"

#if WITH_EDITOR
void UCosmeticInfo::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UCosmeticInfo, SkeletalMesh))
	{
		if (SkeletalMesh && SkeletalMesh->GetMaterials().IsValidIndex(0))
		{
			DefaultCosmeticMaterial = SkeletalMesh->GetMaterials()[0].MaterialInterface;
		}
	}
	else
	{
		DefaultCosmeticMaterial = nullptr;
	}
}
#endif
