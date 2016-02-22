/*
 * angularVelocity.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef ANGULARVELOCITY_H_
#define ANGULARVELOCITY_H_

class angularVelocity {
	double dotPhi;
	double dotPsi;
	double dotTheta;
public:
	angularVelocity();
	virtual ~angularVelocity();
	double getDotPhi();
	void setDotPhi(double dotPhi);
	double getDotPsi();
	void setDotPsi(double dotPsi);
	double getDotTheta();
	void setDotTheta(double dotTheta);
};

#endif /* ANGULARVELOCITY_H_ */
