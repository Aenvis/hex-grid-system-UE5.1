// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

class UStaticMeshComponent;

UENUM()
enum class EHexTileType : uint8
{
	INVALID = 0,
	GRASS,
	WATER
};

UCLASS()
class HEXGRIDSYSTEM_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category = "Tile")
	FIntPoint TileIndex;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	EHexTileType TileType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* TileMesh;
	
public:	
	// Sets default values for this actor's properties
	AHexTile();
};
