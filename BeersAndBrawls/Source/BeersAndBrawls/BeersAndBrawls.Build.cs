// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BeersAndBrawls : ModuleRules
{
	public BeersAndBrawls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
