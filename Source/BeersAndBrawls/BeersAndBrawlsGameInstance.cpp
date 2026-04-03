// Fill out your copyright notice in the Description page of Project Settings.


#include "BeersAndBrawlsGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UBeersAndBrawlsGameInstance::UpdatePlayerBeerBux(int NewValue)
{
	M_PlayerBeerBux = NewValue;
	OnUpdatePlayerBeerBuxEvent.Broadcast(NewValue);
}

void UBeersAndBrawlsGameInstance::UpdatePlayerExp(int NewValue)
{
	M_PlayerExp = NewValue;
	OnUpdatePlayerExpEvent.Broadcast(NewValue);
}

void UBeersAndBrawlsGameInstance::AddColorToPalette(ECosmeticType CosmeticType, FLinearColor NewColor)
{
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			if (Boot_ColorPalette.Contains(NewColor)) break;
			Boot_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Gloves:
			if (Gloves_ColorPalette.Contains(NewColor)) break;
			Gloves_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Head:
			if (Skin_ColorPalette.Contains(NewColor)) break;
			Skin_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Teeth:
			if (Teeth_ColorPalette.Contains(NewColor)) break;
			Teeth_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Beard:
			if (Hair_ColorPalette.Contains(NewColor)) break;
			Hair_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Hair:
			if (Hair_ColorPalette.Contains(NewColor)) break;
			Hair_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Eyes:
			if (Eye_ColorPalette.Contains(NewColor)) break;
			Eye_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Shirt:
			if (Shirt_ColorPalette.Contains(NewColor)) break;
			Shirt_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Pants:
			if (Pants_ColorPalette.Contains(NewColor)) break;
			Pants_ColorPalette.Add(NewColor);
			break;
		case ECosmeticType::Eyebrows:
			if (Hair_ColorPalette.Contains(NewColor)) break;
			Hair_ColorPalette.Add(NewColor);
			break;
		default:
			break;
	}
}
