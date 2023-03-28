// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()

	class UEditableTextBox* editText_id;
	class UButton* btn_start;
	class UButton* btn_goCreate;
	class UButton* btn_GoFind;
	class UEditableTextBox* editText_RoomName;
	class UTextBlock* text_PlayerCount;
	class UButton* btn_CreateBack;
	class UButton* btn_CreateSession;
	class USlider* sl_playerCount;
	class UScrollBox* sbox_RoomList;
	class UButton* btn_FindBack;
	class UButton* btn_Refresh;


};
