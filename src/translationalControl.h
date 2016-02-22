/*
 * translationalControl.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef TRANSLATIONALCONTROL_H_
#define TRANSLATIONALCONTROL_H_

#include "atitude.h"
#include "errors.h"
#include <math.h>

//PD dynamics for the system
//dynamics for x - zeta1
#define KPX 	10
#define KVX 	5

//dynamics for y - zeta2
#define KPY		10
#define KVY		5

//dynamics for z - zeta3
#define KPZ		10
#define KVZ 	5

//System parameters Translational Controller
#define G 	9.81
#define M 	0.46
#define H 	0.3

class translationalControl {
	double fxb;
	double fzb;
	double phiRef;
	double psiRef;
	double thetaRef;
	double zeta1;
	double zeta2;
public:
	translationalControl();
	virtual ~translationalControl();
	double getFxb();
	void setFxb(double fxb);
	double getFzb();
	void setFzb(double fzb);
	double getPhiRef();
	void setPhiRef(double phiRef);
	double getThetaRef();
	void setThetaRef(double thetaRef);
	double getPsiRef();
	void setPsiRef(double psiRef);
	double getZeta1();
	void setZeta1(double zeta1);
	double getZeta2();
	void setZeta2(double zeta2);
	void transControl(errors er, atitude atd, double tauTheta);

};

#endif /* TRANSLATIONALCONTROL_H_ */
