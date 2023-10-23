// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Rat.generated.h"

class UCapsuleComponent;
class UInputMappingContext;
class UInputAction;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class RATA_API ARat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* RatMappingContext;

	void MoveForward(float value);

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
