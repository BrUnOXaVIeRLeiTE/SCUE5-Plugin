using UnrealBuildTool;
using System.IO;

public class SCUE5X : ModuleRules
{
	public SCUE5X(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		string DIRx64 = Path.Combine(ModuleDirectory,"x64");
		//
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			RuntimeDependencies.Add(Path.Combine(DIRx64,"SCUE5x64.exe"));
		}
	}
}