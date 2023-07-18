// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityView.h"
#include "MSMassCollision.generated.h"


USTRUCT(BlueprintType)
struct MASSCOMMUNITYSAMPLE_API FMSSharedStaticMesh : public FMassSharedFragment
{
	GENERATED_BODY()
	FMSSharedStaticMesh() = default;

	explicit FMSSharedStaticMesh(const TSoftObjectPtr<UStaticMesh> InStaticMesh) : StaticMesh(InStaticMesh){};
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> StaticMesh;
};

// Fragment data about THIS mass entity hitting something else
USTRUCT(BlueprintType)
struct MASSCOMMUNITYSAMPLE_API FMSHitResultFragment : public FMassFragment
{
	GENERATED_BODY()
	FMSHitResultFragment() = default;

	explicit FMSHitResultFragment(const FHitResult& HitResult)
		: HitResult(HitResult){}

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FHitResult HitResult;
};

namespace MassSample::Collision
{
	// Does chaos raycast against a mesh from a shared static mesh in local space, then returns a mostly done FHitResult
	bool SingleRaycastEntityStaticMesh(FVector& From, FVector& To, FHitResult& OutHit, const FMSSharedStaticMesh* SharedMesh, FTransform WorldTransform);

	// Does collision calc between two world locations if this entity has a FMSSharedStaticMesh and FTransformFragment
	bool SingleRaycastEntityView(FMassEntityView& EntityView, FVector& From, FVector& To, FHitResult& OutHit);
}



