using UnrealBuildTool;
using System.IO;

public class SCUE5Editor : ModuleRules
{
	public SCUE5Editor(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "Private/SCUE5EditorPrivatePCH.h";
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IWYUSupport = IWYUSupport.None;
		//
		PrivateDependencyModuleNames.AddRange
		(
			new string[]
			{
				"Core",
				"Slate",
				"SCUE5",
				"Engine",
				"Projects",
				"UnrealEd",
				"SlateCore",
				"InputCore",
				"EditorStyle",
				"LevelEditor",
				"CoreUObject",
				"PropertyEditor"
			}
		);
		//
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory,"Private"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory,"Public"));
	}
}