// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingRoomWidget.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API UWaitingRoomWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;


public:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextSlot1;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextSlot2;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextSlot3;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TextSlot4;
	UPROPERTY(meta = (BindWidget))
		class UButton* ButtonStart;

	TArray<UTextBlock*> TextBlockArr; //= { TextSlot1, TextSlot2, TextSlot3, TextSlot4 };

	class AFallGuysCharacter* Player;

	UFUNCTION()
		void GameStart();

	void SetPlayerName(int32 Index, FString Name);
	
};
