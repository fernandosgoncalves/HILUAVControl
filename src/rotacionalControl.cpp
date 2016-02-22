/*
 * rotacionalControl.cpp
 *
 *  Created on: 18/05/2014
 *      Author: fernando
 */

#include "rotacionalControl.h"
#include "Eigen/Dense"
#include <math.h>

using namespace Eigen;

rotacionalControl::rotacionalControl() {
	// TODO Auto-generated constructor stub

}

rotacionalControl::~rotacionalControl() {
	// TODO Auto-generated destructor stub
}

void rotacionalControl::setTauPhi(double tauPhi) {
	this->tauPhi = tauPhi;
}

double rotacionalControl::getTauPhi() {
	return this->tauPhi;
}

void rotacionalControl::setTauTheta(double tauTheta) {
	this->tauTheta = tauTheta;
}

double rotacionalControl::getTauTheta() {
	return this->tauTheta;
}

void rotacionalControl::setTauPsi(double tauPsi) {
	this->tauPsi = tauPsi;
}

double rotacionalControl::getTauPsi() {
	return this->tauPsi;
}

void rotacionalControl::rotationalController(atitude atd,
		angularVelocity angVel, references ref, translationalControl trans) {
	//float atitude[3]
	//atitude[0] => phi;
	//atitude[1] => theta;
	//atitude[2] => psi;

	//float refAtitude[3]
	//refAtitude[0] => phiRef;
	//refAtitude[1] => thetaRef;
	//refAtitude[2] => psiRef;

	//float velAngular[3]
	//velAngular[0] => dotPhi;
	//velAngular[1] => dotTheta;
	//velAngular[2] => dotPsi;

	//float refVelAngular[3]
	//velAngular[0] => dotPhiRef;
	//velAngular[1] => dotThetaRef;
	//velAngular[2] => dotPsiRef;

	double gamma1, gamma2, gamma3, c11, c12, c13, c21, c22, c23, c31, c32, c33,
			mt11, mt12, mt13, mt21, mt22, mt23, mt31, mt32, mt33;

	MatrixXd mt(3, 3), ctt(3, 3), tau(3, 1);
	VectorXd gamma(3), dotTheta(3);

	tau = MatrixXd::Zero(3, 1);

	gamma1 = -KPPHI * (atd.getPhi() - trans.getPhiRef())
	- KVPHI * (angVel.getDotPhi() - ref.getDotPhiRef());

	gamma2 = -KPTHETA * (atd.getTheta() - trans.getThetaRef())
			- KVTHETA * (angVel.getDotTheta() - ref.getDotThetaRef());

	gamma3 = -KPPSHI * (atd.getPsi() - trans.getPsiRef())
			- KVPSHI * (angVel.getDotPsi() - ref.getDotPsiRef());

	//	Feedback Linearization
	gamma << gamma1, gamma2, gamma3;

	//	Part of Equation (46) - First derivative of the euler angles
	dotTheta << angVel.getDotPhi(), angVel.getDotTheta(), angVel.getDotPsi();

	//	Part of Equation (46) - Inertia Matrix M1(THETA) - Mt - obtained by arranging
	//	 equation (7)
	mt11 = IXX;
	mt12 = 0;
	mt13 = -IXX * sin(atd.getTheta());

	mt21 = 0;
	mt22 = IYY * pow(cos(atd.getPhi()), 2) + IZZ * pow(sin(atd.getPhi()), 2);
	mt23 = (IYY - IZZ) * cos(atd.getPhi()) * sin(atd.getPhi()) * cos(atd.getTheta());

	mt31 = -IXX * sin(atd.getTheta());
	mt32 = (IYY - IZZ) * cos(atd.getPhi()) * sin(atd.getPhi()) * cos(atd.getTheta());
	mt33 = IXX * pow(sin(atd.getTheta()), 2)
			+ IYY * pow(sin(atd.getPhi()), 2) * pow(cos(atd.getTheta()), 2)
			+ IZZ * pow(cos(atd.getPhi()), 2) * pow(cos(atd.getTheta()), 2);

	mt << mt11, mt12, mt13, mt21, mt22, mt23, mt31, mt32, mt33;

	/*	Coriolis and Centrifugal Matrix = C(THETA,dotTHETA) - Ctt - obtained by
	 *  christoffel symbols of the first kind page 40 of "ROBUST CONTROL STRATEGIES
	 *  FOR A QUADROTOR HELICOPTER - An Underactuated Mechanical System" by Raffo G.
	 *  */
	c11 = 0;

	c12 = (IYY - IZZ)
			* (angVel.getDotTheta() * cos(atd.getPhi()) * sin(atd.getPhi())
					+ 0.5 * angVel.getDotPsi() * pow(sin(atd.getPhi()), 2)
							* cos(atd.getTheta()))
			+ 0.5 * (IZZ - IYY) * angVel.getDotPsi() * pow(cos(atd.getPhi()), 2)
					* cos(atd.getTheta())
			- 0.5 * IXX * angVel.getDotPsi() * cos(atd.getTheta());

	c13 = (IZZ - IYY)
			* (angVel.getDotPsi() * cos(atd.getPhi()) * sin(atd.getPhi())
					* pow(cos(atd.getTheta()), 2)
					+ 0.5 * angVel.getDotTheta() * cos(atd.getTheta())
							* pow(cos(atd.getPhi()), 2))
			+ 0.5 * (IYY - IZZ) * angVel.getDotTheta() * cos(atd.getTheta())
					* pow(sin(atd.getPhi()), 2)
			- 0.5 * IXX * angVel.getDotTheta() * cos(atd.getTheta());

	c21 =
			(IZZ - IYY)
					* (angVel.getDotTheta() * cos(atd.getPhi()) * sin(atd.getPhi())
							+ 0.5 * angVel.getDotPsi() * pow(sin(atd.getPhi()), 2)
									* cos(atd.getTheta()))
					+ 0.5 * (IYY - IZZ)
							* (angVel.getDotPsi() * pow(cos(atd.getPhi()), 2)
									* cos(atd.getTheta()))
					+ 0.5 * IXX * angVel.getDotPsi() * cos(atd.getTheta());

	c22 = (IZZ - IYY) * angVel.getDotPhi() * cos(atd.getPhi()) * sin(atd.getPhi());

	c23 = -IXX * angVel.getDotPsi() * sin(atd.getTheta()) * cos(atd.getTheta())
			+ IYY * angVel.getDotPsi() * pow(sin(atd.getPhi()), 2) * cos(atd.getTheta())
					* sin(atd.getTheta())
			+ IZZ * angVel.getDotPsi() * pow(cos(atd.getPhi()), 2) * sin(atd.getTheta())
					* cos(atd.getTheta())
			+ 0.5 * (IYY - IZZ) * angVel.getDotPhi() * cos(atd.getTheta())
					* pow(cos(atd.getPhi()), 2)
			+ 0.5 * (IZZ - IYY) * atd.getPhi() * cos(atd.getTheta())
					* pow(sin(atd.getPhi()), 2)
			+ 0.5 * IXX * angVel.getDotPhi() * cos(atd.getTheta());

	c31 = (IYY - IZZ)
			* (angVel.getDotPsi() * pow(cos(atd.getTheta()), 2) * sin(atd.getPhi())
					* cos(atd.getPhi())
					+ 0.5 * angVel.getDotTheta() * cos(atd.getTheta())
							* pow(cos(atd.getPhi()), 2))
			+ 0.5 * (IZZ - IYY) * angVel.getDotTheta() * cos(atd.getTheta())
					* pow(sin(atd.getPhi()), 2)
			- 0.5 * IXX * angVel.getDotTheta() * cos(atd.getTheta());

	c32 = (IZZ - IYY)
			* (angVel.getDotTheta() * cos(atd.getPhi()) * sin(atd.getPhi())
					* sin(atd.getTheta())
					+ 0.5 * angVel.getDotPhi() * pow(sin(atd.getPhi()), 2)
							* cos(atd.getTheta()))
			+ 0.5 * (IYY - IZZ) * angVel.getDotPhi() * pow(cos(atd.getPhi()), 2)
					* cos(atd.getTheta())
			- 0.5 * IXX * angVel.getDotPhi() * cos(atd.getTheta())
			+ IXX * angVel.getDotPsi() * sin(atd.getTheta()) * cos(atd.getTheta())
			- IYY * angVel.getDotPsi() * pow(sin(atd.getPhi()), 2) * sin(atd.getTheta())
					* cos(atd.getTheta())
			- IZZ * angVel.getDotPsi() * pow(cos(atd.getPhi()), 2) * sin(atd.getTheta())
					* cos(atd.getTheta());

	c33 = (IYY - IZZ) * angVel.getDotPhi() * cos(atd.getPhi()) * sin(atd.getPhi())
			* pow(cos(atd.getTheta()), 2)
			- IYY * angVel.getDotTheta() * pow(sin(atd.getPhi()), 2) * cos(atd.getTheta())
					* sin(atd.getTheta())
			- IZZ * angVel.getDotTheta() * pow(cos(atd.getPhi()), 2) * cos(atd.getTheta())
					* sin(atd.getTheta())
			+ IXX * angVel.getDotTheta() * cos(atd.getTheta()) * sin(atd.getTheta());

	ctt << c11, c12, c13, c21, c22, c23, c31, c32, c33;

	//	Rotational dynamics of the system
	tau = (mt * gamma) + ctt * dotTheta;

	this->tauPhi = double(tau(0, 0));
	this->tauTheta = double(tau(1, 0));
	this->tauPsi = double(tau(2, 0));

}
