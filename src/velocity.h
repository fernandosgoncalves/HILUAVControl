/*
 * velocity.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef VELOCITY_H_
#define VELOCITY_H_

class velocity {
	double dotX;
	double dotY;
	double dotZ;
public:
	velocity();
	virtual ~velocity();
	double getDotX();
	void setDotX(double dotX);
	double getDotY();
	void setDotY(double dotY);
	double getDotZ();
	void setDotZ(double dotz);
};

#endif /* VELOCITY_H_ */
