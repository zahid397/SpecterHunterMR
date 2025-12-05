#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ScannerController.generated.h"

UCLASS()
class SPECTERHUNTERMR_API AScannerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    // মোবাইল বাটন থেকে এই ফাংশন কল হবে
    UFUNCTION(BlueprintCallable, Category = "Specter")
    void TriggerScan();

    // সার্ভারকে রিকোয়েস্ট পাঠাবে চেক করার জন্য
    UFUNCTION(Server, Reliable)
    void Server_CheckGhosts(FVector PlayerLocation);
};
