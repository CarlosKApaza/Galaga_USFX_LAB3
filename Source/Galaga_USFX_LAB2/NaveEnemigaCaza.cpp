// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"

void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();
}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	VelocidadY = -100.0f;
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
    //Obtenemos la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();

    // Generamos nuevas coordenadas X e Y aleatorias
    float NuevaX = 0.0f; // No se mueve en el eje X

    // Calculamos la nueva posici�n en el eje Y
    float NuevaPosicionY = PosicionActual.Y + (VelocidadY * DeltaTime);

    // Verificamos si la nave ha alcanzado el l�mite superior o inferior
    if (NuevaPosicionY <= -1850.0f || NuevaPosicionY >= 1850.0f)
    {
        // Cambiamos la direcci�n multiplicando por -1
        VelocidadY *= -1.0f;
    }

    // Establecemos la nueva posici�n del actor
    SetActorLocation(FVector(NuevaX, NuevaPosicionY, PosicionActual.Z));
}