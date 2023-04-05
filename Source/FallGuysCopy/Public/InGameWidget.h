// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Minute;	
	
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* Second;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* GameOverPlayer;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* GamePlayer;

	void TimerSet(float Timer);
	void PlayerNumSet(int32 GameOverNum, int32 AllNum);
};
