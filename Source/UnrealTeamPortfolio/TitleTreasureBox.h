// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TitleTreasureBox.generated.h"

UCLASS()
class UNREALTEAMPORTFOLIO_API ATitleTreasureBox : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATitleTreasureBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
		class UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* BoxMesh;

	float CurrentSpeed;
	float MaxSpeed;
	
};
