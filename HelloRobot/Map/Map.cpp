#include <fstream>
#include <iostream>
#include <math.h>
#include "Map.h"

using namespace std;

Map::Map(char** matrix, int height, int width)
{
	HeightMap = height;
	WidthMap = width;
	_mapMatrix = matrix;
}

void Map::setMapValue(double x, double y, char value)
{
	int col = getColFromXPos(x);
	int row = getRowFromYPos(y);

	if (_mapMatrix[row][col] != BLOCK_CELL)
	{
		_mapMatrix[row][col] = value;
	}
}

void Map::printMap()
{
	for (int i= HeightMap - 1; i >= 0 ; i--)
	{
		for (int j= WidthMap - 1; j >= 0; j--)
		{
			cout << _mapMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

char Map::getMapValueFromRealLocation(double x, double y)
{
	int col = getColFromXPos(x);
	int row = getRowFromYPos(y);
	return _mapMatrix[row][col];
}

int Map::getColFromXPos(double x)
{
	return (x / RESOLUTION) + (WidthMap / 2);
}

int Map::getRowFromYPos(double y)
{
	return (HeightMap / 2) - (y / RESOLUTION);
}


