//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2016 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if PLATFORM_WINDOWS
 #include "Windows/AllowWindowsPlatformTypes.h"
 #include <Windows.h>
 #include <Winuser.h>
 #include "Windows/HideWindowsPlatformTypes.h"
#endif

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/WeakObjectPtr.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "Runtime/Core/Public/Misc/App.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Core/Public/Windows/WindowsPlatformProcess.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformProcess.h"
#include "Runtime/Core/Public/Misc/Paths.h"

#include "SCUE5.generated.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default SCUE5 Settings

UCLASS(ClassGroup = Synaptech, Category = "Synaptech", config = Game)
class SCUE5_API USCUE5Settings : public UObject {
	GENERATED_UCLASS_BODY()
public:
	/** Path to the Editor's Key Generator standalone executable. */
	UPROPERTY(Category = "General Settings", config, EditAnywhere, BlueprintReadOnly)
	FString KeyGeneratorPath;
	//
	/** List of illegal process words that internal scanner shall look for. */
	UPROPERTY(Category = "General Settings", config, EditAnywhere, BlueprintReadOnly)
	TArray<FString> IllegalKeywords;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static const FString ASCII_DIC = TEXT("0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ@~!#$%^&*()_-=+/|[]{}`;:,<>?.\\");
static const FString ASCII_KEY = TEXT(":.,@#}{[=^otTxmY+_!)*rACbfklpKVFWz]%Ju8ZgIi/HXGqj$>2MhPwDd1BS7-(3sEn06c5yRe?9U`L&|OvaNQ;4~<\\");

static FORCEINLINE FString FEncode(FString Input) {
	for (int I = 0; I<Input.Len(); I++) {
		int ID = -1; for (auto CH : ASCII_DIC) {
			ID++; if (Input[I]==CH) {Input[I]=ASCII_KEY[ID]; ID=-1; break;}
		}///
	}///
	//
	return *Input;
}

static FORCEINLINE FString FDecode(FString Input) {
	for (int I = 0; I<Input.Len(); I++) {
		int ID = -1; for (auto CH : ASCII_KEY) {
			ID++; if (Input[I]==CH) {Input[I]=ASCII_DIC[ID]; ID=-1; break;}
		}///
	}///
	//
	return *Input;
}

static FORCEINLINE FString FEncode(FString Key, FString Input) {
	for (int I = 0; I<Input.Len(); I++) {
		int ID = -1; for (auto CH : ASCII_DIC) {
			ID++; if (Input[I]==CH) {Input[I]=Key[ID]; ID=-1; break;}
		}///
	}///
	//
	return *Input;
}

static FORCEINLINE FString FDecode(FString Key, FString Input) {
	for (int I = 0; I<Input.Len(); I++) {
		int ID = -1; for (auto CH : Key) {
			ID++; if (Input[I]==CH) {Input[I]=ASCII_DIC[ID]; ID=-1; break;}
		}///
	}///
	//
	return *Input;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if PLATFORM_WINDOWS
	void FSCUE5_Enumerate();
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** Safe Boolean Property;
 Use this data format to store sensible Bool values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeBool {
	GENERATED_USTRUCT_BODY()
private:
	/** Internal Key. Can be replaced each operation if wanted. */
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;
	//
	/** Default Memory Address. */
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;
	//
	/** Alternative Memory Address. */
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;
	//
	/** Flag will take the value from Address, clear it and shift them,
	then copy value to previous Address and set it as default container. */
	UPROPERTY(SaveGame)
	uint8 Flag;
public:
	////////////////////////////////////////////////////////////
	/// Accessors
	//
	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}///
	//
	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}///
	//
	/** Gets value using Global Key. */
	bool GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FCString::ToBool(*FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FCString::ToBool(*FDecode(Base));
				} break;
			default: return false;}
		}///
	}///
	//
	bool GetValue() const {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
					return FCString::ToBool(*FDecode(Base));
				break;
				case 1:
					return FCString::ToBool(*FDecode(Shift));
				break;
			default: return false;}
		}///
	}///
	//
	/** Gets value from Custom Key. */
	bool GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FCString::ToBool(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FCString::ToBool(*FDecode(Key,Base));
			} break;
		default: return false;}
	}///
	//
	bool GetValue(const FString &Key) const {
		switch (Flag) {
			case 0:
				return FCString::ToBool(*FDecode(Key,Base));
			break;
			case 1:
				return FCString::ToBool(*FDecode(Key,Shift));
			break;
		default: return false;}
	}///
	//
	/** Sets value using Internal or Global Key. */
	void SetValue(const bool Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = FEncode((Input?TEXT("true"):TEXT("false")));
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = FEncode((Input?TEXT("true"):TEXT("false")));
					Flag = 0; Shift.Empty();
				} break;
			}///
		}///
	}///
	//
	/** Sets value from Custom Key. */
	void SetValue(const FString &Key, const bool Input) {
		switch (Flag) {
			case 0:
			{
				Shift = FEncode(Key,(Input?TEXT("true"):TEXT("false")));
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = FEncode(Key,(Input?TEXT("true"):TEXT("false")));
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}///
	//
	////////////////////////////////////////////////////////////
	/// Constructors
	//
	FSafeBool() {
		Internal = FString();
		Base = TEXT("false");
		Shift = TEXT("false");
		Flag = 0;
	}///
	//
	FSafeBool(const bool Input) {
		Internal = FString();
		Base = FEncode((Input?TEXT("true"):TEXT("false")));
		Shift = FEncode((Input?TEXT("true"):TEXT("false")));
		Flag = 0;
	}///
	//
	FSafeBool(const FString &Key, const bool Input) {
		Internal = FString(Key);
		Base = FEncode(Key,(Input?TEXT("true"):TEXT("false")));
		Shift = FEncode(Key,(Input?TEXT("true"):TEXT("false")));
		Flag = 0;
	}///
	//
	////////////////////////////////////////////////////////////
	/// Operators
	//
	FORCEINLINE FSafeBool &operator = (const FSafeBool &B) {
		Internal = B.Internal;
		Shift = B.Shift;
		Base = B.Base;
		Flag = B.Flag;
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeBool &operator = (const bool &B) {
		SetValue(B); return *this;
	}///
	//
	FORCEINLINE FArchive &operator << (FArchive &AR) {
		AR << Internal;
		AR << Shift;
		AR << Base;
		AR << Flag;
		//
		return AR;
	}///
	//
	friend FORCEINLINE uint32 GetTypeHash(const FSafeBool &B) {
		return FCrc::MemCrc32(&B,sizeof(FSafeBool));
	}///
};

/** Safe Byte Property;
 Use this data format to store sensible Byte values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeByte {
	GENERATED_USTRUCT_BODY()
private:
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;
	//
	UPROPERTY(SaveGame)
	uint8 Flag;
public:
	////////////////////////////////////////////////////////////
	/// Accessors
	//
	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}///
	//
	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}///
	//
	uint8 GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FCString::Atoi(*FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FCString::Atoi(*FDecode(Base));
				} break;
			default: return 0;}
		}///
	}///
	//
	uint8 GetValue() const {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
					return FCString::Atoi(*FDecode(Base));
				break;
				case 1:
					return FCString::Atoi(*FDecode(Shift));
				break;
			default: return 0;}
		}///
	}///
	//
	uint8 GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FCString::Atoi(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FCString::Atoi(*FDecode(Key,Base));
			} break;
		default: return 0;}
	}///
	//
	uint8 GetValue(const FString &Key) const {
		switch (Flag) {
			case 0:
				return FCString::Atoi(*FDecode(Key,Base));
			break;
			case 1:
				return FCString::Atoi(*FDecode(Key,Shift));
			break;
		default: return 0;}
	}///
	//
	void SetValue(uint8 Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = FEncode(FString::FromInt(Input));
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = FEncode(FString::FromInt(Input));
					Flag = 0; Shift.Empty();
				} break;
			default: return;}
		}///
	}///
	//
	void SetValue(const FString &Key, uint8 Input) {
		switch (Flag) {
			case 0:
			{
				Shift = FEncode(Key,FString::FromInt(Input));
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = FEncode(Key,FString::FromInt(Input));
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}///
	//
	////////////////////////////////////////////////////////////
	/// Constructors
	//
	FSafeByte() {
		Internal = FString();
		Base = TEXT("0");
		Shift = TEXT("0");
		Flag = 0;
	}///
	//
	FSafeByte(const uint8 Input) {
		Internal = FString();
		Base = FEncode(FString::FromInt(Input));
		Shift = FEncode(FString::FromInt(Input));
		Flag = 0;
	}///
	//
	FSafeByte(const FString &Key, const uint8 Input) {
		Internal = FString(Key);
		Base = FEncode(Key,FString::FromInt(Input));
		Shift = FEncode(Key,FString::FromInt(Input));
		Flag = 0;
	}///
	//
	////////////////////////////////////////////////////////////
	/// Operators
	//
	FORCEINLINE FSafeByte &operator = (const FSafeByte &B) {
		Internal = B.Internal;
		Shift = B.Shift;
		Base = B.Base;
		Flag = B.Flag;
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator = (const uint8 &B) {
		SetValue(B); return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator += (const uint8 &B) {
		uint8 I = (GetValue() + B);
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator -= (const uint8 &B) {
		uint8 I = (GetValue() - B);
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator += (const FSafeByte &B) {
		uint8 I = (GetValue() + B.GetValue());
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator -= (const FSafeByte &B) {
		uint8 I = (GetValue() - B.GetValue());
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte operator ++ (int) {
		FSafeByte SB = *this; (++ *this);
		//
		return SB;
	}///
	//
	FORCEINLINE FSafeByte operator -- (int) {
		FSafeByte SB = *this; (-- *this);
		//
		return SB;
	}///
	//
	FORCEINLINE FSafeByte &operator ++ () {
		uint8 I = GetValue(); I++;
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeByte &operator -- () {
		uint8 I = GetValue(); I--;
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FArchive &operator << (FArchive &AR) {
		AR << Internal;
		AR << Shift;
		AR << Base;
		AR << Flag;
		//
		return AR;
	}///
	//
	friend FORCEINLINE uint32 GetTypeHash(const FSafeByte &B) {
		return FCrc::MemCrc32(&B,sizeof(FSafeByte));
	}///
};

/** Safe Int32 Property;
 Use this data format to store sensible Int values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeInt {
	GENERATED_USTRUCT_BODY()
private:
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;
	//
	UPROPERTY(SaveGame)
	uint8 Flag;
public:
	////////////////////////////////////////////////////////////
	/// Accessors
	//
	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}///
	//
	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}///
	//
	int32 GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FCString::Atoi(*FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FCString::Atoi(*FDecode(Base));
				} break;
			default: return 0;}
		}///
	}///
	//
	int32 GetValue() const {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
					return FCString::Atoi(*FDecode(Base));
				break;
				case 1:
					return FCString::Atoi(*FDecode(Shift));
				break;
			default: return 0;}
		}///
	}///
	//
	int32 GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FCString::Atoi(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FCString::Atoi(*FDecode(Key,Base));
			} break;
		default: return 0;}
	}///
	//
	int32 GetValue(const FString &Key) const {
		switch (Flag) {
			case 0:
				return FCString::Atoi(*FDecode(Key,Base));
			break;
			case 1:
				return FCString::Atoi(*FDecode(Key,Shift));
			break;
		default: return 0;}
	}///
	//
	void SetValue(int32 Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
					Shift = FEncode(FString::FromInt(Input));
					Flag = 1; Base.Empty();
				case 1:
					Base = FEncode(FString::FromInt(Input));
					Flag = 0; Shift.Empty();
			default: return;}
		}///
	}///
	//
	void SetValue(const FString &Key, int32 Input) {
		switch (Flag) {
			case 0:
			{
				Shift = FEncode(Key,FString::FromInt(Input));
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = FEncode(Key,FString::FromInt(Input));
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}///
	//
	////////////////////////////////////////////////////////////
	/// Constructors
	//
	FSafeInt() {
		Internal = FString();
		Base = TEXT("0");
		Shift = TEXT("0");
		Flag = 0;
	}///
	//
	FSafeInt(const int32 Input) {
		Internal = FString();
		Base = FEncode(FString::FromInt(Input));
		Shift = FEncode(FString::FromInt(Input));
		Flag = 0;
	}///
	//
	FSafeInt(const FString &Key, const int32 Input) {
		Internal = FString(Key);
		Base = FEncode(Key,FString::FromInt(Input));
		Shift = FEncode(Key,FString::FromInt(Input));
		Flag = 0;
	}///
	//
	////////////////////////////////////////////////////////////
	/// Operators
	//
	FORCEINLINE FSafeInt &operator = (const FSafeInt &I) {
		Internal = I.Internal;
		Shift = I.Shift;
		Flag = I.Flag;
		Base = I.Base;
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator = (const int32 &I) {
		SetValue(I); return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator += (const FSafeInt &IT) {
		const int32 I = (GetValue() + IT.GetValue());
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator -= (const FSafeInt &IT) {
		const int32 I = (GetValue() - IT.GetValue());
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator += (const int32 &IT) {
		const int32 I = (GetValue() + IT);
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator -= (const int32 &IT) {
		const int32 I = (GetValue() - IT);
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt operator ++ (int) {
		FSafeInt SI = *this; (++ *this);
		//
		return SI;
	}///
	//
	FORCEINLINE FSafeInt operator -- (int) {
		FSafeInt SI = *this; (-- *this);
		//
		return SI;
	}///
	//
	FORCEINLINE FSafeInt &operator ++ () {
		int32 I = GetValue(); I++;
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeInt &operator -- () {
		int32 I = GetValue(); I--;
		SetValue(I);
		//
		return *this;
	}///
	//
	FORCEINLINE FArchive &operator << (FArchive &AR) {
		AR << Internal;
		AR << Shift;
		AR << Base;
		AR << Flag;
		//
		return AR;
	}///
	//
	friend FORCEINLINE uint32 GetTypeHash(const FSafeInt &I) {
		return FCrc::MemCrc32(&I,sizeof(FSafeInt));
	}///
};

/** Safe Float Property;
 Use this data format to store sensible Float values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeFloat {
	GENERATED_USTRUCT_BODY()
private:
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;
	//
	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;
	//
	UPROPERTY(SaveGame)
	uint8 Flag;
public:
	////////////////////////////////////////////////////////////
	/// Accessors
	//
	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}///
	//
	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}///
	//
	float GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FCString::Atof(*FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FCString::Atof(*FDecode(Base));
				} break;
			default: return 0.f;}
		}///
	}///
	//
	float GetValue() const {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
					return FCString::Atof(*FDecode(Base));
				break;
				case 1:
					return FCString::Atof(*FDecode(Shift));
				break;
			default: return 0.f;}
		}///
	}///
	//
	float GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FCString::Atof(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FCString::Atof(*FDecode(Key,Base));
			} break;
		default: return 0.f;}
	}///
	//
	float GetValue(const FString &Key) const {
		switch (Flag) {
			case 0:
				return FCString::Atof(*FDecode(Key,Base));
			break;
			case 1:
				return FCString::Atof(*FDecode(Key,Shift));
			break;
		default: return 0.f;}
	}///
	//
	void SetValue(float Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = FEncode(FString::Printf(TEXT("%f"),Input));
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = FEncode(FString::Printf(TEXT("%f"),Input));
					Flag = 0; Shift.Empty();
				} break;
			default: return;}
		}///
	}///
	//
	void SetValue(const FString &Key, float Input) {
		switch (Flag) {
			case 0:
			{
				Shift = FEncode(Key,FString::Printf(TEXT("%f"),Input));
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = FEncode(Key,FString::Printf(TEXT("%f"),Input));
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}///
	//
	////////////////////////////////////////////////////////////
	/// Constructors
	//
	FSafeFloat() {
		Internal = FString();
		Base = TEXT("0.0");
		Shift = TEXT("0.0");
		Flag = 0;
	}///
	//
	FSafeFloat(const float Input) {
		Internal = FString();
		Base = FEncode(FString::Printf(TEXT("%f"),Input));
		Shift = FEncode(FString::Printf(TEXT("%f"),Input));
		Flag = 0;
	}///
	///
	FSafeFloat(const FString &Key, const float Input) {
		Internal = FString(Key);
		Base = FEncode(Key,FString::Printf(TEXT("%f"),Input));
		Shift = FEncode(Key,FString::Printf(TEXT("%f"),Input));
		Flag = 0;
	}///
	//
	////////////////////////////////////////////////////////////
	/// Operators
	//
	FORCEINLINE FSafeFloat &operator = (const FSafeFloat &F) {
		Internal = F.Internal;
		Base = F.Base;
		Shift = F.Shift;
		Flag = F.Flag;
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator = (const float &F) {
		SetValue(F); return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator += (const FSafeFloat &F) {
		const float SF = (GetValue() + F.GetValue());
		SetValue(SF);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator -= (const FSafeFloat &F) {
		const float SF = (GetValue() - F.GetValue());
		SetValue(SF);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator += (const float &F) {
		const float SF = (GetValue() + F);
		SetValue(SF);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator -= (const float &F) {
		const float SF = (GetValue() - F);
		SetValue(SF);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat operator ++ (int) {
		FSafeFloat SF = *this; (++ *this);
		//
		return SF;
	}///
	//
	FORCEINLINE FSafeFloat operator -- (int) {
		FSafeFloat SF = *this; (-- *this);
		//
		return SF;
	}///
	//
	FORCEINLINE FSafeFloat &operator ++ () {
		float F = GetValue(); F++;
		SetValue(F);
		//
		return *this;
	}///
	//
	FORCEINLINE FSafeFloat &operator -- () {
		float F = GetValue(); F--;
		SetValue(F);
		//
		return *this;
	}///
	//
	FORCEINLINE FArchive &operator << (FArchive &AR) {
		AR << Internal;
		AR << Shift;
		AR << Base;
		AR << Flag;
		//
		return AR;
	}///
	//
	friend FORCEINLINE uint32 GetTypeHash(const FSafeFloat &I) {
		return FCrc::MemCrc32(&I,sizeof(FSafeFloat));
	}///
};

/** Safe Name Property;
 Use this data format to store sensible Name values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeName {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}

	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}

	FName GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FName(*FDecode(Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FName(*FDecode(Base));
			} break;
			default: return TEXT("");}
		}
	}

	FName GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FName(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FName(*FDecode(Key,Base));
			} break;
		default: return TEXT("");}
	}

	void SetValue(FName Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = *FEncode(Input.ToString());
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = *FEncode(Input.ToString());
					Flag = 0; Shift.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FName Input) {
		switch (Flag) {
			case 0:
			{
				Shift = *FEncode(Key,Input.ToString());
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = *FEncode(Key,Input.ToString());
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeName() {
		Internal = FString();
		Base = TEXT("");
		Shift = TEXT("");
		Flag = 0;
	}

	FSafeName(const FName Input) {
		Internal = FString();
		Base = *FEncode(Input.ToString());
		Shift = *FEncode(Input.ToString());
		Flag = 0;
	}

	FSafeName(const FString &Key, const FName Input) {
		Internal = FString(Key);
		Base = *FEncode(Key,Input.ToString());
		Shift = *FEncode(Key,Input.ToString());
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeName &operator = (const FSafeName &N) {
		Internal = N.Internal;
		Base = N.Base;
		Shift = N.Shift;
		Flag = N.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeName &operator = (const FName &N) {
		SetValue(N); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << Base;
		Ar << Shift;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeName &N) {
		return FCrc::MemCrc32(&N,sizeof(FSafeName));
	}

};

/** Safe String Property;
 Use this data format to store sensible String values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeString {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}

	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}

	FString GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FString(*FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FString(*FDecode(Base));
				} break;
			default: return TEXT("");}
		}
	}

	FString GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FString(*FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FString(*FDecode(Key,Base));
			} break;
		default: return TEXT("");}
	}

	void SetValue(FString Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = *FEncode(Input);
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = *FEncode(Input);
					Flag = 0; Shift.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FString Input) {
		switch (Flag) {
			case 0:
			{
				Shift = *FEncode(Key,Input);
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = *FEncode(Key,Input);
				Flag = 0; Shift.Empty();
			} break;
		}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeString() {
		Internal = FString();
		Base = TEXT("");
		Shift = TEXT("");
		Flag = 0;
	}

	FSafeString(const FString Input) {
		Internal = FString();
		Base = *FEncode(Input);
		Shift = *FEncode(Input);
		Flag = 0;
	}

	FSafeString(const FString &Key, const FString Input) {
		Internal = FString(Key);
		Base = *FEncode(Key,Input);
		Shift = *FEncode(Key,Input);
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeString &operator = (const FSafeString &S) {
		Internal = S.Internal;
		Base = S.Base;
		Shift = S.Shift;
		Flag = S.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeString &operator = (const FString &S) {
		SetValue(S); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << Base;
		Ar << Shift;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeString &S) {
		return FCrc::MemCrc32(&S,sizeof(FSafeString));
	}

};

/** Safe Text Property;
 Use this data format to store sensible Text values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeText {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Base;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Shift;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FString GetRaw() {
		if (Shift.Len()>0) {return Shift;} else {return Base;}
	}

	void SetRaw(FString* Value) {
		Shift = *Value;
		Base = *Value;
	}

	FText GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1; Shift = Base; Base.Empty();
					return FText::FromString(FDecode(Shift));
				} break;
				case 1:
				{
					Flag = 0; Base = Shift; Shift.Empty();
					return FText::FromString(FDecode(Base));
				} break;
			default: return FText::GetEmpty();}
		}
	}

	FText GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1; Shift = Base; Base.Empty();
				return FText::FromString(FDecode(Key,Shift));
			} break;
			case 1:
			{
				Flag = 0; Base = Shift; Shift.Empty();
				return FText::FromString(FDecode(Key,Base));
			} break;
		default: return FText::GetEmpty();}
	}

	void SetValue(FText Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Shift = *FEncode(Input.ToString());
					Flag = 1; Base.Empty();
				} break;
				case 1:
				{
					Base = *FEncode(Input.ToString());
					Flag = 0; Shift.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FText Input) {
		switch (Flag) {
			case 0:
			{
				Shift = *FEncode(Key,Input.ToString());
				Flag = 1; Base.Empty();
			} break;
			case 1:
			{
				Base = *FEncode(Key,Input.ToString());
				Flag = 0; Shift.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeText() {
		Internal = FString();
		Base = TEXT("");
		Shift = TEXT("");
		Flag = 0;
	}

	FSafeText(const FText Input) {
		Internal = FString();
		Base = *FEncode(Input.ToString());
		Shift = *FEncode(Input.ToString());
		Flag = 0;
	}

	FSafeText(const FString &Key, const FText Input) {
		Internal = FString(Key);
		Base = *FEncode(Key,Input.ToString());
		Shift = *FEncode(Key,Input.ToString());
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeText &operator = (const FSafeText &T) {
		Internal = T.Internal;
		Base = T.Base;
		Shift = T.Shift;
		Flag = T.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeText &operator = (const FText &T) {
		SetValue(T); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << Base;
		Ar << Shift;
		Ar << Internal;
		return Ar;
	}

};

/** Safe Vector2D Property;
 Use this data format to store sensible Vector2D values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeVector2D {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftY;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FVector2D GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = TrueX; ShiftY = TrueY;
					TrueX.Empty(); TrueY.Empty();
					return FVector2D(FCString::Atof(*FDecode(ShiftX)),FCString::Atof(*FDecode(ShiftY)));
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = ShiftX; TrueY = ShiftY;
					ShiftX.Empty(); ShiftY.Empty();
					return FVector2D(FCString::Atof(*FDecode(TrueX)),FCString::Atof(*FDecode(TrueY)));
				} break;
			default: return FVector2D::ZeroVector;}
		}
	}

	FVector2D GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = TrueX; ShiftY = TrueY;
				TrueX.Empty(); TrueY.Empty();
				return FVector2D(FCString::Atof(*FDecode(Key,ShiftX)),FCString::Atof(*FDecode(Key,ShiftY)));
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = ShiftX; TrueY = ShiftY;
				ShiftX.Empty(); ShiftY.Empty();
				return FVector2D(FCString::Atof(*FDecode(Key,TrueX)),FCString::Atof(*FDecode(Key,TrueY)));
			} break;
		default: return FVector2D::ZeroVector;}
	}

	void SetValue(FVector2D Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
					ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
					TrueX.Empty(); TrueY.Empty();
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
					TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
					ShiftX.Empty(); ShiftY.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FVector2D Input) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
				ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
				TrueX.Empty(); TrueY.Empty();
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
				TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
				ShiftX.Empty(); ShiftY.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeVector2D() {
		Internal = FString();
		TrueX = TEXT(""); TrueY = TEXT("");
		ShiftX = TEXT(""); ShiftY = TEXT("");
		Flag = 0;
	}

	FSafeVector2D(const float X, const float Y) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Y));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Y));
		Flag = 0;
	}

	FSafeVector2D(const FVector2D Input) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
		Flag = 0;
	}

	FSafeVector2D(const FString &Key, const FVector2D Input) {
		Internal = FString(Key);
		TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
		TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
		ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
		ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeVector2D &operator = (const FSafeVector2D &V) {
		Internal = V.Internal;
		TrueX = V.TrueX; TrueY = V.TrueY;
		ShiftX = V.ShiftX; ShiftY = V.ShiftY;
		Flag = V.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeVector2D &operator = (const FVector2D &V) {
		SetValue(V); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << TrueX;
		Ar << TrueY;
		Ar << ShiftX;
		Ar << ShiftY;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeVector2D &V) {
		return FCrc::MemCrc32(&V,sizeof(FSafeVector2D));
	}

};

/** Safe Vector3D Property;
 Use this data format to store sensible Vector3D values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeVector3D {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueZ;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftZ;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////

	FVector GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ;
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
					return FVector(FCString::Atof(*FDecode(ShiftX)),FCString::Atof(*FDecode(ShiftY)),FCString::Atof(*FDecode(ShiftZ)));
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ;
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
					return FVector(FCString::Atof(*FDecode(TrueX)),FCString::Atof(*FDecode(TrueY)),FCString::Atof(*FDecode(TrueZ)));
				} break;
			default: return FVector::ZeroVector;}
		}
	}

	FVector GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ;
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
				return FVector(FCString::Atof(*FDecode(Key,ShiftX)),FCString::Atof(*FDecode(Key,ShiftY)),FCString::Atof(*FDecode(Key,ShiftZ)));
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ;
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
				return FVector(FCString::Atof(*FDecode(Key,TrueX)),FCString::Atof(*FDecode(Key,TrueY)),FCString::Atof(*FDecode(Key,TrueZ)));
			} break;
		default: return FVector::ZeroVector;}
	}

	void SetValue(FVector Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
					ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
					ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input.Z));
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
					TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
					TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input.Z));
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FVector Input) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
				ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
				ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Z));
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
				TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
				TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Z));
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeVector3D() {
		Internal = FString();
		TrueX = TEXT(""); TrueY = TEXT(""); TrueZ = TEXT("");
		ShiftX = TEXT(""); ShiftY = TEXT(""); ShiftZ = TEXT("");
		Flag = 0;
	}

	FSafeVector3D(const float X, const float Y, const float Z) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Y));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Z));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Y));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Z));
		Flag = 0;
	}

	FSafeVector3D(const FVector Input) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input.Z));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Y));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input.Z));
		Flag = 0;
	}

	FSafeVector3D(const FString &Key, const FVector Input) {
		Internal = FString(Key);
		TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
		TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
		TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Z));
		ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.X));
		ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Y));
		ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Z));
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeVector3D &operator = (const FSafeVector3D &V) {
		Internal = V.Internal;
		TrueX = V.TrueX; TrueY = V.TrueY; TrueZ = V.TrueZ;
		ShiftX = V.ShiftX; ShiftY = V.ShiftY; ShiftZ = V.ShiftZ;
		Flag = V.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeVector3D &operator = (const FVector &V) {
		SetValue(V); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << TrueX;
		Ar << TrueY;
		Ar << TrueZ;
		Ar << ShiftX;
		Ar << ShiftY;
		Ar << ShiftZ;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeVector3D &V) {
		return FCrc::MemCrc32(&V,sizeof(FSafeVector3D));
	}

};

/** Safe Vector4D Property;
 Use this data format to store sensible Vector4D values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeVector4D {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueZ;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueW;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftZ;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftW;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FVector4 GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ; ShiftW = TrueW;
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty(); TrueW.Empty();
					return FVector4(FCString::Atof(*FDecode(ShiftX)),FCString::Atof(*FDecode(ShiftY)),FCString::Atof(*FDecode(ShiftZ)),FCString::Atof(*FDecode(ShiftW)));
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ; TrueW = ShiftW;
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty(); ShiftW.Empty();
					return FVector4(FCString::Atof(*FDecode(TrueX)),FCString::Atof(*FDecode(TrueY)),FCString::Atof(*FDecode(TrueZ)),FCString::Atof(*FDecode(TrueW)));
				} break;
			default: return FVector4(FVector2D::ZeroVector,FVector2D::ZeroVector);}
		}
	}

	FVector4 GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ; ShiftW = TrueW;
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty(); TrueW.Empty();
				return FVector4(FCString::Atof(*FDecode(Key,ShiftX)),FCString::Atof(*FDecode(Key,ShiftY)),FCString::Atof(*FDecode(Key,ShiftZ)),FCString::Atof(*FDecode(Key,ShiftW)));
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ; TrueW = ShiftW;
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty(); ShiftW.Empty();
				return FVector4(FCString::Atof(*FDecode(Key,TrueX)),FCString::Atof(*FDecode(Key,TrueY)),FCString::Atof(*FDecode(Key,TrueZ)),FCString::Atof(*FDecode(Key,TrueW)));
			} break;
		default: return FVector4(FVector2D::ZeroVector,FVector2D::ZeroVector);}
	}

	void SetValue(FVector4* Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input->X));
					ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input->Y));
					ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input->Z));
					ShiftW = *FEncode(FString::Printf(TEXT("%f"),Input->W));
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty(); TrueW.Empty();
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = *FEncode(FString::Printf(TEXT("%f"),Input->X));
					TrueY = *FEncode(FString::Printf(TEXT("%f"),Input->Y));
					TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input->Z));
					TrueW = *FEncode(FString::Printf(TEXT("%f"),Input->W));
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty(); ShiftW.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FVector4* Input) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input->X));
				ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Y));
				ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Z));
				ShiftW = *FEncode(Key,FString::Printf(TEXT("%f"),Input->W));
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty(); TrueW.Empty();
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input->X));
				TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Y));
				TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Z));
				TrueW = *FEncode(Key,FString::Printf(TEXT("%f"),Input->W));
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty(); ShiftW.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeVector4D() {
		Internal = FString();
		TrueX = TEXT(""); TrueY = TEXT(""); TrueZ = TEXT(""); TrueW = TEXT("");
		ShiftX = TEXT(""); ShiftY = TEXT(""); ShiftZ = TEXT(""); ShiftW = TEXT("");
		Flag = 0;
	}

	FSafeVector4D(const float X, const float Y, const float Z, const float W) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Y));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Z));
		TrueW = *FEncode(FString::Printf(TEXT("%f"),W));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Y));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Z));
		ShiftW = *FEncode(FString::Printf(TEXT("%f"),W));
		Flag = 0;
	}

	FSafeVector4D(FVector4* Input) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),Input->X));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Input->Y));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input->Z));
		TrueW = *FEncode(FString::Printf(TEXT("%f"),Input->W));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input->X));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input->Y));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input->Z));
		ShiftW = *FEncode(FString::Printf(TEXT("%f"),Input->W));
		Flag = 0;
	}

	FSafeVector4D(const FString &Key, FVector4* Input) {
		Internal = FString(Key);
		TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input->X));
		TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Y));
		TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Z));
		TrueW = *FEncode(Key,FString::Printf(TEXT("%f"),Input->W));
		ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input->X));
		ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Y));
		ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input->Z));
		ShiftW = *FEncode(Key,FString::Printf(TEXT("%f"),Input->W));
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeVector4D &operator = (const FSafeVector4D &V) {
		Internal = V.Internal;
		TrueX = V.TrueX; TrueY = V.TrueY; TrueZ = V.TrueZ; TrueW = V.TrueW;
		ShiftX = V.ShiftX; ShiftY = V.ShiftY; ShiftZ = V.ShiftZ; ShiftW = V.ShiftW;
		Flag = V.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeVector4D &operator = (FVector4 &V) {
		SetValue(&V); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << TrueX;
		Ar << TrueY;
		Ar << TrueZ;
		Ar << TrueW;
		Ar << ShiftX;
		Ar << ShiftY;
		Ar << ShiftZ;
		Ar << ShiftW;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeVector4D &V) {
		return FCrc::MemCrc32(&V,sizeof(FSafeVector4D));
	}

};

/** Safe Color Property;
 Use this data format to store sensible Linear Color values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeColor {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueR;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueG;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueB;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueA;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftR;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftG;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftB;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftA;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FLinearColor GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftR = TrueR; ShiftG = TrueG; ShiftB = TrueB; ShiftA = TrueA;
					TrueR.Empty(); TrueG.Empty(); TrueB.Empty(); TrueA.Empty();
					return FLinearColor(FCString::Atof(*FDecode(ShiftR)),FCString::Atof(*FDecode(ShiftG)),FCString::Atof(*FDecode(ShiftB)),FCString::Atof(*FDecode(ShiftA)));
				} break;
				case 1:
				{
					Flag = 0;
					TrueR = ShiftR; TrueG = ShiftG; TrueB = ShiftB; TrueA = ShiftA;
					ShiftR.Empty(); ShiftG.Empty(); ShiftB.Empty(); ShiftA.Empty();
					return FLinearColor(FCString::Atof(*FDecode(TrueR)),FCString::Atof(*FDecode(TrueG)),FCString::Atof(*FDecode(TrueB)),FCString::Atof(*FDecode(TrueA)));
				} break;
				default: return FLinearColor::Black;}
		}
	}

	FLinearColor GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftR = TrueR; ShiftG = TrueG; ShiftB = TrueB; ShiftA = TrueA;
				TrueR.Empty(); TrueG.Empty(); TrueB.Empty(); TrueA.Empty();
				return FLinearColor(FCString::Atof(*FDecode(Key,ShiftR)),FCString::Atof(*FDecode(Key,ShiftG)),FCString::Atof(*FDecode(Key,ShiftB)),FCString::Atof(*FDecode(Key,ShiftA)));
			} break;
			case 1:
			{
				Flag = 0;
				TrueR = ShiftR; TrueG = ShiftG; TrueB = ShiftB; TrueA = ShiftA;
				ShiftR.Empty(); ShiftG.Empty(); ShiftB.Empty(); ShiftA.Empty();
				return FLinearColor(FCString::Atof(*FDecode(Key,TrueR)),FCString::Atof(*FDecode(Key,TrueG)),FCString::Atof(*FDecode(Key,TrueB)),FCString::Atof(*FDecode(Key,TrueA)));
			} break;
		default: return FLinearColor::Black;}
	}

	void SetValue(FLinearColor* Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftR = *FEncode(FString::Printf(TEXT("%f"),Input->R));
					ShiftG = *FEncode(FString::Printf(TEXT("%f"),Input->G));
					ShiftB = *FEncode(FString::Printf(TEXT("%f"),Input->B));
					ShiftA = *FEncode(FString::Printf(TEXT("%f"),Input->A));
					TrueR.Empty(); TrueG.Empty(); TrueB.Empty(); TrueA.Empty();
				} break;
				case 1:
				{
					Flag = 0;
					TrueR = *FEncode(FString::Printf(TEXT("%f"),Input->R));
					TrueG = *FEncode(FString::Printf(TEXT("%f"),Input->G));
					TrueB = *FEncode(FString::Printf(TEXT("%f"),Input->B));
					TrueA = *FEncode(FString::Printf(TEXT("%f"),Input->A));
					ShiftR.Empty(); ShiftG.Empty(); ShiftB.Empty(); ShiftA.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FLinearColor* Input) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftR = *FEncode(Key,FString::Printf(TEXT("%f"),Input->R));
				ShiftG = *FEncode(Key,FString::Printf(TEXT("%f"),Input->G));
				ShiftB = *FEncode(Key,FString::Printf(TEXT("%f"),Input->B));
				ShiftA = *FEncode(FString::Printf(TEXT("%f"),Input->A));
				TrueR.Empty(); TrueG.Empty(); TrueB.Empty(); TrueA.Empty();
			} break;
			case 1:
			{
				Flag = 0;
				TrueR = *FEncode(Key,FString::Printf(TEXT("%f"),Input->R));
				TrueG = *FEncode(Key,FString::Printf(TEXT("%f"),Input->G));
				TrueB = *FEncode(Key,FString::Printf(TEXT("%f"),Input->B));
				TrueA = *FEncode(Key,FString::Printf(TEXT("%f"),Input->A));
				ShiftR.Empty(); ShiftG.Empty(); ShiftB.Empty(); ShiftA.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeColor() {
		Internal = FString();
		TrueR = TEXT(""); TrueG = TEXT(""); TrueB = TEXT(""); TrueA = TEXT("");
		ShiftR = TEXT(""); ShiftG = TEXT(""); ShiftB = TEXT(""); ShiftA = TEXT("");
		Flag = 0;
	}

	FSafeColor(const FLinearColor Input) {
		Internal = FString();
		TrueR = *FEncode(FString::Printf(TEXT("%f"),Input.R));
		TrueG = *FEncode(FString::Printf(TEXT("%f"),Input.G));
		TrueB = *FEncode(FString::Printf(TEXT("%f"),Input.B));
		TrueA = *FEncode(FString::Printf(TEXT("%f"),Input.A));
		ShiftR = *FEncode(FString::Printf(TEXT("%f"),Input.R));
		ShiftG = *FEncode(FString::Printf(TEXT("%f"),Input.G));
		ShiftB = *FEncode(FString::Printf(TEXT("%f"),Input.B));
		ShiftA = *FEncode(FString::Printf(TEXT("%f"),Input.A));
		Flag = 0;
	}

	FSafeColor(const FString &Key, const FLinearColor Input) {
		Internal = FString(Key);
		TrueR = *FEncode(Key,FString::Printf(TEXT("%f"),Input.R));
		TrueG = *FEncode(Key,FString::Printf(TEXT("%f"),Input.G));
		TrueB = *FEncode(Key,FString::Printf(TEXT("%f"),Input.B));
		TrueA = *FEncode(Key,FString::Printf(TEXT("%f"),Input.A));
		ShiftR = *FEncode(Key,FString::Printf(TEXT("%f"),Input.R));
		ShiftG = *FEncode(Key,FString::Printf(TEXT("%f"),Input.G));
		ShiftB = *FEncode(Key,FString::Printf(TEXT("%f"),Input.B));
		ShiftA = *FEncode(Key,FString::Printf(TEXT("%f"),Input.A));
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeColor &operator = (const FSafeColor &C) {
		Internal = C.Internal;
		TrueR = C.TrueR; TrueG = C.TrueG; TrueB = C.TrueB; TrueA = C.TrueA;
		ShiftR = C.ShiftR; ShiftG = C.ShiftG; ShiftB = C.ShiftB; ShiftA = C.ShiftA;
		Flag = C.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeColor &operator = (FLinearColor &C) {
		SetValue(&C); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << TrueR;
		Ar << TrueG;
		Ar << TrueB;
		Ar << TrueA;
		Ar << ShiftR;
		Ar << ShiftG;
		Ar << ShiftB;
		Ar << ShiftA;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeColor &C) {
		return FCrc::MemCrc32(&C,sizeof(FSafeColor));
	}

};

/** Safe Rotator Property;
 Use this data format to store sensible Rotator values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeRotator {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString Internal;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString TrueZ;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftX;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftY;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FString ShiftZ;

	UPROPERTY(SaveGame)
	uint8 Flag;

public:

	////////////////////////////////////////////////////////////
	/// Accessors

	FRotator GetValue() {
		if (!Internal.IsEmpty()) {return GetValue(Internal);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ;
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
					return FRotator(FCString::Atof(*FDecode(ShiftX)),FCString::Atof(*FDecode(ShiftY)),FCString::Atof(*FDecode(ShiftZ)));
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ;
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
					return FRotator(FCString::Atof(*FDecode(TrueX)),FCString::Atof(*FDecode(TrueY)),FCString::Atof(*FDecode(TrueZ)));
				} break;
			default: return FRotator::ZeroRotator;}
		}
	}

	FRotator GetValue(const FString &Key) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = TrueX; ShiftY = TrueY; ShiftZ = TrueZ;
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
				return FRotator(FCString::Atof(*FDecode(Key,ShiftX)),FCString::Atof(*FDecode(Key,ShiftY)),FCString::Atof(*FDecode(Key,ShiftZ)));
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = ShiftX; TrueY = ShiftY; TrueZ = ShiftZ;
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
				return FRotator(FCString::Atof(*FDecode(Key,TrueX)),FCString::Atof(*FDecode(Key,TrueY)),FCString::Atof(*FDecode(Key,TrueZ)));
			} break;
		default: return FRotator::ZeroRotator;}
	}

	void SetValue(FRotator Input) {
		if (!Internal.IsEmpty()) {SetValue(Internal,Input);} else {
			switch (Flag) {
				case 0:
				{
					Flag = 1;
					ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.Pitch));
					ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Yaw));
					ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input.Roll));
					TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
				} break;
				case 1:
				{
					Flag = 0;
					TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.Pitch));
					TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Yaw));
					TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input.Roll));
					ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
				} break;
			default: return;}
		}
	}

	void SetValue(const FString &Key, FRotator Input) {
		switch (Flag) {
			case 0:
			{
				Flag = 1;
				ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Pitch));
				ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Yaw));
				ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Roll));
				TrueX.Empty(); TrueY.Empty(); TrueZ.Empty();
			} break;
			case 1:
			{
				Flag = 0;
				TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Pitch));
				TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Yaw));
				TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Roll));
				ShiftX.Empty(); ShiftY.Empty(); ShiftZ.Empty();
			} break;
		default: return;}
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeRotator() {
		Internal = FString();
		TrueX = TEXT(""); TrueY = TEXT(""); TrueZ = TEXT("");
		ShiftX = TEXT(""); ShiftY = TEXT(""); ShiftZ = TEXT("");
		Flag = 0;
	}

	FSafeRotator(const float Pitch, const float Yall, const float Roll) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),Pitch));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Yall));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Roll));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),Pitch));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Yall));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Roll));
		Flag = 0;
	}

	FSafeRotator(const FRotator Input) {
		Internal = FString();
		TrueX = *FEncode(FString::Printf(TEXT("%f"),Input.Pitch));
		TrueY = *FEncode(FString::Printf(TEXT("%f"),Input.Yaw));
		TrueZ = *FEncode(FString::Printf(TEXT("%f"),Input.Roll));
		ShiftX = *FEncode(FString::Printf(TEXT("%f"),Input.Pitch));
		ShiftY = *FEncode(FString::Printf(TEXT("%f"),Input.Yaw));
		ShiftZ = *FEncode(FString::Printf(TEXT("%f"),Input.Roll));
		Flag = 0;
	}

	FSafeRotator(const FString &Key, const FRotator Input) {
		Internal = FString(Key);
		TrueX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Pitch));
		TrueY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Yaw));
		TrueZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Roll));
		ShiftX = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Pitch));
		ShiftY = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Yaw));
		ShiftZ = *FEncode(Key,FString::Printf(TEXT("%f"),Input.Roll));
		Flag = 0;
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeRotator &operator = (const FSafeRotator &R) {
		Internal = R.Internal;
		TrueX = R.TrueX; TrueY = R.TrueY; TrueZ = R.TrueZ;
		ShiftX = R.ShiftX; ShiftY = R.ShiftY; ShiftZ = R.ShiftZ;
		Flag = R.Flag;
		return *this;
	}
	
	FORCEINLINE FSafeRotator &operator = (const FRotator &R) {
		SetValue(R); return *this;
	}

	FORCEINLINE FArchive &operator << (FArchive &Ar) { 
		Ar << Flag;
		Ar << TrueX;
		Ar << TrueY;
		Ar << TrueZ;
		Ar << ShiftX;
		Ar << ShiftY;
		Ar << ShiftZ;
		Ar << Internal;
		return Ar;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeRotator &R) {
		return FCrc::MemCrc32(&R,sizeof(FSafeRotator));
	}

};

/** Safe Transform Property;
 Use this data format to store sensible Transform values you need protected against memory hackers. */
USTRUCT(BlueprintType)
struct SCUE5_API FSafeTransform {
	GENERATED_USTRUCT_BODY()
private:

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FSafeVector3D Scale;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FSafeVector3D Position;

	UPROPERTY(Category = "Security", VisibleAnywhere, SaveGame)
	FSafeRotator Rotation;

public:

	////////////////////////////////////////////////////////////

	FTransform GetValue() {
		return FTransform(Rotation.GetValue(),Position.GetValue(),Scale.GetValue());
	}

	FTransform GetValue(const FString &Key) {
		return FTransform(Rotation.GetValue(*&Key),Position.GetValue(*&Key),Scale.GetValue(*&Key));
	}

	void SetValue(FTransform* Input) {
		Scale.SetValue(Input->GetScale3D());
		Position.SetValue(Input->GetLocation());
		Rotation.SetValue(Input->GetRotation().Rotator());
	}

	void SetValue(const FString &Key, FTransform* Input) {
		Scale.SetValue(*&Key,Input->GetScale3D());
		Position.SetValue(*&Key,Input->GetLocation());
		Rotation.SetValue(*&Key,Input->GetRotation().Rotator());
	}

	////////////////////////////////////////////////////////////
	/// Constructors

	FSafeTransform() {
		Scale = FSafeVector3D::FSafeVector3D();
		Position = FSafeVector3D::FSafeVector3D();
		Rotation = FSafeRotator::FSafeRotator();
	}

	FSafeTransform(FTransform* Input) {
		Scale = FSafeVector3D::FSafeVector3D(Input->GetScale3D());
		Position = FSafeVector3D::FSafeVector3D(Input->GetLocation());
		Rotation = FSafeRotator::FSafeRotator(Input->Rotator());
	}

	FSafeTransform(const FString &Key, FTransform* Input) {
		Scale = FSafeVector3D::FSafeVector3D(*&Key,Input->GetScale3D());
		Position = FSafeVector3D::FSafeVector3D(*&Key,Input->GetLocation());
		Rotation = FSafeRotator::FSafeRotator(*&Key,Input->Rotator());
	}

	////////////////////////////////////////////////////////////
	/// Operators

	FORCEINLINE FSafeTransform &operator = (const FSafeTransform &T) {
		Scale = T.Scale;
		Position = T.Position;
		Rotation = T.Rotation;
		return *this;
	}
	
	FORCEINLINE FSafeTransform &operator = (const FTransform &T) {
		Scale = T.GetScale3D();
		Position = T.GetLocation();
		Rotation = T.Rotator();
		return *this;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FSafeTransform &T) {
		return FCrc::MemCrc32(&T,sizeof(FSafeTransform));
	}

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Operators:: Adding support for custom 'Safe Type' operations

// FSBool

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeBool &FSB, FSafeBool &B) {
	return  (FSB.GetValue()==B.GetValue());
}

FORCEINLINE bool operator != (FSafeBool &FSB, FSafeBool &B) {
	return (FSB.GetValue()!=B.GetValue());
}

FORCEINLINE bool operator && (FSafeBool &FSB, FSafeBool &B) {
	return (FSB.GetValue()&&B.GetValue());
}

FORCEINLINE bool operator || (FSafeBool &FSB, FSafeBool &B) {
	return (FSB.GetValue()||B.GetValue());
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeBool &FSB, const bool &B) {
	return (FSB.GetValue()==B);
}

FORCEINLINE bool operator != (FSafeBool &FSB, const bool &B) {
	return (FSB.GetValue()!=B);
}

FORCEINLINE bool operator && (FSafeBool &FSB, const bool &B) {
	return (FSB.GetValue()&&B);
}

FORCEINLINE bool operator || (FSafeBool &FSB, const bool &B) {
	return (FSB.GetValue()||B);
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const bool &B, FSafeBool &FSB) {
	return (B==FSB.GetValue());
}

FORCEINLINE bool operator != (const bool &B, FSafeBool &FSB) {
	return (B!=FSB.GetValue());
}

FORCEINLINE bool operator && (const bool &B, FSafeBool &FSB) {
	return (B&&FSB.GetValue());
}

FORCEINLINE bool operator || (const bool &B, FSafeBool &FSB) {
	return (B||FSB.GetValue());
}

// FSByte

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()==B.GetValue());
}

FORCEINLINE bool operator != (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()!=B.GetValue());
}

FORCEINLINE bool operator > (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()>B.GetValue());
}

FORCEINLINE bool operator < (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()<B.GetValue());
}

FORCEINLINE bool operator >= (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()>=B.GetValue());
}

FORCEINLINE bool operator <= (FSafeByte &FSB, FSafeByte &B) {
	return (FSB.GetValue()<=B.GetValue());
}

FORCEINLINE FSafeByte operator + (FSafeByte &FSB, FSafeByte &B) {
	return FSafeByte(FSB.GetValue()+B.GetValue());
}

FORCEINLINE FSafeByte operator - (FSafeByte &FSB, FSafeByte &B) {
	return FSafeByte(FSB.GetValue()-B.GetValue());
}

FORCEINLINE FSafeByte operator * (FSafeByte &FSB, FSafeByte &B) {
	return FSafeByte(FSB.GetValue()*B.GetValue());
}

FORCEINLINE FSafeByte operator / (FSafeByte &FSB, FSafeByte &B) {
	return FSafeByte(FSB.GetValue()/B.GetValue());
}

FORCEINLINE FSafeByte operator ~ (FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return FSafeByte(~Local);
}

FORCEINLINE FSafeByte operator % (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto Mod = B.GetValue();
	return FSafeByte((Local%Mod));
}

FORCEINLINE FSafeByte operator & (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto An = B.GetValue();
	return FSafeByte((Local&An));
}

FORCEINLINE FSafeByte operator | (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto Orr = B.GetValue();
	return FSafeByte((Local|Orr));
}

FORCEINLINE FSafeByte operator ^ (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto To = B.GetValue();
	return FSafeByte((Local^To));
}

FORCEINLINE FSafeByte operator >> (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto To = B.GetValue();
	return FSafeByte((Local>>To));
}

FORCEINLINE FSafeByte operator << (FSafeByte &FSB, FSafeByte &B) {
	auto Local = FSB.GetValue(); auto To = B.GetValue();
	return FSafeByte((Local<<To));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()==B);
}

FORCEINLINE bool operator != (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()!=B);
}

FORCEINLINE bool operator > (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()>B);
}

FORCEINLINE bool operator < (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()<B);
}

FORCEINLINE bool operator >= (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()>=B);
}

FORCEINLINE bool operator <= (FSafeByte &FSB, const uint8 &B) {
	return (FSB.GetValue()<=B);
}

FORCEINLINE FSafeByte operator + (FSafeByte &FSB, const uint8 &B) {
	return FSafeByte(FSB.GetValue()+B);
}

FORCEINLINE FSafeByte operator - (FSafeByte &FSB, const uint8 &B) {
	return FSafeByte(FSB.GetValue()-B);
}

FORCEINLINE FSafeByte operator * (FSafeByte &FSB, const uint8 &B) {
	return FSafeByte(FSB.GetValue()*B);
}

FORCEINLINE FSafeByte operator / (FSafeByte &FSB, const uint8 &B) {
	return FSafeByte(FSB.GetValue()/B);
}

FORCEINLINE FSafeByte operator % (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local%B));
}

FORCEINLINE FSafeByte operator & (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local&B));
}

FORCEINLINE FSafeByte operator | (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local|B));
}

FORCEINLINE FSafeByte operator ^ (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local^B));
}

FORCEINLINE FSafeByte operator >> (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local>>B));
}

FORCEINLINE FSafeByte operator << (FSafeByte &FSB, const uint8 &B) {
	auto Local = FSB.GetValue();
	return FSafeByte((Local<<B));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const uint8 &B, FSafeByte &FSB) {
	return (B==FSB.GetValue());
}

FORCEINLINE bool operator != (const uint8 &B, FSafeByte &FSB) {
	return (B!=FSB.GetValue());
}

FORCEINLINE bool operator > (const uint8 &B, FSafeByte &FSB) {
	return (B>FSB.GetValue());
}

FORCEINLINE bool operator < (const uint8 &B, FSafeByte &FSB) {
	return (B<FSB.GetValue());
}

FORCEINLINE bool operator >= (const uint8 &B, FSafeByte &FSB) {
	return (B>=FSB.GetValue());
}

FORCEINLINE bool operator <= (const uint8 &B, FSafeByte &FSB) {
	return (B<=FSB.GetValue());
}

FORCEINLINE uint8 operator + (uint8 &B, FSafeByte &FSB) {
	return (B+FSB.GetValue());
}

FORCEINLINE uint8 operator - (uint8 &B, FSafeByte &FSB) {
	return (B-FSB.GetValue());
}

FORCEINLINE uint8 operator * (uint8 &B, FSafeByte &FSB) {
	return (B*FSB.GetValue());
}

FORCEINLINE uint8 operator / (uint8 &B, FSafeByte &FSB) {
	return (B/FSB.GetValue());
}

FORCEINLINE uint8 operator % (uint8 &B, FSafeByte &FSB) {
	auto Mod = FSB.GetValue();
	return ((B%Mod));
}

FORCEINLINE uint8 operator & (uint8 &B, FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return ((B&Local));
}

FORCEINLINE uint8 operator | (uint8 &B, FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return ((B|Local));
}

FORCEINLINE uint8 operator ^ (uint8 &B, FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return ((B^Local));
}

FORCEINLINE uint8 operator >> (uint8 &B, FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return ((B>>Local));
}

FORCEINLINE uint8 operator << (uint8 &B, FSafeByte &FSB) {
	auto Local = FSB.GetValue();
	return ((B<<Local));
}

// FSInt

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue() == I.GetValue());
}

FORCEINLINE bool operator != (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue()!=I.GetValue());
}

FORCEINLINE bool operator > (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue()>I.GetValue());
}

FORCEINLINE bool operator < (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue()<I.GetValue());
}

FORCEINLINE bool operator >= (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue()>=I.GetValue());
}

FORCEINLINE bool operator <= (FSafeInt &FSI, FSafeInt &I) {
	return (FSI.GetValue()<=I.GetValue());
}

FORCEINLINE FSafeInt operator + (FSafeInt &FSI, FSafeInt &I) {
	return FSafeInt(FSI.GetValue()+I.GetValue());
}

FORCEINLINE FSafeInt operator - (FSafeInt &FSI, FSafeInt &I) {
	return FSafeInt(FSI.GetValue()-I.GetValue());
}

FORCEINLINE FSafeInt operator * (FSafeInt &FSI, FSafeInt &I) {
	return FSafeInt(FSI.GetValue()*I.GetValue());
}

FORCEINLINE FSafeInt operator / (FSafeInt &FSI, FSafeInt &I) {
	return FSafeInt(FSI.GetValue()/I.GetValue());
}

FORCEINLINE FSafeInt operator ~ (FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return FSafeInt(~Local);
}

FORCEINLINE FSafeInt operator % (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto Mod = I.GetValue();
	return FSafeInt((Local%Mod));
}

FORCEINLINE FSafeInt operator & (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto An = I.GetValue();
	return FSafeInt((Local&An));
}

FORCEINLINE FSafeInt operator | (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto Orr = I.GetValue();
	return FSafeInt((Local|Orr));
}

FORCEINLINE FSafeInt operator ^ (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto To = I.GetValue();
	return FSafeInt((Local^To));
}

FORCEINLINE FSafeInt operator >> (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto To = I.GetValue();
	return FSafeInt((Local>>To));
}

FORCEINLINE FSafeInt operator << (FSafeInt &FSI, FSafeInt &I) {
	auto Local = FSI.GetValue(); auto To = I.GetValue();
	return FSafeInt((Local<<To));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()==I);
}

FORCEINLINE bool operator != (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()!=I);
}

FORCEINLINE bool operator > (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()>I);
}

FORCEINLINE bool operator < (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()<I);
}

FORCEINLINE bool operator >= (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()>=I);
}

FORCEINLINE bool operator <= (FSafeInt &FSI, const int32 &I) {
	return (FSI.GetValue()<=I);
}

FORCEINLINE FSafeInt operator + (FSafeInt &FSI, const int32 &I) {
	return FSafeInt(FSI.GetValue()+I);
}

FORCEINLINE FSafeInt operator - (FSafeInt &FSI, const int32 &I) {
	return FSafeInt(FSI.GetValue()-I);
}

FORCEINLINE FSafeInt operator * (FSafeInt &FSI, const int32 &I) {
	return FSafeInt(FSI.GetValue()*I);
}

FORCEINLINE FSafeInt operator / (FSafeInt &FSI, const int32 &I) {
	return FSafeInt(FSI.GetValue()/I);
}

FORCEINLINE FSafeInt operator % (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local%I));
}

FORCEINLINE FSafeInt operator & (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local&I));
}

FORCEINLINE FSafeInt operator | (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local|I));
}

FORCEINLINE FSafeInt operator ^ (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local^I));
}

FORCEINLINE FSafeInt operator >> (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local>>I));
}

FORCEINLINE FSafeInt operator << (FSafeInt &FSI, const int32 &I) {
	auto Local = FSI.GetValue();
	return FSafeInt((Local<<I));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const int32 &I, FSafeInt &FSI) {
	return (I==FSI.GetValue());
}

FORCEINLINE bool operator != (const int32 &I, FSafeInt &FSI) {
	return (I!=FSI.GetValue());
}

FORCEINLINE bool operator > (const int32 &I, FSafeInt &FSI) {
	return (I>FSI.GetValue());
}

FORCEINLINE bool operator < (const int32 &I, FSafeInt &FSI) {
	return (I<FSI.GetValue());
}

FORCEINLINE bool operator >= (const int32 &I, FSafeInt &FSI) {
	return (I>=FSI.GetValue());
}

FORCEINLINE bool operator <= (const int32 &I, FSafeInt &FSI) {
	return (I<=FSI.GetValue());
}

FORCEINLINE int32 operator + (int32 &I, FSafeInt &FSI) {
	return (I+FSI.GetValue());
}

FORCEINLINE int32 operator - (int32 &I, FSafeInt &FSI) {
	return (I-FSI.GetValue());
}

FORCEINLINE int32 operator * (int32 &I, FSafeInt &FSI) {
	return (I*FSI.GetValue());
}

FORCEINLINE int32 operator / (int32 &I, FSafeInt &FSI) {
	return (I/FSI.GetValue());
}

FORCEINLINE int32 operator % (int32 &I, FSafeInt &FSI) {
	auto Mod = FSI.GetValue();
	return ((I%Mod));
}

FORCEINLINE int32 operator & (int32 &I, FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return ((I&Local));
}

FORCEINLINE int32 operator | (int32 &I, FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return ((I|Local));
}

FORCEINLINE int32 operator ^ (int32 &I, FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return ((I^Local));
}

FORCEINLINE int32 operator >> (int32 &I, FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return ((I>>Local));
}

FORCEINLINE int32 operator << (int32 &I, FSafeInt &FSI) {
	auto Local = FSI.GetValue();
	return ((I<<Local));
}

// FSFloat

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()==F.GetValue());
}

FORCEINLINE bool operator != (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()!=F.GetValue());
}

FORCEINLINE bool operator > (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()>F.GetValue());
}

FORCEINLINE bool operator < (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()<F.GetValue());
}

FORCEINLINE bool operator >= (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()>=F.GetValue());
}

FORCEINLINE bool operator <= (FSafeFloat &FSF, FSafeFloat &F) {
	return (FSF.GetValue()<=F.GetValue());
}

FORCEINLINE FSafeFloat operator + (FSafeFloat &FSF, FSafeFloat &F) {
	return FSafeFloat(FSF.GetValue()+F.GetValue());
}

FORCEINLINE FSafeFloat operator - (FSafeFloat &FSF, FSafeFloat &F) {
	return FSafeFloat(FSF.GetValue()-F.GetValue());
}

FORCEINLINE FSafeFloat operator * (FSafeFloat &FSF, FSafeFloat &F) {
	return FSafeFloat(FSF.GetValue()*F.GetValue());
}

FORCEINLINE FSafeFloat operator / (FSafeFloat &FSF, FSafeFloat &F) {
	return FSafeFloat(FSF.GetValue()/F.GetValue());
}

FORCEINLINE FSafeFloat operator % (FSafeFloat &FSF, FSafeFloat &F) {
	auto Local = FSF.GetValue(); auto Mod = F.GetValue();
	return FSafeFloat(FGenericPlatformMath::Fmod(Local,Mod));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()==F);
}

FORCEINLINE bool operator != (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()!=F);
}

FORCEINLINE bool operator > (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()>F);
}

FORCEINLINE bool operator < (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()<F);
}

FORCEINLINE bool operator >= (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()>=F);
}

FORCEINLINE bool operator <= (FSafeFloat &FSF, const float &F) {
	return (FSF.GetValue()<=F);
}

FORCEINLINE FSafeFloat operator + (FSafeFloat &FSF, const float &F) {
	return FSafeFloat(FSF.GetValue()+F);
}

FORCEINLINE FSafeFloat operator - (FSafeFloat &FSF, const float &F) {
	return FSafeFloat(FSF.GetValue()-F);
}

FORCEINLINE FSafeFloat operator * (FSafeFloat &FSF, const float &F) {
	return FSafeFloat(FSF.GetValue()*F);
}

FORCEINLINE FSafeFloat operator / (FSafeFloat &FSF, const float &F) {
	return FSafeFloat(FSF.GetValue()/F);
}

FORCEINLINE FSafeFloat operator % (FSafeFloat &FSF, const float &F) {
	auto Local = FSF.GetValue();
	return FSafeFloat(FGenericPlatformMath::Fmod(Local,F));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const float &F, FSafeFloat &FSF) {
	return (F==FSF.GetValue());
}

FORCEINLINE bool operator != (const float &F, FSafeFloat &FSF) {
	return (F!=FSF.GetValue());
}

FORCEINLINE bool operator > (const float &F, FSafeFloat &FSF) {
	return (F>FSF.GetValue());
}

FORCEINLINE bool operator < (const float &F, FSafeFloat &FSF) {
	return (F<FSF.GetValue());
}

FORCEINLINE bool operator >= (const float &F, FSafeFloat &FSF) {
	return (F>=FSF.GetValue());
}

FORCEINLINE bool operator <= (const float &F, FSafeFloat &FSF) {
	return (F<=FSF.GetValue());
}

FORCEINLINE float operator + (float &F, FSafeFloat &FSF) {
	return (F+FSF.GetValue());
}

FORCEINLINE float operator - (float &F, FSafeFloat &FSF) {
	return (F-FSF.GetValue());
}

FORCEINLINE float operator * (float &F, FSafeFloat &FSF) {
	return (F*FSF.GetValue());
}

FORCEINLINE float operator / (float &F, FSafeFloat &FSF) {
	return (F/FSF.GetValue());
}

FORCEINLINE float operator % (float &F, FSafeFloat &FSF) {
	auto Mod = FSF.GetValue();
	return (FGenericPlatformMath::Fmod(F,Mod));
}

// FSName

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeName &FSN, FSafeName &N) {
	return (FSN.GetValue().IsEqual(N.GetValue(),ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator != (FSafeName &FSN, FSafeName &N) {
	return (!FSN.GetValue().IsEqual(N.GetValue(),ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator > (FSafeName &FSN, FSafeName &N) {
	return (N.GetValue().FastLess(FSN.GetValue()));
}

FORCEINLINE bool operator < (FSafeName &FSN, FSafeName &N) {
	return (FSN.GetValue().FastLess(N.GetValue()));
}

FORCEINLINE FSafeName operator + (FSafeName &FSN, FSafeName &N) {
	return FSafeName(*(FSN.GetValue().ToString().Append(N.GetValue().ToString())));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeName &FSN, FName &N) {
	return (FSN.GetValue().IsEqual(N,ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator != (FSafeName &FSN, FName &N) {
	return (!FSN.GetValue().IsEqual(N,ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator > (FSafeName &FSN, FName &N) {
	return N.FastLess(FSN.GetValue());
}

FORCEINLINE bool operator < (FSafeName &FSN, FName &N) {
	return FSN.GetValue().FastLess(N);
}

FORCEINLINE FSafeName operator + (FSafeName &FSN, FName &N) {
	return FSafeName(*(FSN.GetValue().ToString().Append(N.ToString())));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (FName &N, FSafeName &FSN) {
	return (N.IsEqual(FSN.GetValue(),ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator != (FName &N, FSafeName &FSN) {
	return (!N.IsEqual(FSN.GetValue(),ENameCase::CaseSensitive,true));
}

FORCEINLINE bool operator > (FName &N, FSafeName &FSN) {
	return FSN.GetValue().FastLess(N);
}

FORCEINLINE bool operator < (FName &N, FSafeName &FSN) {
	return N.FastLess(FSN.GetValue());
}

FORCEINLINE FName operator + (FName &N, FSafeName &FSN) {
	return FName(*(N.ToString().Append(FSN.GetValue().ToString())));
}

// FSText

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeText &FST, FSafeText &T) {
	return (FST.GetValue().EqualTo(T.GetValue()));
}

FORCEINLINE bool operator != (FSafeText &FST, FSafeText &T) {
	return (!FST.GetValue().EqualTo(T.GetValue()));
}

FORCEINLINE bool operator > (FSafeText &FST, FSafeText &T) {
	return (FST.GetValue().ToString()>T.GetValue().ToString());
}

FORCEINLINE bool operator < (FSafeText &FST, FSafeText &T) {
	return (FST.GetValue().ToString()<T.GetValue().ToString());
}

FORCEINLINE FSafeText operator + (FSafeText &FST, FSafeText &T) {
	return FSafeText(FText::Format(FST.GetValue(),T.GetValue()));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeText &FST, FText &T) {
	return (FST.GetValue().EqualTo(T));
}

FORCEINLINE bool operator != (FSafeText &FST, FText &T) {
	return (!FST.GetValue().EqualTo(T));
}

FORCEINLINE bool operator > (FSafeText &FST, FText &T) {
	return (FST.GetValue().ToString()>T.ToString());
}

FORCEINLINE bool operator < (FSafeText &FST, FText &T) {
	return (FST.GetValue().ToString()<T.ToString());
}

FORCEINLINE FSafeText operator + (FSafeText &FST, FText &T) {
	return FSafeText(FText::Format(FST.GetValue(),T));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (FText &T, FSafeText &FST) {
	return (T.EqualTo(FST.GetValue()));
}

FORCEINLINE bool operator != (FText &T, FSafeText &FST) {
	return (!T.EqualTo(FST.GetValue()));
}

FORCEINLINE bool operator > (FText &T, FSafeText &FST) {
	return (T.ToString()>FST.GetValue().ToString());
}

FORCEINLINE bool operator < (FText &T, FSafeText &FST) {
	return (T.ToString()<FST.GetValue().ToString());
}

FORCEINLINE FText operator + (FText &T, FSafeText &FST) {
	return FText::Format(T,FST.GetValue());
}

// FSString

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeString &FSS, FSafeString &S) {
	return (FSS.GetValue().Equals(S.GetValue(),ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator != (FSafeString &FSS, FSafeString &S) {
	return (!FSS.GetValue().Equals(S.GetValue(),ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator > (FSafeString &FSS, FSafeString &S) {
	return (FSS.GetValue()>S.GetValue());
}

FORCEINLINE bool operator < (FSafeString &FSS, FSafeString &S) {
	return (FSS.GetValue()<S.GetValue());
}

FORCEINLINE FSafeString operator + (FSafeString &FSS, FSafeString &S) {
	return FSafeString(*(FSS.GetValue().Append(S.GetValue()))); return *&FSS;
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeString &FSS, FString &S) {
	return (FSS.GetValue().Equals(S,ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator != (FSafeString &FSS, FString &S) {
	return (!FSS.GetValue().Equals(S,ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator > (FSafeString &FSS, FString &S) {
	return (FSS.GetValue()>S);
}

FORCEINLINE bool operator < (FSafeString &FSS, FString &S) {
	return (FSS.GetValue()<S);
}

FORCEINLINE FSafeString operator + (FSafeString &FSS, FString &S) {
	return FSafeString(*(FSS.GetValue().Append(S)));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (FString &S, FSafeString &FSS) {
	return (S.Equals(FSS.GetValue(),ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator != (FString &S, FSafeString &FSS) {
	return (!S.Equals(FSS.GetValue(),ESearchCase::CaseSensitive));
}

FORCEINLINE bool operator > (FString &S, FSafeString &FSS) {
	return (S>FSS.GetValue());
}

FORCEINLINE bool operator < (FString &S, FSafeString &FSS) {
	return (S<FSS.GetValue());
}

FORCEINLINE FString operator + (FString &S, FSafeString &FSS) {
	return FString(*(S.Append(FSS.GetValue())));
}

// FSVector2D

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()==V.GetValue());
}

FORCEINLINE bool operator != (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()!=V.GetValue());
}

FORCEINLINE bool operator > (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()>V.GetValue());
}

FORCEINLINE bool operator < (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()<V.GetValue());
}

FORCEINLINE bool operator >= (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()>=V.GetValue());
}

FORCEINLINE bool operator <= (FSafeVector2D &FSV, FSafeVector2D &V) {
	return (FSV.GetValue()<=V.GetValue());
}

FORCEINLINE FSafeVector2D operator + (FSafeVector2D &FSV, FSafeVector2D &V) {
	return FSafeVector2D(FSV.GetValue()+V.GetValue());
}

FORCEINLINE FSafeVector2D operator - (FSafeVector2D &FSV, FSafeVector2D &V) {
	return FSafeVector2D(FSV.GetValue()-V.GetValue());
}

FORCEINLINE FSafeVector2D operator * (FSafeVector2D &FSV, FSafeVector2D &V) {
	return FSafeVector2D(FSV.GetValue()*V.GetValue());
}

FORCEINLINE FSafeVector2D operator / (FSafeVector2D &FSV, FSafeVector2D &V) {
	return FSafeVector2D(FSV.GetValue()/V.GetValue());
}

FORCEINLINE FSafeVector2D operator % (FSafeVector2D &FSV, FSafeVector2D &V) {
	auto Local = FSV.GetValue(); auto Mod = V.GetValue();
	auto X = Local.X; auto Y = Local.Y; auto MX = Mod.X; auto MY = Mod.Y; 
	return FSafeVector2D(FVector2D(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY)));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()==V);
}

FORCEINLINE bool operator != (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()!=V);
}

FORCEINLINE bool operator > (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()>V);
}

FORCEINLINE bool operator < (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()<V);
}

FORCEINLINE bool operator >= (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()>=V);
}

FORCEINLINE bool operator <= (FSafeVector2D &FSV, const FVector2D &V) {
	return (FSV.GetValue()<=V);
}

FORCEINLINE FSafeVector2D operator + (FSafeVector2D &FSV, const FVector2D &V) {
	return FSafeVector2D(FSV.GetValue()+V);
}

FORCEINLINE FSafeVector2D operator - (FSafeVector2D &FSV, const FVector2D &V) {
	return FSafeVector2D(FSV.GetValue()-V);
}

FORCEINLINE FSafeVector2D operator * (FSafeVector2D &FSV, const FVector2D &V) {
	return FSafeVector2D(FSV.GetValue()*V);
}

FORCEINLINE FSafeVector2D operator / (FSafeVector2D &FSV, const FVector2D &V) {
	return FSafeVector2D(FSV.GetValue()/V);
}

FORCEINLINE FSafeVector2D operator % (FSafeVector2D &FSV, const FVector2D &V) {
	auto Local = FSV.GetValue();
	auto X = Local.X; auto Y = Local.Y;
	auto MX = V.X; auto MY = V.Y; 
	return FSafeVector2D(FVector2D(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY)));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FVector2D &V, FSafeVector2D &FSV) {
	return (V==FSV.GetValue());
}

FORCEINLINE bool operator != (const FVector2D &V, FSafeVector2D &FSV) {
	return (V!=FSV.GetValue());
}

FORCEINLINE bool operator > (const FVector2D &V, FSafeVector2D &FSV) {
	return (V>FSV.GetValue());
}

FORCEINLINE bool operator < (const FVector2D &V, FSafeVector2D &FSV) {
	return (V<FSV.GetValue());
}

FORCEINLINE bool operator >= (const FVector2D &V, FSafeVector2D &FSV) {
	return (V>=FSV.GetValue());
}

FORCEINLINE bool operator <= (const FVector2D &V, FSafeVector2D &FSV) {
	return (FSV.GetValue()<=V);
}

FORCEINLINE FVector2D operator + (const FVector2D &V, FSafeVector2D &FSV) {
	return (V+FSV.GetValue());
}

FORCEINLINE FVector2D operator - (const FVector2D &V, FSafeVector2D &FSV) {
	return (V-FSV.GetValue());
}

FORCEINLINE FVector2D operator * (const FVector2D &V, FSafeVector2D &FSV) {
	return (V*FSV.GetValue());
}

FORCEINLINE FVector2D operator / (const FVector2D &V, FSafeVector2D &FSV) {
	return (V/FSV.GetValue());
}

FORCEINLINE FVector2D operator % (const FVector2D &V, FSafeVector2D &FSV) {
	auto Local = FSV.GetValue();
	auto X = V.X; auto Y = V.Y; 
	auto MX = Local.X; auto MY = Local.Y;
	return FVector2D(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY));
}

// FSVector3D

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeVector3D &FSV, FSafeVector3D &V) {
	return (FSV.GetValue()==V.GetValue());
}

FORCEINLINE bool operator != (FSafeVector3D &FSV, FSafeVector3D &V) {
	return (FSV.GetValue()!=V.GetValue());
}

FORCEINLINE bool operator > (FSafeVector3D &FSV, FSafeVector3D &V) {
	return ((FSV.GetValue().X>V.GetValue().X)&&(FSV.GetValue().Y>V.GetValue().Y)&&(FSV.GetValue().Z>V.GetValue().Z));
}

FORCEINLINE bool operator < (FSafeVector3D &FSV, FSafeVector3D &V) {
	return ((FSV.GetValue().X<V.GetValue().X)&&(FSV.GetValue().Y<V.GetValue().Y)&&(FSV.GetValue().Z<V.GetValue().Z));
}

FORCEINLINE bool operator >= (FSafeVector3D &FSV, FSafeVector3D &V) {
	return ((FSV.GetValue().X>=V.GetValue().X)&&(FSV.GetValue().Y>=V.GetValue().Y)&&(FSV.GetValue().Z>=V.GetValue().Z));
}

FORCEINLINE bool operator <= (FSafeVector3D &FSV, FSafeVector3D &V) {
	return ((FSV.GetValue().X<=V.GetValue().X)&&(FSV.GetValue().Y<=V.GetValue().Y)&&(FSV.GetValue().Z<=V.GetValue().Z));
}

FORCEINLINE FSafeVector3D operator + (FSafeVector3D &FSV, FSafeVector3D &V) {
	return FSafeVector3D(FSV.GetValue()+V.GetValue());
}

FORCEINLINE FSafeVector3D operator - (FSafeVector3D &FSV, FSafeVector3D &V) {
	return FSafeVector3D(FSV.GetValue()-V.GetValue());
}

FORCEINLINE FSafeVector3D operator * (FSafeVector3D &FSV, FSafeVector3D &V) {
	return FSafeVector3D(FSV.GetValue()*V.GetValue());
}

FORCEINLINE FSafeVector3D operator / (FSafeVector3D &FSV, FSafeVector3D &V) {
	return FSafeVector3D(FSV.GetValue()/V.GetValue());
}

FORCEINLINE FSafeVector3D operator % (FSafeVector3D &FSV, FSafeVector3D &V) {
	auto Local = FSV.GetValue(); auto Mod = V.GetValue();
	auto X = Local.X; auto Y = Local.Y; auto Z = Local.Z;
	auto MX = Mod.X; auto MY = Mod.Y;  auto MZ = Mod.Z;
	return FSafeVector3D(FVector(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ)));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeVector3D &FSV, const FVector &V) {
	return (FSV.GetValue()==V);
}

FORCEINLINE bool operator != (FSafeVector3D &FSV, const FVector &V) {
	return (FSV.GetValue()!=V);
}

FORCEINLINE bool operator > (FSafeVector3D &FSV, const FVector &V) {
	return ((FSV.GetValue().X>V.X)&&(FSV.GetValue().Y>V.Y)&&(FSV.GetValue().Z>V.Z));
}

FORCEINLINE bool operator < (FSafeVector3D &FSV, const FVector &V) {
	return ((FSV.GetValue().X<V.X)&&(FSV.GetValue().Y<V.Y)&&(FSV.GetValue().Z<V.Z));
}

FORCEINLINE bool operator >= (FSafeVector3D &FSV, const FVector &V) {
	return ((FSV.GetValue().X>=V.X)&&(FSV.GetValue().Y>=V.Y)&&(FSV.GetValue().Z>=V.Z));
}

FORCEINLINE bool operator <= (FSafeVector3D &FSV, const FVector &V) {
	return ((FSV.GetValue().X<=V.X)&&(FSV.GetValue().Y<=V.Y)&&(FSV.GetValue().Z<=V.Z));
}

FORCEINLINE FSafeVector3D operator + (FSafeVector3D &FSV, const FVector &V) {
	return FSafeVector3D(FSV.GetValue()+V);
}

FORCEINLINE FSafeVector3D operator - (FSafeVector3D &FSV, const FVector &V) {
	return FSafeVector3D(FSV.GetValue()-V);
}

FORCEINLINE FSafeVector3D operator * (FSafeVector3D &FSV, const FVector &V) {
	return FSafeVector3D(FSV.GetValue()*V);
}

FORCEINLINE FSafeVector3D operator / (FSafeVector3D &FSV, const FVector &V) {
	return FSafeVector3D(FSV.GetValue()/V);
}

FORCEINLINE FSafeVector3D operator % (FSafeVector3D &FSV, const FVector &V) {
	auto Local = FSV.GetValue();
	auto X = Local.X; auto Y = Local.Y; auto Z = Local.Z;
	auto MX = V.X; auto MY = V.Y; auto MZ = V.Z;
	return FSafeVector3D(FVector(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ)));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FVector &V, FSafeVector3D &FSV) {
	return (V==FSV.GetValue());
}

FORCEINLINE bool operator != (const FVector &V, FSafeVector3D &FSV) {
	return (V!=FSV.GetValue());
}

FORCEINLINE bool operator > (const FVector &V, FSafeVector3D &FSV) {
	return ((V.X>FSV.GetValue().X)&&(V.Y>FSV.GetValue().Y)&&(V.Z>FSV.GetValue().Z));
}

FORCEINLINE bool operator < (const FVector &V, FSafeVector3D &FSV) {
	return ((V.X<FSV.GetValue().X)&&(V.Y<FSV.GetValue().Y)&&(V.Z<FSV.GetValue().Z));
}

FORCEINLINE bool operator >= (const FVector &V, FSafeVector3D &FSV) {
	return ((V.X>=FSV.GetValue().X)&&(V.Y>=FSV.GetValue().Y)&&(V.Z>=FSV.GetValue().Z));
}

FORCEINLINE bool operator <= (const FVector &V, FSafeVector3D &FSV) {
	return ((V.X<=FSV.GetValue().X)&&(V.Y<=FSV.GetValue().Y)&&(V.Z<=FSV.GetValue().Z));
}

FORCEINLINE FVector operator + (const FVector &V, FSafeVector3D &FSV) {
	return (V+FSV.GetValue());
}

FORCEINLINE FVector operator - (const FVector &V, FSafeVector3D &FSV) {
	return (V-FSV.GetValue());
}

FORCEINLINE FVector operator * (const FVector &V, FSafeVector3D &FSV) {
	return (V*FSV.GetValue());
}

FORCEINLINE FVector operator / (const FVector &V, FSafeVector3D &FSV) {
	return (V/FSV.GetValue());
}

FORCEINLINE FVector operator % (const FVector &V, FSafeVector3D &FSV) {
	auto Local = FSV.GetValue();
	auto X = V.X; auto Y = V.Y; auto Z = V.Z;
	auto MX = Local.X; auto MY = Local.Y; auto MZ = Local.Z;
	return FVector(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ));
}

// FSVector4D

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeVector4D &FSV, FSafeVector4D &V) {
	return (FSV.GetValue()==V.GetValue());
}

FORCEINLINE bool operator != (FSafeVector4D &FSV, FSafeVector4D &V) {
	return (FSV.GetValue()!=V.GetValue());
}

FORCEINLINE bool operator > (FSafeVector4D &FSV, FSafeVector4D &V) {
	return ((FSV.GetValue().X>V.GetValue().X)&&(FSV.GetValue().Y>V.GetValue().Y)&&(FSV.GetValue().Z>V.GetValue().Z)&&(FSV.GetValue().W>V.GetValue().W));
}

FORCEINLINE bool operator < (FSafeVector4D &FSV, FSafeVector4D &V) {
	return ((FSV.GetValue().X<V.GetValue().X)&&(FSV.GetValue().Y<V.GetValue().Y)&&(FSV.GetValue().Z<V.GetValue().Z)&&(FSV.GetValue().W<V.GetValue().W));
}

FORCEINLINE bool operator >= (FSafeVector4D &FSV, FSafeVector4D &V) {
	return ((FSV.GetValue().X>=V.GetValue().X)&&(FSV.GetValue().Y>=V.GetValue().Y)&&(FSV.GetValue().Z>=V.GetValue().Z)&&(FSV.GetValue().W>=V.GetValue().W));
}

FORCEINLINE bool operator <= (FSafeVector4D &FSV, FSafeVector4D &V) {
	return ((FSV.GetValue().X<=V.GetValue().X)&&(FSV.GetValue().Y<=V.GetValue().Y)&&(FSV.GetValue().Z<=V.GetValue().Z)&&(FSV.GetValue().W<=V.GetValue().W));
}

FORCEINLINE FSafeVector4D operator + (FSafeVector4D &FSV, FSafeVector4D &V) {
	auto Local = (FSV.GetValue()+V.GetValue());
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator - (FSafeVector4D &FSV, FSafeVector4D &V) {
	auto Local = (FSV.GetValue()-V.GetValue());
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator * (FSafeVector4D &FSV, FSafeVector4D &V) {
	auto Local = (FSV.GetValue()*V.GetValue());
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator / (FSafeVector4D &FSV, FSafeVector4D &V) {
	auto Local = (FSV.GetValue()/V.GetValue());
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator % (FSafeVector4D &FSV, FSafeVector4D &V) {
	auto Local = FSV.GetValue(); auto Mod = V.GetValue();
	auto X = Local.X; auto Y = Local.Y; auto Z = Local.Z; auto W = Local.W;
	auto MX = Mod.X; auto MY = Mod.Y;  auto MZ = Mod.Z; auto MW = Mod.W;
	auto F4D = FVector4(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ),FGenericPlatformMath::Fmod(W,MW));
	return FSafeVector4D(F4D.X,F4D.Y,F4D.Z,F4D.W);
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeVector4D &FSV, const FVector4 &V) {
	return (FSV.GetValue()==V);
}

FORCEINLINE bool operator != (FSafeVector4D &FSV, const FVector4 &V) {
	return (FSV.GetValue()!=V);
}

FORCEINLINE bool operator > (FSafeVector4D &FSV, const FVector4 &V) {
	return ((FSV.GetValue().X>V.X)&&(FSV.GetValue().Y>V.Y)&&(FSV.GetValue().Z>V.Z)&&(FSV.GetValue().W>V.W));
}

FORCEINLINE bool operator < (FSafeVector4D &FSV, const FVector4 &V) {
	return ((FSV.GetValue().X<V.X)&&(FSV.GetValue().Y<V.Y)&&(FSV.GetValue().Z<V.Z)&&(FSV.GetValue().W>V.W));
}

FORCEINLINE bool operator >= (FSafeVector4D &FSV, const FVector4 &V) {
	return ((FSV.GetValue().X>=V.X)&&(FSV.GetValue().Y>=V.Y)&&(FSV.GetValue().Z>=V.Z));
}

FORCEINLINE bool operator <= (FSafeVector4D &FSV, const FVector4 &V) {
	return ((FSV.GetValue().X<=V.X)&&(FSV.GetValue().Y<=V.Y)&&(FSV.GetValue().Z<=V.Z));
}

FORCEINLINE FSafeVector4D operator + (FSafeVector4D &FSV, const FVector4 &V) {
	auto Local = (FSV.GetValue()+V);
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator - (FSafeVector4D &FSV, const FVector4 &V) {
	auto Local = (FSV.GetValue()-V);
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator * (FSafeVector4D &FSV, const FVector4 &V) {
	auto Local = (FSV.GetValue()*V);
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator / (FSafeVector4D &FSV, const FVector4 &V) {
	auto Local = (FSV.GetValue()/V);
	return FSafeVector4D(Local.X,Local.Y,Local.Z,Local.W);
}

FORCEINLINE FSafeVector4D operator % (FSafeVector4D &FSV, const FVector4 &V) {
	auto Local = FSV.GetValue();
	auto MX = V.X; auto MY = V.Y;  auto MZ = V.Z; auto MW = V.W;
	auto X = Local.X; auto Y = Local.Y; auto Z = Local.Z; auto W = Local.W;
	auto F4D = FVector4(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ),FGenericPlatformMath::Fmod(W,MW));
	return FSafeVector4D(F4D.X,F4D.Y,F4D.Z,F4D.W);
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FVector4 &V, FSafeVector4D &FSV) {
	return (V==FSV.GetValue());
}

FORCEINLINE bool operator != (const FVector4 &V, FSafeVector4D &FSV) {
	return (V!=FSV.GetValue());
}

FORCEINLINE bool operator > (const FVector4 &V, FSafeVector4D &FSV) {
	return ((V.X>FSV.GetValue().X)&&(V.Y>FSV.GetValue().Y)&&(V.Z>FSV.GetValue().Z)&&(V.W>FSV.GetValue().W));
}

FORCEINLINE bool operator < (const FVector4 &V, FSafeVector4D &FSV) {
	return ((V.X<FSV.GetValue().X)&&(V.Y<FSV.GetValue().Y)&&(V.Z<FSV.GetValue().Z)&&(V.W<FSV.GetValue().W));
}

FORCEINLINE bool operator >= (const FVector4 &V, FSafeVector4D &FSV) {
	return ((V.X>=FSV.GetValue().X)&&(V.Y>=FSV.GetValue().Y)&&(V.Z>=FSV.GetValue().Z)&&(V.W>=FSV.GetValue().W));
}

FORCEINLINE bool operator <= (const FVector4 &V, FSafeVector4D &FSV) {
	return ((V.X<=FSV.GetValue().X)&&(V.Y<=FSV.GetValue().Y)&&(V.Z<=FSV.GetValue().Z)&&(V.W<=FSV.GetValue().W));
}

FORCEINLINE FVector4 operator + (const FVector4 &V, FSafeVector4D &FSV) {
	return (V+FSV.GetValue());
}

FORCEINLINE FVector4 operator - (const FVector4 &V, FSafeVector4D &FSV) {
	return (V-FSV.GetValue());
}

FORCEINLINE FVector4 operator * (const FVector4 &V, FSafeVector4D &FSV) {
	return (V*FSV.GetValue());
}

FORCEINLINE FVector4 operator / (const FVector4 &V, FSafeVector4D &FSV) {
	return (V/FSV.GetValue());
}

FORCEINLINE FVector4 operator % (const FVector4 &V, FSafeVector4D &FSV) {
	auto Local = FSV.GetValue();
	auto X = V.X; auto Y = V.Y; auto Z = V.Z; auto W = V.W;
	auto MX = Local.X; auto MY = Local.Y; auto MZ = Local.Z; auto MW = Local.W;
	return FVector4(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ),FGenericPlatformMath::Fmod(W,MW));
}

// FSColor

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeColor &FSC, FSafeColor &C) {
	return (FSC.GetValue()==C.GetValue());
}

FORCEINLINE bool operator != (FSafeColor &FSC, FSafeColor &C) {
	return (FSC.GetValue()!=C.GetValue());
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeColor &FSC, const FLinearColor &C) {
	return (FSC.GetValue()==C);
}

FORCEINLINE bool operator != (FSafeColor &FSC, const FLinearColor &C) {
	return (FSC.GetValue()!=C);
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FLinearColor &C, FSafeColor &FSC) {
	return (C==FSC.GetValue());
}

FORCEINLINE bool operator != (const FLinearColor &C, FSafeColor &FSC) {
	return (C!=FSC.GetValue());
}

// FSRotator

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeRotator &FSR, FSafeRotator &R) {
	return (FSR.GetValue()==R.GetValue());
}

FORCEINLINE bool operator != (FSafeRotator &FSR, FSafeRotator &R) {
	return (FSR.GetValue()!=R.GetValue());
}

FORCEINLINE bool operator > (FSafeRotator &FSR, FSafeRotator &R) {
	return ((FSR.GetValue().Pitch>R.GetValue().Pitch)&&(FSR.GetValue().Yaw>R.GetValue().Yaw)&&(FSR.GetValue().Roll>R.GetValue().Roll));
}

FORCEINLINE bool operator < (FSafeRotator &FSR, FSafeRotator &R) {
	return ((FSR.GetValue().Pitch<R.GetValue().Pitch)&&(FSR.GetValue().Yaw<R.GetValue().Yaw)&&(FSR.GetValue().Roll<R.GetValue().Roll));
}

FORCEINLINE bool operator >= (FSafeRotator &FSR, FSafeRotator &R) {
	return ((FSR.GetValue().Pitch>=R.GetValue().Pitch)&&(FSR.GetValue().Yaw>=R.GetValue().Yaw)&&(FSR.GetValue().Roll>=R.GetValue().Roll));
}

FORCEINLINE bool operator <= (FSafeRotator &FSR, FSafeRotator &R) {
	return ((FSR.GetValue().Pitch<=R.GetValue().Pitch)&&(FSR.GetValue().Yaw<=R.GetValue().Yaw)&&(FSR.GetValue().Roll<=R.GetValue().Roll));
}

FORCEINLINE FSafeRotator operator + (FSafeRotator &FSR, FSafeRotator &R) {
	return FSafeRotator(FSR.GetValue()+R.GetValue());
}

FORCEINLINE FSafeRotator operator - (FSafeRotator &FSR, FSafeRotator &R) {
	return FSafeRotator(FSR.GetValue()-R.GetValue());
}

FORCEINLINE FSafeRotator operator * (FSafeRotator &FSR, FSafeRotator &R) {
	auto A = FSR.GetValue(); auto B = R.GetValue();
	auto Rotator = FRotator(A.Pitch*B.Pitch,A.Yaw*B.Yaw,A.Roll*B.Roll);
	return FSafeRotator(Rotator);
}

FORCEINLINE FSafeRotator operator / (FSafeRotator &FSR, FSafeRotator &R) {
	auto A = FSR.GetValue(); auto B = R.GetValue();
	auto Rotator = FRotator(A.Pitch/B.Pitch,A.Yaw/B.Yaw,A.Roll/B.Roll);
	return FSafeRotator(Rotator);
}

FORCEINLINE FSafeRotator operator % (FSafeRotator &FSR, FSafeRotator &R) {
	auto Local = FSR.GetValue(); auto Mod = R.GetValue();
	auto X = Local.Pitch; auto Y = Local.Yaw; auto Z = Local.Roll;
	auto MX = Mod.Pitch; auto MY = Mod.Yaw;  auto MZ = Mod.Roll;
	return FSafeRotator(FRotator(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ)));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeRotator &FSR, const FRotator &R) {
	return (FSR.GetValue()==R);
}

FORCEINLINE bool operator != (FSafeRotator &FSR, const FRotator &R) {
	return (FSR.GetValue()!=R);
}

FORCEINLINE bool operator > (FSafeRotator &FSR, const FRotator &R) {
	return ((FSR.GetValue().Pitch>R.Pitch)&&(FSR.GetValue().Yaw>R.Yaw)&&(FSR.GetValue().Roll>R.Roll));
}

FORCEINLINE bool operator < (FSafeRotator &FSR, const FRotator &R) {
	return ((FSR.GetValue().Pitch<R.Pitch)&&(FSR.GetValue().Yaw<R.Yaw)&&(FSR.GetValue().Roll<R.Roll));
}

FORCEINLINE bool operator >= (FSafeRotator &FSR, const FRotator &R) {
	return ((FSR.GetValue().Pitch>=R.Pitch)&&(FSR.GetValue().Yaw>=R.Yaw)&&(FSR.GetValue().Roll>=R.Roll));
}

FORCEINLINE bool operator <= (FSafeRotator &FSR, const FRotator &R) {
	return ((FSR.GetValue().Pitch<=R.Pitch)&&(FSR.GetValue().Yaw<=R.Yaw)&&(FSR.GetValue().Roll<=R.Roll));
}

FORCEINLINE FSafeRotator operator + (FSafeRotator &FSR, const FRotator &R) {
	return FSafeRotator(FSR.GetValue()+R);
}

FORCEINLINE FSafeRotator operator - (FSafeRotator &FSR, const FRotator &R) {
	return FSafeRotator(FSR.GetValue()-R);
}

FORCEINLINE FSafeRotator operator * (FSafeRotator &FSR, const FRotator &R) {
	auto Local = FSR.GetValue();
	auto Rotator = FRotator(Local.Pitch*R.Pitch,Local.Yaw*R.Yaw,Local.Roll*R.Roll);
	return FSafeRotator(Rotator);
}

FORCEINLINE FSafeRotator operator / (FSafeRotator &FSR, const FRotator &R) {
	auto Local = FSR.GetValue();
	auto Rotator = FRotator(Local.Pitch/R.Pitch,Local.Yaw/R.Yaw,Local.Roll/R.Roll);
	return FSafeRotator(Rotator);
}

FORCEINLINE FSafeRotator operator % (FSafeRotator &FSR, const FRotator &R) {
	auto Local = FSR.GetValue();
	auto X = Local.Pitch; auto Y = Local.Yaw; auto Z = Local.Roll;
	auto MX = R.Pitch; auto MY = R.Yaw; auto MZ = R.Roll;
	return FSafeRotator(FRotator(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ)));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FRotator &R, FSafeRotator &FSR) {
	return (R==FSR.GetValue());
}

FORCEINLINE bool operator != (const FRotator &R, FSafeRotator &FSR) {
	return (R!=FSR.GetValue());
}

FORCEINLINE bool operator > (const FRotator &R, FSafeRotator &FSR) {
	return ((R.Pitch>FSR.GetValue().Pitch)&&(R.Yaw>FSR.GetValue().Yaw)&&(R.Roll>FSR.GetValue().Roll));
}

FORCEINLINE bool operator < (const FRotator &R, FSafeRotator &FSR) {
	return ((R.Pitch<FSR.GetValue().Pitch)&&(R.Yaw<FSR.GetValue().Yaw)&&(R.Roll<FSR.GetValue().Roll));
}

FORCEINLINE bool operator >= (const FRotator &R, FSafeRotator &FSR) {
	return ((R.Pitch>=FSR.GetValue().Pitch)&&(R.Yaw>=FSR.GetValue().Yaw)&&(R.Roll>=FSR.GetValue().Roll));
}

FORCEINLINE bool operator <= (const FRotator &R, FSafeRotator &FSR) {
	return ((R.Pitch<=FSR.GetValue().Pitch)&&(R.Yaw<=FSR.GetValue().Yaw)&&(R.Roll<=FSR.GetValue().Roll));
}

FORCEINLINE FRotator operator + (const FRotator &R, FSafeRotator &FSR) {
	return (R+FSR.GetValue());
}

FORCEINLINE FRotator operator - (const FRotator &R, FSafeRotator &FSR) {
	return (R-FSR.GetValue());
}

FORCEINLINE FRotator operator * (const FRotator &R, FSafeRotator &FSR) {
	auto Local = FSR.GetValue();
	return FRotator(R.Pitch*Local.Pitch,R.Yaw*Local.Yaw,R.Roll*Local.Roll);
}

FORCEINLINE FRotator operator / (const FRotator &R, FSafeRotator &FSR) {
	auto Local = FSR.GetValue();
	return FRotator(R.Pitch/Local.Pitch,R.Yaw/Local.Yaw,R.Roll/Local.Roll);
}

FORCEINLINE FRotator operator % (const FRotator &R, FSafeRotator &FSR) {
	auto Local = FSR.GetValue();
	auto X = R.Pitch; auto Y = R.Yaw; auto Z = R.Roll;
	auto MX = Local.Pitch; auto MY = Local.Yaw; auto MZ = Local.Roll;
	return FRotator(FGenericPlatformMath::Fmod(X,MX),FGenericPlatformMath::Fmod(Y,MY),FGenericPlatformMath::Fmod(Z,MZ));
}

// FSTransform

/* FSafe -> FSafe */

FORCEINLINE bool operator == (FSafeTransform &FST, FSafeTransform &T) {
	auto Local = FST.GetValue(); auto To = T.GetValue();
	return ((Local.GetLocation()==To.GetLocation())&&(Local.GetRotation()==To.GetRotation())&&(Local.GetScale3D()==To.GetScale3D()));
}

FORCEINLINE bool operator != (FSafeTransform &FST, FSafeTransform &T) {
	auto Local = FST.GetValue(); auto To = T.GetValue();
	return ((Local.GetLocation()!=To.GetLocation())&&(Local.GetRotation()!=To.GetRotation())&&(Local.GetScale3D()!=To.GetScale3D()));
}

/* Native -> FSafe */

FORCEINLINE bool operator == (FSafeTransform &FST, const FTransform &T) {
	auto Local = FST.GetValue();
	return ((Local.GetLocation()==T.GetLocation())&&(Local.GetRotation()==T.GetRotation())&&(Local.GetScale3D()==T.GetScale3D()));
}

FORCEINLINE bool operator != (FSafeTransform &FST, const FTransform &T) {
	auto Local = FST.GetValue();
	return ((Local.GetLocation()!=T.GetLocation())&&(Local.GetRotation()!=T.GetRotation())&&(Local.GetScale3D()!=T.GetScale3D()));
}

/* FSafe -> Native */

FORCEINLINE bool operator == (const FTransform &T, FSafeTransform &FST) {
	auto Local = FST.GetValue();
	return ((T.GetLocation()==Local.GetLocation())&&(T.GetRotation()==Local.GetRotation())&&(T.GetScale3D()==Local.GetScale3D()));
}

FORCEINLINE bool operator != (const FTransform &T, FSafeTransform &FST) {
	auto Local = FST.GetValue();
	return ((T.GetLocation()!=Local.GetLocation())&&(T.GetRotation()!=Local.GetRotation())&&(T.GetScale3D()!=Local.GetScale3D()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS(ClassGroup = Security, Category = "Security", Blueprintable, hideCategories = (Activation), meta = (DisplayName = "{S} Safe Game Instance", ShortTooltip = "{S} Safe Game Instance Class. Check documentation for more information."))
class SCUE5_API USafeGameInstance : public UGameInstance {
	GENERATED_BODY()
};

UCLASS(ClassGroup = Security, Category = "Security", Blueprintable, hideCategories = (Activation))
class SCUE5_API USafeGameInstanceSubsystem : public UGameInstanceSubsystem {
	GENERATED_BODY()
protected:
	FProcHandle GuardProcess;
	const TCHAR* Editor = TEXT("EDITOR");
	const TCHAR* Guardx86 = TEXT("SCUE5x86.exe");
	const TCHAR* Guardx64 = TEXT("SCUE5x64.exe");
	const TCHAR* Game = FApp::GetProjectName();
	//
	FTimerHandle THInvokeGuard;
	FTimerHandle THScanner;
	uint32 GuardPID = 0;
public:
	virtual void Initialize(FSubsystemCollectionBase &Collection) override;
	virtual void Deinitialize() override;
public:
	/* Sets visibility of Game-Guard console window.
	Console is only visible in Editor Mode, on packaged games it's always hidden. */
	UPROPERTY(Category = "Security", EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool HideGameGuard = true;
	//
	/* To increase defenses against memory readers, uncheck this option when you're ready to
	ship final standalone game build. If disabled, option won't allow Debuggers attach to the game process. */
	UPROPERTY(Category = "Security", EditAnywhere, meta = (AllowPrivateAccess = "true"))
	bool AllowDebugging = true;
	//
	/** Interval, in seconds, for Internal Process Scanner to be automatically invoked. */
	UPROPERTY(Category = "Security", EditAnywhere, meta = (AllowPrivateAccess = "true", ClampMin = "10", ClampMax = "1000", UIMin = "10", UIMax = "1000"))
	uint32 ScannerInterval = 30.f;
	//
	/* Sets visibility of Game-Guard console window.
	Console is only visible in Editor Mode, on packaged games it's always hidden. */
	UFUNCTION(Category = "Security", BlueprintCallable, meta = (DisplayName = "{S}:: Hide Game-Guard Console", Keywords = "Security Guard"))
	void HideGameGuardConsole(bool Set);
public:
	void InvokeGuard() {
	#if PLATFORM_WINDOWS
		#if WITH_EDITOR
		//GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::EnginePluginsDir(),TEXT("Marketplace/SCUE5/Source/ThirdParty/x64"),Guardx64),Editor,false,HideGameGuard,HideGameGuard,&GuardPID,0,nullptr,nullptr);
		GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::ProjectPluginsDir(),TEXT("SCUE5/Source/ThirdParty/x64"),Guardx64),Editor,false,HideGameGuard,HideGameGuard,&GuardPID,0,nullptr,nullptr);
		#else
			#if !PLATFORM_64BITS
			//if (!FPaths::FileExists(FPaths::Combine(*FPaths::EnginePluginsDir(),TEXT("Marketplace/SCUE5/Source/ThirdParty/x86/"),Guardx86))) {FGenericPlatformMisc::RequestExit(false);}
			//GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::EnginePluginsDir(),TEXT("Marketplace/SCUE5/Source/ThirdParty/x86/"),Guardx86),Game,false,true,true,&GuardPID,0,nullptr,nullptr);
			if (!FPaths::FileExists(FPaths::Combine(*FPaths::ProjectPluginsDir(),TEXT("SCUE5/Source/ThirdParty/x86/"),Guardx86))) {FGenericPlatformMisc::RequestExit(false);}
			GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::ProjectPluginsDir(),TEXT("SCUE5/Source/ThirdParty/x86/"),Guardx86),Game,false,true,true,&GuardPID,0,nullptr,nullptr);
			#else
			//if (!FPaths::FileExists(FPaths::Combine(*FPaths::EnginePluginsDir(),TEXT("Marketplace/SCUE5/Source/ThirdParty/x64/"),Guardx64))) {FGenericPlatformMisc::RequestExit(false);}
			//GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::EnginePluginsDir(),TEXT("Marketplace/SCUE5/Source/ThirdParty/x64/"),Guardx64),Game,false,true,true,&GuardPID,0,nullptr,nullptr);
			if (!FPaths::FileExists(FPaths::Combine(*FPaths::ProjectPluginsDir(),TEXT("SCUE5/Source/ThirdParty/x64/"),Guardx64))) {FGenericPlatformMisc::RequestExit(false);}
			GuardProcess = FPlatformProcess::CreateProc(*FPaths::Combine(*FPaths::ProjectPluginsDir(),TEXT("SCUE5/Source/ThirdParty/x64/"),Guardx64),Game,false,true,true,&GuardPID,0,nullptr,nullptr);
			#endif
		#endif
	#endif
	}
	//
	void GameGuard() {
	#if PLATFORM_WINDOWS && UE_BUILD_SHIPPING
		if (!GuardProcess.IsValid() || !FPlatformProcess::IsProcRunning(GuardProcess)) {InvokeGuard();}
		if (!AllowDebugging) {if (IsDebuggerPresent() || HasDebugger() || HasThreat()) {FGenericPlatformMisc::RequestExit(false);}}
	#endif
	}
	//
	bool IsDebuggerPresent() {
	#if PLATFORM_WINDOWS && UE_BUILD_SHIPPING
		HINSTANCE Kernel = LoadLibraryEx(TEXT("kernel32.dll"),NULL,0);
		FARPROC IDebuggerPresent = GetProcAddress(Kernel,"IsDebuggerPresent");
		if(IDebuggerPresent && IDebuggerPresent()) {FreeLibrary(Kernel); return true;}
		FreeLibrary(Kernel); return false;
	#else
		return false;
	#endif
	}
	//
	FORCEINLINE bool HasDebugger() {
	#if PLATFORM_WINDOWS
		#if UE_BUILD_SHIPPING && PLATFORM_32BITS
			__try {
				__asm __emit 0xF3
				__asm __emit 0x64
				__asm __emit 0xF1
			} __except(EXCEPTION_EXECUTE_HANDLER) {
				return false;
			} return true;
		#else
			return false;
		#endif
	#else
		return false;
	#endif
	}
	//
	FORCEINLINE bool HasThreat() {
	#if PLATFORM_WINDOWS
		#if !WITH_EDITOR
		if (OpenFileMapping(FILE_MAP_READ|FILE_MAP_WRITE,false,L"CEHYPERSCANSETTINGS")!=0) {return true;}
		auto HND = FindWindowA((LPCSTR)"WinDbgFrameClass",NULL); if (HND) {return true;}
		HND = FindWindowA((LPCSTR)"WinDbgFrameClass",NULL); if (HND) {return true;}
		HND = FindWindowA((LPCSTR)"OLLYDBG",NULL); if (HND) {return true;}
		HND = FindWindowA((LPCSTR)"Window",NULL); if (HND) {return true;}
		return false;
		#endif
		return false;
	#else
		return false;
	#endif
	}
	//
	void ScanProcesses() {
	#if PLATFORM_WINDOWS
		#if UE_BUILD_SHIPPING && !WITH_SERVER_CODE
		FSCUE5_Enumerate();
		#endif
	#endif
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////