#include "Behavior.h"

void Behavior::addNext(Behavior* behaviorToAdd)
{
	_behaviors.push_back(behaviorToAdd);
}

Behavior* Behavior::selectNext()
{
	Behavior* currBehavior= NULL;
	int nBehaviorsSize = _behaviors.size();
	bool isFoundBehavior = false;

	// Searches for the first behavior that can start
	for(int i=0; i < nBehaviorsSize && !isFoundBehavior; i++)
	{
		currBehavior = _behaviors[i];

		// Checks if the current behavior can start
		if (currBehavior->startCond())
		{
			// Signs that there is a behavior that can start
			// and stops the loop
			isFoundBehavior = true;
		}
	}

	return currBehavior;
}

Behavior::~Behavior()
{
	/*if (_behaviors != NULL)
	{
		_behaviors.clear();
		delete _behaviors;
	}*/
}
