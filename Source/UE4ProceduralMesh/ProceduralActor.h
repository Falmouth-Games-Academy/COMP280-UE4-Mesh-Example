// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralActor.generated.h"

UCLASS()
class UE4PROCEDURALMESH_API AProceduralActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PostActorCreated() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Procedural Mesh Component, to use this you need to add ProceduralMeshComponent to the *.Build.cs
	UPROPERTY(VisibleAnywhere)
	class UProceduralMeshComponent * ProceduralMesh;

};
