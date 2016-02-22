/*
 * errors.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef ERRORS_H_
#define ERRORS_H_

#include "references.h"
#include "position.h"
#include "velocity.h"

class errors {
	double erX;
	double erY;
	double erZ;
	double erDotX;
	double erDotY;
	double erDotZ;
public:
	errors();
	virtual ~errors();
	double getErDotX();
	void setErDotX(double erDotX);
	double getErDotY();
	void setErDotY(double erDotY);
	double getErDotZ();
	void setErDotZ(double erDotZ);
	double getErX();
	void setErX(double erX);
	double getErY();
	void setErY(double erY);
	double getErZ();
	void setErZ(double erZ);
	void generateErrors(references ref, position pos, velocity vel);
};

#endif /* ERRORS_H_ */


