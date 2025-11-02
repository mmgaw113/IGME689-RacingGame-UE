// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "FirstPersonPlayerCharacter.generated.h"

class UArcGISLocationComponent;
class UArcGISCameraComponent;

UCLASS()
class IGME689_API AFirstPersonPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//void Move(const FInputActionValue& Value);
	//void Look(const FInputActionValue& Value);

	UArcGISCameraComponent* cameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	UArcGISLocationComponent* locationComponent;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess))
	UInputMappingContext* mappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Scenes/Input/IMC_FirstPerson.IMC_FirstPerson'"));
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess))
	UInputAction* move;
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess))
	UInputAction* look;

};
