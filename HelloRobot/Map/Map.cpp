#include <fstream>
#include <iostream>
#include <math.h>
#include "Map.h"

using namespace std;

Map::Map(char** matrix, int height, int width, float resolution)
{
	HeightMap = height;
	WidthMap = width;
	_mapMatrix = matrix;
	this->resolution = resolution;
}

void Map::setMapValueFromRealLocation(double x, double y, char value)
{
	setMapValue(getRowFromYPos(y), getColFromXPos(x), value);
}

void Map::setMapValue(int row, int col, char value)
{
	if (_mapMatrix[row][col] != BLOCK_CELL)
	{
		_mapMatrix[row][col] = value;
	}
}

void Map::printMap()
{
	for (int i= 0; i < HeightMap ; i++)
	{
		for (int j= 0; j < WidthMap; j++)
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

char Map::getMapValue(int row, int col)
{
	return _mapMatrix[row][col];
}

int Map::getColFromXPos(double x)
{
	int r = round((x / resolution) + ((double)WidthMap / 2));
	return r;
}

int Map::getRowFromYPos(double y)
{
	return round(((double)HeightMap / 2) - (y / resolution));
}

int Map::getMapHeight()
{
	return HeightMap;
}

int Map::getMapWidth()
{
	return WidthMap;
}


