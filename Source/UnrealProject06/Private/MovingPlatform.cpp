#include "MovingPlatform.h"
#include "Components/ArrowComponent.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	StartPos = 0;
	EndPos = 0;
	MoveSpeed = 100.0f;
	MaxRange = 200.0f;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
		StaticMeshComponent->SetRelativeScale3D(FVector(5.0f, 5.0f, 0.25f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface>
		MaterialAsset(TEXT("/Game/WindmillValley/Materials/MaterialInstances/MI_WallCurved_01.MI_WallCurved_01"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComponent->SetMaterial(0, MaterialAsset.Object);
	}
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPos = GetActorLocation().X;
	EndPos = StartPos + MaxRange;
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currentlocation = GetActorLocation();
	if (FMath::IsNearlyZero(MoveSpeed) == false && FMath::IsNearlyZero(MaxRange) == false)
	{
		if (!direction)
		{
			SetActorLocation(FVector(currentlocation.X + (MoveSpeed * DeltaTime), currentlocation.Y, currentlocation.Z));
			if (currentlocation.X > EndPos) direction = !direction;
		}
		else
		{
			SetActorLocation(FVector(currentlocation.X + (MoveSpeed * DeltaTime * -1), currentlocation.Y, currentlocation.Z));
			if (currentlocation.X < StartPos) direction = !direction;
		}
	}
}

