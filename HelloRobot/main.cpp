/*
 * main.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */
// lior
// Niv
#include <libplayerc++/playerc++.h>
#include "ConfigurationManager.h"
#include "MapLoader/MapLoader.h"
#include "A-Star/AStar.h"
#include "Waypoints/Waypoint.h"
#include "Waypoints/WaypointsManager.h"

using namespace PlayerCc;

int main() {

	// Init map
	ConfigurationManager config("/home/colman/Desktop/parameters.txt");
	Map map = CreateMap(config);

	// Put robot on map
	double* robotStartLocation = config.getStartLocation();
	//map.setMapValueFromRealLocation(robotStartLocation[0], robotStartLocation[1], ROBOT_CELL);

	// Put goal on map
	double* goalLocation = config.getGoal();
	//map.setMapValueFromRealLocation(goalLocation[0], goalLocation[1], GOAL_CELL);

	AStar* astar = new AStar(&map);
	vector<Position*> path = astar->findPath(map.getRowFromYPos(robotStartLocation[1]),
											 map.getColFromXPos(robotStartLocation[0]),
											 map.getRowFromYPos(goalLocation[1]),
											 map.getColFromXPos(goalLocation[0]));

	for(int i = 0; i < path.size(); i++)
	{
		map.setMapValue(path[i]->row, path[i]->col, PATH_CELL);
	}

	map.setMapValueFromRealLocation(robotStartLocation[0], robotStartLocation[1], ROBOT_CELL);
	map.setMapValueFromRealLocation(goalLocation[0], goalLocation[1], GOAL_CELL);

	map.printMap();

	// Create waypoints
	WaypointsManager manager(map.getMapWidth(), map.getMapHeight(), config.getMapResolutionCM() / 100);
	Waypoint* startWaypoint = manager.createWaypoints(path);

	int i=1;
	while (startWaypoint){
		cout << i << "/n";
		i++;
		startWaypoint = startWaypoint->nextWaypoint;
	}

	return 0;

}
