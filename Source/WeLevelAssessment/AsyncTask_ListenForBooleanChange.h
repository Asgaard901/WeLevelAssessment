#pragma once

#include "CoreMinimal.h"
#include "TargetActor.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncTask_ListenForBooleanChange.generated.h"

class ATargetActor;

// Delegate Declaration
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResponseDelegate, bool, NewValue);

// MetaTag exposes the reference to the node as output pin in BP
// BlueprintType Exposes this class as a type that can be used for variables in Blueprints.
UCLASS(BlueprintType, meta=(ExposedAsyncProxy = AsyncTask))
class WELEVELASSESSMENT_API UAsyncTask_ListenForBooleanChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	virtual void SetReadyToDestroy() override;
	//~UBlueprintAsyncActionBase interface

protected:
	// BP Exec output using delegate
	UPROPERTY(BlueprintAssignable)
	FResponseDelegate OnValueChanged;

	// Creates the node
	UFUNCTION(BlueprintCallable, Category = "Custom Async Node", meta = (BlueprintInternalUseOnly = "true"))
	static UAsyncTask_ListenForBooleanChange* ListenForBooleanChange(ATargetActor* TargetActor);

	// Unbinds from node's execution pin from target's delegate
	UFUNCTION(BlueprintCallable, Category = "Custom Async Node")
	void StopListening();

	// Broadcasts the OnValueChanged delegate
	UFUNCTION()
	void TargetBooleanValueChanged(bool bNewValue);

private:
	UPROPERTY()
	ATargetActor* TargetActor;
};