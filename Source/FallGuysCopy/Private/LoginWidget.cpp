// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/Slider.h"
#include "Components/ScrollBox.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "ServerGameInstance.h"




void ULoginWidget::NativeConstruct()
{
	
	editText_id->SetText(FText::FromString(""));
	text_PlayerCount->SetText(FText::FromString("2"));
	sl_playerCount->SetValue(2.0f);
	editText_roomName->SetText(FText::FromString(""));

	btn_Login->OnClicked.AddDynamic(this, &ULoginWidget::ClickLogin);
	btn_goCreate->OnClicked.AddDynamic(this, &ULoginWidget::GoCreate);
	btn_MainStart->OnClicked.AddDynamic(this, &ULoginWidget::WidgetStart);
	btn_GoFind->OnClicked.AddDynamic(this, &ULoginWidget::FindServer);
	sl_playerCount->OnValueChanged.AddDynamic(this, &ULoginWidget::MoveSlider);
	btn_FindBack->OnClicked.AddDynamic(this, &ULoginWidget::GoBack);
	btn_CreateBack->OnClicked.AddDynamic(this, &ULoginWidget::ClickBack);

	gameInstance = Cast<UServerGameInstance>(GetGameInstance());
}

void ULoginWidget::ClickLogin()
{
	if (!editText_id->GetText().IsEmpty())
	{

		widgetSwicher->SetActiveWidgetIndex(2);
	}
	
}

void ULoginWidget::GoCreate()
{
	widgetSwicher->SetActiveWidgetIndex(3);
}

void ULoginWidget::WidgetStart()
{
	widgetSwicher->SetActiveWidgetIndex(1);
	UE_LOG(LogTemp, Warning, TEXT("aaaaa"));

}

void ULoginWidget::CreateServer()
{
	int32 playerCnt = FMath::RoundHalfFromZero(sl_playerCount->GetValue());
	gameInstance->CreateMySession(editText_roomName->GetText().ToString(), playerCnt);
}

void ULoginWidget::FindServer()
{
	widgetSwicher->SetActiveWidgetIndex(4);
}

void ULoginWidget::MoveSlider(float value)
{
	int32 newval = FMath::RoundHalfFromZero(value);
	text_PlayerCount->SetText(FText::AsNumber(newval));
}

void ULoginWidget::GoBack()
{
	widgetSwicher->SetActiveWidgetIndex(2);
}

void ULoginWidget::ClickBack()
{
	widgetSwicher->SetActiveWidgetIndex(2);
}
