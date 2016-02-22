/*
 * velocity.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "velocity.h"

velocity::velocity() {
	// TODO Auto-generated constructor stub
	dotX = 0;
	dotY = 0;
	dotZ = 0;
}

velocity::~velocity() {
	// TODO Auto-generated destructor stub
}

double velocity::getDotX() {
	return dotX;
}

void velocity::setDotX(double dotX) {
	this->dotX = dotX;
}

double velocity::getDotY() {
	return dotY;
}

void velocity::setDotY(double dotY) {
	this->dotY = dotY;
}

double velocity::getDotZ() {
	return dotZ;
}

void velocity::setDotZ(double dotz) {
	this->dotZ = dotz;
}
