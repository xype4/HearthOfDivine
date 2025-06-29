using UnrealBuildTool;

public class EntityAnimationsClasses: ModuleRules
{
    public EntityAnimationsClasses(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
    }
}
