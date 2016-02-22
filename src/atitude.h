/*
 * atitude.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef ATITUDE_H_
#define ATITUDE_H_

class atitude {
	double phi;
	double psi;
	double theta;
public:
	atitude();
	virtual ~atitude();
	double getPhi();
	void setPhi(double phi);
	double getPsi();
	void setPsi(double psi);
	double getTheta();
	void setTheta(double theta);
	double getTauTheta();
	void setTauTheta(double tauTheta);
};

#endif /* ATITUDE_H_ */
