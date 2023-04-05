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
public:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UEditableText* editText_id;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_Login;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_goCreate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_GoFind;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* text_PlayerCount;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_CreateBack;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_CreateSession;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class USlider* sl_playerCount;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UScrollBox* sbox_RoomList;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_FindBack;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_Refresh;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UEditableText* editText_roomName;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UWidgetSwitcher* widgetSwicher;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_MainStart;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta=(BindWidget))
	class UButton* btn_Quit;


	UPROPERTY(EditAnywhere)
	TSubclassOf<class USessionSlotWidget> sessionSlot;


	class UServerGameInstance* gameInstance;

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void ClickLogin();
	UFUNCTION()
	void GoCreate();
	UFUNCTION()
	void WidgetStart();
	UFUNCTION()
	void CreateServer();
	UFUNCTION()
	void FindServer();
	UFUNCTION()
	void MoveSlider(float value);
	UFUNCTION()
	void GoBack();
	UFUNCTION()
	void ClickBack();
	UFUNCTION()
	void RefreshList();
	UFUNCTION()
	void AddNewSlot(FSessionInfo sessionInfo);
	UFUNCTION()
	void RefreshEnabled();
	UFUNCTION()
	void QuitGame();
	UFUNCTION()
	void PlayMusic();
};
