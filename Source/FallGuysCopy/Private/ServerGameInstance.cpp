// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerGameInstance.h"
#include <../Plugins/Online/OnlineSubsystem/Source/Public/OnlineSubsystem.h>
#include <../Plugins/Online/OnlineSubsystem/Source/Public/OnlineSessionSettings.h>

UServerGameInstance::UServerGameInstance()
{
	sessionID = "Test Session";
}

void UServerGameInstance::Init()
{
	IOnlineSubsystem* subsys = IOnlineSubsystem::Get();
	if (subsys)
	{
		sessionInterface = subsys -> GetSessionInterface();

		if (sessionInterface != nullptr)
		{

		}

	}
}

void UServerGameInstance::CreateMySession(FString roomName, int32 playerCount)
{
	if(sessionInterface != nullptr)
	{
		
		FOnlineSessionSettings sessionSettings;
		sessionSettings.bAllowInvites = false;
		sessionSettings.bAllowJoinInProgress = true;
		sessionSettings.bAllowJoinViaPresence = true;
		sessionSettings.bShouldAdvertise = true;
		sessionSettings.bIsDedicated = false;
		sessionSettings.bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "Null";
		sessionSettings.NumPublicConnections = playerCount;
		sessionSettings.Set(FName("KEY_RoomName"), roomName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
		sessionInterface->CreateSession(0, sessionID, sessionSettings);
		UE_LOG(LogTemp, Warning, TEXT("Create Session try!"));
	}

}

void UServerGameInstance::FindMySession()
{
	sessionSearch = MakeShareable(new FOnlineSessionSearch());
	sessionSearch->bIsLanQuery = IOnlineSubsystem::Get()->GetSubsystemName() == "Null";
	sessionSearch->MaxSearchResults = 30;
}
