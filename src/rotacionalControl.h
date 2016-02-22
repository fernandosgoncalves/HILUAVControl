/*
 * rotacionalControl.h
 *
 *  Created on: 18/05/2014
 *      Author: fernando
 */

#ifndef ROTACIONALCONTROL_H_
#define ROTACIONALCONTROL_H_

#include "translationalControl.h"
#include "angularVelocity.h"
#include "references.h"
#include "atitude.h"

class rotacionalControl {
	//rotational controller variables
	double tauPhi;
	double tauTheta;
	double tauPsi;
	//PD dynamics for the system
	//dynamics for gamma1
//#define KPPHI	4700
//#define	 KVPHI	100
#define KPPHI	100
#define	 KVPHI	10

	//dynamics for gamma2
//#define KPTHETA		4700
//#define KVTHETA		100
#define KPTHETA		100
#define KVTHETA		10


	//dynamics for gamma3
//#define KPPSHI		4700
//#define KVPSHI		100
#define KPPSHI		100
#define KVPSHI		10

	// System Parameters Rotational Controller
//#define IXX		0.0096
//#define IYY		0.0116
//#define IZZ		0.0218
#define IXX  0.01905797115
#define IYY  0.00502396129
#define IZZ  0.01859602726

public:
	rotacionalControl();
	virtual ~rotacionalControl();
	void setTauPhi(double tauPhi);
	double getTauPhi();
	void setTauTheta(double tauTheta);
	double getTauTheta();
	void setTauPsi(double tauPsi);
	double getTauPsi();
	void rotationalController(atitude atd, angularVelocity angVel, references ref, translationalControl trans);
};

#endif /* ROTACIONALCONTROL_H_ */
