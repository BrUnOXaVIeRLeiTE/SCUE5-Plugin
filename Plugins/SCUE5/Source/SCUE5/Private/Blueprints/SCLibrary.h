///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//		Copyright 2016 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SCUE5.h"
#include "Runtime/CoreUObject/Public/UObject/TextProperty.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "SCLibrary.generated.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class SCUE5_API USCLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
public:

	/** Pure:: Gets hidden value from 'Safe Bool Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Pure_GetSafeBool(UPARAM(Ref)FSafeBool &SB);
	//
	/** Pure:: Gets hidden value from 'Safe Bool Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Pure_GetSafeBoolWithKey(UPARAM(Ref)FSafeBool &SB, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Bool Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Pure_SetSafeBool(UPARAM(Ref)FSafeBool &SB, const bool Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Bool Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Pure_SetSafeBoolWithKey(UPARAM(Ref)FSafeBool &SB, FString Key, const bool Value);

	//

	/** Pure:: Gets hidden value from 'Safe Int Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Pure_GetSafeInt(UPARAM(Ref)FSafeInt &SI);
	//
	/**	Pure:: Gets hidden value from 'Safe Int Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Pure_GetSafeIntWithKey(UPARAM(Ref)FSafeInt &SI, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Int Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Pure_SetSafeInt(UPARAM(Ref)FSafeInt &SI, const int32 Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Int Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Pure_SetSafeIntWithKey(UPARAM(Ref)FSafeInt &SI, FString Key, const int32 Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Byte Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Pure_GetSafeByte(UPARAM(Ref)FSafeByte &SB);
	//
	/**	Pure:: Gets hidden value from 'Safe Byte Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Pure_GetSafeByteWithKey(UPARAM(Ref)FSafeByte &SB, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Byte Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Pure_SetSafeByte(UPARAM(Ref)FSafeByte &SB, const uint8 Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Byte Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Pure_SetSafeByteWithKey(UPARAM(Ref)FSafeByte &SB, FString Key, const uint8 Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Float Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Pure_GetSafeFloat(UPARAM(Ref)FSafeFloat &SF);
	//
	/**	Pure:: Gets hidden value from 'Safe Float Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Pure_GetSafeFloatWithKey(UPARAM(Ref)FSafeFloat &SF, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Float Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Pure_SetSafeFloat(UPARAM(Ref)FSafeFloat &SF, const float Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Float Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Pure_SetSafeFloatWithKey(UPARAM(Ref)FSafeFloat &SF, FString Key, const float Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Name Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Pure_GetSafeName(UPARAM(Ref)FSafeName &SN);
	//
	/**	Pure:: Gets hidden value from 'Safe Name Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Pure_GetSafeNameWithKey(UPARAM(Ref)FSafeName &SN, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Name Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Pure_SetSafeName(UPARAM(Ref)FSafeName &SN, const FName Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Name Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Pure_SetSafeNameWithKey(UPARAM(Ref)FSafeName &SN, FString Key, const FName Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe String Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Pure_GetSafeString(UPARAM(Ref)FSafeString &SS);
	//
	/**	Pure:: Gets hidden value from 'Safe String Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Pure_GetSafeStringWithKey(UPARAM(Ref)FSafeString &SS, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe String Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Pure_SetSafeString(UPARAM(Ref)FSafeString &SS, const FString Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe String Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Pure_SetSafeStringWithKey(UPARAM(Ref)FSafeString &SS, FString Key, const FString Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Text Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Pure_GetSafeText(UPARAM(Ref)FSafeText &ST);
	//
	/**	Pure:: Gets hidden value from 'Safe Text Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Pure_GetSafeTextWithKey(UPARAM(Ref)FSafeText &ST, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Text Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Pure_SetSafeText(UPARAM(Ref)FSafeText &ST, const FText Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Text Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Pure_SetSafeTextWithKey(UPARAM(Ref)FSafeText &ST, FString Key, const FText Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Vector2D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Pure_GetSafeVector2D(UPARAM(Ref)FSafeVector2D &SV);
	//
	/**	Pure:: Gets hidden value from 'Safe Vector2D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Pure_GetSafeVector2DWithKey(UPARAM(Ref)FSafeVector2D &SV, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Vector2D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Pure_SetSafeVector2D(UPARAM(Ref)FSafeVector2D &SV, const FVector2D Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Vector2D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Pure_SetSafeVector2DWithKey(UPARAM(Ref)FSafeVector2D &SV, FString Key, const FVector2D Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Vector3D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Pure_GetSafeVector3D(UPARAM(Ref)FSafeVector3D &SV);
	//
	/**	Pure:: Gets hidden value from 'Safe Vector3D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Pure_GetSafeVector3DWithKey(UPARAM(Ref)FSafeVector3D &SV, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Vector3D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Pure_SetSafeVector3D(UPARAM(Ref)FSafeVector3D &SV, const FVector Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Vector3D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Pure_SetSafeVector3DWithKey(UPARAM(Ref)FSafeVector3D &SV, FString Key, const FVector Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Vector4D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Pure_GetSafeVector4D(UPARAM(Ref)FSafeVector4D &SV);
	//
	/**	Pure:: Gets hidden value from 'Safe Vector4D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Pure_GetSafeVector4DWithKey(UPARAM(Ref)FSafeVector4D &SV, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Vector4D Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Pure_SetSafeVector4D(UPARAM(Ref)FSafeVector4D &SV, UPARAM(Ref)FVector4 &Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Vector4D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Pure_SetSafeVector4DWithKey(UPARAM(Ref)FSafeVector4D &SV, FString Key, UPARAM(Ref)FVector4 &Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Color Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Pure_GetSafeColor(UPARAM(Ref)FSafeColor &SC);
	//
	/**	Pure:: Gets hidden value from 'Safe Color Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Pure_GetSafeColorWithKey(UPARAM(Ref)FSafeColor &SC, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Color Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Pure_SetSafeColor(UPARAM(Ref)FSafeColor &SC, UPARAM(Ref)FLinearColor& Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Color Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Pure_SetSafeColorWithKey(UPARAM(Ref)FSafeColor &SC, FString Key, UPARAM(Ref)FLinearColor& Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Rotator Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Pure_GetSafeRotator(UPARAM(Ref)FSafeRotator &SR);
	//
	/**	Pure:: Gets hidden value from 'Safe Rotator Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Pure_GetSafeRotatorWithKey(UPARAM(Ref)FSafeRotator &SR, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Rotator Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Pure_SetSafeRotator(UPARAM(Ref)FSafeRotator &SR, const FRotator Value);
	//
	/**	Pure:: Sets, and hides in memory, value for 'Safe Rotator Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Pure_SetSafeRotatorWithKey(UPARAM(Ref)FSafeRotator &SR, FString Key, const FRotator Value);

	//
	
	/** Pure:: Gets hidden value from 'Safe Transform Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Pure_GetSafeTransform(UPARAM(Ref)FSafeTransform &ST);
	//
	/** Pure:: Gets hidden value from 'Safe Transform Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Get Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Pure_GetSafeTransformWithKey(UPARAM(Ref)FSafeTransform &ST, FString Key);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Transform Struct'. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Pure_SetSafeTransform(UPARAM(Ref)FSafeTransform &ST, UPARAM(Ref)FTransform &Value);
	//
	/** Pure:: Sets, and hides in memory, value for 'Safe Transform Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintPure, Category = "Security", meta = (DisplayName = "Set Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Pure_SetSafeTransformWithKey(UPARAM(Ref)FSafeTransform &ST, FString Key, UPARAM(Ref)FTransform &Value);

	//
	//
	
	/** Callable:: Gets raw value from 'Safe Bool Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Bool (Raw Value)", Keywords = "Security Get Safe Bool"))
	static FString SCL_Callable_GetRawSafeBool(UPARAM(Ref)FSafeBool &SB);
	//
	/** Callable:: Gets hidden value from 'Safe Bool Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Callable_GetSafeBool(UPARAM(Ref)FSafeBool &SB);
	//
	/**	Callable:: Gets hidden value from 'Safe Bool Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Callable_GetSafeBoolWithKey(UPARAM(Ref)FSafeBool &SB, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Bool Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Bool (Raw Value)", Keywords = "Security Get Safe Bool"))
	static bool SCL_Callable_SetRawSafeBool(UPARAM(Ref)FSafeBool &SB, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Bool Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Callable_SetSafeBool(UPARAM(Ref)FSafeBool &SB, const bool Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Bool Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Bool", Keywords = "Security Get Safe Bool"))
	static bool SCL_Callable_SetSafeBoolWithKey(UPARAM(Ref)FSafeBool &SB, FString Key, const bool Value);

	//

	/** Callable:: Gets raw value from 'Safe Int Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Int (Raw Value)", Keywords = "Security Get Safe Int"))
	static FString SCL_Callable_GetRawSafeInt(UPARAM(Ref)FSafeInt &SI);
	//
	/** Callable:: Gets hidden value from 'Safe Int Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Callable_GetSafeInt(UPARAM(Ref)FSafeInt &SI);
	//
	/**	Gets hidden value from 'Safe Int Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Callable_GetSafeIntWithKey(UPARAM(Ref)FSafeInt &SI, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Int Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Int (Raw Value)", Keywords = "Security Get Safe Int"))
	static int32 SCL_Callable_SetRawSafeInt(UPARAM(Ref)FSafeInt &SI, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Int Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Callable_SetSafeInt(UPARAM(Ref)FSafeInt &SI, const int32 Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Int Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Int", Keywords = "Security Get Safe Int"))
	static int32 SCL_Callable_SetSafeIntWithKey(UPARAM(Ref)FSafeInt &SI, FString Key, const int32 Value);

	//
	
	/** Callable:: Gets raw value from 'Safe Byte Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Byte (Raw Value)", Keywords = "Security Get Safe Byte"))
	static FString SCL_Callable_GetRawSafeByte(UPARAM(Ref)FSafeByte &SB);
	//
	/** Callable:: Gets hidden value from 'Safe Byte Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Callable_GetSafeByte(UPARAM(Ref)FSafeByte &SB);
	//
	/**	Gets hidden value from 'Safe Byte Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Callable_GetSafeByteWithKey(UPARAM(Ref)FSafeByte &SB, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Byte Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Byte (Raw Value)", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Callable_SetRawSafeByte(UPARAM(Ref)FSafeByte &SB, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Byte Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Callable_SetSafeByte(UPARAM(Ref)FSafeByte &SB, const uint8 Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Byte Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Byte", Keywords = "Security Get Safe Byte"))
	static uint8 SCL_Callable_SetSafeByteWithKey(UPARAM(Ref)FSafeByte &SB, FString Key, const uint8 Value);

	//
	
	/** Callable:: Gets raw value from 'Safe Float Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Float (Raw Value)", Keywords = "Security Get Safe Float"))
	static FString SCL_Callable_GetRawSafeFloat(UPARAM(Ref)FSafeFloat &SF);
	//
	/** Callable:: Gets hidden value from 'Safe Float Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Callable_GetSafeFloat(UPARAM(Ref)FSafeFloat &SF);
	//
	/**	Callable:: Gets hidden value from 'Safe Float Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Callable_GetSafeFloatWithKey(UPARAM(Ref)FSafeFloat &SF, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Float Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Float (Raw Value)", Keywords = "Security Get Safe Float"))
	static float SCL_Callable_SetRawSafeFloat(UPARAM(Ref)FSafeFloat &SF, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Float Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Callable_SetSafeFloat(UPARAM(Ref)FSafeFloat &SF, const float Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Float Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Float", Keywords = "Security Get Safe Float"))
	static float SCL_Callable_SetSafeFloatWithKey(UPARAM(Ref)FSafeFloat &SF, FString Key, const float Value);

	//
	
	/** Callable:: Gets raw value from 'Safe Name Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Name (Raw Value)", Keywords = "Security Get Safe Name"))
	static FString SCL_Callable_GetRawSafeName(UPARAM(Ref)FSafeName &SN);
	//
	/** Callable:: Gets hidden value from 'Safe Name Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Callable_GetSafeName(UPARAM(Ref)FSafeName &SN);
	//
	/**	Callable:: Gets hidden value from 'Safe Name Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Callable_GetSafeNameWithKey(UPARAM(Ref)FSafeName &SN, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Name Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Name (Raw Value)", Keywords = "Security Get Safe Name"))
	static FName SCL_Callable_SetRawSafeName(UPARAM(Ref)FSafeName &SN, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Name Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Callable_SetSafeName(UPARAM(Ref)FSafeName &SN, const FName Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Name Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Name", Keywords = "Security Get Safe Name"))
	static FName SCL_Callable_SetSafeNameWithKey(UPARAM(Ref)FSafeName &SN, FString Key, const FName Value);

	//
	
	/** Callable:: Gets raw value from 'Safe String Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe String (Raw Value)", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_GetRawSafeString(UPARAM(Ref)FSafeString &SS);
	//
	/** Callable:: Gets hidden value from 'Safe String Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_GetSafeString(UPARAM(Ref)FSafeString &SS);
	//
	/**	Callable:: Gets hidden value from 'Safe String Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_GetSafeStringWithKey(UPARAM(Ref)FSafeString &SS, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe String Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe String (Raw Value)", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_SetRawSafeString(UPARAM(Ref)FSafeString &SS, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe String Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_SetSafeString(UPARAM(Ref)FSafeString &SS, FString Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe String Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe String", Keywords = "Security Get Safe String"))
	static FString SCL_Callable_SetSafeStringWithKey(UPARAM(Ref)FSafeString &SS, FString Key, FString Value);

	//
	
	/** Callable:: Gets raw value from 'Safe Text Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Text (Raw Value)", Keywords = "Security Get Safe Text"))
	static FString SCL_Callable_GetRawSafeText(UPARAM(Ref)FSafeText &ST);
	//
	/** Callable:: Gets hidden value from 'Safe Text Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Callable_GetSafeText(UPARAM(Ref)FSafeText &ST);
	//
	/**	Callable:: Gets hidden value from 'Safe Text Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Callable_GetSafeTextWithKey(UPARAM(Ref)FSafeText &ST, FString Key);
	//
	/** Callable:: Sets, and hides in memory, raw value for 'Safe Text Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Text (Raw Value)", Keywords = "Security Get Safe Text"))
	static FText SCL_Callable_SetRawSafeText(UPARAM(Ref)FSafeText &ST, FString Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Text Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Callable_SetSafeText(UPARAM(Ref)FSafeText &ST, const FText Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Text Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Text", Keywords = "Security Get Safe Text"))
	static FText SCL_Callable_SetSafeTextWithKey(UPARAM(Ref)FSafeText &ST, FString Key, const FText Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Vector2D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Callable_GetSafeVector2D(UPARAM(Ref)FSafeVector2D &SV);
	//
	/**	Callable:: Gets hidden value from 'Safe Vector2D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Callable_GetSafeVector2DWithKey(UPARAM(Ref)FSafeVector2D &SV, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Vector2D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Callable_SetSafeVector2D(UPARAM(Ref)FSafeVector2D &SV, const FVector2D Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Vector2D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector2D", Keywords = "Security Get Safe Vector2D"))
	static FVector2D SCL_Callable_SetSafeVector2DWithKey(UPARAM(Ref)FSafeVector2D &SV, FString Key, const FVector2D Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Vector3D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Callable_GetSafeVector3D(UPARAM(Ref)FSafeVector3D &SV);
	//
	/**	Callable:: Gets hidden value from 'Safe Vector3D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Callable_GetSafeVector3DWithKey(UPARAM(Ref)FSafeVector3D &SV, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Vector3D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Callable_SetSafeVector3D(UPARAM(Ref)FSafeVector3D &SV, const FVector Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Vector3D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector3D", Keywords = "Security Get Safe Vector3D"))
	static FVector SCL_Callable_SetSafeVector3DWithKey(UPARAM(Ref)FSafeVector3D &SV, FString Key, const FVector Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Vector4D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Callable_GetSafeVector4D(UPARAM(Ref)FSafeVector4D &SV);
	//
	/**	Callable:: Gets hidden value from 'Safe Vector4D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Callable_GetSafeVector4DWithKey(UPARAM(Ref)FSafeVector4D &SV, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Vector4D Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Callable_SetSafeVector4D(UPARAM(Ref)FSafeVector4D &SV, UPARAM(Ref)FVector4& Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Vector4D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Vector4D", Keywords = "Security Get Safe Vector4D"))
	static FVector4 SCL_Callable_SetSafeVector4DWithKey(UPARAM(Ref)FSafeVector4D &SV, FString Key, UPARAM(Ref)FVector4& Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Rotator Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Callable_GetSafeRotator(UPARAM(Ref)FSafeRotator &SR);
	//
	/**	Callable:: Gets hidden value from 'Safe Vector4D Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Callable_GetSafeRotatorWithKey(UPARAM(Ref)FSafeRotator &SR, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Rotator Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Callable_SetSafeRotator(UPARAM(Ref)FSafeRotator &SR, const FRotator Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Rotator Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Rotator", Keywords = "Security Get Safe Rotator"))
	static FRotator SCL_Callable_SetSafeRotatorWithKey(UPARAM(Ref)FSafeRotator &SR, FString Key, const FRotator Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Color Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Callable_GetSafeColor(UPARAM(Ref)FSafeColor &SC);
	//
	/**	Callable:: Gets hidden value from 'Safe Color Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Callable_GetSafeColorWithKey(UPARAM(Ref)FSafeColor &SC, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Color Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Callable_SetSafeColor(UPARAM(Ref)FSafeColor &SC, UPARAM(Ref)FLinearColor& Value);
	//
	/**	Callable:: Sets, and hides in memory, value for 'Safe Color Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Color", Keywords = "Security Get Safe Color"))
	static FLinearColor SCL_Callable_SetSafeColorWithKey(UPARAM(Ref)FSafeColor &SC, FString Key, UPARAM(Ref)FLinearColor& Value);

	//
	
	/** Callable:: Gets hidden value from 'Safe Transform Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Callable_GetSafeTransform(UPARAM(Ref)FSafeTransform &ST);
	//
	/** Callable:: Gets hidden value from 'Safe Transform Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Get Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Callable_GetSafeTransformWithKey(UPARAM(Ref)FSafeTransform &ST, FString Key);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Transform Struct'. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Callable_SetSafeTransform(UPARAM(Ref)FSafeTransform &ST, UPARAM(Ref)FTransform &Value);
	//
	/** Callable:: Sets, and hides in memory, value for 'Safe Transform Struct'.
	Custom Key Required: If have custom encryption Key, attach to Key input value. */
	UFUNCTION(BlueprintCallable, Category = "Security", meta = (DisplayName = "Set Safe Transform", Keywords = "Security Get Safe Transform"))
	static FTransform SCL_Callable_SetSafeTransformWithKey(UPARAM(Ref)FSafeTransform &ST, FString Key, UPARAM(Ref)FTransform &Value);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// FSBool

	/* FSafe -> FSafe */

	/** Set:: Safe Bool = Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Bool)", CompactNodeTitle = "=", Keywords = "Security Set Safe Bool EQUAL ="))
	static FSafeBool SCO_Pure_SetSafeBoolEqualFSB(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)FSafeBool &SSB, bool &Output);

	/** Get:: Safe Bool == Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Bool)", CompactNodeTitle = "==", Keywords = "Security Get Safe Bool EQUAL =="))
	static FSafeBool SCO_Pure_GetSafeBoolEqualFSB(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)FSafeBool &SSB, bool &Output);

	/** Get:: Safe Bool != Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Bool)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Bool NOT !="))
	static FSafeBool SCO_Pure_GetSafeBoolNotEqualFSB(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)FSafeBool &SSB, bool &Output);

	/** Get:: Safe Bool && Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "&& (Safe Bool)", CompactNodeTitle = "&&", Keywords = "Security Get Safe Bool AND &&"))
	static FSafeBool SCO_Pure_GetSafeBoolAndFSB(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)FSafeBool &SSB, bool &Output);

	/** Get:: Safe Bool || Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "|| (Safe Bool)", CompactNodeTitle = "||", Keywords = "Security Get Safe Bool OR ||"))
	static FSafeBool SCO_Pure_GetSafeBoolOrFSB(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)FSafeBool &SSB, bool &Output);
	
	/* Native -> FSafe */

	/** Set:: Safe Bool = Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Bool)", CompactNodeTitle = "=", Keywords = "Security Set Safe Bool EQUAL ="))
	static FSafeBool SCO_Pure_SetSafeBoolEqualBool(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)bool &NB, bool &Output);

	/** Get:: Safe Bool == Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Bool)", CompactNodeTitle = "==", Keywords = "Security Get Safe Bool EQUAL =="))
	static FSafeBool SCO_Pure_GetSafeBoolEqualBool(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)bool &NB, bool &Output);

	/** Get:: Safe Bool != Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Bool)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Bool NOT !="))
	static FSafeBool SCO_Pure_GetSafeBoolNotEqualBool(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)bool &NB, bool &Output);

	/** Get:: Safe Bool && Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "&& (Bool)", CompactNodeTitle = "&&", Keywords = "Security Get Safe Bool AND &&"))
	static FSafeBool SCO_Pure_GetSafeBoolAndBool(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)bool &NB, bool &Output);

	/** Get:: Safe Bool || Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "|| (Bool)", CompactNodeTitle = "||", Keywords = "Security Get Safe Bool OR ||"))
	static FSafeBool SCO_Pure_GetSafeBoolOrBool(UPARAM(Ref)FSafeBool &FSB, UPARAM(Ref)bool &NB, bool &Output);
	
	/* FSafe -> Native */

	/** Set:: Bool = Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Bool)", CompactNodeTitle = "=", Keywords = "Security Set Safe Bool EQUAL ="))
	static bool SCO_Pure_SetBoolEqualFSB(UPARAM(Ref)bool &NB, UPARAM(Ref)FSafeBool &FSB);

	/** Get:: Bool == Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Bool)", CompactNodeTitle = "==", Keywords = "Security Get Safe Bool EQUAL =="))
	static bool SCO_Pure_GetBoolEqualFSB(UPARAM(Ref)bool &NB, UPARAM(Ref)FSafeBool &FSB);

	/** Get:: Bool != Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Bool)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Bool NOT !="))
	static bool SCO_Pure_GetBoolNotEqualFSB(UPARAM(Ref)bool &NB, UPARAM(Ref)FSafeBool &FSB);

	/** Get:: Bool && Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "&& (Safe Bool)", CompactNodeTitle = "&&", Keywords = "Security Get Safe Bool AND &&"))
	static bool SCO_Pure_GetBoolAndFSB(UPARAM(Ref)bool &NB, UPARAM(Ref)FSafeBool &FSB);

	/** Get:: Bool || Safe Bool */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "|| (Safe Bool)", CompactNodeTitle = "||", Keywords = "Security Get Safe Bool OR ||"))
	static bool SCO_Pure_GetBoolOrFSB(UPARAM(Ref)bool &NB, UPARAM(Ref)FSafeBool &FSB);

	// FSByte

	/* FSafe -> FSafe */

	/** Get:: Safe Byte == Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Byte)", CompactNodeTitle = "==", Keywords = "Security Get Safe Byte EQUAL =="))
	static bool SCO_Pure_GetSafeByteEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Get:: Safe Byte != Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Byte)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Byte NOT !="))
	static bool SCO_Pure_GetSafeByteNotEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Get:: Safe Byte > Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Byte)", CompactNodeTitle = ">", Keywords = "Security Get Safe Byte GREATER >"))
	static bool SCO_Pure_GetSafeByteGreaterFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Get:: Safe Byte < Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Byte)", CompactNodeTitle = "<", Keywords = "Security Get Safe Byte LESS <"))
	static bool SCO_Pure_GetSafeByteSmallerFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Get:: Safe Byte >= Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Byte)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Byte GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeByteGreaterEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Get:: Safe Byte <= Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Byte)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Byte LESS EQUAL <="))
	static bool SCO_Pure_GetSafeByteSmallerEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB);

	/** Set:: Safe Byte = Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Byte)", CompactNodeTitle = "=", Keywords = "Security Set Safe Byte EQUAL ="))
	static FSafeByte SCO_Pure_SetSafeByteEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte + Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Byte)", CompactNodeTitle = "+", Keywords = "Security Get Safe Byte PLUS +"))
	static FSafeByte SCO_Pure_GetSafeBytePlusFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte - Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Byte)", CompactNodeTitle = "-", Keywords = "Security Get Safe Byte MINUS -"))
	static FSafeByte SCO_Pure_GetSafeByteMinusFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte * Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Byte)", CompactNodeTitle = "*", Keywords = "Security Get Safe Byte TIMES *"))
	static FSafeByte SCO_Pure_GetSafeByteTimesFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte / Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Byte)", CompactNodeTitle = "/", Keywords = "Security Get Safe Byte DIVIDE /"))
	static FSafeByte SCO_Pure_GetSafeByteDivideFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte ++ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "++ (Safe Byte)", CompactNodeTitle = "++", Keywords = "Security Get Safe Byte ADD PLUS ++"))
	static FSafeByte SCO_Pure_GetSafeByteIncreaseFSB(UPARAM(Ref)FSafeByte &FSB, uint8 &Output);

	/** Get:: Safe Byte -- */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-- (Safe Byte)", CompactNodeTitle = "--", Keywords = "Security Get Safe Byte LESS --"))
	static FSafeByte SCO_Pure_GetSafeByteDecreaseFSB(UPARAM(Ref)FSafeByte &FSB, uint8 &Output);

	/** Get:: Safe Byte += Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Safe Byte)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Byte PLUS EQUAL +="))
	static FSafeByte SCO_Pure_GetSafeBytePlusEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte -= Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Safe Byte)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Byte MINUS EQUAL -="))
	static FSafeByte SCO_Pure_GetSafeByteMinusEqualFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte ~ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "~ (Safe Byte)", CompactNodeTitle = "~", Keywords = "Security Get Safe Byte NOT ~"))
	static FSafeByte SCO_Pure_GetSafeByteNotFSB(UPARAM(Ref)FSafeByte &FSB, uint8 &Output);

	/** Get:: Safe Byte % Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Byte)", CompactNodeTitle = "%", Keywords = "Security Get Safe Byte MOD %"))
	static FSafeByte SCO_Pure_GetSafeByteModFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte & Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Safe Byte)", CompactNodeTitle = "&", Keywords = "Security Get Safe Byte AND &"))
	static FSafeByte SCO_Pure_GetSafeByteAndFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte | Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Safe Byte)", CompactNodeTitle = "|", Keywords = "Security Get Safe Byte OR |"))
	static FSafeByte SCO_Pure_GetSafeByteOrFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte ^ Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Safe Byte)", CompactNodeTitle = "^", Keywords = "Security Get Safe Byte XOR ^"))
	static FSafeByte SCO_Pure_GetSafeByteXorFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte >> Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Safe Byte)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Byte SHIFT >>"))
	static FSafeByte SCO_Pure_GetSafeByteShiftRFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/** Get:: Safe Byte << Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Safe Byte)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Byte SHIFT <<"))
	static FSafeByte SCO_Pure_GetSafeByteShiftLFSB(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)FSafeByte &SSB, uint8 &Output);

	/* Native -> FSafe */

	/** Get:: Safe Byte == Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Byte)", CompactNodeTitle = "==", Keywords = "Security Get Safe Byte EQUAL =="))
	static bool SCO_Pure_GetSafeByteEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Get:: Safe Byte != Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Byte)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Byte NOT !="))
	static bool SCO_Pure_GetSafeByteNotEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Get:: Safe Byte > Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Byte)", CompactNodeTitle = ">", Keywords = "Security Get Safe Byte GREATER >"))
	static bool SCO_Pure_GetSafeByteGreaterByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Get:: Safe Byte < Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Byte)", CompactNodeTitle = "<", Keywords = "Security Get Safe Byte LESS <"))
	static bool SCO_Pure_GetSafeByteSmallerByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Get:: Safe Byte >= Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Byte)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Byte GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeByteGreaterEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Get:: Safe Byte <= Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Byte)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Byte LESS EQUAL <="))
	static bool SCO_Pure_GetSafeByteSmallerEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB);

	/** Set:: Safe Byte = Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Byte)", CompactNodeTitle = "=", Keywords = "Security Set Safe Byte EQUAL ="))
	static FSafeByte SCO_Pure_SetSafeByteEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte + Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Byte)", CompactNodeTitle = "+", Keywords = "Security Get Safe Byte PLUS +"))
	static FSafeByte SCO_Pure_GetSafeBytePlusByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte - Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Byte)", CompactNodeTitle = "-", Keywords = "Security Get Safe Byte MINUS -"))
	static FSafeByte SCO_Pure_GetSafeByteMinusByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte * Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Byte)", CompactNodeTitle = "*", Keywords = "Security Get Safe Byte TIMES *"))
	static FSafeByte SCO_Pure_GetSafeByteTimesByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte / Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Byte)", CompactNodeTitle = "/", Keywords = "Security Get Safe Byte DIVIDE /"))
	static FSafeByte SCO_Pure_GetSafeByteDivideByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte += Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Byte)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Byte PLUS EQUAL +="))
	static FSafeByte SCO_Pure_GetSafeBytePlusEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte -= Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Byte)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Byte MINUS EQUAL -="))
	static FSafeByte SCO_Pure_GetSafeByteMinusEqualByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte ~ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "~ (Safe Byte)", CompactNodeTitle = "~", Keywords = "Security Get Safe Byte NOT ~"))
	static FSafeByte SCO_Pure_GetSafeByteNotByte(UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte % Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Byte)", CompactNodeTitle = "%", Keywords = "Security Get Safe Byte MOD %"))
	static FSafeByte SCO_Pure_GetSafeByteModByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte & Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Byte)", CompactNodeTitle = "&", Keywords = "Security Get Safe Byte AND &"))
	static FSafeByte SCO_Pure_GetSafeByteAndByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte | Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Byte)", CompactNodeTitle = "|", Keywords = "Security Get Safe Byte OR |"))
	static FSafeByte SCO_Pure_GetSafeByteOrByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte ^ Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Byte)", CompactNodeTitle = "^", Keywords = "Security Get Safe Byte XOR ^"))
	static FSafeByte SCO_Pure_GetSafeByteXorByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte >> Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Byte)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Byte SHIFT >>"))
	static FSafeByte SCO_Pure_GetSafeByteShiftRByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/** Get:: Safe Byte << Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Byte)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Byte SHIFT <<"))
	static FSafeByte SCO_Pure_GetSafeByteShiftLByte(UPARAM(Ref)FSafeByte &FSB, UPARAM(Ref)uint8 &NB, uint8 &Output);

	/* FSafe -> Native */

	/** Get:: Byte == Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Byte)", CompactNodeTitle = "==", Keywords = "Security Get Safe Byte EQUAL =="))
	static bool SCO_Pure_GetByteEqualFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte != Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Byte)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Byte NOT !="))
	static bool SCO_Pure_GetByteNotEqualFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte > Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Byte)", CompactNodeTitle = ">", Keywords = "Security Get Safe Byte GREATER >"))
	static bool SCO_Pure_GetByteGreaterFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte < Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Byte)", CompactNodeTitle = "<", Keywords = "Security Get Safe Byte LESS <"))
	static bool SCO_Pure_GetByteSmallerFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte >= Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Byte)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Byte GREATER EQUAL >="))
	static bool SCO_Pure_GetByteGreaterEqualFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte <= Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Byte)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Byte LESS EQUAL <="))
	static bool SCO_Pure_GetByteSmallerEqualFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Set:: Byte = Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Byte)", CompactNodeTitle = "=", Keywords = "Security Set Safe Byte EQUAL ="))
	static uint8 SCO_Pure_SetByteEqualFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte + Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Byte)", CompactNodeTitle = "+", Keywords = "Security Get Safe Byte PLUS +"))
	static uint8 SCO_Pure_GetBytePlusFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte - Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Byte)", CompactNodeTitle = "-", Keywords = "Security Get Safe Byte MINUS -"))
	static uint8 SCO_Pure_GetByteMinusFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte * Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Byte)", CompactNodeTitle = "*", Keywords = "Security Get Safe Byte TIMES *"))
	static uint8 SCO_Pure_GetByteTimesFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte / Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Byte)", CompactNodeTitle = "/", Keywords = "Security Get Safe Byte DIVIDE /"))
	static uint8 SCO_Pure_GetByteDivideFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);
	
	/** Get:: Byte % Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Byte)", CompactNodeTitle = "%", Keywords = "Security Get Safe Byte MOD %"))
	static uint8 SCO_Pure_GetByteModFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte & Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Safe Byte)", CompactNodeTitle = "&", Keywords = "Security Get Safe Byte AND &"))
	static uint8 SCO_Pure_GetByteAndFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte | Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Safe Byte)", CompactNodeTitle = "|", Keywords = "Security Get Safe Byte OR |"))
	static uint8 SCO_Pure_GetByteOrFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte ^ Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Safe Byte)", CompactNodeTitle = "^", Keywords = "Security Get Safe Byte XOR ^"))
	static uint8 SCO_Pure_GetByteXorFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte >> Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Safe Byte)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Byte SHIFT >>"))
	static uint8 SCO_Pure_GetByteShiftRFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	/** Get:: Byte << Safe Byte */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Safe Byte)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Byte SHIFT <<"))
	static uint8 SCO_Pure_GetByteShiftLFSB(UPARAM(Ref)uint8 &NB, UPARAM(Ref)FSafeByte &FSB);

	// FSInt

	/* FSafe -> FSafe */

	/** Get:: Safe Integer == Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Integer)", CompactNodeTitle = "==", Keywords = "Security Get Safe Integer EQUAL =="))
	static bool SCO_Pure_GetSafeIntEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Get:: Safe Integer != Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Integer)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Integer NOT !="))
	static bool SCO_Pure_GetSafeIntNotEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Get:: Safe Integer > Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Integer)", CompactNodeTitle = ">", Keywords = "Security Get Safe Integer GREATER >"))
	static bool SCO_Pure_GetSafeIntGreaterFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Get:: Safe Integer < Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Integer)", CompactNodeTitle = "<", Keywords = "Security Get Safe Integer LESS <"))
	static bool SCO_Pure_GetSafeIntSmallerFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Get:: Safe Integer >= Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Integer)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Integer GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeIntGreaterEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Get:: Safe Integer <= Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Integer)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Integer LESS EQUAL <="))
	static bool SCO_Pure_GetSafeIntSmallerEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI);

	/** Set:: Safe Integer = Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Integer)", CompactNodeTitle = "=", Keywords = "Security Set Safe Integer EQUAL ="))
	static FSafeInt SCO_Pure_SetSafeIntEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer + Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Integer)", CompactNodeTitle = "+", Keywords = "Security Get Safe Integer PLUS +"))
	static FSafeInt SCO_Pure_GetSafeIntPlusFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer - Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Integer)", CompactNodeTitle = "-", Keywords = "Security Get Safe Integer MINUS -"))
	static FSafeInt SCO_Pure_GetSafeIntMinusFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer * Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Integer)", CompactNodeTitle = "*", Keywords = "Security Get Safe Integer TIMES *"))
	static FSafeInt SCO_Pure_GetSafeIntTimesFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer / Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Integer)", CompactNodeTitle = "/", Keywords = "Security Get Safe Integer DIVIDE /"))
	static FSafeInt SCO_Pure_GetSafeIntDivideFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer ++ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "++ (Safe Integer)", CompactNodeTitle = "++", Keywords = "Security Get Safe Integer ADD PLUS ++"))
	static FSafeInt SCO_Pure_GetSafeIntIncreaseFSI(UPARAM(Ref)FSafeInt &FSI, int32 &Output);

	/** Get:: Safe Integer -- */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-- (Safe Integer)", CompactNodeTitle = "--", Keywords = "Security Get Safe Integer LESS --"))
	static FSafeInt SCO_Pure_GetSafeIntDecreaseFSI(UPARAM(Ref)FSafeInt &FSI, int32 &Output);

	/** Get:: Safe Integer += Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Safe Integer)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Integer PLUS EQUAL +="))
	static FSafeInt SCO_Pure_GetSafeIntPlusEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer -= Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Safe Integer)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Integer MINUS EQUAL -="))
	static FSafeInt SCO_Pure_GetSafeIntMinusEqualFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer ~ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "~ (Safe Integer)", CompactNodeTitle = "~", Keywords = "Security Get Safe Integer NOT ~"))
	static FSafeInt SCO_Pure_GetSafeIntNotFSI(UPARAM(Ref)FSafeInt &FSI, int32 &Output);

	/** Get:: Safe Integer % Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Integer)", CompactNodeTitle = "%", Keywords = "Security Get Safe Integer MOD %"))
	static FSafeInt SCO_Pure_GetSafeIntModFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer & Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Safe Integer)", CompactNodeTitle = "&", Keywords = "Security Get Safe Integer AND &"))
	static FSafeInt SCO_Pure_GetSafeIntAndFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer | Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Safe Integer)", CompactNodeTitle = "|", Keywords = "Security Get Safe Integer OR |"))
	static FSafeInt SCO_Pure_GetSafeIntOrFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer ^ Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Safe Integer)", CompactNodeTitle = "^", Keywords = "Security Get Safe Integer XOR ^"))
	static FSafeInt SCO_Pure_GetSafeIntXorFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer >> Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Safe Integer)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Integer SHIFT >>"))
	static FSafeInt SCO_Pure_GetSafeIntShiftRFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/** Get:: Safe Integer << Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Safe Integer)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Integer SHIFT <<"))
	static FSafeInt SCO_Pure_GetSafeIntShiftLFSI(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)FSafeInt &SSI, int32 &Output);

	/* Native -> FSafe */

	/** Get:: Safe Integer == Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Integer)", CompactNodeTitle = "==", Keywords = "Security Get Safe Integer EQUAL =="))
	static bool SCO_Pure_GetSafeIntEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Get:: Safe Integer != Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Integer)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Integer NOT !="))
	static bool SCO_Pure_GetSafeIntNotEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Get:: Safe Integer > Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Integer)", CompactNodeTitle = ">", Keywords = "Security Get Safe Integer GREATER >"))
	static bool SCO_Pure_GetSafeIntGreaterInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Get:: Safe Integer < Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Integer)", CompactNodeTitle = "<", Keywords = "Security Get Safe Integer LESS <"))
	static bool SCO_Pure_GetSafeIntSmallerInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Get:: Safe Integer >= Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Integer)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Integer GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeIntGreaterEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Get:: Safe Integer <= Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Integer)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Integer LESS EQUAL <="))
	static bool SCO_Pure_GetSafeIntSmallerEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI);

	/** Set:: Safe Integer = Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Integer)", CompactNodeTitle = "=", Keywords = "Security Set Safe Integer EQUAL ="))
	static FSafeInt SCO_Pure_SetSafeIntEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer + Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Integer)", CompactNodeTitle = "+", Keywords = "Security Get Safe Integer PLUS +"))
	static FSafeInt SCO_Pure_GetSafeIntPlusInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer - Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Integer)", CompactNodeTitle = "-", Keywords = "Security Get Safe Integer MINUS -"))
	static FSafeInt SCO_Pure_GetSafeIntMinusInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer * Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Integer)", CompactNodeTitle = "*", Keywords = "Security Get Safe Integer TIMES *"))
	static FSafeInt SCO_Pure_GetSafeIntTimesInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer / Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Integer)", CompactNodeTitle = "/", Keywords = "Security Get Safe Integer DIVIDE /"))
	static FSafeInt SCO_Pure_GetSafeIntDivideInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer += Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Integer)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Integer PLUS EQUAL +="))
	static FSafeInt SCO_Pure_GetSafeIntPlusEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer -= Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Integer)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Integer MINUS EQUAL -="))
	static FSafeInt SCO_Pure_GetSafeIntMinusEqualInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer ~ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "~ (Safe Integer)", CompactNodeTitle = "~", Keywords = "Security Get Safe Integer NOT ~"))
	static FSafeInt SCO_Pure_GetSafeIntNotInt(UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer % Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Integer)", CompactNodeTitle = "%", Keywords = "Security Get Safe Integer MOD %"))
	static FSafeInt SCO_Pure_GetSafeIntModInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer & Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Integer)", CompactNodeTitle = "&", Keywords = "Security Get Safe Integer AND &"))
	static FSafeInt SCO_Pure_GetSafeIntAndInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer | Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Integer)", CompactNodeTitle = "|", Keywords = "Security Get Safe Integer OR |"))
	static FSafeInt SCO_Pure_GetSafeIntOrInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer ^ Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Integer)", CompactNodeTitle = "^", Keywords = "Security Get Safe Integer XOR ^"))
	static FSafeInt SCO_Pure_GetSafeIntXorInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer >> Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Integer)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Integer SHIFT >>"))
	static FSafeInt SCO_Pure_GetSafeIntShiftRInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/** Get:: Safe Integer << Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Integer)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Integer SHIFT <<"))
	static FSafeInt SCO_Pure_GetSafeIntShiftLInt(UPARAM(Ref)FSafeInt &FSI, UPARAM(Ref)int32 &NI, int32 &Output);

	/* FSafe -> Native */

	/** Get:: Integer == Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Integer)", CompactNodeTitle = "==", Keywords = "Security Get Safe Integer EQUAL =="))
	static bool SCO_Pure_GetIntEqualFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer != Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Integer)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Integer NOT !="))
	static bool SCO_Pure_GetIntNotEqualFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer > Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Integer)", CompactNodeTitle = ">", Keywords = "Security Get Safe Integer GREATER >"))
	static bool SCO_Pure_GetIntGreaterFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer < Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Integer)", CompactNodeTitle = "<", Keywords = "Security Get Safe Integer LESS <"))
	static bool SCO_Pure_GetIntSmallerFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer >= Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Integer)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Integer GREATER EQUAL >="))
	static bool SCO_Pure_GetIntGreaterEqualFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer <= Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Integer)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Integer LESS EQUAL <="))
	static bool SCO_Pure_GetIntSmallerEqualFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Set:: Integer = Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Integer)", CompactNodeTitle = "=", Keywords = "Security Set Safe Integer EQUAL ="))
	static int32 SCO_Pure_SetIntEqualFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer + Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Integer)", CompactNodeTitle = "+", Keywords = "Security Get Safe Integer PLUS +"))
	static int32 SCO_Pure_GetIntPlusFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer - Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Integer)", CompactNodeTitle = "-", Keywords = "Security Get Safe Integer MINUS -"))
	static int32 SCO_Pure_GetIntMinusFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer * Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Integer)", CompactNodeTitle = "*", Keywords = "Security Get Safe Integer TIMES *"))
	static int32 SCO_Pure_GetIntTimesFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer / Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Integer)", CompactNodeTitle = "/", Keywords = "Security Get Safe Integer DIVIDE /"))
	static int32 SCO_Pure_GetIntDivideFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer % Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Integer)", CompactNodeTitle = "%", Keywords = "Security Get Safe Integer MOD %"))
	static int32 SCO_Pure_GetIntModFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer & Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "& (Safe Integer)", CompactNodeTitle = "&", Keywords = "Security Get Safe Integer AND &"))
	static int32 SCO_Pure_GetIntAndFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer | Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "| (Safe Integer)", CompactNodeTitle = "|", Keywords = "Security Get Safe Integer OR |"))
	static int32 SCO_Pure_GetIntOrFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer ^ Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "^ (Safe Integer)", CompactNodeTitle = "^", Keywords = "Security Get Safe Integer XOR ^"))
	static int32 SCO_Pure_GetIntXorFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer >> Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">> (Safe Integer)", CompactNodeTitle = ">>", Keywords = "Security Get Safe Integer SHIFT >>"))
	static int32 SCO_Pure_GetIntShiftRFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	/** Get:: Integer << Safe Integer */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<< (Safe Integer)", CompactNodeTitle = "<<", Keywords = "Security Get Safe Integer SHIFT <<"))
	static int32 SCO_Pure_GetIntShiftLFSI(UPARAM(Ref)int32 &NI, UPARAM(Ref)FSafeInt &FSI);

	// FSFloat

	/* FSafe -> FSafe */

	/** Get:: Safe Float == Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Float)", CompactNodeTitle = "==", Keywords = "Security Get Safe Float EQUAL =="))
	static bool SCO_Pure_GetSafeFloatEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Get:: Safe Float != Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Float)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Float NOT !="))
	static bool SCO_Pure_GetSafeFloatNotEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Get:: Safe Float > Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Float)", CompactNodeTitle = ">", Keywords = "Security Get Safe Float GREATER >"))
	static bool SCO_Pure_GetSafeFloatGreaterFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Get:: Safe Float < Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Float)", CompactNodeTitle = "<", Keywords = "Security Get Safe Float LESS <"))
	static bool SCO_Pure_GetSafeFloatSmallerFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Get:: Safe Float >= Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Float)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Float GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeFloatGreaterEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Get:: Safe Float <= Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Float)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Float LESS EQUAL <="))
	static bool SCO_Pure_GetSafeFloatSmallerEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF);

	/** Set:: Safe Float = Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Float)", CompactNodeTitle = "=", Keywords = "Security Set Safe Float EQUAL ="))
	static FSafeFloat SCO_Pure_SetSafeFloatEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float + Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Float)", CompactNodeTitle = "+", Keywords = "Security Get Safe Float PLUS +"))
	static FSafeFloat SCO_Pure_GetSafeFloatPlusFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float - Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Float)", CompactNodeTitle = "-", Keywords = "Security Get Safe Float MINUS -"))
	static FSafeFloat SCO_Pure_GetSafeFloatMinusFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float * Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Float)", CompactNodeTitle = "*", Keywords = "Security Get Safe Float TIMES *"))
	static FSafeFloat SCO_Pure_GetSafeFloatTimesFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float / Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Float)", CompactNodeTitle = "/", Keywords = "Security Get Safe Float DIVIDE /"))
	static FSafeFloat SCO_Pure_GetSafeFloatDivideFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float ++ */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "++ (Safe Float)", CompactNodeTitle = "++", Keywords = "Security Get Safe Float ADD PLUS ++"))
	static FSafeFloat SCO_Pure_GetSafeFloatIncreaseFSF(UPARAM(Ref)FSafeFloat &FSF, float &Output);

	/** Get:: Safe Float -- */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-- (Safe Float)", CompactNodeTitle = "--", Keywords = "Security Get Safe Float LESS --"))
	static FSafeFloat SCO_Pure_GetSafeFloatDecreaseFSF(UPARAM(Ref)FSafeFloat &FSF, float &Output);

	/** Get:: Safe Float += Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Safe Float)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Float PLUS EQUAL +="))
	static FSafeFloat SCO_Pure_GetSafeFloatPlusEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float -= Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Safe Float)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Float MINUS EQUAL -="))
	static FSafeFloat SCO_Pure_GetSafeFloatMinusEqualFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/** Get:: Safe Float % Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Float)", CompactNodeTitle = "%", Keywords = "Security Get Safe Float MOD %"))
	static FSafeFloat SCO_Pure_GetSafeFloatModFSF(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)FSafeFloat &SSF, float &Output);

	/* Native -> FSafe */

	/** Get:: Safe Float == Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Float)", CompactNodeTitle = "==", Keywords = "Security Get Safe Float EQUAL =="))
	static bool SCO_Pure_GetSafeFloatEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Get:: Safe Float != Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Float)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Float NOT !="))
	static bool SCO_Pure_GetSafeFloatNotEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Get:: Safe Float > Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Float)", CompactNodeTitle = ">", Keywords = "Security Get Safe Float GREATER >"))
	static bool SCO_Pure_GetSafeFloatGreaterFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Get:: Safe Float < Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Float)", CompactNodeTitle = "<", Keywords = "Security Get Safe Float LESS <"))
	static bool SCO_Pure_GetSafeFloatSmallerFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Get:: Safe Float >= Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Float)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Float GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeFloatGreaterEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Get:: Safe Float <= Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Float)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Float LESS EQUAL <="))
	static bool SCO_Pure_GetSafeFloatSmallerEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF);

	/** Set:: Safe Float = Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Float)", CompactNodeTitle = "=", Keywords = "Security Set Safe Float EQUAL ="))
	static FSafeFloat SCO_Pure_SetSafeFloatEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float + Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Float)", CompactNodeTitle = "+", Keywords = "Security Get Safe Float PLUS +"))
	static FSafeFloat SCO_Pure_GetSafeFloatPlusFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float - Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Float)", CompactNodeTitle = "-", Keywords = "Security Get Safe Float MINUS -"))
	static FSafeFloat SCO_Pure_GetSafeFloatMinusFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float * Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Float)", CompactNodeTitle = "*", Keywords = "Security Get Safe Float TIMES *"))
	static FSafeFloat SCO_Pure_GetSafeFloatTimesFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float / Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Float)", CompactNodeTitle = "/", Keywords = "Security Get Safe Float DIVIDE /"))
	static FSafeFloat SCO_Pure_GetSafeFloatDivideFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float += Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+= (Float)", CompactNodeTitle = "+=", Keywords = "Security Get Safe Float PLUS EQUAL +="))
	static FSafeFloat SCO_Pure_GetSafeFloatPlusEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float -= Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "-= (Float)", CompactNodeTitle = "-=", Keywords = "Security Get Safe Float MINUS EQUAL -="))
	static FSafeFloat SCO_Pure_GetSafeFloatMinusEqualFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/** Get:: Safe Float % Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Float)", CompactNodeTitle = "%", Keywords = "Security Get Safe Float MOD %"))
	static FSafeFloat SCO_Pure_GetSafeFloatModFloat(UPARAM(Ref)FSafeFloat &FSF, UPARAM(Ref)float &NF, float &Output);

	/* FSafe -> Native */

	/** Get:: Float == Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Float)", CompactNodeTitle = "==", Keywords = "Security Get Safe Float EQUAL =="))
	static bool SCO_Pure_GetFloatEqualFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float != Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Float)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Float NOT !="))
	static bool SCO_Pure_GetFloatNotEqualFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float > Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Float)", CompactNodeTitle = ">", Keywords = "Security Get Safe Float GREATER >"))
	static bool SCO_Pure_GetFloatGreaterFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float < Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Float)", CompactNodeTitle = "<", Keywords = "Security Get Safe Float LESS <"))
	static bool SCO_Pure_GetFloatSmallerFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float >= Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Float)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Float GREATER EQUAL >="))
	static bool SCO_Pure_GetFloatGreaterEqualFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float <= Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Float)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Float LESS EQUAL <="))
	static bool SCO_Pure_GetFloatSmallerEqualFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Set:: Float = Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Float)", CompactNodeTitle = "=", Keywords = "Security Set Safe Float EQUAL ="))
	static float SCO_Pure_SetFloatEqualFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float + Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Float)", CompactNodeTitle = "+", Keywords = "Security Get Safe Float PLUS +"))
	static float SCO_Pure_GetFloatPlusFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float - Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Float)", CompactNodeTitle = "-", Keywords = "Security Get Safe Float MINUS -"))
	static float SCO_Pure_GetFloatMinusFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float * Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Float)", CompactNodeTitle = "*", Keywords = "Security Get Safe Float TIMES *"))
	static float SCO_Pure_GetFloatTimesFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float / Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Float)", CompactNodeTitle = "/", Keywords = "Security Get Safe Float DIVIDE /"))
	static float SCO_Pure_GetFloatDivideFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	/** Get:: Float % Safe Float */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Float)", CompactNodeTitle = "%", Keywords = "Security Get Safe Float MOD %"))
	static float SCO_Pure_GetFloatModFSF(UPARAM(Ref)float &NF, UPARAM(Ref)FSafeFloat &FSF);

	// FSName

	/* FSafe -> FSafe */

	/** Get:: Safe Name == Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Name)", CompactNodeTitle = "==", Keywords = "Security Get Safe Name EQUAL =="))
	static bool SCO_Pure_GetSafeNameEqualFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN);

	/** Get:: Safe Name != Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Name)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Name NOT !="))
	static bool SCO_Pure_GetSafeNameNotEqualFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN);

	/** Get:: Safe Name > Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Name)", CompactNodeTitle = ">", Keywords = "Security Get Safe Name GREATER >"))
	static bool SCO_Pure_GetSafeNameGreaterFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN);

	/** Get:: Safe Name < Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Name)", CompactNodeTitle = "<", Keywords = "Security Get Safe Name LESS <"))
	static bool SCO_Pure_GetSafeNameSmallerFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN);

	/** Set:: Safe Name = Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Name)", CompactNodeTitle = "=", Keywords = "Security Set Safe Name EQUAL ="))
	static FSafeName SCO_Pure_SetSafeNameEqualFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN, FName &Output);

	/** Get:: Safe Name + Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Name)", CompactNodeTitle = "+", Keywords = "Security Get Safe Name PLUS +"))
	static FSafeName SCO_Pure_GetSafeNamePlusFSN(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FSafeName &SSN, FName &Output);
	
	/* Native -> FSafe */

	/** Get:: Safe Name == Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Name)", CompactNodeTitle = "==", Keywords = "Security Get Safe Name EQUAL =="))
	static bool SCO_Pure_GetSafeNameEqualName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN);

	/** Get:: Safe Name != Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Name)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Name NOT !="))
	static bool SCO_Pure_GetSafeNameNotEqualName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN);

	/** Get:: Safe Name > Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Name)", CompactNodeTitle = ">", Keywords = "Security Get Safe Name GREATER >"))
	static bool SCO_Pure_GetSafeNameGreaterName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN);

	/** Get:: Safe Name < Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Name)", CompactNodeTitle = "<", Keywords = "Security Get Safe Name LESS <"))
	static bool SCO_Pure_GetSafeNameSmallerName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN);

	/** Set:: Safe Name = Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Name)", CompactNodeTitle = "=", Keywords = "Security Set Safe Name EQUAL ="))
	static FSafeName SCO_Pure_SetSafeNameEqualName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN, FName &Output);

	/** Get:: Safe Name + Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Name)", CompactNodeTitle = "+", Keywords = "Security Get Safe Name PLUS +"))
	static FSafeName SCO_Pure_GetSafeNamePlusName(UPARAM(Ref)FSafeName &FSN, UPARAM(Ref)FName &NN, FName &Output);
		
	/* FSafe -> Native */

	/** Get:: Name == Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Name)", CompactNodeTitle = "==", Keywords = "Security Get Safe Name EQUAL =="))
	static bool SCO_Pure_GetNameEqualFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);

	/** Get:: Name != Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Name)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Name NOT !="))
	static bool SCO_Pure_GetNameNotEqualFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);

	/** Get:: Name > Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Name)", CompactNodeTitle = ">", Keywords = "Security Get Safe Name GREATER >"))
	static bool SCO_Pure_GetNameGreaterFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);

	/** Get:: Name < Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Name)", CompactNodeTitle = "<", Keywords = "Security Get Safe Name LESS <"))
	static bool SCO_Pure_GetNameSmallerFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);

	/** Set:: Name = Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Name)", CompactNodeTitle = "=", Keywords = "Security Set Safe Name EQUAL ="))
	static FName SCO_Pure_SetNameEqualFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);

	/** Get:: Name + Safe Name */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Name)", CompactNodeTitle = "+", Keywords = "Security Get Safe Name PLUS +"))
	static FName SCO_Pure_GetNamePlusFSN(UPARAM(Ref)FName &NN, UPARAM(Ref)FSafeName &FSN);
	
	// FSText

	/* FSafe -> FSafe */

	/** Get:: Safe Text == Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Text)", CompactNodeTitle = "==", Keywords = "Security Get Safe Text EQUAL =="))
	static bool SCO_Pure_GetSafeTextEqualFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST);

	/** Get:: Safe Text != Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Text)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Text NOT !="))
	static bool SCO_Pure_GetSafeTextNotEqualFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST);

	/** Get:: Safe Text > Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Text)", CompactNodeTitle = ">", Keywords = "Security Get Safe Text GREATER >"))
	static bool SCO_Pure_GetSafeTextGreaterFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST);

	/** Get:: Safe Text < Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Text)", CompactNodeTitle = "<", Keywords = "Security Get Safe Text LEST <"))
	static bool SCO_Pure_GetSafeTextSmallerFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST);

	/** Set:: Safe Text = Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Text)", CompactNodeTitle = "=", Keywords = "Security Set Safe Text EQUAL ="))
	static FSafeText SCO_Pure_SetSafeTextEqualFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST, FText &Output);

	/** Get:: Safe Text + Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Text)", CompactNodeTitle = "+", Keywords = "Security Get Safe Text PLUS +"))
	static FSafeText SCO_Pure_GetSafeTextPlusFST(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FSafeText &ST, FText &Output);
	
	/* Native -> FSafe */

	/** Get:: Safe Text == Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Text)", CompactNodeTitle = "==", Keywords = "Security Get Safe Text EQUAL =="))
	static bool SCO_Pure_GetSafeTextEqualText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT);

	/** Get:: Safe Text != Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Text)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Text NOT !="))
	static bool SCO_Pure_GetSafeTextNotEqualText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT);

	/** Get:: Safe Text > Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Text)", CompactNodeTitle = ">", Keywords = "Security Get Safe Text GREATER >"))
	static bool SCO_Pure_GetSafeTextGreaterText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT);

	/** Get:: Safe Text < Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Text)", CompactNodeTitle = "<", Keywords = "Security Get Safe Text LEST <"))
	static bool SCO_Pure_GetSafeTextSmallerText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT);

	/** Set:: Safe Text = Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Text)", CompactNodeTitle = "=", Keywords = "Security Set Safe Text EQUAL ="))
	static FSafeText SCO_Pure_SetSafeTextEqualText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT, FText &Output);

	/** Get:: Safe Text + Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Text)", CompactNodeTitle = "+", Keywords = "Security Get Safe Text PLUS +"))
	static FSafeText SCO_Pure_GetSafeTextPlusText(UPARAM(Ref)FSafeText &FST, UPARAM(Ref)FText &NT, FText &Output);
	
	/* FSafe -> Native */

	/** Get:: Text == Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Text)", CompactNodeTitle = "==", Keywords = "Security Get Safe Text EQUAL =="))
	static bool SCO_Pure_GetTextEqualFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	/** Get:: Text != Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Text)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Text NOT !="))
	static bool SCO_Pure_GetTextNotEqualFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	/** Get:: Text > Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Text)", CompactNodeTitle = ">", Keywords = "Security Get Safe Text GREATER >"))
	static bool SCO_Pure_GetTextGreaterFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	/** Get:: Text < Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Text)", CompactNodeTitle = "<", Keywords = "Security Get Safe Text LEST <"))
	static bool SCO_Pure_GetTextSmallerFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	/** Set:: Text = Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Text)", CompactNodeTitle = "=", Keywords = "Security Set Safe Text EQUAL ="))
	static FText SCO_Pure_SetTextEqualFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	/** Get:: Text + Safe Text */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Text)", CompactNodeTitle = "+", Keywords = "Security Get Safe Text PLUS +"))
	static FText SCO_Pure_GetTextPlusFST(UPARAM(Ref)FText &NT, UPARAM(Ref)FSafeText &FST);

	// FSString

	/* FSafe -> FSafe */

	/** Get:: Safe String == Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe String)", CompactNodeTitle = "==", Keywords = "Security Get Safe String EQUAL =="))
	static bool SCO_Pure_GetSafeStringEqualFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS);

	/** Get:: Safe String != Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe String)", CompactNodeTitle = "!=", Keywords = "Security Get Safe String NOT !="))
	static bool SCO_Pure_GetSafeStringNotEqualFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS);

	/** Get:: Safe String > Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe String)", CompactNodeTitle = ">", Keywords = "Security Get Safe String GREATER >"))
	static bool SCO_Pure_GetSafeStringGreaterFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS);

	/** Get:: Safe String < Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe String)", CompactNodeTitle = "<", Keywords = "Security Get Safe String LESS <"))
	static bool SCO_Pure_GetSafeStringSmallerFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS);

	/** Set:: Safe String = Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe String)", CompactNodeTitle = "=", Keywords = "Security Set Safe String EQUAL ="))
	static FSafeString SCO_Pure_SetSafeStringEqualFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS, FString &Output);

	/** Get:: Safe String + Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe String)", CompactNodeTitle = "+", Keywords = "Security Get Safe String PLUS +"))
	static FSafeString SCO_Pure_GetSafeStringPlusFSS(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FSafeString &SS, FString &Output);
	
	/* Native -> FSafe */

	/** Get:: Safe String == String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (String)", CompactNodeTitle = "==", Keywords = "Security Get Safe String EQUAL =="))
	static bool SCO_Pure_GetSafeStringEqualString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS);

	/** Get:: Safe String != String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (String)", CompactNodeTitle = "!=", Keywords = "Security Get Safe String NOT !="))
	static bool SCO_Pure_GetSafeStringNotEqualString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS);

	/** Get:: Safe String > String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (String)", CompactNodeTitle = ">", Keywords = "Security Get Safe String GREATER >"))
	static bool SCO_Pure_GetSafeStringGreaterString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS);

	/** Get:: Safe String < String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (String)", CompactNodeTitle = "<", Keywords = "Security Get Safe String LESS <"))
	static bool SCO_Pure_GetSafeStringSmallerString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS);

	/** Set:: Safe String = String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (String)", CompactNodeTitle = "=", Keywords = "Security Set Safe String EQUAL ="))
	static FSafeString SCO_Pure_SetSafeStringEqualString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS, FString &Output);

	/** Get:: Safe String + String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (String)", CompactNodeTitle = "+", Keywords = "Security Get Safe String PLUS +"))
	static FSafeString SCO_Pure_GetSafeStringPlusString(UPARAM(Ref)FSafeString &FSS, UPARAM(Ref)FString &NS, FString &Output);
	
	/* FSafe -> Native */

	/** Get:: String == Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe String)", CompactNodeTitle = "==", Keywords = "Security Get Safe String EQUAL =="))
	static bool SCO_Pure_GetStringEqualFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	/** Get:: String != Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe String)", CompactNodeTitle = "!=", Keywords = "Security Get Safe String NOT !="))
	static bool SCO_Pure_GetStringNotEqualFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	/** Get:: String > Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe String)", CompactNodeTitle = ">", Keywords = "Security Get Safe String GREATER >"))
	static bool SCO_Pure_GetStringGreaterFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	/** Get:: String < Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe String)", CompactNodeTitle = "<", Keywords = "Security Get Safe String LESS <"))
	static bool SCO_Pure_GetStringSmallerFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	/** Set:: String = Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe String)", CompactNodeTitle = "=", Keywords = "Security Set Safe String EQUAL ="))
	static FString SCO_Pure_SetStringEqualFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	/** Get:: String + Safe String */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe String)", CompactNodeTitle = "+", Keywords = "Security Get Safe String PLUS +"))
	static FString SCO_Pure_GetStringPlusFSS(UPARAM(Ref)FString &NS, UPARAM(Ref)FSafeString &FSS);

	// FSVector2D

	/* FSafe -> FSafe */

	/** Get:: Safe Vector2D == Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector2D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector2D EQUAL =="))
	static bool SCO_Pure_GetSafeVector2DEqualFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Get:: Safe Vector2D != Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector2D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector2D NOT !="))
	static bool SCO_Pure_GetSafeVector2DNotEqualFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Get:: Safe Vector2D > Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector2D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector2D GREATER >"))
	static bool SCO_Pure_GetSafeVector2DGreaterFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Get:: Safe Vector2D < Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector2D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector2D LESS <"))
	static bool SCO_Pure_GetSafeVector2DSmallerFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Get:: Safe Vector2D >= Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector2D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector2D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector2DGreaterEqualFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Get:: Safe Vector2D <= Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector2D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector2D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector2DSmallerEqualFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV);

	/** Set:: Safe Vector2D = Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector2D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector2D EQUAL ="))
	static FSafeVector2D SCO_Pure_SetSafeVector2DEqualFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/** Get:: Safe Vector2D + Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector2D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector2D PLUS +"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DPlusFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/** Get:: Safe Vector2D - Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector2D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector2D MINUS -"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DMinusFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/** Get:: Safe Vector2D * Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector2D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector2D TIMES *"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DTimesFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/** Get:: Safe Vector2D / Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector2D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector2D DIVIDE /"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DDivideFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/** Get:: Safe Vector2D % Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector2D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector2D MOD %"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DModFSV(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FSafeVector2D &SSV, FVector2D &Output);

	/* Native -> FSafe */

	/** Get:: Safe Vector2D == Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Vector2D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector2D EQUAL =="))
	static bool SCO_Pure_GetSafeVector2DEqualVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Get:: Safe Vector2D != Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Vector2D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector2D NOT !="))
	static bool SCO_Pure_GetSafeVector2DNotEqualVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Get:: Safe Vector2D > Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Vector2D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector2D GREATER >"))
	static bool SCO_Pure_GetSafeVector2DGreaterVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Get:: Safe Vector2D < Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Vector2D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector2D LESS <"))
	static bool SCO_Pure_GetSafeVector2DSmallerVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Get:: Safe Vector2D >= Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Vector2D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector2D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector2DGreaterEqualVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Get:: Safe Vector2D <= Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Vector2D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector2D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector2DSmallerEqualVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV);

	/** Set:: Safe Vector2D = Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Vector2D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector2D EQUAL ="))
	static FSafeVector2D SCO_Pure_SetSafeVector2DEqualVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/** Get:: Safe Vector2D + Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Vector2D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector2D PLUS +"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DPlusVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/** Get:: Safe Vector2D - Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Vector2D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector2D MINUS -"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DMinusVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/** Get:: Safe Vector2D * Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Vector2D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector2D TIMES *"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DTimesVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/** Get:: Safe Vector2D / Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Vector2D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector2D DIVIDE /"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DDivideVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/** Get:: Safe Vector2D % Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Vector2D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector2D MOD %"))
	static FSafeVector2D SCO_Pure_GetSafeVector2DModVector2D(UPARAM(Ref)FSafeVector2D &FSV, UPARAM(Ref)FVector2D &NV, FVector2D &Output);

	/* FSafe -> Native */

	/** Get:: Vector2D == Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector2D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector2D EQUAL =="))
	static bool SCO_Pure_GetVector2DEqualFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D != Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector2D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector2D NOT !="))
	static bool SCO_Pure_GetVector2DNotEqualFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D > Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector2D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector2D GREATER >"))
	static bool SCO_Pure_GetVector2DGreaterFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D < Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector2D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector2D LESS <"))
	static bool SCO_Pure_GetVector2DSmallerFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D >= Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector2D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector2D GREATER EQUAL >="))
	static bool SCO_Pure_GetVector2DGreaterEqualFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D <= Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector2D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector2D LESS EQUAL <="))
	static bool SCO_Pure_GetVector2DSmallerEqualFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Set:: Vector2D = Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector2D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector2D EQUAL ="))
	static FVector2D SCO_Pure_SetVector2DEqualFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D + Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector2D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector2D PLUS +"))
	static FVector2D SCO_Pure_GetVector2DPlusFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D - Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector2D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector2D MINUS -"))
	static FVector2D SCO_Pure_GetVector2DMinusFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D * Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector2D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector2D TIMES *"))
	static FVector2D SCO_Pure_GetVector2DTimesFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D / Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector2D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector2D DIVIDE /"))
	static FVector2D SCO_Pure_GetVector2DDivideFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	/** Get:: Vector2D % Safe Vector2D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector2D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector2D MOD %"))
	static FVector2D SCO_Pure_GetVector2DModFSV(UPARAM(Ref)FVector2D &NV, UPARAM(Ref)FSafeVector2D &FSV);

	// FSVector3D

	/* FSafe -> FSafe */

	/** Get:: Safe Vector3D == Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector3D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector3D EQUAL =="))
	static bool SCO_Pure_GetSafeVector3DEqualFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Get:: Safe Vector3D != Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector3D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector3D NOT !="))
	static bool SCO_Pure_GetSafeVector3DNotEqualFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Get:: Safe Vector3D > Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector3D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector3D GREATER >"))
	static bool SCO_Pure_GetSafeVector3DGreaterFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Get:: Safe Vector3D < Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector3D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector3D LESS <"))
	static bool SCO_Pure_GetSafeVector3DSmallerFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Get:: Safe Vector3D >= Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector3D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector3D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector3DGreaterEqualFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Get:: Safe Vector3D <= Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector3D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector3D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector3DSmallerEqualFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV);

	/** Set:: Safe Vector3D = Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector3D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector3D EQUAL ="))
	static FSafeVector3D SCO_Pure_SetSafeVector3DEqualFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/** Get:: Safe Vector3D + Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector3D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector3D PLUS +"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DPlusFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/** Get:: Safe Vector3D - Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector3D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector3D MINUS -"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DMinusFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/** Get:: Safe Vector3D * Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector3D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector3D TIMES *"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DTimesFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/** Get:: Safe Vector3D / Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector3D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector3D DIVIDE /"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DDivideFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/** Get:: Safe Vector3D % Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector3D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector3D MOD %"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DModFSV(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FSafeVector3D &SSV, FVector &Output);

	/* Native -> FSafe */

	/** Get:: Safe Vector3D == Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Vector3D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector3D EQUAL =="))
	static bool SCO_Pure_GetSafeVector3DEqualVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Get:: Safe Vector3D != Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Vector3D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector3D NOT !="))
	static bool SCO_Pure_GetSafeVector3DNotEqualVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Get:: Safe Vector3D > Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Vector3D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector3D GREATER >"))
	static bool SCO_Pure_GetSafeVector3DGreaterVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Get:: Safe Vector3D < Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Vector3D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector3D LESS <"))
	static bool SCO_Pure_GetSafeVector3DSmallerVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Get:: Safe Vector3D >= Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Vector3D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector3D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector3DGreaterEqualVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Get:: Safe Vector3D <= Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Vector3D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector3D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector3DSmallerEqualVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV);

	/** Set:: Safe Vector3D = Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Vector3D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector3D EQUAL ="))
	static FSafeVector3D SCO_Pure_SetSafeVector3DEqualVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/** Get:: Safe Vector3D + Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Vector3D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector3D PLUS +"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DPlusVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/** Get:: Safe Vector3D - Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Vector3D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector3D MINUS -"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DMinusVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/** Get:: Safe Vector3D * Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Vector3D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector3D TIMES *"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DTimesVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/** Get:: Safe Vector3D / Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Vector3D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector3D DIVIDE /"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DDivideVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/** Get:: Safe Vector3D % Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Vector3D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector3D MOD %"))
	static FSafeVector3D SCO_Pure_GetSafeVector3DModVector3D(UPARAM(Ref)FSafeVector3D &FSV, UPARAM(Ref)FVector &NV, FVector &Output);

	/* FSafe -> Native */

	/** Get:: Vector3D == Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector3D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector3D EQUAL =="))
	static bool SCO_Pure_GetVector3DEqualFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D != Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector3D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector3D NOT !="))
	static bool SCO_Pure_GetVector3DNotEqualFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D > Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector3D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector3D GREATER >"))
	static bool SCO_Pure_GetVector3DGreaterFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D < Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector3D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector3D LESS <"))
	static bool SCO_Pure_GetVector3DSmallerFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D >= Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector3D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector3D GREATER EQUAL >="))
	static bool SCO_Pure_GetVector3DGreaterEqualFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D <= Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector3D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector3D LESS EQUAL <="))
	static bool SCO_Pure_GetVector3DSmallerEqualFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Set:: Vector3D = Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector3D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector3D EQUAL ="))
	static FVector SCO_Pure_SetVector3DEqualFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D + Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector3D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector3D PLUS +"))
	static FVector SCO_Pure_GetVector3DPlusFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D - Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector3D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector3D MINUS -"))
	static FVector SCO_Pure_GetVector3DMinusFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D * Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector3D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector3D TIMES *"))
	static FVector SCO_Pure_GetVector3DTimesFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D / Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector3D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector3D DIVIDE /"))
	static FVector SCO_Pure_GetVector3DDivideFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	/** Get:: Vector3D % Safe Vector3D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector3D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector3D MOD %"))
	static FVector SCO_Pure_GetVector3DModFSV(UPARAM(Ref)FVector &NV, UPARAM(Ref)FSafeVector3D &FSV);

	// FSVector4D

	/* FSafe -> FSafe */

	/** Get:: Safe Vector4D == Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector4D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector4D EQUAL =="))
	static bool SCO_Pure_GetSafeVector4DEqualFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Get:: Safe Vector4D != Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector4D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector4D NOT !="))
	static bool SCO_Pure_GetSafeVector4DNotEqualFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Get:: Safe Vector4D > Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector4D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector4D GREATER >"))
	static bool SCO_Pure_GetSafeVector4DGreaterFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Get:: Safe Vector4D < Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector4D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector4D LESS <"))
	static bool SCO_Pure_GetSafeVector4DSmallerFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Get:: Safe Vector4D >= Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector4D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector4D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector4DGreaterEqualFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Get:: Safe Vector4D <= Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector4D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector4D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector4DSmallerEqualFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV);

	/** Set:: Safe Vector4D = Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector4D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector4D EQUAL ="))
	static FSafeVector4D SCO_Pure_SetSafeVector4DEqualFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/** Get:: Safe Vector4D + Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector4D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector4D PLUS +"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DPlusFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/** Get:: Safe Vector4D - Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector4D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector4D MINUS -"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DMinusFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/** Get:: Safe Vector4D * Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector4D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector4D TIMES *"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DTimesFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/** Get:: Safe Vector4D / Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector4D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector4D DIVIDE /"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DDivideFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/** Get:: Safe Vector4D % Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector4D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector4D MOD %"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DModFSV(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FSafeVector4D &SSV, FVector4 &Output);

	/* Native -> FSafe */

	/** Get:: Safe Vector4D == Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Vector4D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector4D EQUAL =="))
	static bool SCO_Pure_GetSafeVector4DEqualVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Get:: Safe Vector4D != Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Vector4D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector4D NOT !="))
	static bool SCO_Pure_GetSafeVector4DNotEqualVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Get:: Safe Vector4D > Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Vector4D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector4D GREATER >"))
	static bool SCO_Pure_GetSafeVector4DGreaterVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Get:: Safe Vector4D < Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Vector4D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector4D LESS <"))
	static bool SCO_Pure_GetSafeVector4DSmallerVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Get:: Safe Vector4D >= Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Vector4D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector4D GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeVector4DGreaterEqualVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Get:: Safe Vector4D <= Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Vector4D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector4D LESS EQUAL <="))
	static bool SCO_Pure_GetSafeVector4DSmallerEqualVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV);

	/** Set:: Safe Vector4D = Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Vector4D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector4D EQUAL ="))
	static FSafeVector4D SCO_Pure_SetSafeVector4DEqualVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/** Get:: Safe Vector4D + Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Vector4D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector4D PLUS +"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DPlusVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/** Get:: Safe Vector4D - Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Vector4D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector4D MINUS -"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DMinusVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/** Get:: Safe Vector4D * Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Vector4D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector4D TIMES *"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DTimesVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/** Get:: Safe Vector4D / Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Vector4D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector4D DIVIDE /"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DDivideVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/** Get:: Safe Vector4D % Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Vector4D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector4D MOD %"))
	static FSafeVector4D SCO_Pure_GetSafeVector4DModVector4D(UPARAM(Ref)FSafeVector4D &FSV, UPARAM(Ref)FVector4 &NV, FVector4 &Output);

	/* FSafe -> Native */

	/** Get:: Vector4D == Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Vector4D)", CompactNodeTitle = "==", Keywords = "Security Get Safe Vector4D EQUAL =="))
	static bool SCO_Pure_GetVector4DEqualFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D != Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Vector4D)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Vector4D NOT !="))
	static bool SCO_Pure_GetVector4DNotEqualFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D > Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Vector4D)", CompactNodeTitle = ">", Keywords = "Security Get Safe Vector4D GREATER >"))
	static bool SCO_Pure_GetVector4DGreaterFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D < Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Vector4D)", CompactNodeTitle = "<", Keywords = "Security Get Safe Vector4D LESS <"))
	static bool SCO_Pure_GetVector4DSmallerFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D >= Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Vector4D)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Vector4D GREATER EQUAL >="))
	static bool SCO_Pure_GetVector4DGreaterEqualFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D <= Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Vector4D)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Vector4D LESS EQUAL <="))
	static bool SCO_Pure_GetVector4DSmallerEqualFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Set:: Vector4D = Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Vector4D)", CompactNodeTitle = "=", Keywords = "Security Set Safe Vector4D EQUAL ="))
	static FVector4 SCO_Pure_SetVector4DEqualFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D + Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Vector4D)", CompactNodeTitle = "+", Keywords = "Security Get Safe Vector4D PLUS +"))
	static FVector4 SCO_Pure_GetVector4DPlusFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D - Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Vector4D)", CompactNodeTitle = "-", Keywords = "Security Get Safe Vector4D MINUS -"))
	static FVector4 SCO_Pure_GetVector4DMinusFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D * Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Vector4D)", CompactNodeTitle = "*", Keywords = "Security Get Safe Vector4D TIMES *"))
	static FVector4 SCO_Pure_GetVector4DTimesFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D / Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Vector4D)", CompactNodeTitle = "/", Keywords = "Security Get Safe Vector4D DIVIDE /"))
	static FVector4 SCO_Pure_GetVector4DDivideFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	/** Get:: Vector4D % Safe Vector4D */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Vector4D)", CompactNodeTitle = "%", Keywords = "Security Get Safe Vector4D MOD %"))
	static FVector4 SCO_Pure_GetVector4DModFSV(UPARAM(Ref)FVector4 &NV, UPARAM(Ref)FSafeVector4D &FSV);

	// FSColor

	/* FSafe -> FSafe */

	/** Get:: Safe Color == Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Color)", CompactNodeTitle = "==", Keywords = "Security Get Safe Color EQUAL =="))
	static bool SCO_Pure_GetSafeColorEqualFSC(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FSafeColor &SSC);

	/** Get:: Safe Color != Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Color)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Color NOT !="))
	static bool SCO_Pure_GetSafeColorNotEqualFSC(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FSafeColor &SSC);

	/** Set:: Safe Color = Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Color)", CompactNodeTitle = "=", Keywords = "Security Set Safe Color EQUAL ="))
	static FSafeColor SCO_Pure_SetSafeColorEqualFSC(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FSafeColor &SSC, FLinearColor &Output);
	
	/* Native -> FSafe */

	/** Get:: Safe Color == Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Color)", CompactNodeTitle = "==", Keywords = "Security Get Safe Color EQUAL =="))
	static bool SCO_Pure_GetSafeColorEqualColor(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FLinearColor &NC);

	/** Get:: Safe Color != Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Color)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Color NOT !="))
	static bool SCO_Pure_GetSafeColorNotEqualColor(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FLinearColor &NC);

	/** Set:: Safe Color = Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Color)", CompactNodeTitle = "=", Keywords = "Security Set Safe Color EQUAL ="))
	static FSafeColor SCO_Pure_SetSafeColorEqualColor(UPARAM(Ref)FSafeColor &FSC, UPARAM(Ref)FLinearColor &SSC, FLinearColor &Output);

	/* FSafe -> Native */

	/** Get:: Color == Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Color)", CompactNodeTitle = "==", Keywords = "Security Get Safe Color EQUAL =="))
	static bool SCO_Pure_GetColorEqualFSC(UPARAM(Ref)FLinearColor &NC, UPARAM(Ref)FSafeColor &FSC);

	/** Get:: Color != Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Color)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Color NOT !="))
	static bool SCO_Pure_GetColorNotEqualFSC(UPARAM(Ref)FLinearColor &NC, UPARAM(Ref)FSafeColor &FSC);

	/** Set:: Color = Safe Color */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Color)", CompactNodeTitle = "=", Keywords = "Security Set Safe Color EQUAL ="))
	static FLinearColor SCO_Pure_SetColorEqualFSC(UPARAM(Ref)FLinearColor &NC, UPARAM(Ref)FSafeColor &FSC);

	// FSRotator

	/* FSafe -> FSafe */

	/** Get:: Safe Rotator == Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Rotator)", CompactNodeTitle = "==", Keywords = "Security Get Safe Rotator EQUAL =="))
	static bool SCO_Pure_GetSafeRotatorEqualFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Get:: Safe Rotator != Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Rotator)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Rotator NOT !="))
	static bool SCO_Pure_GetSafeRotatorNotEqualFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Get:: Safe Rotator > Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Rotator)", CompactNodeTitle = ">", Keywords = "Security Get Safe Rotator GREATER >"))
	static bool SCO_Pure_GetSafeRotatorGreaterFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Get:: Safe Rotator < Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Rotator)", CompactNodeTitle = "<", Keywords = "Security Get Safe Rotator LESS <"))
	static bool SCO_Pure_GetSafeRotatorSmallerFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Get:: Safe Rotator >= Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Rotator)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Rotator GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeRotatorGreaterEqualFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Get:: Safe Rotator <= Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Rotator)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Rotator LESS EQUAL <="))
	static bool SCO_Pure_GetSafeRotatorSmallerEqualFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR);

	/** Set:: Safe Rotator = Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Rotator)", CompactNodeTitle = "=", Keywords = "Security Set Safe Rotator EQUAL ="))
	static FSafeRotator SCO_Pure_SetSafeRotatorEqualFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/** Get:: Safe Rotator + Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Rotator)", CompactNodeTitle = "+", Keywords = "Security Get Safe Rotator PLUS +"))
	static FSafeRotator SCO_Pure_GetSafeRotatorPlusFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/** Get:: Safe Rotator - Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Rotator)", CompactNodeTitle = "-", Keywords = "Security Get Safe Rotator MINUS -"))
	static FSafeRotator SCO_Pure_GetSafeRotatorMinusFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/** Get:: Safe Rotator * Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Rotator)", CompactNodeTitle = "*", Keywords = "Security Get Safe Rotator TIMES *"))
	static FSafeRotator SCO_Pure_GetSafeRotatorTimesFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/** Get:: Safe Rotator / Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Rotator)", CompactNodeTitle = "/", Keywords = "Security Get Safe Rotator DIVIDE /"))
	static FSafeRotator SCO_Pure_GetSafeRotatorDivideFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/** Get:: Safe Rotator % Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Rotator)", CompactNodeTitle = "%", Keywords = "Security Get Safe Rotator MOD %"))
	static FSafeRotator SCO_Pure_GetSafeRotatorModFSR(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FSafeRotator &SSR, FRotator &Output);

	/* Native -> FSafe */

	/** Get:: Safe Rotator == Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Rotator)", CompactNodeTitle = "==", Keywords = "Security Get Safe Rotator EQUAL =="))
	static bool SCO_Pure_GetSafeRotatorEqualRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Get:: Safe Rotator != Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Rotator)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Rotator NOT !="))
	static bool SCO_Pure_GetSafeRotatorNotEqualRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Get:: Safe Rotator > Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Rotator)", CompactNodeTitle = ">", Keywords = "Security Get Safe Rotator GREATER >"))
	static bool SCO_Pure_GetSafeRotatorGreaterRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Get:: Safe Rotator < Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Rotator)", CompactNodeTitle = "<", Keywords = "Security Get Safe Rotator LESS <"))
	static bool SCO_Pure_GetSafeRotatorSmallerRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Get:: Safe Rotator >= Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Rotator)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Rotator GREATER EQUAL >="))
	static bool SCO_Pure_GetSafeRotatorGreaterEqualRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Get:: Safe Rotator <= Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Rotator)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Rotator LESS EQUAL <="))
	static bool SCO_Pure_GetSafeRotatorSmallerEqualRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR);

	/** Set:: Safe Rotator = Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Rotator)", CompactNodeTitle = "=", Keywords = "Security Set Safe Rotator EQUAL ="))
	static FSafeRotator SCO_Pure_SetSafeRotatorEqualRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/** Get:: Safe Rotator + Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Rotator)", CompactNodeTitle = "+", Keywords = "Security Get Safe Rotator PLUS +"))
	static FSafeRotator SCO_Pure_GetSafeRotatorPlusRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/** Get:: Safe Rotator - Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Rotator)", CompactNodeTitle = "-", Keywords = "Security Get Safe Rotator MINUS -"))
	static FSafeRotator SCO_Pure_GetSafeRotatorMinusRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/** Get:: Safe Rotator * Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Rotator)", CompactNodeTitle = "*", Keywords = "Security Get Safe Rotator TIMES *"))
	static FSafeRotator SCO_Pure_GetSafeRotatorTimesRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/** Get:: Safe Rotator / Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Rotator)", CompactNodeTitle = "/", Keywords = "Security Get Safe Rotator DIVIDE /"))
	static FSafeRotator SCO_Pure_GetSafeRotatorDivideRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/** Get:: Safe Rotator % Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Rotator)", CompactNodeTitle = "%", Keywords = "Security Get Safe Rotator MOD %"))
	static FSafeRotator SCO_Pure_GetSafeRotatorModRotator(UPARAM(Ref)FSafeRotator &FSR, UPARAM(Ref)FRotator &NR, FRotator &Output);

	/* FSafe -> Native */

	/** Get:: Rotator == Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Rotator)", CompactNodeTitle = "==", Keywords = "Security Get Safe Rotator EQUAL =="))
	static bool SCO_Pure_GetRotatorEqualFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator != Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Rotator)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Rotator NOT !="))
	static bool SCO_Pure_GetRotatorNotEqualFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator > Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "> (Safe Rotator)", CompactNodeTitle = ">", Keywords = "Security Get Safe Rotator GREATER >"))
	static bool SCO_Pure_GetRotatorGreaterFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator < Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "< (Safe Rotator)", CompactNodeTitle = "<", Keywords = "Security Get Safe Rotator LESS <"))
	static bool SCO_Pure_GetRotatorSmallerFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator >= Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = ">= (Safe Rotator)", CompactNodeTitle = ">=", Keywords = "Security Get Safe Rotator GREATER EQUAL >="))
	static bool SCO_Pure_GetRotatorGreaterEqualFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator <= Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "<= (Safe Rotator)", CompactNodeTitle = "<=", Keywords = "Security Get Safe Rotator LESS EQUAL <="))
	static bool SCO_Pure_GetRotatorSmallerEqualFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Set:: Rotator = Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Rotator)", CompactNodeTitle = "=", Keywords = "Security Set Safe Rotator EQUAL ="))
	static FRotator SCO_Pure_SetRotatorEqualFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator + Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "+ (Safe Rotator)", CompactNodeTitle = "+", Keywords = "Security Get Safe Rotator PLUS +"))
	static FRotator SCO_Pure_GetRotatorPlusFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator - Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "- (Safe Rotator)", CompactNodeTitle = "-", Keywords = "Security Get Safe Rotator MINUS -"))
	static FRotator SCO_Pure_GetRotatorMinusFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator * Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "* (Safe Rotator)", CompactNodeTitle = "*", Keywords = "Security Get Safe Rotator TIMES *"))
	static FRotator SCO_Pure_GetRotatorTimesFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator / Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "/ (Safe Rotator)", CompactNodeTitle = "/", Keywords = "Security Get Safe Rotator DIVIDE /"))
	static FRotator SCO_Pure_GetRotatorDivideFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	/** Get:: Rotator % Safe Rotator */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "% (Safe Rotator)", CompactNodeTitle = "%", Keywords = "Security Get Safe Rotator MOD %"))
	static FRotator SCO_Pure_GetRotatorModFSR(UPARAM(Ref)FRotator &NR, UPARAM(Ref)FSafeRotator &FSR);

	// FSTransform

	/* FSafe -> FSafe */

	/** Get:: Safe Transform == Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Transform)", CompactNodeTitle = "==", Keywords = "Security Get Safe Transform EQUAL =="))
	static bool SCO_Pure_GetSafeTransformEqualFST(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FSafeTransform &SST);

	/** Get:: Safe Transform != Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Transform)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Transform NOT !="))
	static bool SCO_Pure_GetSafeTransformNotEqualFST(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FSafeTransform &SST);

	/** Set:: Safe Transform = Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Transform)", CompactNodeTitle = "=", Keywords = "Security Set Safe Transform EQUAL ="))
	static FSafeTransform SCO_Pure_SetSafeTransformEqualFST(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FSafeTransform &SST, FTransform &Output);
	
	/* Native -> FSafe */

	/** Get:: Safe Transform == Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Transform)", CompactNodeTitle = "==", Keywords = "Security Get Safe Transform EQUAL =="))
	static bool SCO_Pure_GetSafeTransformEqualTransform(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FTransform &NT);

	/** Get:: Safe Transform != Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Transform)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Transform NOT !="))
	static bool SCO_Pure_GetSafeTransformNotEqualTransform(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FTransform &NT);

	/** Set:: Safe Transform = Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Transform)", CompactNodeTitle = "=", Keywords = "Security Set Safe Transform EQUAL ="))
	static FSafeTransform SCO_Pure_SetSafeTransformEqualTransform(UPARAM(Ref)FSafeTransform &FST, UPARAM(Ref)FTransform &SST, FTransform &Output);

	/* FSafe -> Native */

	/** Get:: Transform == Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "== (Safe Transform)", CompactNodeTitle = "==", Keywords = "Security Get Safe Transform EQUAL =="))
	static bool SCO_Pure_GetTransformEqualFST(UPARAM(Ref)FTransform &NT, UPARAM(Ref)FSafeTransform &FST);

	/** Get:: Transform != Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "!= (Safe Transform)", CompactNodeTitle = "!=", Keywords = "Security Get Safe Transform NOT !="))
	static bool SCO_Pure_GetTransformNotEqualFST(UPARAM(Ref)FTransform &NT, UPARAM(Ref)FSafeTransform &FST);

	/** Set:: Transform = Safe Transform */
	UFUNCTION(BlueprintPure, Category = "Variables|Security", meta = (DisplayName = "= (Safe Transform)", CompactNodeTitle = "=", Keywords = "Security Set Safe Transform EQUAL ="))
	static FTransform SCO_Pure_SetTransformEqualFST(UPARAM(Ref)FTransform &NT, UPARAM(Ref)FSafeTransform &FST);

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////