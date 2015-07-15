#include "BehaviorsManager.h"

BehaviorsManager::BehaviorsManager(Robot* robot)
{
	_arrBehaviors = new Behavior*[3];

	// Create the behaviors
	_arrBehaviors[0] = new MoveForward(robot);
	_arrBehaviors[1] = new TurnLeft(robot);
	_arrBehaviors[2] = new TurnRight(robot);

	// Set the next behaviors for each behavior
	_arrBehaviors[0]->addNext(_arrBehaviors[1]);
	_arrBehaviors[0]->addNext(_arrBehaviors[2]);
	_arrBehaviors[1]->addNext(_arrBehaviors[0]);
	_arrBehaviors[2]->addNext(_arrBehaviors[0]);
}

Behavior* BehaviorsManager::firstBehavior()
{
	return _arrBehaviors[0];
}

BehaviorsManager::~BehaviorsManager()
{
	if (_arrBehaviors != NULL)
	{
		delete[] _arrBehaviors;
	}
}
