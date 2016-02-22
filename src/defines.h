/*
 * defines.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef DEFINES_H_
#define DEFINES_H_

typedef struct
	__attribute__((packed)) {
//	modelArticle
		double x;
		double y;
		double z;
		double dotX;
		double dotY;
		double dotZ;
		double phi;
		double theta;
		double psi;
		double dotPhi;
		double dotTheta;
		double dotPsi;
		double flag;
	} PcPackage;

	typedef struct
		__attribute__((packed)) {
			//	sigTrans
			double fR;
			double fL;
			double alphaR;
			double alphaL;
		} BeaglePackage;

#endif /* DEFINES_H_ */

