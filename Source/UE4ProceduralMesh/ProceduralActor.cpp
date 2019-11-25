// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralActor.h"
#include "ProceduralMeshComponent.h"

// Sets default values
AProceduralActor::AProceduralActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create an empty procedural mesh
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = ProceduralMesh;
}

//This function is called when the actor has been created, this means we will only see the triangle
//when we are in play mode
void AProceduralActor::PostActorCreated()
{
	//Add in some vertices, we must have these
	TArray<FVector> vertices;
	vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(100, 0, 0));
	vertices.Add(FVector(0, 0, 100));

	//We must have some indices or Triangles in UE4
	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);

	TArray<FVector> normals;
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(-1, 0, 0));

	TArray<FProcMeshTangent> tangents;
	tangents.Init(FProcMeshTangent(0.0f, 0.0f, 0.0f), 3);

	TArray<FVector2D> uvs;
	uvs.Init(FVector2D(0.0f, 0.0f), 3);

	TArray<FColor> colours;
	colours.Init(FColor::Black, 3);

	ProceduralMesh->CreateMeshSection(0, vertices, Triangles, normals, uvs, colours, tangents, false);
}

// Called when the game starts or when spawned
void AProceduralActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProceduralActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

