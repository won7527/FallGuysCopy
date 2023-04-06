// Fill out your copyright notice in the Description page of Project Settings.


#include "BGMManager.h"
#include <Components/AudioComponent.h>
#include <Sound/SoundBase.h>

// Sets default values
ABGMManager::ABGMManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	loadSound = CreateDefaultSubobject<UAudioComponent>(TEXT("loadSound"));
	ConstructorHelpers::FObjectFinder<USoundBase>bgm1(TEXT("/Script/Engine.SoundWave'/Game/JY/Assets/BGM/LoadingBGM.LoadingBGM'"));
	if (bgm1.Succeeded())
	{
		loadSound->SetSound(bgm1. Object);
	}

}

// Called when the game starts or when spawned
void ABGMManager::BeginPlay()
{
	Super::BeginPlay();

	loadSound->Play();
}

// Called every frame
void ABGMManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

