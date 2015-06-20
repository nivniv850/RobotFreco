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

using namespace PlayerCc;

int main() {

	// Init map
	ConfigurationManager config("/home/colman/Desktop/parameters.txt");
	Map map = CreateMap(config);

	// Put robot on map
	double* robotStartLocation = config.getStartLocation();
	map.setMapValue(robotStartLocation[0], robotStartLocation[1], ROBOT_CELL);

	// Put goal on map
	double* goalLocation = config.getGoal();
	map.setMapValue(goalLocation[0], goalLocation[1], GOAL_CELL);

	return 0;

}
