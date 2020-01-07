// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CPPUnrealLectureHUD.generated.h"

UCLASS()
class ACPPUnrealLectureHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACPPUnrealLectureHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

