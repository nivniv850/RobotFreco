/*
 * WaypointsManger.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: colman
 */

#include "WaypointsManager.h"

using namespace std;

WaypointsManager::WaypointsManager(int w, int h, int r){
	WidthMap = w;
	HeightMap = h;
	resoultion = r;
}

WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}

// Creates the waypoint from the path, a way point will be created in a corner or every 4 cells of the map
Waypoint* WaypointsManager::createWaypoints(vector<Position*> positionArray)
{
	int numberOfCells = 0;
	int* currentWay;
	Waypoint* firstWaypoint;
	Waypoint* waypoint;

	// First way point will be the first cell of the path
	firstWaypoint  = waypoint = new Waypoint(getXFromCol(positionArray[0]->col), getYFromRow(positionArray[0]->row));
	currentWay = getWay(positionArray[0], positionArray[1]);

	// Go over all the positions
	for (int i = 1; i < positionArray.size() - 1; i++)
	{
		int* nextWay = getWay(positionArray[i], positionArray[i + 1]);

		// Check if the way is changed (corner). Also check if it is the fourth position
		if (currentWay[0] !=  nextWay[0] || currentWay[1] != nextWay[1] || numberOfCells == 4)
		{
			waypoint->nextWaypoint = new Waypoint(getXFromCol(positionArray[i]->col), getYFromRow(positionArray[i]->row));
			waypoint = waypoint->nextWaypoint;
			numberOfCells = 0;
		}

		numberOfCells++;
		currentWay = nextWay;
	}

	// The last position of the path is a waypoint
	waypoint->nextWaypoint = new Waypoint(getXFromCol(positionArray[positionArray.size() - 1]->col),
										  getYFromRow(positionArray[positionArray.size() - 1]->row));

	return firstWaypoint;
}

int* WaypointsManager::getWay(Position* current, Position* next)
{
	int* way = new int[2];
	way[0] = current->row - next->row;
	way[1] = current->col - next ->col;
	return way;
}

float WaypointsManager::getXFromCol(int col)
{
	return (col - ((double)WidthMap / 2)) * resoultion;
}

float WaypointsManager::getYFromRow(int row)
{
	return (row + ((double)HeightMap / 2)) * resoultion;
}
