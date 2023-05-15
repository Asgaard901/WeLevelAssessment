// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBooleanValueChangedEvent, bool, NewValue);

UCLASS()
class WELEVELASSESSMENT_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATargetActor();

	// Custom function for setting the boolean variable. Triggers the event dispatcher.
	UFUNCTION(BlueprintCallable, Category = "Target Actor")
	void SetBooleanValue(const bool bNewBooleanValue);

	// An event dispatcher that is triggered when its boolean value changes
	UPROPERTY(BlueprintAssignable, Category = "Event Dispatchers")
	FBooleanValueChangedEvent OnBooleanValueChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Target Actor")
	bool bBooleanValue;
};