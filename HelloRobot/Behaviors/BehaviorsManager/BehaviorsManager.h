#ifndef BEHAVIORSMANAGER_H_
#define BEHAVIORSMANAGER_H_

#include "../Behavior.h"
#include "../MoveForward.h"
#include "../TurnLeft.h"
#include "../TurnRight.h"
#include <vector>

class BehaviorsManager
{
private:
	Behavior** _arrBehaviors;
public:
	BehaviorsManager(Robot* robot);
	Behavior* firstBehavior();
	virtual ~BehaviorsManager();
};


#endif /* BEHAVIORSMANAGER_H_ */
