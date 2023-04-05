// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInfoWidget.h"
#include "Components/TextBlock.h"

void UPlayerInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayerInfoWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

}

void UPlayerInfoWidget::SetName(FString PlayerName)
{
	Name->SetText(FText::FromString(PlayerName));
	
}