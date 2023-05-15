#include "AsyncTask_ListenForBooleanChange.h"

void UAsyncTask_ListenForBooleanChange::Activate()
{
	Super::Activate();

	if (!IsValid(TargetActor)) return;

	TargetActor->OnBooleanValueChanged.AddUniqueDynamic(this, &UAsyncTask_ListenForBooleanChange::TargetBooleanValueChanged);

}

void UAsyncTask_ListenForBooleanChange::SetReadyToDestroy()
{
	StopListening();
	Super::SetReadyToDestroy();
}

UAsyncTask_ListenForBooleanChange* UAsyncTask_ListenForBooleanChange::ListenForBooleanChange(ATargetActor* TargetActor)
{
	UAsyncTask_ListenForBooleanChange* AsyncTaskNode = NewObject<UAsyncTask_ListenForBooleanChange>();
	if (!ensure(AsyncTaskNode)) return nullptr;

	AsyncTaskNode->TargetActor = TargetActor;

	return AsyncTaskNode;
}

void UAsyncTask_ListenForBooleanChange::StopListening()
{
	if (!IsValid(TargetActor)) return;
	
	TargetActor->OnBooleanValueChanged.RemoveDynamic(this, &UAsyncTask_ListenForBooleanChange::TargetBooleanValueChanged);
}

void UAsyncTask_ListenForBooleanChange::TargetBooleanValueChanged(const bool bNewValue)
{
	OnValueChanged.Broadcast(bNewValue);
}