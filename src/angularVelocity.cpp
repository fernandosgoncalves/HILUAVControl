/*
 * angularVelocity.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "angularVelocity.h"

angularVelocity::angularVelocity() {
	// TODO Auto-generated constructor stub
	dotPhi = 0;
	dotPsi = 0;
	dotTheta = 0;
}

angularVelocity::~angularVelocity() {
	// TODO Auto-generated destructor stub
}

double angularVelocity::getDotPhi() {
	return dotPhi;
}

void angularVelocity::setDotPhi(double dotPhi) {
	this->dotPhi = dotPhi;
}

double angularVelocity::getDotPsi(){
	return dotPsi;
}

void angularVelocity::setDotPsi(double dotPsi) {
	this->dotPsi = dotPsi;
}

double angularVelocity::getDotTheta() {
	return dotTheta;
}

void angularVelocity::setDotTheta(double dotTheta) {
	this->dotTheta = dotTheta;
}


