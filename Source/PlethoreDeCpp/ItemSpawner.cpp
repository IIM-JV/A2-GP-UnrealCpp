// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSpawner.h"
#include "Components/BillboardComponent.h"
#include "Item.h"

// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

#if WITH_EDITOR
	EditorBillboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("EditorBillboard"));
	EditorBillboard->SetupAttachment(Scene);
#endif

	RootComponent = Scene;
}

void AItemSpawner::BeginPlay()
{
	UWorld* World = GetWorld();
	check(World);

	AItem* SpawnedItem = World->SpawnActor<AItem>(ItemToSpawn, Scene->GetComponentTransform());
}
