//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//			Copyright 2025 (C) Bruno Xavier Leite
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Modules/ModuleManager.h"

#include "Widgets/Input/SNumericEntryBox.h"
#include "PropertyEditing.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "LevelEditor.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FToolBarBuilder;
class FMenuBuilder;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FSCUE5Editor : public IModuleInterface {
private:
	TSharedPtr<FUICommandList> PluginCommands;
	void AddToolbarExtension(FToolBarBuilder &Builder);
	void AddMenuExtension(FMenuBuilder &Builder);
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	//
	void PluginButtonClicked();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeBool

class SCUE5EDITOR_API FSBool_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	ECheckBoxState OnGetValue() const;
	void OnSetValue(ECheckBoxState Input) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeByte

class SCUE5EDITOR_API FSByte_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<uint8> OnGetValue() const;
	void OnSetValue(uint8 Input) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeInt

class SCUE5EDITOR_API FSInt_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<int32> OnGetValue() const;
	void OnSetValue(int32 Input) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeFloat

class SCUE5EDITOR_API FSFloat_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValue() const;
	void OnSetValue(float Input) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeName

class SCUE5EDITOR_API FSName_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	FText OnGetValue() const;
	void OnSetValue(const FText &Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeString

class SCUE5EDITOR_API FSString_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	FText OnGetValue() const;
	void OnSetValue(const FText &Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeText

class SCUE5EDITOR_API FSText_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> Real;
	TSharedPtr<IPropertyHandle> Flip;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	FText OnGetValue() const;
	void OnSetValue(const FText &Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector2D

class SCUE5EDITOR_API FSV2D_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> RealX;
	TSharedPtr<IPropertyHandle> RealY;
	TSharedPtr<IPropertyHandle> FlipX;
	TSharedPtr<IPropertyHandle> FlipY;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValueX() const;
	TOptional<float> OnGetValueY() const;
	void OnValueChangeX(float Input) const;
	void OnValueChangeY(float Input) const;
	void OnSetValueX(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueY(float Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector3D

class SCUE5EDITOR_API FSV3D_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> RealX;
	TSharedPtr<IPropertyHandle> RealY;
	TSharedPtr<IPropertyHandle> RealZ;
	TSharedPtr<IPropertyHandle> FlipX;
	TSharedPtr<IPropertyHandle> FlipY;
	TSharedPtr<IPropertyHandle> FlipZ;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValueX() const;
	TOptional<float> OnGetValueY() const;
	TOptional<float> OnGetValueZ() const;
	void OnValueChangeX(float Input) const;
	void OnValueChangeY(float Input) const;
	void OnValueChangeZ(float Input) const;
	void OnSetValueX(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueY(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueZ(float Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeVector4D

class SCUE5EDITOR_API FSV4D_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> RealX;
	TSharedPtr<IPropertyHandle> RealY;
	TSharedPtr<IPropertyHandle> RealZ;
	TSharedPtr<IPropertyHandle> RealW;
	TSharedPtr<IPropertyHandle> FlipX;
	TSharedPtr<IPropertyHandle> FlipY;
	TSharedPtr<IPropertyHandle> FlipZ;
	TSharedPtr<IPropertyHandle> FlipW;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValueX() const;
	TOptional<float> OnGetValueY() const;
	TOptional<float> OnGetValueZ() const;
	TOptional<float> OnGetValueW() const;
	void OnValueChangeX(float Input) const;
	void OnValueChangeY(float Input) const;
	void OnValueChangeZ(float Input) const;
	void OnValueChangeW(float Input) const;
	void OnSetValueX(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueY(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueZ(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueW(float Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeColor

class SCUE5EDITOR_API FSColor_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> RealR;
	TSharedPtr<IPropertyHandle> RealG;
	TSharedPtr<IPropertyHandle> RealB;
	TSharedPtr<IPropertyHandle> RealA;
	TSharedPtr<IPropertyHandle> FlipR;
	TSharedPtr<IPropertyHandle> FlipG;
	TSharedPtr<IPropertyHandle> FlipB;
	TSharedPtr<IPropertyHandle> FlipA;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValueR() const;
	TOptional<float> OnGetValueG() const;
	TOptional<float> OnGetValueB() const;
	TOptional<float> OnGetValueA() const;
	void OnValueChangeR(float Input) const;
	void OnValueChangeG(float Input) const;
	void OnValueChangeB(float Input) const;
	void OnValueChangeA(float Input) const;
	void OnSetValueR(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueG(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueB(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueA(float Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FSafeRotator

class SCUE5EDITOR_API FSRotator_CustomDetails : public IPropertyTypeCustomization {
private:
	TSharedPtr<IPropertyHandle> Keys;
	TSharedPtr<IPropertyHandle> RealX;
	TSharedPtr<IPropertyHandle> RealY;
	TSharedPtr<IPropertyHandle> RealZ;
	TSharedPtr<IPropertyHandle> FlipX;
	TSharedPtr<IPropertyHandle> FlipY;
	TSharedPtr<IPropertyHandle> FlipZ;
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	//
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow &HeaderRow, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder &StructBuilder, IPropertyTypeCustomizationUtils &StructCustomizationUtils) override;
	//
	TOptional<float> OnGetValueX() const;
	TOptional<float> OnGetValueY() const;
	TOptional<float> OnGetValueZ() const;
	void OnValueChangeX(float Input) const;
	void OnValueChangeY(float Input) const;
	void OnValueChangeZ(float Input) const;
	void OnSetValueX(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueY(float Input, ETextCommit::Type CommitType) const;
	void OnSetValueZ(float Input, ETextCommit::Type CommitType) const;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOCTEXT_NAMESPACE "FSCUE5Editor"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_DELEGATE_OneParam(FOnValueChanged,float);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SVector2DBox : public SCompoundWidget {
private:
	TAttribute<TOptional<float>> ValueX;
	TAttribute<TOptional<float>> ValueY;
	TOptional<float> GetValueX() const {return ValueX.Get();}
	TOptional<float> GetValueY() const {return ValueY.Get();}
public:
	SLATE_BEGIN_ARGS(SVector2DBox) {}
		SLATE_ATTRIBUTE(TOptional<float>,ValueX)
		SLATE_ATTRIBUTE(TOptional<float>,ValueY)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueX)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueY)
		SLATE_EVENT(FOnValueChanged,OnValueChangeX)
		SLATE_EVENT(FOnValueChanged,OnValueChangeY)
	SLATE_END_ARGS()
	//
	void Construct(const FArguments &InArgs) {
		ValueX = InArgs._ValueX;
		ValueY = InArgs._ValueY;
		//
		this->ChildSlot
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.AllowSpin(true)
					.LabelVAlign(VAlign_Center)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(100)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV2DXAxisLabel","X"))
					]	
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV2DXLabelToolTip","X value"))
					.Value(this,&SVector2DBox::GetValueX)
					.OnValueCommitted(InArgs._OnSetValueX)
					.OnValueChanged(InArgs._OnValueChangeX)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.AllowSpin(true)
					.LabelVAlign(VAlign_Center)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(100)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV2DYAxisLabel","Y"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV2DYAxisLabelToolTip","Y value"))
					.Value(this,&SVector2DBox::GetValueY)
					.OnValueCommitted(InArgs._OnSetValueY)
					.OnValueChanged(InArgs._OnValueChangeY)
				]
			]
		];
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SVector3DBox : public SCompoundWidget {
private:
	TAttribute<TOptional<float>> ValueX;
	TAttribute<TOptional<float>> ValueY;
	TAttribute<TOptional<float>> ValueZ;
	TOptional<float> GetValueX() const {return ValueX.Get();}
	TOptional<float> GetValueY() const {return ValueY.Get();}
	TOptional<float> GetValueZ() const {return ValueZ.Get();}
public:
	SLATE_BEGIN_ARGS(SVector3DBox) {}
		SLATE_ATTRIBUTE(TOptional<float>,ValueX)
		SLATE_ATTRIBUTE(TOptional<float>,ValueY)
		SLATE_ATTRIBUTE(TOptional<float>,ValueZ)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueX)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueY)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueZ)
		SLATE_EVENT(FOnValueChanged,OnValueChangeX)
		SLATE_EVENT(FOnValueChanged,OnValueChangeY)
		SLATE_EVENT(FOnValueChanged,OnValueChangeZ)
	SLATE_END_ARGS()
	//
	void Construct(const FArguments &InArgs) {
		ValueX = InArgs._ValueX;
		ValueY = InArgs._ValueY;
		ValueZ = InArgs._ValueZ;
		//
		this->ChildSlot
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV3DXAxisLabel","X"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV3DXLabelToolTip","X value"))
					.Value(this,&SVector3DBox::GetValueX)
					.OnValueCommitted(InArgs._OnSetValueX)
					.OnValueChanged(InArgs._OnValueChangeX)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV3DYAxisLabel","Y"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV3DYAxisLabelToolTip","Y value"))
					.Value(this,&SVector3DBox::GetValueY)
					.OnValueCommitted(InArgs._OnSetValueY)
					.OnValueChanged(InArgs._OnValueChangeY)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV3DZAxisLabel","Z"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV3DZAxisLabelToolTip","Z value"))
					.Value(this,&SVector3DBox::GetValueZ)
					.OnValueCommitted(InArgs._OnSetValueZ)
					.OnValueChanged(InArgs._OnValueChangeZ)
				]
			]
		];
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SVector4DBox : public SCompoundWidget {
private:
	TAttribute<TOptional<float>> ValueX;
	TAttribute<TOptional<float>> ValueY;
	TAttribute<TOptional<float>> ValueZ;
	TAttribute<TOptional<float>> ValueW;
	TOptional<float> GetValueX() const {return ValueX.Get();}
	TOptional<float> GetValueY() const {return ValueY.Get();}
	TOptional<float> GetValueZ() const {return ValueZ.Get();}
	TOptional<float> GetValueW() const {return ValueW.Get();}
public:
	SLATE_BEGIN_ARGS(SVector4DBox) {}
		SLATE_ATTRIBUTE(TOptional<float>,ValueX)
		SLATE_ATTRIBUTE(TOptional<float>,ValueY)
		SLATE_ATTRIBUTE(TOptional<float>,ValueZ)
		SLATE_ATTRIBUTE(TOptional<float>,ValueW)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueX)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueY)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueZ)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueW)
		SLATE_EVENT(FOnValueChanged,OnValueChangeX)
		SLATE_EVENT(FOnValueChanged,OnValueChangeY)
		SLATE_EVENT(FOnValueChanged,OnValueChangeZ)
		SLATE_EVENT(FOnValueChanged,OnValueChangeW)
	SLATE_END_ARGS()
	//
	void Construct(const FArguments &InArgs) {
		ValueX = InArgs._ValueX;
		ValueY = InArgs._ValueY;
		ValueZ = InArgs._ValueZ;
		ValueW = InArgs._ValueW;
		//
		this->ChildSlot
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV4DXAxisLabel","X"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV4DXLabelToolTip","X value"))
					.Value(this,&SVector4DBox::GetValueX)
					.OnValueCommitted(InArgs._OnSetValueX)
					.OnValueChanged(InArgs._OnValueChangeX)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV4DYAxisLabel","Y"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV4DYAxisLabelToolTip","Y value"))
					.Value(this,&SVector4DBox::GetValueY)
					.OnValueCommitted(InArgs._OnSetValueY)
					.OnValueChanged(InArgs._OnValueChangeY)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV4DZAxisLabel","Z"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV4DZAxisLabelToolTip","Z value"))
					.Value(this,&SVector4DBox::GetValueZ)
					.OnValueCommitted(InArgs._OnSetValueZ)
					.OnValueChanged(InArgs._OnValueChangeZ)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSV4DWAxisLabel","W"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSV4DWAxisLabelToolTip","W value"))
					.Value(this,&SVector4DBox::GetValueW)
					.OnValueCommitted(InArgs._OnSetValueW)
					.OnValueChanged(InArgs._OnValueChangeW)
				]
			]
		];
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SColorBox : public SCompoundWidget {
private:
	TAttribute<TOptional<float>> ValueR;
	TAttribute<TOptional<float>> ValueG;
	TAttribute<TOptional<float>> ValueB;
	TAttribute<TOptional<float>> ValueA;
	TOptional<float> GetValueR() const {return ValueR.Get();}
	TOptional<float> GetValueG() const {return ValueG.Get();}
	TOptional<float> GetValueB() const {return ValueB.Get();}
	TOptional<float> GetValueA() const {return ValueA.Get();}
public:
	SLATE_BEGIN_ARGS(SColorBox) {}
		SLATE_ATTRIBUTE(TOptional<float>,ValueR)
		SLATE_ATTRIBUTE(TOptional<float>,ValueG)
		SLATE_ATTRIBUTE(TOptional<float>,ValueB)
		SLATE_ATTRIBUTE(TOptional<float>,ValueA)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueR)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueG)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueB)
		SLATE_EVENT(FOnFloatValueCommitted,OnSetValueA)
		SLATE_EVENT(FOnValueChanged,OnValueChangeR)
		SLATE_EVENT(FOnValueChanged,OnValueChangeG)
		SLATE_EVENT(FOnValueChanged,OnValueChangeB)
		SLATE_EVENT(FOnValueChanged,OnValueChangeA)
	SLATE_END_ARGS()
	//
	void Construct(const FArguments &InArgs) {
		ValueR = InArgs._ValueR;
		ValueG = InArgs._ValueG;
		ValueB = InArgs._ValueB;
		ValueA = InArgs._ValueA;
		//
		this->ChildSlot
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSColorRLabel","R"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSColorRLabelToolTip","Red value"))
					.Value(this,&SColorBox::GetValueR)
					.OnValueCommitted(InArgs._OnSetValueR)
					.OnValueChanged(InArgs._OnValueChangeR)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSColorGLabel","G"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSColorGLabelToolTip","Green value"))
					.Value(this,&SColorBox::GetValueG)
					.OnValueCommitted(InArgs._OnSetValueG)
					.OnValueChanged(InArgs._OnValueChangeG)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSColorBLabel","B"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSColorBLabelToolTip","Blue value"))
					.Value(this,&SColorBox::GetValueB)
					.OnValueCommitted(InArgs._OnSetValueB)
					.OnValueChanged(InArgs._OnValueChangeB)
				]
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				.AutoWidth()
				.FillWidth(1)
				.Padding(2)
				[
					SNew(SNumericEntryBox<float>)
					.LabelVAlign(VAlign_Center)
					.AllowSpin(true)
					.MinValue(TNumericLimits<float>::Lowest())
					.MaxValue(TNumericLimits<float>::Max())
					.MinDesiredValueWidth(50)
					.MinSliderValue(TNumericLimits<float>::Lowest())
					.MaxSliderValue(TNumericLimits<float>::Max())
					.Delta(0.1f)
					.Label()
					[
						SNew(STextBlock)
						.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
						.Text(LOCTEXT("FSColorALabel","A"))
					]
					.Font(FAppStyle::GetFontStyle("Graph.VectorEditableTextBox"))
					.UndeterminedString(LOCTEXT("MultipleValues","Multiple Values"))
					.ToolTipText(LOCTEXT("FSColorALabelToolTip","Alpha value"))
					.Value(this,&SColorBox::GetValueA)
					.OnValueCommitted(InArgs._OnSetValueA)
					.OnValueChanged(InArgs._OnValueChangeA)
				]
			]
		];
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////