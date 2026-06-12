// Copyright 2026 Moovers Racer. All Rights Reserved.

using UnrealBuildTool;

public class MooversRacer : ModuleRules
{
	public MooversRacer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"PhysicsCore",
			"Chaos",
			"ChaosVehicles",
			"UMG",
			"Slate",
			"SlateCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
		});

		// Enable RTTI for serialization
		bUseRTTI = true;
	}
}
