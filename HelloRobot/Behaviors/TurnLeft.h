#ifndef TURNLEFT_H_
#define TURNLEFT_H_
#include "Behavior.h"

class TurnLeft: public Behavior {
public:
	TurnLeft(Robot* robot) : Behavior(robot) {}
	virtual ~TurnLeft();
	void action();
	bool startCond();
	bool stopCond();
};

#endif /* TURNLEFT_H_ */
