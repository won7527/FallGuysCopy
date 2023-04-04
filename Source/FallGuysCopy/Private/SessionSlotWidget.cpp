// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionSlotWidget.h"
#include "ServerGameInstance.h"
#include "Components/Button.h"

void USessionSlotWidget::NativeConstruct()
{
	gameInstance = Cast<UServerGameInstance>(GetGameInstance());

	btn_roomName->OnClicked.AddDynamic(this, &USessionSlotWidget::JoinRoom);
}

void USessionSlotWidget::JoinRoom()
{
	UE_LOG(LogTemp, Warning, TEXT("ASDAAS"));
	if (gameInstance != nullptr)
	{
		gameInstance->JoinMySession(index);
	}
}
