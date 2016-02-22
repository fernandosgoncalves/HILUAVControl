/*
 * atitude.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "atitude.h"

atitude::atitude() {
	// TODO Auto-generated constructor stub
	phi = 0;
	psi = 0;
	theta = 0;

}

atitude::~atitude() {
	// TODO Auto-generated destructor stub
}

double atitude::getPhi() {
	return phi;
}

void atitude::setPhi(double phi) {
	this->phi = phi;
}

double atitude::getPsi() {
	return psi;
}

void atitude::setPsi(double psi) {
	this->psi = psi;
}

double atitude::getTheta() {
	return theta;
}

void atitude::setTheta(double theta) {
	this->theta = theta;
}
