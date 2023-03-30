// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FallGuysCopy : ModuleRules
{
	public FallGuysCopy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",  "EnhancedInput", "GeometryCollectionEngine", "UMG", "OnlineSubsystem", "AnimGraphRuntime", "OnlineSubsystemSteam" });
	}
}
