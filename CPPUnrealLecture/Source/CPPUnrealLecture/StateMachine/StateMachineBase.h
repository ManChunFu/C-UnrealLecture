// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "State.h"
#include "StateMachineBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class CPPUNREALLECTURE_API UStateMachineBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineBase();

	UPROPERTY(EditAnyWhere, Category = "Ticking")
	bool bTickEnabled = true;

	UPROPERTY(EditAnywhere, Category = "States")
	TSubclassOf<UState> InitialState = UState::StaticClass();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void ReceiveEvent(FName EventName);
private:
	UPROPERTY(EditAnywhere)
	UState* CurrentState = nullptr;
};
