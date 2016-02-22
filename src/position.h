/*
 * position.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef POSITION_H_
#define POSITION_H_

class position {
	double x;
	double y;
	double z;
public:
	position();
	virtual ~position();
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);
	double getZ();
	void setZ(double z);
};

#endif /* POSITION_H_ */
