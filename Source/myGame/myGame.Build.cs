// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class myGame : ModuleRules
{
	public myGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG"  });

		// PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

		// PrivateDependencyModuleNames.AddRange(new string[] {  });

		// ��ʹ��Slate UI����ȡ��ע��
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
