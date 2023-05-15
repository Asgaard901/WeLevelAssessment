// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"

ATargetActor::ATargetActor()
{
	// Set the default value for the boolean variable
	bBooleanValue = false;
}

void ATargetActor::SetBooleanValue(const bool bNewBooleanValue)
{
	// Only trigger the event dispatcher if the value has changed
	if (bBooleanValue != bNewBooleanValue)
	{
		bBooleanValue = bNewBooleanValue;

		// Trigger the event dispatcher
		OnBooleanValueChanged.Broadcast(bBooleanValue);
	}
}