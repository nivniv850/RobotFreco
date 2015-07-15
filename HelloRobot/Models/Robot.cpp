#include "Robot.h"

using namespace std;

double Robot::getLaserScan(int index)
{
	return _lp[index];
}

void Robot::Read()
{
	_pc.Read();
}

void Robot::setSpeed(double linearSpeed, double angularSpeed)
{
	_pp.SetSpeed(linearSpeed,angularSpeed);
}

double Robot::getXPos()
{
	return _pp.GetXPos();
}

double Robot::getYPos()
{
	return _pp.GetYPos();
}

double Robot::getYaw()
{
	return _pp.GetYaw();
}

Robot::~Robot()
{
	delete &_pc;
	delete &_pp;
	delete &_lp;
}
