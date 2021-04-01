// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

class AEnemyCharacter;
/**
 * 
 */
UCLASS()
class ATTACKRPG_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY(BlueprintReadOnly)
	uint8 bIsRun : 1; // «∑Ò±º≈‹


	UPROPERTY()
		AEnemyCharacter* Enemy; //π÷ŒÔCharacter

};
