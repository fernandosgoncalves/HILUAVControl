/*
 * position.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "position.h"

position::position() {
	// TODO Auto-generated constructor stub
	x = 0;
	y = 0;
	z = 0;
}

position::~position() {
	// TODO Auto-generated destructor stub
}

double position::getX() {
	return x;
}

void position::setX(double x) {
	this->x = x;
}

double position::getY() {
	return y;
}

void position::setY(double y) {
	this->y = y;
}

double position::getZ() {
	return z;
}

void position::setZ(double z) {
	this->z = z;
}
