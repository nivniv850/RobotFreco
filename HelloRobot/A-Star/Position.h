/*
 * Position.h
 *
 *  Created on: Jun 20, 2015
 *      Author: colman
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	Position(int x, int y);
	virtual ~Position();
	int x, y;
};

#endif /* POSITION_H_ */
