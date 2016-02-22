/*
 * signalTransformation.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef SIGNALTRANSFORMATION_H_
#define SIGNALTRANSFORMATION_H_

//Sytem parameters to Signal Transformation
#define L	0.55

#include "translationalControl.h"
#include "rotacionalControl.h"
#include <math.h>

class signalTransformation {
	double fR;
	double fL;
	double alphaR;
	double alphaL;
public:
	signalTransformation();
	virtual ~signalTransformation();
	double getAlphaL();
	void setAlphaL(double alphaL);
	double getAlphaR();
	void setAlphaR(double alphaR);
	double getFL();
	void setFL(double l);
	double getFR();
	void setFR(double r);
	void sigTrans(translationalControl trans, rotacionalControl rot);
};

#endif /* SIGNALTRANSFORMATION_H_ */
