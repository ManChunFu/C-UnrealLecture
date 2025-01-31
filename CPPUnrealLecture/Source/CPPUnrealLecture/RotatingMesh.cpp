// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingMesh.h"

ARotatingMesh::ARotatingMesh()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingMesh::Tick(float DeltaSeonds)
{
	SetActorRotation(GetActorRotation() + RotationPerSecond * DeltaSeonds, ETeleportType::TeleportPhysics);
}

float ARotatingMesh::ApplyDamage_Implementation(float InDamage)
{
	CurrentHealth -= InDamage;

	if (CurrentHealth <= 0.0f)
	{
		Destroy();
	}

	return CurrentHealth;
}
