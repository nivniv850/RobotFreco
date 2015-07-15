#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include <libplayerc++/playerc++.h>

using namespace std;
using namespace PlayerCc;

class Robot {
private:
	PlayerClient _pc;
	Position2dProxy _pp;
	LaserProxy _lp;
public:
	Robot(char* host, int port):_pc(host,port), _pp(&_pc),_lp(&_pc){}
	virtual ~Robot();
	double getLaserScan(int index);
	void Read();
	void setSpeed(double linearSpeed, double angularSpeed);
	double getXPos();
	double getYPos();
	double getYaw();
};

#endif /* ROBOT_H_ */
