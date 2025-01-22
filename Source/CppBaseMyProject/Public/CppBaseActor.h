// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMechComponent;


USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotator = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

UCLASS()
class CPPBASEMYPROJECT_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mech;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FString InstanceName = "Actor";

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditAnywhere)
	bool IsAlive = true;


	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	UFUNCTION(BlueprintCallable)
	FVector SinMovement(FVector CurrentPosition);

	UPROPERTY(EditAnywhere)
	float Amplitude = 50;

	UPROPERTY(EditAnywhere)
	float Frequency = 20;

	FVector InitialLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

};
