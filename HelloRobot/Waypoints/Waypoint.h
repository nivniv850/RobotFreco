/*
 * Waypoint.h
 *
 *  Created on: Jun 21, 2015
 *      Author: colman
 */

#ifndef WAYPOINT_H_
#define WAYPOINT_H_

class Waypoint {
private:
	float x,y;
public:
	Waypoint(float x, float y);
	virtual ~Waypoint();
	Waypoint* nextWaypoint;
};

#endif /* WAYPOINT_H_ */
