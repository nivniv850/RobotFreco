#ifndef MANAGER_H_
#define MANAGER_H_
#include "Behaviors/BehaviorsManager/BehaviorsManager.h"
#include "Behaviors/Behavior.h"
#include "Models/Robot.h"

// Noise to simulate real world wrong reads.
#define NOISE_POSITION_FACTOR 0.02
#define NOISE_YAW_FACTOR 0.01

class Manager {
	Robot* _robot;
	BehaviorsManager* _behaviorsManager;
	Behavior* _currBehavior;
	//SlamManager _slamManager;
public:
	Manager(Robot* robot, BehaviorsManager* plan);
	virtual ~Manager();
	void run();
};

#endif /* MANAGER_H_ */
