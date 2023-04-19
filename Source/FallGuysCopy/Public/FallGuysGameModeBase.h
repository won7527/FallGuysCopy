// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FallGuysGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API AFallGuysGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;


public:
	
	virtual AActor* ChoosePlayerStart_Implementation(AController* player) override;

};
