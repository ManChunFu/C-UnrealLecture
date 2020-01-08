// Fill out your copyright notice in the Description page of Project Settings.


#include "StateMachineBase.h"

// Sets default values for this component's properties
UStateMachineBase::UStateMachineBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = bTickEnabled;

	// ...
}


// Called when the game starts
void UStateMachineBase::BeginPlay()
{
	Super::BeginPlay();
	
	/// teacher didn't add *
	CurrentState = NewObject<UState>(this, *InitialState->GetName(), RF_NoFlags, InitialState.GetDefaultObject());
	CurrentState->OnEnterState();
}


// Called every frame
void UStateMachineBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	CurrentState->OnTickState();
}

void UStateMachineBase::ReceiveEvent(FName EventName)
{
	TSubclassOf<UState>* NextStateClass = CurrentState->StateTransitions.Find(EventName);

	if (NextStateClass != nullptr)
	{
		if (CurrentState->GetClass() == *NextStateClass)
		{
			return;
		}
		CurrentState->OnExitState();
		CurrentState = NewObject<UState>(*NextStateClass);
		CurrentState->OnEnterState();
	}

}

