#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UArrowComponent;

UCLASS()
class UNREALPROJECT06_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
private:	
protected:
	float StartPos;
	float EndPos;
	bool direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;
public:	
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;
};
