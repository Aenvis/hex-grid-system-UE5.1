// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGridManager.h"
#include "HexTile.h"

// Sets default values
AHexGridManager::AHexGridManager()
{
	
}

// Called when the game starts or when spawned
void AHexGridManager::BeginPlay()
{
	Super::BeginPlay();
}

void AHexGridManager::SpawnGrid()
{
	HexGrid.SetNumZeroed(gridWidth);
	for(int32 i = 0; i < HexGrid.Num(); i++)
	{
		HexGrid[i].SetNumZeroed(gridHeight);
	}
	
	for (int32 y = 0; y < gridHeight; ++y)
	{
		for (int32 x = 0; x < gridWidth; ++x)
		{
			const bool oddRow = y % 2 == 1;
			const float xPos = oddRow ? x * TileHorizontalOffset + OddRowHorizontalOffset : x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			TSubclassOf<AHexTile> tileToSpawn = GrassHexTile;

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, FVector(xPos, yPos, 5), FRotator::ZeroRotator);
			newTile->TileIndex = FIntPoint(x, y);
			HexGrid[x][y] = newTile;
		}
	}
}

