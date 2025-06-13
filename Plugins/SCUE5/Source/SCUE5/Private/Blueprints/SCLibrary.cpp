///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2025 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SCLibrary.h"
#include "SCUE5PrivatePCH.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FString USCLibrary::SCL_Callable_GetRawSafeBool(FSafeBool &SB) {
	return SB.GetRaw();
}

bool USCLibrary::SCL_Pure_GetSafeBool(FSafeBool &SB) {
	return SB.GetValue();
}

bool USCLibrary::SCL_Pure_GetSafeBoolWithKey(FSafeBool &SB, FString Key) {
	return SB.GetValue(Key);
}

bool USCLibrary::SCL_Callable_GetSafeBool(FSafeBool &SB) {
	return SB.GetValue();
}

bool USCLibrary::SCL_Callable_GetSafeBoolWithKey(FSafeBool &SB, FString Key) {
	return SB.GetValue(Key);
}

//

bool USCLibrary::SCL_Callable_SetRawSafeBool(FSafeBool &SB, FString Value) {
	SB.SetRaw(&Value); return SB.GetValue();
}

bool USCLibrary::SCL_Pure_SetSafeBool(FSafeBool &SB, const bool Value) {
	SB.SetValue(Value); return SB.GetValue();
}

bool USCLibrary::SCL_Pure_SetSafeBoolWithKey(FSafeBool &SB, FString Key, const bool Value) {
	SB.SetValue(Key,Value); return SB.GetValue();
}

bool USCLibrary::SCL_Callable_SetSafeBool(FSafeBool &SB, const bool Value) {
	SB.SetValue(Value); return SB.GetValue();
}

bool USCLibrary::SCL_Callable_SetSafeBoolWithKey(FSafeBool &SB, FString Key, const bool Value) {
	SB.SetValue(Key,Value); return SB.GetValue();
}

//

FString USCLibrary::SCL_Callable_GetRawSafeInt(FSafeInt &SI) {
	return SI.GetRaw();
}

int32 USCLibrary::SCL_Pure_GetSafeInt(FSafeInt &SI) {
	return SI.GetValue();
}

int32 USCLibrary::SCL_Pure_GetSafeIntWithKey(FSafeInt &SI, FString Key) {
	return SI.GetValue(Key);
}

int32 USCLibrary::SCL_Callable_GetSafeInt(FSafeInt &SI) {
	return SI.GetValue();
}

int32 USCLibrary::SCL_Callable_GetSafeIntWithKey(FSafeInt &SI, FString Key) {
	return SI.GetValue(Key);
}

//

int32 USCLibrary::SCL_Callable_SetRawSafeInt(FSafeInt &SI, FString Value) {
	SI.SetRaw(&Value); return SI.GetValue();
}

int32 USCLibrary::SCL_Pure_SetSafeInt(FSafeInt &SI, const int32 Value) {
	SI.SetValue(Value); return SI.GetValue();
}

int32 USCLibrary::SCL_Pure_SetSafeIntWithKey(FSafeInt &SI, FString Key, const int32 Value) {
	SI.SetValue(Key,Value); return SI.GetValue(Key);
}

int32 USCLibrary::SCL_Callable_SetSafeInt(FSafeInt &SI, const int32 Value) {
	SI.SetValue(Value); return SI.GetValue();
}

int32 USCLibrary::SCL_Callable_SetSafeIntWithKey(FSafeInt &SI, FString Key, const int32 Value) {
	SI.SetValue(Key,Value); return SI.GetValue(Key);
}

//

FString USCLibrary::SCL_Callable_GetRawSafeByte(FSafeByte &SB) {
	return SB.GetRaw();
}

uint8 USCLibrary::SCL_Pure_GetSafeByte(FSafeByte &SB) {
	return SB.GetValue();
}

uint8 USCLibrary::SCL_Pure_GetSafeByteWithKey(FSafeByte &SB, FString Key) {
	return SB.GetValue(Key);
}

uint8 USCLibrary::SCL_Callable_GetSafeByte(FSafeByte &SB) {
	return SB.GetValue();
}

uint8 USCLibrary::SCL_Callable_GetSafeByteWithKey(FSafeByte &SB, FString Key) {
	return SB.GetValue(Key);
}

//

uint8 USCLibrary::SCL_Callable_SetRawSafeByte(FSafeByte &SB, FString Value) {
	SB.SetRaw(&Value); return SB.GetValue();
}

uint8 USCLibrary::SCL_Pure_SetSafeByte(FSafeByte &SB, const uint8 Value) {
	SB.SetValue(Value); return SB.GetValue();
}

uint8 USCLibrary::SCL_Pure_SetSafeByteWithKey(FSafeByte &SB, FString Key, const uint8 Value) {
	SB.SetValue(Key,Value); return SB.GetValue(Key);
}

uint8 USCLibrary::SCL_Callable_SetSafeByte(FSafeByte &SB, const uint8 Value) {
	SB.SetValue(Value); return SB.GetValue();
}

uint8 USCLibrary::SCL_Callable_SetSafeByteWithKey(FSafeByte &SB, FString Key, const uint8 Value) {
	SB.SetValue(Key,Value); return SB.GetValue(Key);
}

//

FString USCLibrary::SCL_Callable_GetRawSafeFloat(FSafeFloat &SF) {
	return SF.GetRaw();
}

float USCLibrary::SCL_Pure_GetSafeFloat(FSafeFloat &SF) {
	return SF.GetValue();
}

float USCLibrary::SCL_Pure_GetSafeFloatWithKey(FSafeFloat &SF, FString Key) {
	return SF.GetValue(Key);
}

float USCLibrary::SCL_Callable_GetSafeFloat(FSafeFloat &SF) {
	return SF.GetValue();
}

float USCLibrary::SCL_Callable_GetSafeFloatWithKey(FSafeFloat &SF, FString Key) {
	return SF.GetValue(Key);
}

//

float USCLibrary::SCL_Callable_SetRawSafeFloat(FSafeFloat &SF, FString Value) {
	SF.SetRaw(&Value); return SF.GetValue();
}

float USCLibrary::SCL_Pure_SetSafeFloat(FSafeFloat &SF, const float Value) {
	SF.SetValue(Value); return SF.GetValue();
}

float USCLibrary::SCL_Pure_SetSafeFloatWithKey(FSafeFloat &SF, FString Key, const float Value) {
	SF.SetValue(Key,Value); return SF.GetValue(Key);
}

float USCLibrary::SCL_Callable_SetSafeFloat(FSafeFloat &SF, const float Value) {
	SF.SetValue(Value); return SF.GetValue();
}

float USCLibrary::SCL_Callable_SetSafeFloatWithKey(FSafeFloat &SF, FString Key, const float Value) {
	SF.SetValue(Key,Value); return SF.GetValue(Key);
}

FString USCLibrary::SCL_Callable_GetRawSafeName(FSafeName &SN) {
	return SN.GetRaw();
}

//

FName USCLibrary::SCL_Pure_GetSafeName(FSafeName &SN) {
	return SN.GetValue();
}

FName USCLibrary::SCL_Pure_GetSafeNameWithKey(FSafeName &SN, FString Key) {
	return SN.GetValue(Key);
}

FName USCLibrary::SCL_Callable_GetSafeName(FSafeName &SN) {
	return SN.GetValue();
}

FName USCLibrary::SCL_Callable_GetSafeNameWithKey(FSafeName &SN, FString Key) {
	return SN.GetValue(Key);
}

//

FName USCLibrary::SCL_Callable_SetRawSafeName(FSafeName &SN, FString Value) {
	SN.SetRaw(&Value); return SN.GetValue();
}

FName USCLibrary::SCL_Pure_SetSafeName(FSafeName &SN, const FName Value) {
	SN.SetValue(Value); return SN.GetValue();
}

FName USCLibrary::SCL_Pure_SetSafeNameWithKey(FSafeName &SN, FString Key, const FName Value) {
	SN.SetValue(Key,Value); return SN.GetValue(Key);
}

FName USCLibrary::SCL_Callable_SetSafeName(FSafeName &SN, const FName Value) {
	SN.SetValue(Value); return SN.GetValue();
}

FName USCLibrary::SCL_Callable_SetSafeNameWithKey(FSafeName &SN, FString Key, const FName Value) {
	SN.SetValue(Key,Value); return SN.GetValue(Key);
}

//

FString USCLibrary::SCL_Callable_GetRawSafeString(FSafeString &SS) {
	return SS.GetRaw();
}

FString USCLibrary::SCL_Pure_GetSafeString(FSafeString &SS) {
	return SS.GetValue();
}

FString USCLibrary::SCL_Pure_GetSafeStringWithKey(FSafeString &SS, FString Key) {
	return SS.GetValue(Key);
}

FString USCLibrary::SCL_Callable_GetSafeString(FSafeString &SS) {
	return SS.GetValue();
}

FString USCLibrary::SCL_Callable_GetSafeStringWithKey(FSafeString &SS, FString Key) {
	return SS.GetValue(Key);
}

//

FString USCLibrary::SCL_Callable_SetRawSafeString(FSafeString &SS, FString Value) {
	SS.SetRaw(&Value); return SS.GetValue();
}

FString USCLibrary::SCL_Pure_SetSafeString(FSafeString &SS, const FString Value) {
	SS.SetValue(Value); return SS.GetValue();
}

FString USCLibrary::SCL_Pure_SetSafeStringWithKey(FSafeString &SS, FString Key, const FString Value) {
	SS.SetValue(Key,Value); return SS.GetValue(Key);
}

FString USCLibrary::SCL_Callable_SetSafeString(FSafeString &SS, const FString Value) {
	SS.SetValue(Value); return SS.GetValue();
}

FString USCLibrary::SCL_Callable_SetSafeStringWithKey(FSafeString &SS, FString Key, const FString Value) {
	SS.SetValue(Key,Value); return SS.GetValue(Key);
}

//

FString USCLibrary::SCL_Callable_GetRawSafeText(FSafeText &ST) {
	return ST.GetRaw();
}

FText USCLibrary::SCL_Pure_GetSafeText(FSafeText &ST) {
	return ST.GetValue();
}

FText USCLibrary::SCL_Pure_GetSafeTextWithKey(FSafeText &ST, FString Key) {
	return ST.GetValue(Key);
}

FText USCLibrary::SCL_Callable_GetSafeText(FSafeText &ST) {
	return ST.GetValue();
}

FText USCLibrary::SCL_Callable_GetSafeTextWithKey(FSafeText &ST, FString Key) {
	return ST.GetValue(Key);
}

//

FText USCLibrary::SCL_Callable_SetRawSafeText(FSafeText &ST, FString Value) {
	ST.SetRaw(&Value); return ST.GetValue();
}

FText USCLibrary::SCL_Pure_SetSafeText(FSafeText &ST, const FText Value) {
	ST.SetValue(Value); return ST.GetValue();
}

FText USCLibrary::SCL_Pure_SetSafeTextWithKey(FSafeText &ST, FString Key, const FText Value) {
	ST.SetValue(Key,Value); return ST.GetValue(Key);
}

FText USCLibrary::SCL_Callable_SetSafeText(FSafeText &ST, const FText Value) {
	ST.SetValue(Value); return ST.GetValue();
}

FText USCLibrary::SCL_Callable_SetSafeTextWithKey(FSafeText &ST, FString Key, const FText Value) {
	ST.SetValue(Key,Value); return ST.GetValue(Key);
}

//

FVector2D USCLibrary::SCL_Pure_GetSafeVector2D(FSafeVector2D &SV) {
	return SV.GetValue();
}

FVector2D USCLibrary::SCL_Pure_GetSafeVector2DWithKey(FSafeVector2D &SV, FString Key) {
	return SV.GetValue(Key);
}

FVector2D USCLibrary::SCL_Callable_GetSafeVector2D(FSafeVector2D &SV) {
	return SV.GetValue();
}

FVector2D USCLibrary::SCL_Callable_GetSafeVector2DWithKey(FSafeVector2D &SV, FString Key) {
	return SV.GetValue(Key);
}

//

FVector2D USCLibrary::SCL_Pure_SetSafeVector2D(FSafeVector2D &SV, const FVector2D Value) {
	SV.SetValue(Value); return SV.GetValue();
}

FVector2D USCLibrary::SCL_Pure_SetSafeVector2DWithKey(FSafeVector2D &SV, FString Key, const FVector2D Value) {
	SV.SetValue(Key,Value); return SV.GetValue(Key);
}

FVector2D USCLibrary::SCL_Callable_SetSafeVector2D(FSafeVector2D &SV, const FVector2D Value) {
	SV.SetValue(Value); return SV.GetValue();
}

FVector2D USCLibrary::SCL_Callable_SetSafeVector2DWithKey(FSafeVector2D &SV, FString Key, const FVector2D Value) {
	SV.SetValue(Key,Value); return SV.GetValue(Key);
}

//

FVector USCLibrary::SCL_Pure_GetSafeVector3D(FSafeVector3D &SV) {
	return SV.GetValue();
}

FVector USCLibrary::SCL_Pure_GetSafeVector3DWithKey(FSafeVector3D &SV, FString Key) {
	return SV.GetValue(Key);
}

FVector USCLibrary::SCL_Callable_GetSafeVector3D(FSafeVector3D &SV) {
	return SV.GetValue();
}

FVector USCLibrary::SCL_Callable_GetSafeVector3DWithKey(FSafeVector3D &SV, FString Key) {
	return SV.GetValue(Key);
}

//

FVector USCLibrary::SCL_Pure_SetSafeVector3D(FSafeVector3D &SV, const FVector Value) {
	SV.SetValue(Value); return SV.GetValue();
}

FVector USCLibrary::SCL_Pure_SetSafeVector3DWithKey(FSafeVector3D &SV, FString Key, const FVector Value) {
	SV.SetValue(Key,Value); return SV.GetValue(Key);
}

FVector USCLibrary::SCL_Callable_SetSafeVector3D(FSafeVector3D &SV, const FVector Value) {
	SV.SetValue(Value); return SV.GetValue();
}

FVector USCLibrary::SCL_Callable_SetSafeVector3DWithKey(FSafeVector3D &SV, FString Key, const FVector Value) {
	SV.SetValue(Key,Value); return SV.GetValue(Key);
}

//

FVector4 USCLibrary::SCL_Pure_GetSafeVector4D(FSafeVector4D &SV) {
	return SV.GetValue();
}

FVector4 USCLibrary::SCL_Pure_GetSafeVector4DWithKey(FSafeVector4D &SV, FString Key) {
	return SV.GetValue(Key);
}

FVector4 USCLibrary::SCL_Callable_GetSafeVector4D(FSafeVector4D &SV) {
	return SV.GetValue();
}

FVector4 USCLibrary::SCL_Callable_GetSafeVector4DWithKey(FSafeVector4D &SV, FString Key) {
	return SV.GetValue(Key);
}

//

FVector4 USCLibrary::SCL_Pure_SetSafeVector4D(FSafeVector4D &SV, FVector4& Value) {
	SV.SetValue(&Value); return SV.GetValue();
}

FVector4 USCLibrary::SCL_Pure_SetSafeVector4DWithKey(FSafeVector4D &SV, FString Key, FVector4& Value) {
	SV.SetValue(Key,&Value); return SV.GetValue(Key);
}

FVector4 USCLibrary::SCL_Callable_SetSafeVector4D(FSafeVector4D &SV, FVector4& Value) {
	SV.SetValue(&Value); return SV.GetValue();
}

FVector4 USCLibrary::SCL_Callable_SetSafeVector4DWithKey(FSafeVector4D &SV, FString Key, FVector4& Value) {
	SV.SetValue(Key,&Value); return SV.GetValue(Key);
}

//

FLinearColor USCLibrary::SCL_Pure_GetSafeColor(FSafeColor &SC) {
	return SC.GetValue();
}

FLinearColor USCLibrary::SCL_Pure_GetSafeColorWithKey(FSafeColor &SC, FString Key) {
	return SC.GetValue(Key);
}

FLinearColor USCLibrary::SCL_Callable_GetSafeColor(FSafeColor &SC) {
	return SC.GetValue();
}

FLinearColor USCLibrary::SCL_Callable_GetSafeColorWithKey(FSafeColor &SC, FString Key) {
	return SC.GetValue(Key);
}

//

FLinearColor USCLibrary::SCL_Pure_SetSafeColor(FSafeColor &SC, FLinearColor& Value) {
	SC.SetValue(&Value); return SC.GetValue();
}

FLinearColor USCLibrary::SCL_Pure_SetSafeColorWithKey(FSafeColor &SC, FString Key, FLinearColor& Value) {
	SC.SetValue(Key,&Value); return SC.GetValue(Key);
}

FLinearColor USCLibrary::SCL_Callable_SetSafeColor(FSafeColor &SC, FLinearColor& Value) {
	SC.SetValue(&Value); return SC.GetValue();
}

FLinearColor USCLibrary::SCL_Callable_SetSafeColorWithKey(FSafeColor &SC, FString Key, FLinearColor& Value) {
	SC.SetValue(Key,&Value); return SC.GetValue(Key);
}

//

FRotator USCLibrary::SCL_Pure_GetSafeRotator(FSafeRotator &SR) {
	return SR.GetValue();
}

FRotator USCLibrary::SCL_Pure_GetSafeRotatorWithKey(FSafeRotator &SR, FString Key) {
	return SR.GetValue(Key);
}

FRotator USCLibrary::SCL_Callable_GetSafeRotator(FSafeRotator &SR) {
	return SR.GetValue();
}

FRotator USCLibrary::SCL_Callable_GetSafeRotatorWithKey(FSafeRotator &SR, FString Key) {
	return SR.GetValue(Key);
}

//

FRotator USCLibrary::SCL_Pure_SetSafeRotator(FSafeRotator &SR, const FRotator Value) {
	SR.SetValue(Value); return SR.GetValue();
}

FRotator USCLibrary::SCL_Pure_SetSafeRotatorWithKey(FSafeRotator &SR, FString Key, const FRotator Value) {
	SR.SetValue(Key,Value); return SR.GetValue(Key);
}

FRotator USCLibrary::SCL_Callable_SetSafeRotator(FSafeRotator &SR, const FRotator Value) {
	SR.SetValue(Value); return SR.GetValue();
}

FRotator USCLibrary::SCL_Callable_SetSafeRotatorWithKey(FSafeRotator &SR, FString Key, const FRotator Value) {
	SR.SetValue(Key,Value); return SR.GetValue(Key);
}

//

FTransform USCLibrary::SCL_Pure_GetSafeTransform(FSafeTransform &ST) {
	return ST.GetValue();
}

FTransform USCLibrary::SCL_Pure_GetSafeTransformWithKey(FSafeTransform &ST, FString Key) {
	return ST.GetValue(Key);
}

FTransform USCLibrary::SCL_Callable_GetSafeTransform(FSafeTransform &ST) {
	return ST.GetValue();
}

FTransform USCLibrary::SCL_Callable_GetSafeTransformWithKey(FSafeTransform &ST, FString Key) {
	return ST.GetValue(Key);
}

//

FTransform USCLibrary::SCL_Pure_SetSafeTransform(FSafeTransform &ST, FTransform& Value) {
	ST.SetValue(&Value); return ST.GetValue();
}

FTransform USCLibrary::SCL_Pure_SetSafeTransformWithKey(FSafeTransform &ST, FString Key, FTransform& Value) {
	ST.SetValue(Key,&Value); return ST.GetValue();
}

FTransform USCLibrary::SCL_Callable_SetSafeTransform(FSafeTransform &ST, FTransform& Value) {
	ST.SetValue(&Value); return ST.GetValue();
}

FTransform USCLibrary::SCL_Callable_SetSafeTransformWithKey(FSafeTransform &ST, FString Key, FTransform& Value) {
	ST.SetValue(Key,&Value); return ST.GetValue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// FSBool

/* FSafe -> FSafe */

FSafeBool USCLibrary::SCO_Pure_SetSafeBoolEqualFSB(FSafeBool &FSB, FSafeBool &SSB, bool &Output) {
	FSB = SSB; Output = FSB.GetValue(); return FSB;
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolEqualFSB(FSafeBool &FSB, FSafeBool &SSB, bool &Output) {
	Output = (FSB == SSB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolNotEqualFSB(FSafeBool &FSB, FSafeBool &SSB, bool &Output) {
	Output = (FSB != SSB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolAndFSB(FSafeBool &FSB, FSafeBool &SSB, bool &Output) {
	Output = (FSB && SSB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolOrFSB(FSafeBool &FSB, FSafeBool &SSB, bool &Output) {
	Output = (FSB || SSB); return FSafeBool(Output);
}

/* Native -> FSafe */

FSafeBool USCLibrary::SCO_Pure_SetSafeBoolEqualBool(FSafeBool &FSB, bool &NB, bool &Output) {
	FSB = NB; Output = FSB.GetValue(); return FSB;
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolEqualBool(FSafeBool &FSB, bool &NB, bool &Output) {
	Output = (FSB == NB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolNotEqualBool(FSafeBool &FSB, bool &NB, bool &Output) {
	Output = (FSB != NB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolAndBool(FSafeBool &FSB, bool &NB, bool &Output) {
	Output = (FSB && NB); return FSafeBool(Output);
}

FSafeBool USCLibrary::SCO_Pure_GetSafeBoolOrBool(FSafeBool &FSB, bool &NB, bool &Output) {
	Output = (FSB || NB); return FSafeBool(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_SetBoolEqualFSB(bool &NB, FSafeBool &FSB) {
	return (NB = FSB.GetValue());
}

bool USCLibrary::SCO_Pure_GetBoolEqualFSB(bool &NB, FSafeBool &FSB) {
	return (NB == FSB);
}

bool USCLibrary::SCO_Pure_GetBoolNotEqualFSB(bool &NB, FSafeBool &FSB) {
	return (NB != FSB);
}

bool USCLibrary::SCO_Pure_GetBoolAndFSB(bool &NB, FSafeBool &FSB) {
	return (NB && FSB);
}

bool USCLibrary::SCO_Pure_GetBoolOrFSB(bool &NB, FSafeBool &FSB) {
	return (NB || FSB);
}

// FSByte

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeByteEqualFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB == SSB);
}

bool USCLibrary::SCO_Pure_GetSafeByteNotEqualFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB != SSB);
}

bool USCLibrary::SCO_Pure_GetSafeByteGreaterFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB > SSB);
}

bool USCLibrary::SCO_Pure_GetSafeByteSmallerFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB < SSB);
}

bool USCLibrary::SCO_Pure_GetSafeByteGreaterEqualFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB >= SSB);
}

bool USCLibrary::SCO_Pure_GetSafeByteSmallerEqualFSB(FSafeByte &FSB, FSafeByte &SSB) {
	return (FSB <= SSB);
}

FSafeByte USCLibrary::SCO_Pure_SetSafeByteEqualFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	FSB = SSB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeBytePlusFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB + SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteMinusFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB - SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteTimesFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB * SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteDivideFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB / SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteIncreaseFSB(FSafeByte &FSB, uint8 &Output) {
	Output = (++ FSB).GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteDecreaseFSB(FSafeByte &FSB, uint8 &Output) {
	Output = (-- FSB).GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeBytePlusEqualFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	FSB += SSB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteMinusEqualFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	FSB -= SSB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteNotFSB(FSafeByte &FSB, uint8 &Output) {
	Output = ( ~ FSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteModFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB % SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteAndFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB & SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteOrFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB | SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteXorFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB ^ SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteShiftRFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB >> SSB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteShiftLFSB(FSafeByte &FSB, FSafeByte &SSB, uint8 &Output) {
	Output = (FSB << SSB).GetValue(); return FSafeByte(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeByteEqualByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB == NB);
}

bool USCLibrary::SCO_Pure_GetSafeByteNotEqualByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB != NB);
}

bool USCLibrary::SCO_Pure_GetSafeByteGreaterByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB > NB);
}

bool USCLibrary::SCO_Pure_GetSafeByteSmallerByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB < NB);
}

bool USCLibrary::SCO_Pure_GetSafeByteGreaterEqualByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB >= NB);
}

bool USCLibrary::SCO_Pure_GetSafeByteSmallerEqualByte(FSafeByte &FSB, uint8 &NB) {
	return (FSB <= NB);
}

FSafeByte USCLibrary::SCO_Pure_SetSafeByteEqualByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	FSB = NB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeBytePlusByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB + NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteMinusByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB - NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteTimesByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB * NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteDivideByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB / NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeBytePlusEqualByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	FSB += NB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteMinusEqualByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	FSB -= NB; Output = FSB.GetValue(); return FSB;
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteNotByte(uint8 &NB, uint8 &Output) {
	Output = ( ~ NB); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteModByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB % NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteAndByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB & NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteOrByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB | NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteXorByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB ^ NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteShiftRByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB >> NB).GetValue(); return FSafeByte(Output);
}

FSafeByte USCLibrary::SCO_Pure_GetSafeByteShiftLByte(FSafeByte &FSB, uint8 &NB, uint8 &Output) {
	Output = (FSB << NB).GetValue(); return FSafeByte(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetByteEqualFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB == FSB);
}

bool USCLibrary::SCO_Pure_GetByteNotEqualFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB != FSB);
}

bool USCLibrary::SCO_Pure_GetByteGreaterFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB > FSB);
}

bool USCLibrary::SCO_Pure_GetByteSmallerFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB < FSB);
}

bool USCLibrary::SCO_Pure_GetByteGreaterEqualFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB >= FSB);
}

bool USCLibrary::SCO_Pure_GetByteSmallerEqualFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB <= FSB);
}

uint8 USCLibrary::SCO_Pure_SetByteEqualFSB(uint8 &NB, FSafeByte &FSB) {
	NB = FSB.GetValue(); return NB;
}

uint8 USCLibrary::SCO_Pure_GetBytePlusFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB + FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteMinusFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB - FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteTimesFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB * FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteDivideFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB / FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteModFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB % FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteAndFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB & FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteOrFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB | FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteXorFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB ^ FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteShiftRFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB >> FSB);
}

uint8 USCLibrary::SCO_Pure_GetByteShiftLFSB(uint8 &NB, FSafeByte &FSB) {
	return (NB << FSB);
}


// FSInt

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeIntEqualFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI == SSI);
}

bool USCLibrary::SCO_Pure_GetSafeIntNotEqualFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI != SSI);
}

bool USCLibrary::SCO_Pure_GetSafeIntGreaterFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI > SSI);
}

bool USCLibrary::SCO_Pure_GetSafeIntSmallerFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI < SSI);
}

bool USCLibrary::SCO_Pure_GetSafeIntGreaterEqualFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI >= SSI);
}

bool USCLibrary::SCO_Pure_GetSafeIntSmallerEqualFSI(FSafeInt &FSI, FSafeInt &SSI) {
	return (FSI <= SSI);
}

FSafeInt USCLibrary::SCO_Pure_SetSafeIntEqualFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	FSI = SSI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntPlusFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI + SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntMinusFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI - SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntTimesFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI * SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntDivideFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI / SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntIncreaseFSI(FSafeInt &FSI, int32 &Output) {
	Output = (++ FSI).GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntDecreaseFSI(FSafeInt &FSI, int32 &Output) {
	Output = (-- FSI).GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntPlusEqualFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	FSI += SSI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntMinusEqualFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	FSI -= SSI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntNotFSI(FSafeInt &FSI, int32 &Output) {
	Output = ( ~ FSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntModFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI % SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntAndFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI & SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntOrFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI | SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntXorFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI ^ SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntShiftRFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI >> SSI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntShiftLFSI(FSafeInt &FSI, FSafeInt &SSI, int32 &Output) {
	Output = (FSI << SSI).GetValue(); return FSafeInt(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeIntEqualInt(FSafeInt &FSI, int32 &NI) {
	return (FSI == NI);
}

bool USCLibrary::SCO_Pure_GetSafeIntNotEqualInt(FSafeInt &FSI, int32 &NI) {
	return (FSI != NI);
}

bool USCLibrary::SCO_Pure_GetSafeIntGreaterInt(FSafeInt &FSI, int32 &NI) {
	return (FSI > NI);
}

bool USCLibrary::SCO_Pure_GetSafeIntSmallerInt(FSafeInt &FSI, int32 &NI) {
	return (FSI < NI);
}

bool USCLibrary::SCO_Pure_GetSafeIntGreaterEqualInt(FSafeInt &FSI, int32 &NI) {
	return (FSI >= NI);
}

bool USCLibrary::SCO_Pure_GetSafeIntSmallerEqualInt(FSafeInt &FSI, int32 &NI) {
	return (FSI <= NI);
}

FSafeInt USCLibrary::SCO_Pure_SetSafeIntEqualInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	FSI = NI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntPlusInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI + NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntMinusInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI - NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntTimesInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI * NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntDivideInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI / NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntPlusEqualInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	FSI += NI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntMinusEqualInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	FSI -= NI; Output = FSI.GetValue(); return FSI;
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntNotInt(int32 &NI, int32 &Output) {
	Output = ( ~ NI); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntModInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI % NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntAndInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI & NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntOrInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI | NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntXorInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI ^ NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntShiftRInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI >> NI).GetValue(); return FSafeInt(Output);
}

FSafeInt USCLibrary::SCO_Pure_GetSafeIntShiftLInt(FSafeInt &FSI, int32 &NI, int32 &Output) {
	Output = (FSI << NI).GetValue(); return FSafeInt(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetIntEqualFSI(int32 &NI, FSafeInt &FSI) {
	return (NI == FSI);
}

bool USCLibrary::SCO_Pure_GetIntNotEqualFSI(int32 &NI, FSafeInt &FSI) {
	return (NI != FSI);
}

bool USCLibrary::SCO_Pure_GetIntGreaterFSI(int32 &NI, FSafeInt &FSI) {
	return (NI > FSI);
}

bool USCLibrary::SCO_Pure_GetIntSmallerFSI(int32 &NI, FSafeInt &FSI) {
	return (NI < FSI);
}

bool USCLibrary::SCO_Pure_GetIntGreaterEqualFSI(int32 &NI, FSafeInt &FSI) {
	return (NI >= FSI);
}

bool USCLibrary::SCO_Pure_GetIntSmallerEqualFSI(int32 &NI, FSafeInt &FSI) {
	return (NI <= FSI);
}

int32 USCLibrary::SCO_Pure_SetIntEqualFSI(int32 &NI, FSafeInt &FSI) {
	NI = FSI.GetValue(); return NI;
}

int32 USCLibrary::SCO_Pure_GetIntPlusFSI(int32 &NI, FSafeInt &FSI) {
	return (NI + FSI);
}

int32 USCLibrary::SCO_Pure_GetIntMinusFSI(int32 &NI, FSafeInt &FSI) {
	return (NI - FSI);
}

int32 USCLibrary::SCO_Pure_GetIntTimesFSI(int32 &NI, FSafeInt &FSI) {
	return (NI * FSI);
}

int32 USCLibrary::SCO_Pure_GetIntDivideFSI(int32 &NI, FSafeInt &FSI) {
	return (NI / FSI);
}

int32 USCLibrary::SCO_Pure_GetIntModFSI(int32 &NI, FSafeInt &FSI) {
	return (NI % FSI);
}

int32 USCLibrary::SCO_Pure_GetIntAndFSI(int32 &NI, FSafeInt &FSI) {
	return (NI & FSI);
}

int32 USCLibrary::SCO_Pure_GetIntOrFSI(int32 &NI, FSafeInt &FSI) {
	return (NI | FSI);
}

int32 USCLibrary::SCO_Pure_GetIntXorFSI(int32 &NI, FSafeInt &FSI) {
	return (NI ^ FSI);
}

int32 USCLibrary::SCO_Pure_GetIntShiftRFSI(int32 &NI, FSafeInt &FSI) {
	return (NI >> FSI);
}

int32 USCLibrary::SCO_Pure_GetIntShiftLFSI(int32 &NI, FSafeInt &FSI) {
	return (NI << FSI);
}

// FSFloat

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeFloatEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF == SSF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatNotEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF != SSF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatGreaterFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF > SSF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatSmallerFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF < SSF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatGreaterEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF >= SSF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatSmallerEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF) {
	return (FSF <= SSF);
}

FSafeFloat USCLibrary::SCO_Pure_SetSafeFloatEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	FSF = SSF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatPlusFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	Output = (FSF + SSF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatMinusFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	Output = (FSF - SSF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatTimesFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	Output = (FSF * SSF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatDivideFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	Output = (FSF / SSF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatIncreaseFSF(FSafeFloat &FSF, float &Output) {
	Output = (++ FSF).GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatDecreaseFSF(FSafeFloat &FSF, float &Output) {
	Output = (-- FSF).GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatPlusEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	FSF += SSF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatMinusEqualFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	FSF -= SSF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatModFSF(FSafeFloat &FSF, FSafeFloat &SSF, float &Output) {
	Output = (FSF % SSF).GetValue(); return FSafeFloat(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeFloatEqualFloat(FSafeFloat &FSF, float &NF) {
	return (FSF == NF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatNotEqualFloat(FSafeFloat &FSF, float &NF) {
	return (FSF != NF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatGreaterFloat(FSafeFloat &FSF, float &NF) {
	return (FSF > NF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatSmallerFloat(FSafeFloat &FSF, float &NF) {
	return (FSF < NF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatGreaterEqualFloat(FSafeFloat &FSF, float &NF) {
	return (FSF >= NF);
}

bool USCLibrary::SCO_Pure_GetSafeFloatSmallerEqualFloat(FSafeFloat &FSF, float &NF) {
	return (FSF <= NF);
}

FSafeFloat USCLibrary::SCO_Pure_SetSafeFloatEqualFloat(FSafeFloat &FSF, float &NF, float &Output) {
	FSF = NF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatPlusFloat(FSafeFloat &FSF, float &NF, float &Output) {
	Output = (FSF + NF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatMinusFloat(FSafeFloat &FSF, float &NF, float &Output) {
	Output = (FSF - NF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatTimesFloat(FSafeFloat &FSF, float &NF, float &Output) {
	Output = (FSF * NF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatDivideFloat(FSafeFloat &FSF, float &NF, float &Output) {
	Output = (FSF / NF).GetValue(); return FSafeFloat(Output);
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatPlusEqualFloat(FSafeFloat &FSF, float &NF, float &Output) {
	FSF += NF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatMinusEqualFloat(FSafeFloat &FSF, float &NF, float &Output) {
	FSF -= NF; Output = FSF.GetValue(); return FSF;
}

FSafeFloat USCLibrary::SCO_Pure_GetSafeFloatModFloat(FSafeFloat &FSF, float &NF, float &Output) {
	Output = (FSF % NF).GetValue(); return FSafeFloat(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetFloatEqualFSF(float &NF, FSafeFloat &FSF) {
	return (NF == FSF);
}

bool USCLibrary::SCO_Pure_GetFloatNotEqualFSF(float &NF, FSafeFloat &FSF) {
	return (NF != FSF);
}

bool USCLibrary::SCO_Pure_GetFloatGreaterFSF(float &NF, FSafeFloat &FSF) {
	return (NF > FSF);
}

bool USCLibrary::SCO_Pure_GetFloatSmallerFSF(float &NF, FSafeFloat &FSF) {
	return (NF < FSF);
}

bool USCLibrary::SCO_Pure_GetFloatGreaterEqualFSF(float &NF, FSafeFloat &FSF) {
	return (NF >= FSF);
}

bool USCLibrary::SCO_Pure_GetFloatSmallerEqualFSF(float &NF, FSafeFloat &FSF) {
	return (NF <= FSF);
}

float USCLibrary::SCO_Pure_SetFloatEqualFSF(float &NF, FSafeFloat &FSF) {
	NF = FSF.GetValue(); return NF;
}

float USCLibrary::SCO_Pure_GetFloatPlusFSF(float &NF, FSafeFloat &FSF) {
	return (NF + FSF);
}

float USCLibrary::SCO_Pure_GetFloatMinusFSF(float &NF, FSafeFloat &FSF) {
	return (NF - FSF);
}

float USCLibrary::SCO_Pure_GetFloatTimesFSF(float &NF, FSafeFloat &FSF) {
	return (NF * FSF);
}

float USCLibrary::SCO_Pure_GetFloatDivideFSF(float &NF, FSafeFloat &FSF) {
	return (NF / FSF);
}

float USCLibrary::SCO_Pure_GetFloatModFSF(float &NF, FSafeFloat &FSF) {
	return (NF % FSF);
}

// FSName

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeNameEqualFSN(FSafeName &FSN, FSafeName &SSN) {
	return (FSN == SSN);
}

bool USCLibrary::SCO_Pure_GetSafeNameNotEqualFSN(FSafeName &FSN, FSafeName &SSN) {
	return (FSN != SSN);
}

bool USCLibrary::SCO_Pure_GetSafeNameGreaterFSN(FSafeName &FSN, FSafeName &SSN) {
	return (FSN > SSN);
}

bool USCLibrary::SCO_Pure_GetSafeNameSmallerFSN(FSafeName &FSN, FSafeName &SSN) {
	return (FSN < SSN);
}

FSafeName USCLibrary::SCO_Pure_SetSafeNameEqualFSN(FSafeName &FSN, FSafeName &SSN, FName &Output) {
	FSN = SSN; Output = FSN.GetValue(); return FSN;
}

FSafeName USCLibrary::SCO_Pure_GetSafeNamePlusFSN(FSafeName &FSN, FSafeName &SSN, FName &Output) {
	Output = (FSN + SSN).GetValue(); return FSafeName(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeNameEqualName(FSafeName &FSN, FName &NN) {
	return (FSN == NN);
}

bool USCLibrary::SCO_Pure_GetSafeNameNotEqualName(FSafeName &FSN, FName &NN) {
	return (FSN != NN);
}

bool USCLibrary::SCO_Pure_GetSafeNameGreaterName(FSafeName &FSN, FName &NN) {
	return (FSN > NN);
}

bool USCLibrary::SCO_Pure_GetSafeNameSmallerName(FSafeName &FSN, FName &NN) {
	return (FSN < NN);
}

FSafeName USCLibrary::SCO_Pure_SetSafeNameEqualName(FSafeName &FSN, FName &NN, FName &Output) {
	FSN = NN; Output = FSN.GetValue(); return FSN;
}

FSafeName USCLibrary::SCO_Pure_GetSafeNamePlusName(FSafeName &FSN, FName &NN, FName &Output) {
	Output = (FSN + NN).GetValue(); return FSafeName(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetNameEqualFSN(FName &NN, FSafeName &FSN) {
	return (NN == FSN);
}

bool USCLibrary::SCO_Pure_GetNameNotEqualFSN(FName &NN, FSafeName &FSN) {
	return (NN != FSN);
}

bool USCLibrary::SCO_Pure_GetNameGreaterFSN(FName &NN, FSafeName &FSN) {
	return (NN > FSN);
}

bool USCLibrary::SCO_Pure_GetNameSmallerFSN(FName &NN, FSafeName &FSN) {
	return (NN < FSN);
}

FName USCLibrary::SCO_Pure_SetNameEqualFSN(FName &NN, FSafeName &FSN) {
	NN = FSN.GetValue(); return NN;
}

FName USCLibrary::SCO_Pure_GetNamePlusFSN(FName &NN, FSafeName &FSN) {
	return (NN + FSN);
}

// FSText

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeTextEqualFST(FSafeText &FST, FSafeText &ST) {
	return (FST == ST);
}

bool USCLibrary::SCO_Pure_GetSafeTextNotEqualFST(FSafeText &FST, FSafeText &ST) {
	return (FST != ST);
}

bool USCLibrary::SCO_Pure_GetSafeTextGreaterFST(FSafeText &FST, FSafeText &ST) {
	return (FST > ST);
}

bool USCLibrary::SCO_Pure_GetSafeTextSmallerFST(FSafeText &FST, FSafeText &ST) {
	return (FST < ST);
}

FSafeText USCLibrary::SCO_Pure_SetSafeTextEqualFST(FSafeText &FST, FSafeText &ST, FText &Output) {
	FST = ST; Output = FST.GetValue(); return FST;
}

FSafeText USCLibrary::SCO_Pure_GetSafeTextPlusFST(FSafeText &FST, FSafeText &ST, FText &Output) {
	Output = (FST + ST).GetValue(); return FSafeText(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeTextEqualText(FSafeText &FST, FText &NT) {
	return (FST == NT);
}

bool USCLibrary::SCO_Pure_GetSafeTextNotEqualText(FSafeText &FST, FText &NT) {
	return (FST != NT);
}

bool USCLibrary::SCO_Pure_GetSafeTextGreaterText(FSafeText &FST, FText &NT) {
	return (FST > NT);
}

bool USCLibrary::SCO_Pure_GetSafeTextSmallerText(FSafeText &FST, FText &NT) {
	return (FST < NT);
}

FSafeText USCLibrary::SCO_Pure_SetSafeTextEqualText(FSafeText &FST, FText &NT, FText &Output) {
	FST = NT; Output = FST.GetValue(); return FST;
}

FSafeText USCLibrary::SCO_Pure_GetSafeTextPlusText(FSafeText &FST, FText &NT, FText &Output) {
	Output = (FST + NT).GetValue(); return FSafeText(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetTextEqualFST(FText &NT, FSafeText &FST) {
	return (NT == FST);
}

bool USCLibrary::SCO_Pure_GetTextNotEqualFST(FText &NT, FSafeText &FST) {
	return (NT != FST);
}

bool USCLibrary::SCO_Pure_GetTextGreaterFST(FText &NT, FSafeText &FST) {
	return (NT > FST);
}

bool USCLibrary::SCO_Pure_GetTextSmallerFST(FText &NT, FSafeText &FST) {
	return (NT < FST);
}

FText USCLibrary::SCO_Pure_SetTextEqualFST(FText &NT, FSafeText &FST) {
	NT = FST.GetValue(); return NT;
}

FText USCLibrary::SCO_Pure_GetTextPlusFST(FText &NT, FSafeText &FST) {
	return (NT + FST);
}

// FSString

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeStringEqualFSS(FSafeString &FSS, FSafeString &SSN) {
	return (FSS == SSN);
}

bool USCLibrary::SCO_Pure_GetSafeStringNotEqualFSS(FSafeString &FSS, FSafeString &SSN) {
	return (FSS != SSN);
}

bool USCLibrary::SCO_Pure_GetSafeStringGreaterFSS(FSafeString &FSS, FSafeString &SSN) {
	return (FSS > SSN);
}

bool USCLibrary::SCO_Pure_GetSafeStringSmallerFSS(FSafeString &FSS, FSafeString &SSN) {
	return (FSS < SSN);
}

FSafeString USCLibrary::SCO_Pure_SetSafeStringEqualFSS(FSafeString &FSS, FSafeString &SSN, FString &Output) {
	FSS = SSN; Output = FSS.GetValue(); return FSS;
}

FSafeString USCLibrary::SCO_Pure_GetSafeStringPlusFSS(FSafeString &FSS, FSafeString &SSN, FString &Output) {
	Output = (FSS + SSN).GetValue(); return FSafeString(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeStringEqualString(FSafeString &FSS, FString &NS) {
	return (FSS == NS);
}

bool USCLibrary::SCO_Pure_GetSafeStringNotEqualString(FSafeString &FSS, FString &NS) {
	return (FSS != NS);
}

bool USCLibrary::SCO_Pure_GetSafeStringGreaterString(FSafeString &FSS, FString &NS) {
	return (FSS > NS);
}

bool USCLibrary::SCO_Pure_GetSafeStringSmallerString(FSafeString &FSS, FString &NS) {
	return (FSS < NS);
}

FSafeString USCLibrary::SCO_Pure_SetSafeStringEqualString(FSafeString &FSS, FString &NS, FString &Output) {
	FSS = NS; Output = FSS.GetValue(); return FSS;
}

FSafeString USCLibrary::SCO_Pure_GetSafeStringPlusString(FSafeString &FSS, FString &NS, FString &Output) {
	Output = (FSS + NS).GetValue(); return FSafeString(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetStringEqualFSS(FString &NS, FSafeString &FSS) {
	return (NS == FSS);
}

bool USCLibrary::SCO_Pure_GetStringNotEqualFSS(FString &NS, FSafeString &FSS) {
	return (NS != FSS);
}

bool USCLibrary::SCO_Pure_GetStringGreaterFSS(FString &NS, FSafeString &FSS) {
	return (NS > FSS);
}

bool USCLibrary::SCO_Pure_GetStringSmallerFSS(FString &NS, FSafeString &FSS) {
	return (NS < FSS);
}

FString USCLibrary::SCO_Pure_SetStringEqualFSS(FString &NS, FSafeString &FSS) {
	NS = FSS.GetValue(); return NS;
}

FString USCLibrary::SCO_Pure_GetStringPlusFSS(FString &NS, FSafeString &FSS) {
	return (NS + FSS);
}

// FSVector2D

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector2DEqualFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV == SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DNotEqualFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV != SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DGreaterFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV > SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DSmallerFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV < SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DGreaterEqualFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV >= SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DSmallerEqualFSV(FSafeVector2D &FSV, FSafeVector2D &SSV) {
	return (FSV <= SSV);
}

FSafeVector2D USCLibrary::SCO_Pure_SetSafeVector2DEqualFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	FSV = SSV; Output = FSV.GetValue(); return FSV;
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DPlusFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	Output = (FSV + SSV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DMinusFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	Output = (FSV - SSV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DTimesFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	Output = (FSV * SSV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DDivideFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	Output = (FSV / SSV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DModFSV(FSafeVector2D &FSV, FSafeVector2D &SSV, FVector2D &Output) {
	Output = (FSV % SSV).GetValue(); return FSafeVector2D(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector2DEqualVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV == NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DNotEqualVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV != NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DGreaterVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV > NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DSmallerVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV < NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DGreaterEqualVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV >= NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector2DSmallerEqualVector2D(FSafeVector2D &FSV, FVector2D &NV) {
	return (FSV <= NV);
}

FSafeVector2D USCLibrary::SCO_Pure_SetSafeVector2DEqualVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	FSV = NV; Output = FSV.GetValue(); return FSV;
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DPlusVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	Output = (FSV + NV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DMinusVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	Output = (FSV - NV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DTimesVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	Output = (FSV * NV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DDivideVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	Output = (FSV / NV).GetValue(); return FSafeVector2D(Output);
}

FSafeVector2D USCLibrary::SCO_Pure_GetSafeVector2DModVector2D(FSafeVector2D &FSV, FVector2D &NV, FVector2D &Output) {
	Output = (FSV % NV).GetValue(); return FSafeVector2D(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetVector2DEqualFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV == FSV);
}

bool USCLibrary::SCO_Pure_GetVector2DNotEqualFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV != FSV);
}

bool USCLibrary::SCO_Pure_GetVector2DGreaterFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV > FSV);
}

bool USCLibrary::SCO_Pure_GetVector2DSmallerFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV < FSV);
}

bool USCLibrary::SCO_Pure_GetVector2DGreaterEqualFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV >= FSV);
}

bool USCLibrary::SCO_Pure_GetVector2DSmallerEqualFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV <= FSV);
}

FVector2D USCLibrary::SCO_Pure_SetVector2DEqualFSV(FVector2D &NV, FSafeVector2D &FSV) {
	NV = FSV.GetValue(); return NV;
}

FVector2D USCLibrary::SCO_Pure_GetVector2DPlusFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV + FSV);
}

FVector2D USCLibrary::SCO_Pure_GetVector2DMinusFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV - FSV);
}

FVector2D USCLibrary::SCO_Pure_GetVector2DTimesFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV * FSV);
}

FVector2D USCLibrary::SCO_Pure_GetVector2DDivideFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV / FSV);
}

FVector2D USCLibrary::SCO_Pure_GetVector2DModFSV(FVector2D &NV, FSafeVector2D &FSV) {
	return (NV % FSV);
}

// FSVector3D

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector3DEqualFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV == SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DNotEqualFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV != SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DGreaterFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV > SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DSmallerFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV < SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DGreaterEqualFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV >= SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DSmallerEqualFSV(FSafeVector3D &FSV, FSafeVector3D &SSV) {
	return (FSV <= SSV);
}

FSafeVector3D USCLibrary::SCO_Pure_SetSafeVector3DEqualFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	FSV = SSV; Output = FSV.GetValue(); return FSV;
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DPlusFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	Output = (FSV + SSV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DMinusFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	Output = (FSV - SSV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DTimesFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	Output = (FSV * SSV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DDivideFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	Output = (FSV / SSV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DModFSV(FSafeVector3D &FSV, FSafeVector3D &SSV, FVector &Output) {
	Output = (FSV % SSV).GetValue(); return FSafeVector3D(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector3DEqualVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV == NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DNotEqualVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV != NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DGreaterVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV > NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DSmallerVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV < NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DGreaterEqualVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV >= NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector3DSmallerEqualVector3D(FSafeVector3D &FSV, FVector &NV) {
	return (FSV <= NV);
}

FSafeVector3D USCLibrary::SCO_Pure_SetSafeVector3DEqualVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	FSV = NV; Output = FSV.GetValue(); return FSV;
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DPlusVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	Output = (FSV + NV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DMinusVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	Output = (FSV - NV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DTimesVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	Output = (FSV * NV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DDivideVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	Output = (FSV / NV).GetValue(); return FSafeVector3D(Output);
}

FSafeVector3D USCLibrary::SCO_Pure_GetSafeVector3DModVector3D(FSafeVector3D &FSV, FVector &NV, FVector &Output) {
	Output = (FSV % NV).GetValue(); return FSafeVector3D(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetVector3DEqualFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV == FSV);
}

bool USCLibrary::SCO_Pure_GetVector3DNotEqualFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV != FSV);
}

bool USCLibrary::SCO_Pure_GetVector3DGreaterFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV > FSV);
}

bool USCLibrary::SCO_Pure_GetVector3DSmallerFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV < FSV);
}

bool USCLibrary::SCO_Pure_GetVector3DGreaterEqualFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV >= FSV);
}

bool USCLibrary::SCO_Pure_GetVector3DSmallerEqualFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV <= FSV);
}

FVector USCLibrary::SCO_Pure_SetVector3DEqualFSV(FVector &NV, FSafeVector3D &FSV) {
	NV = FSV.GetValue(); return NV;
}

FVector USCLibrary::SCO_Pure_GetVector3DPlusFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV + FSV);
}

FVector USCLibrary::SCO_Pure_GetVector3DMinusFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV - FSV);
}

FVector USCLibrary::SCO_Pure_GetVector3DTimesFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV * FSV);
}

FVector USCLibrary::SCO_Pure_GetVector3DDivideFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV / FSV);
}

FVector USCLibrary::SCO_Pure_GetVector3DModFSV(FVector &NV, FSafeVector3D &FSV) {
	return (NV % FSV);
}

// FSVector4D

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector4DEqualFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV == SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DNotEqualFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV != SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DGreaterFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV > SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DSmallerFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV < SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DGreaterEqualFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV >= SSV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DSmallerEqualFSV(FSafeVector4D &FSV, FSafeVector4D &SSV) {
	return (FSV <= SSV);
}

FSafeVector4D USCLibrary::SCO_Pure_SetSafeVector4DEqualFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	FSV = SSV; Output = FSV.GetValue(); return FSV;
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DPlusFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	Output = (FSV + SSV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DMinusFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	Output = (FSV - SSV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DTimesFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	Output = (FSV * SSV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DDivideFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	Output = (FSV / SSV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DModFSV(FSafeVector4D &FSV, FSafeVector4D &SSV, FVector4 &Output) {
	Output = (FSV % SSV).GetValue(); return FSafeVector4D(&Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeVector4DEqualVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV == NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DNotEqualVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV != NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DGreaterVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV > NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DSmallerVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV < NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DGreaterEqualVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV >= NV);
}

bool USCLibrary::SCO_Pure_GetSafeVector4DSmallerEqualVector4D(FSafeVector4D &FSV, FVector4 &NV) {
	return (FSV <= NV);
}

FSafeVector4D USCLibrary::SCO_Pure_SetSafeVector4DEqualVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	FSV = NV; Output = FSV.GetValue(); return FSV;
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DPlusVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	Output = (FSV + NV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DMinusVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	Output = (FSV - NV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DTimesVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	Output = (FSV * NV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DDivideVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	Output = (FSV / NV).GetValue(); return FSafeVector4D(&Output);
}

FSafeVector4D USCLibrary::SCO_Pure_GetSafeVector4DModVector4D(FSafeVector4D &FSV, FVector4 &NV, FVector4 &Output) {
	Output = (FSV % NV).GetValue(); return FSafeVector4D(&Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetVector4DEqualFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV == FSV);
}

bool USCLibrary::SCO_Pure_GetVector4DNotEqualFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV != FSV);
}

bool USCLibrary::SCO_Pure_GetVector4DGreaterFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV > FSV);
}

bool USCLibrary::SCO_Pure_GetVector4DSmallerFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV < FSV);
}

bool USCLibrary::SCO_Pure_GetVector4DGreaterEqualFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV >= FSV);
}

bool USCLibrary::SCO_Pure_GetVector4DSmallerEqualFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV <= FSV);
}

FVector4 USCLibrary::SCO_Pure_SetVector4DEqualFSV(FVector4 &NV, FSafeVector4D &FSV) {
	NV = FSV.GetValue(); return NV;
}

FVector4 USCLibrary::SCO_Pure_GetVector4DPlusFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV + FSV);
}

FVector4 USCLibrary::SCO_Pure_GetVector4DMinusFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV - FSV);
}

FVector4 USCLibrary::SCO_Pure_GetVector4DTimesFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV * FSV);
}

FVector4 USCLibrary::SCO_Pure_GetVector4DDivideFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV / FSV);
}

FVector4 USCLibrary::SCO_Pure_GetVector4DModFSV(FVector4 &NV, FSafeVector4D &FSV) {
	return (NV % FSV);
}

// FSColor

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeColorEqualFSC(FSafeColor &FSC, FSafeColor &SSC) {
	return (FSC == SSC);
}

bool USCLibrary::SCO_Pure_GetSafeColorNotEqualFSC(FSafeColor &FSC, FSafeColor &SSC) {
	return (FSC != SSC);
}

FSafeColor USCLibrary::SCO_Pure_SetSafeColorEqualFSC(FSafeColor &FSC, FSafeColor &SSC, FLinearColor &Output) {
	FSC = SSC; Output = FSC.GetValue(); return FSC;
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeColorEqualColor(FSafeColor &FSC, FLinearColor &NC) {
	return (FSC == NC);
}

bool USCLibrary::SCO_Pure_GetSafeColorNotEqualColor(FSafeColor &FSC, FLinearColor &NC) {
	return (FSC != NC);
}

FSafeColor USCLibrary::SCO_Pure_SetSafeColorEqualColor(FSafeColor &FSC, FLinearColor &NC, FLinearColor &Output) {
	FSC = NC; Output = FSC.GetValue(); return FSC;
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetColorEqualFSC(FLinearColor &NC, FSafeColor &FSC) {
	return (NC == FSC);
}

bool USCLibrary::SCO_Pure_GetColorNotEqualFSC(FLinearColor &NC, FSafeColor &FSC) {
	return (NC != FSC);
}

FLinearColor USCLibrary::SCO_Pure_SetColorEqualFSC(FLinearColor &NC, FSafeColor &FSC) {
	NC = FSC.GetValue(); return NC;
}

// FSRotator

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeRotatorEqualFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR == SSR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorNotEqualFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR != SSR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorGreaterFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR > SSR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorSmallerFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR < SSR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorGreaterEqualFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR >= SSR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorSmallerEqualFSR(FSafeRotator &FSR, FSafeRotator &SSR) {
	return (FSR <= SSR);
}

FSafeRotator USCLibrary::SCO_Pure_SetSafeRotatorEqualFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	FSR = SSR; Output = FSR.GetValue(); return FSR;
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorPlusFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	Output = (FSR + SSR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorMinusFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	Output = (FSR - SSR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorTimesFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	Output = (FSR * SSR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorDivideFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	Output = (FSR / SSR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorModFSR(FSafeRotator &FSR, FSafeRotator &SSR, FRotator &Output) {
	Output = (FSR % SSR).GetValue(); return FSafeRotator(Output);
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeRotatorEqualRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR == NR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorNotEqualRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR != NR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorGreaterRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR > NR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorSmallerRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR < NR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorGreaterEqualRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR >= NR);
}

bool USCLibrary::SCO_Pure_GetSafeRotatorSmallerEqualRotator(FSafeRotator &FSR, FRotator &NR) {
	return (FSR <= NR);
}

FSafeRotator USCLibrary::SCO_Pure_SetSafeRotatorEqualRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	FSR = NR; Output = FSR.GetValue(); return FSR;
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorPlusRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	Output = (FSR + NR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorMinusRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	Output = (FSR - NR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorTimesRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	Output = (FSR * NR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorDivideRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	Output = (FSR / NR).GetValue(); return FSafeRotator(Output);
}

FSafeRotator USCLibrary::SCO_Pure_GetSafeRotatorModRotator(FSafeRotator &FSR, FRotator &NR, FRotator &Output) {
	Output = (FSR % NR).GetValue(); return FSafeRotator(Output);
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetRotatorEqualFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR == FSR);
}

bool USCLibrary::SCO_Pure_GetRotatorNotEqualFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR != FSR);
}

bool USCLibrary::SCO_Pure_GetRotatorGreaterFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR > FSR);
}

bool USCLibrary::SCO_Pure_GetRotatorSmallerFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR < FSR);
}

bool USCLibrary::SCO_Pure_GetRotatorGreaterEqualFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR >= FSR);
}

bool USCLibrary::SCO_Pure_GetRotatorSmallerEqualFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR <= FSR);
}

FRotator USCLibrary::SCO_Pure_SetRotatorEqualFSR(FRotator &NR, FSafeRotator &FSR) {
	NR = FSR.GetValue(); return NR;
}

FRotator USCLibrary::SCO_Pure_GetRotatorPlusFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR + FSR);
}

FRotator USCLibrary::SCO_Pure_GetRotatorMinusFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR - FSR);
}

FRotator USCLibrary::SCO_Pure_GetRotatorTimesFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR * FSR);
}

FRotator USCLibrary::SCO_Pure_GetRotatorDivideFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR / FSR);
}

FRotator USCLibrary::SCO_Pure_GetRotatorModFSR(FRotator &NR, FSafeRotator &FSR) {
	return (NR % FSR);
}

// FSTransform

/* FSafe -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeTransformEqualFST(FSafeTransform &FST, FSafeTransform &SST) {
	return (FST == SST);
}

bool USCLibrary::SCO_Pure_GetSafeTransformNotEqualFST(FSafeTransform &FST, FSafeTransform &SST) {
	return (FST != SST);
}

FSafeTransform USCLibrary::SCO_Pure_SetSafeTransformEqualFST(FSafeTransform &FST, FSafeTransform &SST, FTransform &Output) {
	FST = SST; Output = FST.GetValue(); return FST;
}

/* Native -> FSafe */

bool USCLibrary::SCO_Pure_GetSafeTransformEqualTransform(FSafeTransform &FST, FTransform &NT) {
	return (FST == NT);
}

bool USCLibrary::SCO_Pure_GetSafeTransformNotEqualTransform(FSafeTransform &FST, FTransform &NT) {
	return (FST != NT);
}

FSafeTransform USCLibrary::SCO_Pure_SetSafeTransformEqualTransform(FSafeTransform &FST, FTransform &NT, FTransform &Output) {
	FST = NT; Output = FST.GetValue(); return FST;
}

/* FSafe -> Native */

bool USCLibrary::SCO_Pure_GetTransformEqualFST(FTransform &NT, FSafeTransform &FST) {
	return (NT == FST);
}

bool USCLibrary::SCO_Pure_GetTransformNotEqualFST(FTransform &NT, FSafeTransform &FST) {
	return (NT != FST);
}

FTransform USCLibrary::SCO_Pure_SetTransformEqualFST(FTransform &NT, FSafeTransform &FST) {
	NT = FST.GetValue(); return NT;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////