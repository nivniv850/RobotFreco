#ifndef MAP_H_
#define MAP_H_

#define RESOLUTION 0.1

#include "../Consts.h"

class Map {
private:
	int HeightMap;
	int WidthMap;
	int getColFromXPos(double x);
	int getRowFromYPos(double y);
	char** _mapMatrix;
public:
	Map(char** matrix, int HeightMap, int WidthMap);
	void setMapValue(double x, double y, char value);
	void printMap();
	char getMapValueFromRealLocation(double x, double y);
};

#endif
