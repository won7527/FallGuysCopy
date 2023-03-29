// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/Slider.h"
#include "Components/ScrollBox.h"
#include "Components/WidgetSwitcher.h"




void ULoginWidget::NativeConstruct()
{
	
	editText_id->SetText(FText::FromString(""));


	btn_start->OnClicked.AddDynamic(this, &ULoginWidget::ClickStart);
	btn_goCreate->OnClicked.AddDynamic(this, &ULoginWidget::GoCreate);
	btn_MainStart->OnClicked.AddDynamic(this, &ULoginWidget::WidgetStart);

}

void ULoginWidget::ClickStart()
{
	if (!editText_id->GetText().IsEmpty())
	{
		widgetSwicher->SetActiveWidgetIndex(1);

	}
	
}

void ULoginWidget::GoCreate()
{

}

void ULoginWidget::WidgetStart()
{
	widgetSwicher->SetActiveWidgetIndex(1);
	UE_LOG(LogTemp, Warning, TEXT("aaaaa"));

}
