// Fill out your copyright notice in the Description page of Project Settings.


#include "WaitingRoomWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "FallGuysCharacter.h"

void UWaitingRoomWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Player = Cast<AFallGuysCharacter>(GetOwningPlayerPawn());
	ButtonStart->OnClicked.AddDynamic(this, &UWaitingRoomWidget::GameStart);
	TextBlockArr.Add(TextSlot1);
	TextBlockArr.Add(TextSlot2);
	TextBlockArr.Add(TextSlot3);
	TextBlockArr.Add(TextSlot4);
}

void UWaitingRoomWidget::GameStart()
{
	if (Player->HasAuthority())
	{
		Player->ServerSetRoomVisibility();
	}
	
}

void UWaitingRoomWidget::SetPlayerName(int32 Index, FString Name)
{
	
	TextBlockArr[Index]->SetText(FText::FromString(Name));
	//TextBlockArr[Index]->SetText(FText::FromString(FString("Ready!!")));
	
}