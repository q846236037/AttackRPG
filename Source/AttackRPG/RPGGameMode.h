// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RPGGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ATTACKRPG_API ARPGGameMode : public AGameMode
{
	GENERATED_BODY()
		ARPGGameMode();
protected:

	virtual void BeginPlay() override;
	
};
