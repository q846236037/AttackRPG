// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "EnemyCharacter.generated.h"


UCLASS()
class ATTACKRPG_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()
		AEnemyCharacter();
public:
	// Sets default values for this character's properties

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FGenericTeamId GetGenericTeamID() { return TeamId; };
protected:
	FGenericTeamId TeamId;
};
