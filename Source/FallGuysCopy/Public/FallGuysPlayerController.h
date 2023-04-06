// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FallGuysPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API AFallGuysPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			TSubclassOf<class UInGameWidget> InGameUI;

		UPROPERTY()
			class UInGameWidget* GameUI;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			TSubclassOf<class UWaitingRoomWidget> WaitingRoomUI;
		
		UPROPERTY()
			class UWaitingRoomWidget* WaitingRoomWidget;
};
