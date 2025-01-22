// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mech = CreateDefaultSubobject<UStaticMeshComponent>("Mech");
	SetRootComponent(Mech);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = { 0.0f, 0.0f, 0.0f };
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called every frame
void ACppBaseActor::ShowActorInformation()
{
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

FVector ACppBaseActor::SinMovement(FVector CurrentPosition)
{
	CurrentPosition.Z = Amplitude * FMath::Sin(GetWorld()->GetTimeSeconds() * Frequency) + CurrentPosition.Z;
	return CurrentPosition;
}
			