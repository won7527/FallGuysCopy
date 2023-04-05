// Fill out your copyright notice in the Description page of Project Settings.


#include "FallGuysPlayerController.h"
#include "InGameWidget.h"
#include "Kismet/GameplayStatics.h"
#include "FallGuysCharacter.h"

void AFallGuysPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bool IsMain = FString("MainMap") == UGameplayStatics::GetCurrentLevelName(GetWorld());
	if (InGameUI && IsLocalController() && IsMain)
	{
		GameUI = CreateWidget<UInGameWidget>(this, InGameUI);
		if (GameUI)
		{
			GameUI->AddToViewport(true);

		}
	}
}

void AFallGuysPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}