// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class CPPUNREALLECTURE_API UState : public UObject
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
    void OnEnterState();
    void OnEnterState_Implementation() {};

    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
    void OnTickState();
    void OnTickState_Implementation() {};

    UFUNCTION(BlueprintNativeEvent, Category = "State Handlers")
    void OnExitState();
    void OnExitState_Implementation() {};
};
