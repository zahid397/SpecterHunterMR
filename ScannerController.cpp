#include "ScannerController.h"
#include "GhostActor.h"
#include "Kismet/GameplayStatics.h"

void AScannerController::TriggerScan()
{
    if(GetPawn())
    {
        // সার্ভারকে নিজের লোকেশন পাঠাচ্ছি
        Server_CheckGhosts(GetPawn()->GetActorLocation());
    }
}

void AScannerController::Server_CheckGhosts_Implementation(FVector PlayerLocation)
{
    TArray<AActor*> FoundGhosts;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGhostActor::StaticClass(), FoundGhosts);

    for (AActor* Actor : FoundGhosts)
    {
        AGhostActor* Ghost = Cast<AGhostActor>(Actor);
        if (Ghost)
        {
            // ১০ মিটার (1000 units) এর মধ্যে ভুত থাকলে রিভিল হবে
            float Distance = FVector::Dist(PlayerLocation, Ghost->GetActorLocation());
            if (Distance < 1000.0f)
            {
                Ghost->Server_RevealGhost();
            }
        }
    }
}
