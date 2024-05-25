// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase; // forward declaration example

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile Data", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile Data", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* MovementComponent;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Projectile Data")
	class UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile Data", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* TrailParticleComponent;

	UPROPERTY(EditAnywhere, Category = "Projectile Data")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Projectile Data")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<UCameraShakeBase> HitCameraShakeClass;
};
