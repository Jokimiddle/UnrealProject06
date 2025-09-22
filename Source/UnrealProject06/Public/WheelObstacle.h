#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheelObstacle.generated.h"

struct FTimerHandle;
UCLASS()
class UNREALPROJECT06_API AWheelObstacle : public AActor
{
	GENERATED_BODY()
	
protected:
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wheel Settings")
	UStaticMeshComponent* StaticMeshComponent;

	FTimerHandle WheelTimerHandle;

	virtual void BeginPlay() override;
public:	
	AWheelObstacle();
	virtual void Tick(float DeltaTime) override;
	void RefeatRotation();
};
