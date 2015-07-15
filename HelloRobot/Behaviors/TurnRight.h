#ifndef TURNRIGHT_H_
#define TURNRIGHT_H_
#include "Behavior.h"

class TurnRight: public Behavior {
public:
	TurnRight(Robot* robot) : Behavior(robot) {}
	virtual ~TurnRight();
	void action();
	bool startCond();
	bool stopCond();
};

#endif /* TURNRIGHT_H_ */
