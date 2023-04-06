// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadZone.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FallGuysCharacter.h"
#include "FallGuysGameModeBase.h"



// Sets default values
ADeadZone::ADeadZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	OnActorBeginOverlap.AddDynamic(this, &ADeadZone::OnOverlapped);

}

// Called when the game starts or when spawned
void ADeadZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeadZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeadZone::OnOverlapped(AActor* OverlappedActor, AActor* OtherActor)
{
	Player = Cast<AFallGuysCharacter>(OtherActor);
	if (Player && HasAuthority())
	{
		Player->SetActorHiddenInGame(true);
		Player->DisableInput(Cast<APlayerController>(GetWorld()->GetFirstPlayerController()));
		Player->ServerSetDeadNum();
	}
}