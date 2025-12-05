#include "GhostActor.h"
#include "Net/UnrealNetwork.h"

AGhostActor::AGhostActor()
{
 	bReplicates = true; // নেটওয়ার্কিং অন
    GhostMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GhostMesh"));
    RootComponent = GhostMesh;
    bIsVisible = false;
}

void AGhostActor::BeginPlay()
{
	Super::BeginPlay();
    // গেম শুরু হলে ভুত অদৃশ্য থাকবে
    if(GhostMesh) GhostMesh->SetVisibility(false);
}

void AGhostActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    // bIsVisible ভ্যারিয়েবলটি সবার সাথে সিঙ্ক হবে
    DOREPLIFETIME(AGhostActor, bIsVisible);
}

void AGhostActor::OnRep_IsVisible()
{
    // সার্ভার থেকে সিগন্যাল আসলে ভুত দৃশ্যমান হবে
    if(GhostMesh) GhostMesh->SetVisibility(bIsVisible);
}

void AGhostActor::Server_RevealGhost_Implementation()
{
    bIsVisible = true;
    OnRep_IsVisible(); // হোস্ট নিজেও দেখবে

    // ৫ সেকেন্ড পর আবার অদৃশ্য হবে
    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
    {
        bIsVisible = false;
        OnRep_IsVisible();
    }, 5.0f, false);
}
