//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//			Copyright 2016 (C) Bruno Xavier Leite
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SCUE5Editor.h"
#include "SCUE5EditorCommands.h"
#include "SCUE5EditorStyle.h"

#include "SCUE5.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOCTEXT_NAMESPACE "FSCUE5Editor"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const FName SCUE5EditorTabName("SCUE5Editor");

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSCUE5Editor::StartupModule() {
	FSCUE5EditorStyle::Initialize();
	FSCUE5EditorStyle::ReloadTextures();
	FSCUE5EditorCommands::Register();
	//
	PluginCommands = MakeShareable(new FUICommandList);
	PluginCommands->MapAction(FSCUE5EditorCommands::Get().PluginAction,FExecuteAction::CreateRaw(this, &FSCUE5Editor::PluginButtonClicked),FCanExecuteAction());
	//
	FLevelEditorModule &LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	//
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout",EExtensionHook::After,PluginCommands,FMenuExtensionDelegate::CreateRaw(this,&FSCUE5Editor::AddMenuExtension));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings",EExtensionHook::After,PluginCommands,FToolBarExtensionDelegate::CreateRaw(this,&FSCUE5Editor::AddToolbarExtension));
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	//
	{
		FPropertyEditorModule &PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeBool",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSBool_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeByte",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSByte_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeInt",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSInt_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeFloat",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSFloat_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeName",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSName_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeString",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSString_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeText",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSText_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeVector2D",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSV2D_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeVector3D",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSV3D_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeVector4D",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSV4D_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeColor",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSColor_CustomDetails::MakeInstance));
		PropertyEditorModule.RegisterCustomPropertyTypeLayout("SafeRotator",FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FSRotator_CustomDetails::MakeInstance));
	}
}

void FSCUE5Editor::ShutdownModule() {
	FSCUE5EditorStyle::Shutdown();
	FSCUE5EditorCommands::Unregister();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void FSCUE5Editor::AddMenuExtension(FMenuBuilder &Builder) {
	Builder.AddMenuEntry(FSCUE5EditorCommands::Get().PluginAction);
}

void FSCUE5Editor::AddToolbarExtension(FToolBarBuilder &Builder) {
	Builder.AddToolBarButton(FSCUE5EditorCommands::Get().PluginAction);
}

void FSCUE5Editor::PluginButtonClicked() {
	const auto &Settings = GetMutableDefault<USCUE5Settings>();
	//
	if (Settings && FPaths::FileExists(Settings->KeyGeneratorPath)) {
		FPlatformProcess::CreateProc(*Settings->KeyGeneratorPath,nullptr,true,false,false,nullptr,0,nullptr,nullptr,nullptr);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeBool

TSharedRef<IPropertyTypeCustomization> FSBool_CustomDetails::MakeInstance() {
	return MakeShareable(new FSBool_CustomDetails());
}

void FSBool_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSBoolTooltip","Safe Bool"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeBool"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SCheckBox)
		.IsChecked(this,&FSBool_CustomDetails::OnGetValue)
		.OnCheckStateChanged(this,&FSBool_CustomDetails::OnSetValue)
	];
}

void FSBool_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSBool_CustomDetails::OnSetValue(ECheckBoxState Input) const {
	FString K; Keys->GetValue(K);
	//
	switch (Input) {
		case ECheckBoxState::Checked:
			if (K.Len()>0) {Real->SetValue(FEncode(K,TEXT("true")));} else {Real->SetValue(FEncode(TEXT("true")));}
			if (K.Len()>0) {Flip->SetValue(FEncode(K,TEXT("true")));} else {Flip->SetValue(FEncode(TEXT("true")));}
			break;
		case ECheckBoxState::Unchecked:
			if (K.Len()>0) {Real->SetValue(FEncode(K,TEXT("false")));} else {Real->SetValue(FEncode(TEXT("false")));}
			if (K.Len()>0) {Flip->SetValue(FEncode(K,TEXT("false")));} else {Flip->SetValue(FEncode(TEXT("false")));}
			break;
		default:
			Real->SetValue(FEncode(TEXT("false")));
			Flip->SetValue(FEncode(TEXT("false")));
	break;}
}

ECheckBoxState FSBool_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	//
	if (K.Len()>0) {
		if (FCString::ToBool(*FDecode(K,R))) {return ECheckBoxState::Checked;} else {return ECheckBoxState::Unchecked;}}
	else {if (FCString::ToBool(*FDecode(R))) {return ECheckBoxState::Checked;} else {return ECheckBoxState::Unchecked;}}
	//
	return ECheckBoxState::Undetermined;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeByte

TSharedRef<IPropertyTypeCustomization> FSByte_CustomDetails::MakeInstance() {
	return MakeShareable(new FSByte_CustomDetails());
}

void FSByte_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSByteTooltip","Safe Byte"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeByte"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SNumericEntryBox<uint8>)
		.AllowSpin(true)
		.MinValue(TNumericLimits<uint8>::Lowest())
		.MaxValue(TNumericLimits<uint8>::Max())
		.MinSliderValue(0)
		.MaxSliderValue(MAX_int8)
		.Value(this,&FSByte_CustomDetails::OnGetValue)
		.OnValueChanged(this,&FSByte_CustomDetails::OnSetValue)
	];
}

void FSByte_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSByte_CustomDetails::OnSetValue(uint8 Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,FString::FromInt(Input)));} else {Real->SetValue(FEncode(FString::FromInt(Input)));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,FString::FromInt(Input)));} else {Flip->SetValue(FEncode(FString::FromInt(Input)));}
}

TOptional<uint8> FSByte_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	//
	if (K.Len()>0) {return FCString::Atoi(*FDecode(K,R));} else {return FCString::Atoi(*FDecode(R));} return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeInt

TSharedRef<IPropertyTypeCustomization> FSInt_CustomDetails::MakeInstance() {
	return MakeShareable(new FSInt_CustomDetails());
}

void FSInt_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSIntTooltip","Safe Int32"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeInt"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SNumericEntryBox<int32>)
		.AllowSpin(true)
		.MinValue(TNumericLimits<int32>::Lowest())
		.MaxValue(TNumericLimits<int32>::Max())
		.MinSliderValue(0)
		.MaxSliderValue(1000)
		.Value(this,&FSInt_CustomDetails::OnGetValue)
		.OnValueChanged(this,&FSInt_CustomDetails::OnSetValue)
	];
}

void FSInt_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSInt_CustomDetails::OnSetValue(int32 Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,FString::FromInt(Input)));} else {Real->SetValue(FEncode(FString::FromInt(Input)));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,FString::FromInt(Input)));} else {Flip->SetValue(FEncode(FString::FromInt(Input)));}
}

TOptional<int32> FSInt_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	FString F; Flip->GetValue(F);
	//
	if (R.Len()>0) { if (K.Len()>0) {return FCString::Atoi(*FDecode(K,R));} else {return FCString::Atoi(*FDecode(R));} }
	if (F.Len()>0) { if (K.Len()>0) {return FCString::Atoi(*FDecode(K,F));} else {return FCString::Atoi(*FDecode(F));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeFloat

TSharedRef<IPropertyTypeCustomization> FSFloat_CustomDetails::MakeInstance() {
	return MakeShareable(new FSFloat_CustomDetails());
}

void FSFloat_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSFloatTooltip","Safe Float"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeFloat"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SNumericEntryBox<float>)
		.AllowSpin(true)
		.MinValue(TNumericLimits<float>::Lowest())
		.MaxValue(TNumericLimits<float>::Max())
		.MinSliderValue(0)
		.MaxSliderValue(1000)
		.Value(this,&FSFloat_CustomDetails::OnGetValue)
		.OnValueChanged(this,&FSFloat_CustomDetails::OnSetValue)
	];
}

void FSFloat_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSFloat_CustomDetails::OnSetValue(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {Real->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {Flip->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSFloat_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	FString F; Flip->GetValue(F);
	//
	if (R.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,R));} else {return FCString::Atof(*FDecode(R));} }
	if (F.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,F));} else {return FCString::Atof(*FDecode(F));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeName

TSharedRef<IPropertyTypeCustomization> FSName_CustomDetails::MakeInstance() {
	return MakeShareable(new FSName_CustomDetails());
}

void FSName_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSNameTooltip","Safe Name"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeName"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SEditableTextBox)
		.Text(this,&FSName_CustomDetails::OnGetValue)
		.OnTextCommitted(this,&FSName_CustomDetails::OnSetValue)
	];
}

void FSName_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSName_CustomDetails::OnSetValue(const FText &Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,*&Input.ToString()));} else {Real->SetValue(FEncode(*&Input.ToString()));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,*&Input.ToString()));} else {Flip->SetValue(FEncode(*&Input.ToString()));}
}

FText FSName_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	FString F; Real->GetValue(F);
	//
	if (R.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,R));} else {return FText::FromString(*FDecode(R));} }
	if (F.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,F));} else {return FText::FromString(*FDecode(F));} }
	//
	return FText::FText();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeString

TSharedRef<IPropertyTypeCustomization> FSString_CustomDetails::MakeInstance() {
	return MakeShareable(new FSString_CustomDetails());
}

void FSString_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSStringTooltip","Safe String"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeString"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SEditableTextBox)
		.Text(this,&FSString_CustomDetails::OnGetValue)
		.OnTextCommitted(this,&FSString_CustomDetails::OnSetValue)
	];
}

void FSString_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSString_CustomDetails::OnSetValue(const FText &Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,*&Input.ToString()));} else {Real->SetValue(FEncode(*&Input.ToString()));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,*&Input.ToString()));} else {Flip->SetValue(FEncode(*&Input.ToString()));}
}

FText FSString_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	FString F; Real->GetValue(F);
	//
	if (R.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,R));} else {return FText::FromString(*FDecode(R));} }
	if (F.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,F));} else {return FText::FromString(*FDecode(F));} }
	//
	return FText::FText();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeText

TSharedRef<IPropertyTypeCustomization> FSText_CustomDetails::MakeInstance() {
	return MakeShareable(new FSText_CustomDetails());
}

void FSText_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<3) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	Real = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	Flip = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	if (!Keys->IsValidHandle()||!Real->IsValidHandle()||!Flip->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSTextTooltip","Safe Text"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeText"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(400)
	[
		SNew(SEditableTextBox)
		.Text(this,&FSText_CustomDetails::OnGetValue)
		.OnTextCommitted(this,&FSText_CustomDetails::OnSetValue)
	];
}

void FSText_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSText_CustomDetails::OnSetValue(const FText &Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {Real->SetValue(FEncode(K,*&Input.ToString()));} else {Real->SetValue(FEncode(*&Input.ToString()));}
	if (K.Len()>0) {Flip->SetValue(FEncode(K,*&Input.ToString()));} else {Flip->SetValue(FEncode(*&Input.ToString()));}
}

FText FSText_CustomDetails::OnGetValue() const {
	FString K; Keys->GetValue(K);
	FString R; Real->GetValue(R);
	FString F; Real->GetValue(F);
	//
	if (R.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,R));} else {return FText::FromString(*FDecode(R));} }
	if (F.Len()>0) { if (K.Len()>0) {return FText::FromString(*FDecode(K,F));} else {return FText::FromString(*FDecode(F));} }
	//
	return FText::FText();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector2D

TSharedRef<IPropertyTypeCustomization> FSV2D_CustomDetails::MakeInstance() {
	return MakeShareable(new FSV2D_CustomDetails());
}

void FSV2D_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<5) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	RealX = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	RealY = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	FlipX = StructPropertyHandle->GetChildHandle(3).ToSharedRef();
	FlipY = StructPropertyHandle->GetChildHandle(4).ToSharedRef();
	//
	if (!Keys->IsValidHandle()) {return;}
	if (!RealX->IsValidHandle()||!RealY->IsValidHandle()) {return;}
	if (!FlipX->IsValidHandle()||!FlipY->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSV2DTooltip","Safe Vector 2D"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeVector2D"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(600)
	[
		SNew(SVector2DBox)
		.ValueX(this,&FSV2D_CustomDetails::OnGetValueX)
		.ValueY(this,&FSV2D_CustomDetails::OnGetValueY)
		.OnSetValueX(this,&FSV2D_CustomDetails::OnSetValueX)
		.OnSetValueY(this,&FSV2D_CustomDetails::OnSetValueY)
		.OnValueChangeX(this,&FSV2D_CustomDetails::OnValueChangeX)
		.OnValueChangeY(this,&FSV2D_CustomDetails::OnValueChangeY)
	];
}

void FSV2D_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSV2D_CustomDetails::OnSetValueX(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV2D_CustomDetails::OnSetValueY(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV2D_CustomDetails::OnValueChangeX(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV2D_CustomDetails::OnValueChangeY(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSV2D_CustomDetails::OnGetValueX() const {
	FString K; Keys->GetValue(K);
	FString RX; RealX->GetValue(RX);
	FString FX; FlipX->GetValue(FX);
	//
	if (RX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RX));} else {return FCString::Atof(*FDecode(RX));} }
	if (FX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FX));} else {return FCString::Atof(*FDecode(FX));} }
	//
	return 0;
}

TOptional<float> FSV2D_CustomDetails::OnGetValueY() const {
	FString K; Keys->GetValue(K);
	FString RY; RealY->GetValue(RY);
	FString FY; FlipY->GetValue(FY);
	//
	if (RY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RY));} else {return FCString::Atof(*FDecode(RY));} }
	if (FY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FY));} else {return FCString::Atof(*FDecode(FY));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector3D

TSharedRef<IPropertyTypeCustomization> FSV3D_CustomDetails::MakeInstance() {
	return MakeShareable(new FSV3D_CustomDetails());
}

void FSV3D_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<7) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	RealX = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	RealY = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	RealZ = StructPropertyHandle->GetChildHandle(3).ToSharedRef();
	FlipX = StructPropertyHandle->GetChildHandle(4).ToSharedRef();
	FlipY = StructPropertyHandle->GetChildHandle(5).ToSharedRef();
	FlipZ = StructPropertyHandle->GetChildHandle(6).ToSharedRef();
	//
	if (!Keys->IsValidHandle()) {return;}
	if (!RealX->IsValidHandle()||!RealY->IsValidHandle()||!RealZ->IsValidHandle()) {return;}
	if (!FlipX->IsValidHandle()||!FlipY->IsValidHandle()||!FlipZ->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSV3DTooltip","Safe Vector 3D"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeVector3D"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(600)
	[
		SNew(SVector3DBox)
		.ValueX(this,&FSV3D_CustomDetails::OnGetValueX)
		.ValueY(this,&FSV3D_CustomDetails::OnGetValueY)
		.ValueZ(this,&FSV3D_CustomDetails::OnGetValueZ)
		.OnSetValueX(this,&FSV3D_CustomDetails::OnSetValueX)
		.OnSetValueY(this,&FSV3D_CustomDetails::OnSetValueY)
		.OnSetValueZ(this,&FSV3D_CustomDetails::OnSetValueZ)
		.OnValueChangeX(this,&FSV3D_CustomDetails::OnValueChangeX)
		.OnValueChangeY(this,&FSV3D_CustomDetails::OnValueChangeY)
		.OnValueChangeZ(this,&FSV3D_CustomDetails::OnValueChangeZ)
	];
}

void FSV3D_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSV3D_CustomDetails::OnSetValueX(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV3D_CustomDetails::OnSetValueY(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV3D_CustomDetails::OnSetValueZ(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV3D_CustomDetails::OnValueChangeX(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV3D_CustomDetails::OnValueChangeY(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV3D_CustomDetails::OnValueChangeZ(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSV3D_CustomDetails::OnGetValueX() const {
	FString K; Keys->GetValue(K);
	FString RX; RealX->GetValue(RX);
	FString FX; FlipX->GetValue(FX);
	//
	if (RX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RX));} else {return FCString::Atof(*FDecode(RX));} }
	if (FX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FX));} else {return FCString::Atof(*FDecode(FX));} }
	//
	return 0;
}

TOptional<float> FSV3D_CustomDetails::OnGetValueY() const {
	FString K; Keys->GetValue(K);
	FString RY; RealY->GetValue(RY);
	FString FY; FlipY->GetValue(FY);
	//
	if (RY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RY));} else {return FCString::Atof(*FDecode(RY));} }
	if (FY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FY));} else {return FCString::Atof(*FDecode(FY));} }
	//
	return 0;
}

TOptional<float> FSV3D_CustomDetails::OnGetValueZ() const {
	FString K; Keys->GetValue(K);
	FString RZ; RealZ->GetValue(RZ);
	FString FZ; FlipZ->GetValue(FZ);
	//
	if (RZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RZ));} else {return FCString::Atof(*FDecode(RZ));} }
	if (FZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FZ));} else {return FCString::Atof(*FDecode(FZ));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector4D

TSharedRef<IPropertyTypeCustomization> FSV4D_CustomDetails::MakeInstance() {
	return MakeShareable(new FSV4D_CustomDetails());
}

void FSV4D_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<9) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	RealX = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	RealY = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	RealZ = StructPropertyHandle->GetChildHandle(3).ToSharedRef();
	RealW = StructPropertyHandle->GetChildHandle(4).ToSharedRef();
	FlipX = StructPropertyHandle->GetChildHandle(5).ToSharedRef();
	FlipY = StructPropertyHandle->GetChildHandle(6).ToSharedRef();
	FlipZ = StructPropertyHandle->GetChildHandle(7).ToSharedRef();
	FlipW = StructPropertyHandle->GetChildHandle(8).ToSharedRef();
	//
	if (!Keys->IsValidHandle()) {return;}
	if (!RealX->IsValidHandle()||!RealY->IsValidHandle()||!RealZ->IsValidHandle()||!RealW->IsValidHandle()) {return;}
	if (!FlipX->IsValidHandle()||!FlipY->IsValidHandle()||!FlipZ->IsValidHandle()||!FlipW->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSV4DTooltip","Safe Vector 4D"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeVector4D"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(600)
	[
		SNew(SVector4DBox)
		.ValueX(this,&FSV4D_CustomDetails::OnGetValueX)
		.ValueY(this,&FSV4D_CustomDetails::OnGetValueY)
		.ValueZ(this,&FSV4D_CustomDetails::OnGetValueZ)
		.ValueW(this,&FSV4D_CustomDetails::OnGetValueW)
		.OnSetValueX(this,&FSV4D_CustomDetails::OnSetValueX)
		.OnSetValueY(this,&FSV4D_CustomDetails::OnSetValueY)
		.OnSetValueZ(this,&FSV4D_CustomDetails::OnSetValueZ)
		.OnSetValueW(this,&FSV4D_CustomDetails::OnSetValueW)
		.OnValueChangeX(this,&FSV4D_CustomDetails::OnValueChangeX)
		.OnValueChangeY(this,&FSV4D_CustomDetails::OnValueChangeY)
		.OnValueChangeZ(this,&FSV4D_CustomDetails::OnValueChangeZ)
		.OnValueChangeW(this,&FSV4D_CustomDetails::OnValueChangeW)
	];
}

void FSV4D_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSV4D_CustomDetails::OnSetValueX(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnSetValueY(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnSetValueZ(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnSetValueW(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealW->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealW->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipW->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipW->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnValueChangeX(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnValueChangeY(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnValueChangeZ(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSV4D_CustomDetails::OnValueChangeW(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealW->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealW->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipW->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipW->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSV4D_CustomDetails::OnGetValueX() const {
	FString K; Keys->GetValue(K);
	FString RX; RealX->GetValue(RX);
	FString FX; FlipX->GetValue(FX);
	//
	if (RX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RX));} else {return FCString::Atof(*FDecode(RX));} }
	if (FX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FX));} else {return FCString::Atof(*FDecode(FX));} }
	//
	return 0;
}

TOptional<float> FSV4D_CustomDetails::OnGetValueY() const {
	FString K; Keys->GetValue(K);
	FString RY; RealY->GetValue(RY);
	FString FY; FlipY->GetValue(FY);
	//
	if (RY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RY));} else {return FCString::Atof(*FDecode(RY));} }
	if (FY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FY));} else {return FCString::Atof(*FDecode(FY));} }
	//
	return 0;
}

TOptional<float> FSV4D_CustomDetails::OnGetValueZ() const {
	FString K; Keys->GetValue(K);
	FString RZ; RealZ->GetValue(RZ);
	FString FZ; FlipZ->GetValue(FZ);
	//
	if (RZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RZ));} else {return FCString::Atof(*FDecode(RZ));} }
	if (FZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FZ));} else {return FCString::Atof(*FDecode(FZ));} }
	//
	return 0;
}

TOptional<float> FSV4D_CustomDetails::OnGetValueW() const {
	FString K; Keys->GetValue(K);
	FString RW; RealW->GetValue(RW);
	FString FW; FlipW->GetValue(FW);
	//
	if (RW.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RW));} else {return FCString::Atof(*FDecode(RW));} }
	if (FW.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FW));} else {return FCString::Atof(*FDecode(FW));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeColor

TSharedRef<IPropertyTypeCustomization> FSColor_CustomDetails::MakeInstance() {
	return MakeShareable(new FSColor_CustomDetails());
}

void FSColor_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<9) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	RealR = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	RealG = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	RealB = StructPropertyHandle->GetChildHandle(3).ToSharedRef();
	RealA = StructPropertyHandle->GetChildHandle(4).ToSharedRef();
	FlipR = StructPropertyHandle->GetChildHandle(5).ToSharedRef();
	FlipG = StructPropertyHandle->GetChildHandle(6).ToSharedRef();
	FlipB = StructPropertyHandle->GetChildHandle(7).ToSharedRef();
	FlipA = StructPropertyHandle->GetChildHandle(8).ToSharedRef();
	//
	if (!Keys->IsValidHandle()) {return;}
	if (!RealR->IsValidHandle()||!RealG->IsValidHandle()||!RealB->IsValidHandle()||!RealA->IsValidHandle()) {return;}
	if (!FlipR->IsValidHandle()||!FlipG->IsValidHandle()||!FlipB->IsValidHandle()||!FlipA->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSColorTooltip","Safe Color"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeColor"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(600)
	[
		SNew(SColorBox)
		.ValueR(this,&FSColor_CustomDetails::OnGetValueR)
		.ValueG(this,&FSColor_CustomDetails::OnGetValueG)
		.ValueB(this,&FSColor_CustomDetails::OnGetValueB)
		.ValueA(this,&FSColor_CustomDetails::OnGetValueA)
		.OnSetValueR(this,&FSColor_CustomDetails::OnSetValueR)
		.OnSetValueG(this,&FSColor_CustomDetails::OnSetValueG)
		.OnSetValueB(this,&FSColor_CustomDetails::OnSetValueB)
		.OnSetValueA(this,&FSColor_CustomDetails::OnSetValueA)
		.OnValueChangeR(this,&FSColor_CustomDetails::OnValueChangeR)
		.OnValueChangeG(this,&FSColor_CustomDetails::OnValueChangeG)
		.OnValueChangeB(this,&FSColor_CustomDetails::OnValueChangeB)
		.OnValueChangeA(this,&FSColor_CustomDetails::OnValueChangeA)
	];
}

void FSColor_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSColor_CustomDetails::OnSetValueR(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealR->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealR->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipR->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipR->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnSetValueG(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealG->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealG->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipG->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipG->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnSetValueB(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealB->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealB->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipB->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipB->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnSetValueA(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealA->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealA->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipA->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipA->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnValueChangeR(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealR->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealR->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipR->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipR->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnValueChangeG(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealG->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealG->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipG->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipG->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnValueChangeB(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealB->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealB->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipB->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipB->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSColor_CustomDetails::OnValueChangeA(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealA->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealA->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipA->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipA->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSColor_CustomDetails::OnGetValueR() const {
	FString K; Keys->GetValue(K);
	FString RR; RealR->GetValue(RR);
	FString FR; FlipR->GetValue(FR);
	//
	if (RR.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RR));} else {return FCString::Atof(*FDecode(RR));} }
	if (FR.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FR));} else {return FCString::Atof(*FDecode(FR));} }
	//
	return 0;
}

TOptional<float> FSColor_CustomDetails::OnGetValueG() const {
	FString K; Keys->GetValue(K);
	FString RG; RealG->GetValue(RG);
	FString FG; FlipG->GetValue(FG);
	//
	if (RG.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RG));} else {return FCString::Atof(*FDecode(RG));} }
	if (FG.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FG));} else {return FCString::Atof(*FDecode(FG));} }
	//
	return 0;
}

TOptional<float> FSColor_CustomDetails::OnGetValueB() const {
	FString K; Keys->GetValue(K);
	FString RB; RealB->GetValue(RB);
	FString FB; FlipB->GetValue(FB);
	//
	if (RB.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RB));} else {return FCString::Atof(*FDecode(RB));} }
	if (FB.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FB));} else {return FCString::Atof(*FDecode(FB));} }
	//
	return 0;
}

TOptional<float> FSColor_CustomDetails::OnGetValueA() const {
	FString K; Keys->GetValue(K);
	FString RA; RealA->GetValue(RA);
	FString FA; FlipA->GetValue(FA);
	//
	if (RA.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RA));} else {return FCString::Atof(*FDecode(RA));} }
	if (FA.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FA));} else {return FCString::Atof(*FDecode(FA));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeRotator

TSharedRef<IPropertyTypeCustomization> FSRotator_CustomDetails::MakeInstance() {
	return MakeShareable(new FSRotator_CustomDetails());
}

void FSRotator_CustomDetails::CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {
	uint32 C; StructPropertyHandle->GetNumChildren(C); if (C<7) {return;}
	Keys = StructPropertyHandle->GetChildHandle(0).ToSharedRef();
	RealX = StructPropertyHandle->GetChildHandle(1).ToSharedRef();
	RealY = StructPropertyHandle->GetChildHandle(2).ToSharedRef();
	RealZ = StructPropertyHandle->GetChildHandle(3).ToSharedRef();
	FlipX = StructPropertyHandle->GetChildHandle(4).ToSharedRef();
	FlipY = StructPropertyHandle->GetChildHandle(5).ToSharedRef();
	FlipZ = StructPropertyHandle->GetChildHandle(6).ToSharedRef();
	//
	if (!Keys->IsValidHandle()) {return;}
	if (!RealX->IsValidHandle()||!RealY->IsValidHandle()||!RealZ->IsValidHandle()) {return;}
	if (!FlipX->IsValidHandle()||!FlipY->IsValidHandle()||!FlipZ->IsValidHandle()) {return;}
	//
	//
	HeaderRow
	.NameContent()
	[
		SNew(SHorizontalBox)
		.ToolTipText(LOCTEXT("FSRotatorTooltip","Safe Rotator"))
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(0,0,5,0)
			[
				SNew(SImage)
				.Image(FSCUE5EditorStyle::Get().GetBrush("ClassIcon.SafeRotator"))
			]
		+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(IDetailLayoutBuilder::GetDetailFont())
			.Text(StructPropertyHandle->GetPropertyDisplayName())
		]
	]
	.ValueContent()
	.MinDesiredWidth(150)
	.MaxDesiredWidth(600)
	[
		SNew(SVector3DBox)
		.ValueX(this,&FSRotator_CustomDetails::OnGetValueX)
		.ValueY(this,&FSRotator_CustomDetails::OnGetValueY)
		.ValueZ(this,&FSRotator_CustomDetails::OnGetValueZ)
		.OnSetValueX(this,&FSRotator_CustomDetails::OnSetValueX)
		.OnSetValueY(this,&FSRotator_CustomDetails::OnSetValueY)
		.OnSetValueZ(this,&FSRotator_CustomDetails::OnSetValueZ)
		.OnValueChangeX(this,&FSRotator_CustomDetails::OnValueChangeX)
		.OnValueChangeY(this,&FSRotator_CustomDetails::OnValueChangeY)
		.OnValueChangeZ(this,&FSRotator_CustomDetails::OnValueChangeZ)
	];
}

void FSRotator_CustomDetails::CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) {}

void FSRotator_CustomDetails::OnSetValueX(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSRotator_CustomDetails::OnSetValueY(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSRotator_CustomDetails::OnSetValueZ(float Input, ETextCommit::Type CommitType) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSRotator_CustomDetails::OnValueChangeX(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipX->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipX->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSRotator_CustomDetails::OnValueChangeY(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipY->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipY->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

void FSRotator_CustomDetails::OnValueChangeZ(float Input) const {
	FString K; Keys->GetValue(K);
	//
	if (K.Len()>0) {RealZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {RealZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
	if (K.Len()>0) {FlipZ->SetValue(FEncode(K,FString::Printf(TEXT("%f"),Input)));} else {FlipZ->SetValue(FEncode(FString::Printf(TEXT("%f"),Input)));}
}

TOptional<float> FSRotator_CustomDetails::OnGetValueX() const {
	FString K; Keys->GetValue(K);
	FString RX; RealX->GetValue(RX);
	FString FX; FlipX->GetValue(FX);
	//
	if (RX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RX));} else {return FCString::Atof(*FDecode(RX));} }
	if (FX.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FX));} else {return FCString::Atof(*FDecode(FX));} }
	//
	return 0;
}

TOptional<float> FSRotator_CustomDetails::OnGetValueY() const {
	FString K; Keys->GetValue(K);
	FString RY; RealY->GetValue(RY);
	FString FY; FlipY->GetValue(FY);
	//
	if (RY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RY));} else {return FCString::Atof(*FDecode(RY));} }
	if (FY.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FY));} else {return FCString::Atof(*FDecode(FY));} }
	//
	return 0;
}

TOptional<float> FSRotator_CustomDetails::OnGetValueZ() const {
	FString K; Keys->GetValue(K);
	FString RZ; RealZ->GetValue(RZ);
	FString FZ; FlipZ->GetValue(FZ);
	//
	if (RZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,RZ));} else {return FCString::Atof(*FDecode(RZ));} }
	if (FZ.Len()>0) { if (K.Len()>0) {return FCString::Atof(*FDecode(K,FZ));} else {return FCString::Atof(*FDecode(FZ));} }
	//
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IMPLEMENT_MODULE(FSCUE5Editor,SCUE5Editor)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////