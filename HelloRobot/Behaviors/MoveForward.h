#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_
#include "Behavior.h"

class MoveForward : public Behavior {
public:
	MoveForward(Robot* robot) : Behavior(robot) {}
	virtual ~MoveForward();
	void action();
	bool startCond();
	bool stopCond();
};

#endif /* MOVEFORWARD_H_ */
