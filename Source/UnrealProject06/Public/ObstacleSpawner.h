#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleSpawner.generated.h"

class AWheelObstacle;

UCLASS()
class UNREALPROJECT06_API AObstacleSpawner : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float RangeX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float RangeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	int32 SpawnCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Settings")
	float SpawnTime;

	FTimerHandle SpawnTimerHandle;
	TArray<AWheelObstacle*>Obstacles;
public:	
	AObstacleSpawner();
	virtual void Tick(float DeltaTime) override;
	void RefeatMove();
};
