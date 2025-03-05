// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EStatusEffectTypes:uint8
{
	Dazed,
	Electrocuted,
	Inflamed,
	Frozen,
	Intoxicated,
	Weakened,
	Invigorated
};
