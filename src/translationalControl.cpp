/*
 * translationalControl.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "translationalControl.h"

translationalControl::translationalControl() {
	// TODO Auto-generated constructor stub

}

translationalControl::~translationalControl() {
	// TODO Auto-generated destructor stub
}

double translationalControl::getFxb() {
	return fxb;
}

void translationalControl::setFxb(double fxb) {
	this->fxb = fxb;
}

double translationalControl::getFzb() {
	return fzb;
}

void translationalControl::setFzb(double fzb) {
	this->fzb = fzb;
}

double translationalControl::getPhiRef() {
	return phiRef;
}

void translationalControl::setPhiRef(double phiRef) {
	this->phiRef = phiRef;
}

double translationalControl::getThetaRef() {
	return thetaRef;
}

void translationalControl::setThetaRef(double thetaRef) {
	this->thetaRef = thetaRef;
}

double translationalControl::getPsiRef() {
	return psiRef;
}

void translationalControl::setPsiRef(double psiRef) {
	this->psiRef = psiRef;
}

double translationalControl::getZeta1() {
	return zeta1;
}

void translationalControl::setZeta1(double zeta1) {
	this->zeta1 = zeta1;
}

double translationalControl::getZeta2() {
	return zeta2;
}

void translationalControl::setZeta2(double zeta2) {
	this->zeta2 = zeta2;
}

void translationalControl::transControl(errors er, atitude atd,
		double tauTheta) {
	double zeta1, zeta2, zeta3, auxThetaRef, auxPhiRef;

	zeta1 = -KPX * er.getErX() - KVX * er.getErDotX();

	zeta2 = -KPY * er.getErY() - KVY * er.getErDotY();

	zeta3 = -KPZ * er.getErZ() - KVZ * er.getErDotZ();

	this->zeta1 = zeta1;
	this->zeta2 = zeta2;

	//	Feedback Linearization
	this->fxb = tauTheta / H;

	this->fzb = (( M * zeta3 + M * G + sin(atd.getTheta()) * this->fxb)
			/ (cos(atd.getPhi()) * cos(atd.getTheta())));

	//	Implements the sigma function - equation(24) in equation (25)
	auxThetaRef =
			(M * zeta1 - sin(atd.getPsi()) * sin(atd.getPhi()) * this->fzb)
					/ (cos(atd.getPsi())
							* sqrt(
									pow(cos(atd.getPhi()), 2)
											* pow(this->fzb, 2)
											+ pow(this->fxb, 2)));

	if (auxThetaRef > 1)
		auxThetaRef = 1;
	else if (auxThetaRef < -1) {
		auxThetaRef = -1;
	}

	this->thetaRef = asin(auxThetaRef)
			- atan(this->fxb / (cos(atd.getPhi()) * this->fzb));

	//	Implements the sigma function - equation (24) in equation (29)
	//	aux_phi_ref = cos(psi)*m*(zeta1-zeta2)/Fzb; this is the equation in the article, which I believe is wrong
	//	auxPhiRef = (cos(an.getPsi()) / this->fzb)
	//	* (tan(an.getPsi()) * M * zeta1 - M * zeta2);

	auxPhiRef = (sin(atd.getPsi()) * M * zeta1 - cos(atd.getPsi()) * M * zeta2)
			/ this->fzb;

	if (auxPhiRef > 1)
		auxPhiRef = 1;
	else if (auxPhiRef < -1) {
		auxPhiRef = -1;
	}

	this->phiRef = asin(auxPhiRef);
}
