// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PlethoreDeCpp : ModuleRules
{
	public PlethoreDeCpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
