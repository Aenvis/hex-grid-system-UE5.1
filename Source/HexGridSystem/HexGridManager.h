// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HexTile.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

class AHexTile;

UCLASS(Blueprintable)
class HEXGRIDSYSTEM_API AHexGridManager : public AActor
{
	GENERATED_BODY()

protected:
	TArray<TArray<AHexTile*>> HexGrid;
	
	UPROPERTY(EditAnywhere, Category = "HexGrid | Layout")
	int32 gridWidth;
	
	UPROPERTY(EditAnywhere, Category = "HexGrid | Layout")
	int32 gridHeight;

	UPROPERTY(EditAnywhere, Category = "HexGrid | Layout")
	float TileHorizontalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid | Layout")
	float OddRowHorizontalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid | Layout")
	float TileVerticalOffset;

	UPROPERTY(EditAnywhere, Category = "HexGrid | Setup")
	TSubclassOf<AHexTile> GrassHexTile;
	
public:	
	// Sets default values for this actor's properties
	AHexGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "C++ Methods")
	void SpawnGrid();

};
