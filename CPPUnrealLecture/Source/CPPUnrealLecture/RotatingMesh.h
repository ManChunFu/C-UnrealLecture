// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageableInterface.h"
#include "Engine/StaticMeshActor.h"
#include "RotatingMesh.generated.h"

/**
 * 
 */
UCLASS()
class CPPUNREALLECTURE_API ARotatingMesh : public AStaticMeshActor, public IDamageableInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Movement")
	FRotator RotationPerSecond = FRotator(0.0f, 90.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Health")
	float CurrentHealth = 10.0f;

	ARotatingMesh();

	virtual void Tick(float DeltaSeonds) override;
	virtual float ApplyDamage_Implementation(float InDamage) override;
};
