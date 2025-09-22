// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawner.h"
#include "WheelObstacle.h"

// Sets default values
AObstacleSpawner::AObstacleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	RangeX = 10.0f;
	RangeY = 10.0f;
	SpawnCount = 5;
	SpawnTime = 5;
}

// Called when the game starts or when spawned
void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
	Obstacles.Init(nullptr, SpawnCount);
	FVector SpawnLocation_0 = GetActorLocation();
	SpawnLocation_0.X -= RangeX;
	SpawnLocation_0.Y -= RangeY;

	FVector SpawnLocation_1 = GetActorLocation();
	SpawnLocation_1.X += RangeX;
	SpawnLocation_1.Y += RangeY;

	for (int32 i = 0; i < SpawnCount; i++)
	{
		FVector SpawnLocaiton(FMath::RandRange(SpawnLocation_0.X, SpawnLocation_1.X),
			FMath::RandRange(SpawnLocation_0.Y, SpawnLocation_1.Y),
			SpawnLocation_0.Z);
		AWheelObstacle* SpawnedActor = GetWorld()->SpawnActor<AWheelObstacle>(SpawnLocaiton, GetActorRotation());
		if (SpawnedActor)
		{
			Obstacles[i] = SpawnedActor;
		}
	}
	if (SpawnTime != 0)
	{
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AObstacleSpawner::RefeatMove, SpawnTime, true);
	}
}

// Called every frame
void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacleSpawner::RefeatMove()
{
	FVector SpawnLocation_0 = GetActorLocation();
	SpawnLocation_0.X -= RangeX;
	SpawnLocation_0.Y -= RangeY;

	FVector SpawnLocation_1 = GetActorLocation();
	SpawnLocation_1.X += RangeX;
	SpawnLocation_1.Y += RangeY;
	for (int32 i = 0; i < SpawnCount; i++)
	{
		FVector MoveLocaiton(FMath::RandRange(SpawnLocation_0.X, SpawnLocation_1.X),
			FMath::RandRange(SpawnLocation_0.Y, SpawnLocation_1.Y),
			Obstacles[i]->GetActorLocation().Z);
		Obstacles[i]->SetActorLocation(MoveLocaiton);
	}
}
