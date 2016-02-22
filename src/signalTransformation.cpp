/*
 * signalTransformation.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "signalTransformation.h"

signalTransformation::signalTransformation() {
	// TODO Auto-generated constructor stub

}

signalTransformation::~signalTransformation() {
	// TODO Auto-generated destructor stub
}

double signalTransformation::getAlphaL() {
	return alphaL;
}

void signalTransformation::setAlphaL(double alphaL) {
	this->alphaL = alphaL;
}

double signalTransformation::getAlphaR() {
	return alphaR;
}

void signalTransformation::setAlphaR(double alphaR) {
	this->alphaR = alphaR;
}

double signalTransformation::getFL() {
	return fL;
}

void signalTransformation::setFL(double l) {
	fL = l;
}

double signalTransformation::getFR() {
	return fR;
}

void signalTransformation::setFR(double r) {
	fR = r;
}

void signalTransformation::sigTrans(translationalControl trans, rotacionalControl rot) {
	//	Developed equations
	this->fR = 0.5
			* sqrt(
					pow((rot.getTauTheta() / H + rot.getTauPsi() / L), 2)
							+ pow((-trans.getFzb() + rot.getTauPhi() / L), 2));

	this->fL = 0.5
			* sqrt(
					pow((-rot.getTauTheta() / H + rot.getTauPsi() / L), 2)
							+ pow((trans.getFzb() + rot.getTauPhi() / L), 2));

	this->alphaR = atan(
			(rot.getTauTheta() / H + rot.getTauPsi() / L)
					/ (trans.getFzb() - rot.getTauPhi() / L));

	this->alphaL = atan(
			(rot.getTauTheta() / H - rot.getTauPsi() / L)
					/ (trans.getFzb() + rot.getTauPhi() / L));
}

