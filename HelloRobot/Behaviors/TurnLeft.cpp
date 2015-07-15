#include "TurnLeft.h"

/**
 * Turn left
 */
void TurnLeft::action()
{
	//_robot->setSpeed(0.0, ROTATION_SPEED);
}

/**
 * Start Condition: Only if there is no obstacle
 * in the left side of the robot
 */
bool TurnLeft::startCond()
{
	// Goes all over the indexes of the laser that points to the left
	// side of the robot
	/*for(int i=CENTER_LASER_INDEX; i<MAX_LASER_INDEX; i++)
	{
		// Checks that there is no obstacle in the left side of the robot
		if(_robot->getLaserScan(i) < MIN_SIDE_DISTANCE)
		{
			return false;
		}
	}*/

	return true;
}

/**
 * If the robot can move forward, it stops to turn left
 */
bool TurnLeft::stopCond()
{
	// Goes all over the indexes of the laser that points
	// to the front of the robot
	/*for(int i=RIGHT_LIMIT_LASER_INDEX; i<LEFT_LIMIT_LASER_INDEX; i++)
	{
		// Checks there is no obstacle in front of the robot
		if (_robot->getLaserScan(i) <= MIN_FRONT_DISTANCE)
		{
			return false;
		}
	}*/

	return true;
}

TurnLeft::~TurnLeft()
{
}
