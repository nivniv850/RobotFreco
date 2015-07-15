#include "Manager.h"
#include <math.h>

Manager::Manager(Robot* robot, BehaviorsManager* behaviorsManager)
{
	_robot = robot;
	_behaviorsManager = behaviorsManager;
	_currBehavior = _behaviorsManager->firstBehavior();
}

void Manager::run()
{
	// For fixing Player's BUG
	for(int i = 0; i < 15; i++)
	{
		_robot->Read();
	}

	double prevX = 0, prevY = 0, prevYaw = 0;
	double newX, newY, newYaw;

	while (_currBehavior != NULL)
	{
		while(!_currBehavior->stopCond())
		{
			_currBehavior->action();
			_robot->Read();

			// Get the robot's new location
			newX = _robot->getXPos();
			newY = _robot->getYPos();
			newYaw = _robot->getYaw();

			// Use some noise to simulate real world wrong reads.
			newX = newX + ((double) rand() / (RAND_MAX)) * 2 * NOISE_POSITION_FACTOR - NOISE_POSITION_FACTOR;
			newY = newY + ((double) rand() / (RAND_MAX)) * 2 * NOISE_POSITION_FACTOR - NOISE_POSITION_FACTOR;
			newYaw = newYaw + ((double) rand() / (RAND_MAX)) * 2 * NOISE_YAW_FACTOR - NOISE_YAW_FACTOR;

			cout << "Robot's position: " << newX << ", " << newY << ", " << newYaw << endl;

			// Update particles and printing the map
			//_slamManager.update(newX - prevX, newY - prevY, newYaw - prevYaw);

			prevX = newX;
			prevY = newY;
			prevYaw = newYaw;
		}

		_currBehavior = _currBehavior->selectNext();
	}
}

Manager::~Manager() {
}
