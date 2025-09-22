#include "WheelObstacle.h"
#include "TimerManager.h"


AWheelObstacle::AWheelObstacle()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
		StaticMeshComponent->SetRelativeScale3D(FVector(4.0f, 0.25f, 2.0f));
		StaticMeshComponent->AddRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>
		MaterialAsset(TEXT("/Game/WindmillValley/Materials/MaterialInstances/MI_WallCurved_01.MI_WallCurved_01"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void AWheelObstacle::BeginPlay()
{
	Super::BeginPlay();

	RotationSpeed = FMath::RandRange(30.0f, 180.0f);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		GetWorldTimerManager().SetTimer(WheelTimerHandle, this, &AWheelObstacle::RefeatRotation, 0.025f, true);
	}
}

// Called every frame
void AWheelObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWheelObstacle::RefeatRotation()
{
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * 0.025f, 0.0f));
}


