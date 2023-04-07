// Fill out your copyright notice in the Description page of Project Settings.


#include "FallGuysGameModeBase.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"




void AFallGuysGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	

}

AActor* AFallGuysGameModeBase::ChoosePlayerStart_Implementation(AController* player)
{
	for (TActorIterator<APlayerStart> Iter(GetWorld()); Iter; ++Iter)
	{
		APlayerStart* PS = *Iter;
		if (PS->PlayerStartTag != FName("Spawned"))
		{
			PS->PlayerStartTag = FName("Spawned");
			return PS;
		}
	}
	return nullptr;
}

