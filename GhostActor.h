#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GhostActor.generated.h"

UCLASS()
class SPECTERHUNTERMR_API AGhostActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGhostActor();

    // ভুতের শরীর (Mesh)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Specter")
    UStaticMeshComponent* GhostMesh;

    // ভুত দেখা যাচ্ছে কি না (Network Replicated)
    UPROPERTY(ReplicatedUsing = OnRep_IsVisible)
    bool bIsVisible;

    UFUNCTION()
    void OnRep_IsVisible();

    // সার্ভারকে বলার ফাংশন: "ভুত রিভিল কর"
    UFUNCTION(Server, Reliable, BlueprintCallable)
    void Server_RevealGhost();

protected:
	virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
