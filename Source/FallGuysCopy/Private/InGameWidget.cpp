// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"
#include "Kismet/KismetTextLibrary.h"
#include "Components/TextBlock.h"

void UInGameWidget::TimerSet(float Timer)
{
	Minute->SetText(UKismetTextLibrary::Conv_IntToText((int)Timer / 60));
	Second->SetText(UKismetTextLibrary::Conv_IntToText((int)Timer % 60));
}

void UInGameWidget::PlayerNumSet(int32 GameOverNum, int32 AllNum)
{
	GameOverPlayer->SetText(UKismetTextLibrary::Conv_IntToText(GameOverNum));
	GamePlayer->SetText(UKismetTextLibrary::Conv_IntToText(AllNum));
}