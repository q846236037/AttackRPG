// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "../EnemyCharacter.h"

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!Enemy)
	{
		Enemy = Cast<AEnemyCharacter>(TryGetPawnOwner());
		return;
	}

	bIsRun = FMath::RandBool();

}
