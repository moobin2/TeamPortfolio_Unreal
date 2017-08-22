// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleTreasureBox.h"
#include "Engine.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ATitleTreasureBox::ATitleTreasureBox()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 메쉬컴포넌트를 루트 컴포넌트로
	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = BoxMesh;
	
	// 박스 메쉬를 불러온다
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Box(TEXT("StaticMesh'/Game/SimpleDungeons/Meshes/Props/SM_Prop_Chest_Skull_01.SM_Prop_Chest_Skull_01'"));
	BoxMesh->SetStaticMesh(SM_Box.Object);

	// 스프링암, 카메라 설정
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BoxMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 150.0f), FRotator(-50.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 1100.0f;
	SpringArm->bDoCollisionTest = false;
	//SpringArm->bUsePawnControlRotation = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ATitleTreasureBox::BeginPlay()
{
	Super::BeginPlay();

	MaxSpeed = 0.2;
	CurrentSpeed = 0.0f;
	
}

// Called every frame
void ATitleTreasureBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentSpeed += 0.0001;

	if (CurrentSpeed >= MaxSpeed)
	{
		CurrentSpeed = MaxSpeed;
	}

	SpringArm->AddWorldRotation(FRotator(0.0f, CurrentSpeed, 0.0f));

}

// Called to bind functionality to input
void ATitleTreasureBox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

