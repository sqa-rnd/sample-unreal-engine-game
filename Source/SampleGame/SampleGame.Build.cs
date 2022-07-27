// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SampleGame : ModuleRules
{
	public SampleGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		MinFilesUsingPrecompiledHeaderOverride = 1;
		bUseUnity = false;

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
