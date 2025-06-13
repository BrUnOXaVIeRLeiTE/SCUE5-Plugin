using UnrealBuildTool;
using System.IO;

public class SCUE5 : ModuleRules
{
	public SCUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "Private/SCUE5PrivatePCH.h";
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IWYUSupport = IWYUSupport.None;
		//
		PublicDependencyModuleNames.AddRange
		(
			new string[]
			{
				"Core",
				"Engine",
				"SCUE5X",
				"Projects",
				"CoreUObject"
			}
		);
		//
		PublicDefinitions.Add("WITH_ANTI_CHEAT");
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"Private"));
	}
}