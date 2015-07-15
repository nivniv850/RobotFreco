#include "MoveForward.h"
#include "../Models/Robot.h"

/**
 * Move forward
 */
void MoveForward::action()
{
	//_robot->setSpeed(FORWARD_SPEED,0.0);
}

bool MoveForward::startCond()
{
	// Move forward only if none of the front laser indexes found obstacle
	/*for(int i=RIGHT_LIMIT_LASER_INDEX; i<LEFT_LIMIT_LASER_INDEX; i++)
	{
		if(_robot->getLaserScan(i) < MIN_FRONT_DISTANCE)
			return false;
	}*/

	return true;
}

bool MoveForward::stopCond()
{
	return !startCond();
}

MoveForward::~MoveForward()
{
}
