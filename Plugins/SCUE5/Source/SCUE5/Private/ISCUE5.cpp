//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2025 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ISCUE5.h"
#include "SCUE5.h"
#include "SCUE5PrivatePCH.h"
	
#if WITH_EDITORONLY_DATA
 #include "ISettingsModule.h"
 #include "ISettingsSection.h"
 #include "ISettingsContainer.h"
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOCTEXT_NAMESPACE "Synaptech"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FSCUE5 : public ISCUE5 {
private:
	bool HandleSettingsSaved() {
	  #if WITH_EDITORONLY_DATA
		const auto &Settings = GetMutableDefault<USCUE5Settings>();
		Settings->SaveConfig(); return true;
	  #else
		return false;
	  #endif
	}
	//
	void RegisterSettings() {
	  #if WITH_EDITORONLY_DATA
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings")) {
			ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");
			SettingsContainer->DescribeCategory("Synaptech",LOCTEXT("SynaptechCategoryName","Synaptech"),
			LOCTEXT("SynaptechCategoryDescription","Configuration of Synaptech Systems."));
			//
			ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project","Synaptech","SCUE5Settings",
				LOCTEXT("SCUE5SettingsName","Anti-Cheat Settings"),
				LOCTEXT("SCUE5SettingsDescription","General settings for the SCUE5 Plugin"),
			GetMutableDefault<USCUE5Settings>());
			//
			if (SettingsSection.IsValid()) {SettingsSection->OnModified().BindRaw(this,&FSCUE5::HandleSettingsSaved);}
		}
	  #endif
	}
	//
	void UnregisterSettings() {
	  #if WITH_EDITORONLY_DATA
		if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings")) {
			SettingsModule->UnregisterSettings("Project","Synaptech","SCUE5Settings");
		}
	  #endif
	}
	//
public:
	virtual void StartupModule() override {RegisterSettings(); UE_LOG(LogTemp,Warning,TEXT("{S}:: Initializing Secure-Client Plugin [Anti-Cheat]."));}
	virtual void ShutdownModule() override {if (UObjectInitialized()) {UnregisterSettings();}}
	virtual bool SupportsDynamicReloading() override {return true;}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_GAME_MODULE(FSCUE5,SCUE5);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////