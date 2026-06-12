// Copyright 2026 Moovers Racer. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MooversRacerTarget : TargetRules
{
	public MooversRacerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange(new string[] { "MooversRacer" });

		// Android-specific settings
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			bUseOpenGL = false;
			bUseVulkan = true;
		}
	}
}
