#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include "../Models/Robot.h"
#include "../Consts.h"
#include <vector>

using namespace std;

class Behavior {
	vector<Behavior*> _behaviors;
protected:
	Robot* _robot;
public:
	Behavior(Robot* robot): _behaviors(NULL),_robot(robot){}
	virtual ~Behavior();
	virtual void action() = 0;
	virtual bool startCond() = 0;
	virtual bool stopCond() = 0;
	void addNext(Behavior* newBehavior);
	Behavior* selectNext();
};

#endif /* BEHAVIOR_H_ */
