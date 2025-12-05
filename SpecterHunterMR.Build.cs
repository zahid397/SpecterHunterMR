using UnrealBuildTool;

public class SpecterHunterMR : ModuleRules
{
	public SpecterHunterMR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // "OnlineSubsystem" এখানে যোগ করা হয়েছে
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "OnlineSubsystem" });
	}
}
