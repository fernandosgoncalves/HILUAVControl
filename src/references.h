/*
 * references.h
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#ifndef REFERENCES_H_
#define REFERENCES_H_

class references {
	double refX;
	double refY;
	double refZ;
	double refDotX;
	double refDotY;
	double refDotZ;
	double dotPhiRef;
	double dotPsiRef;
	double dotThetaRef;
public:
	references();
	virtual ~references();
	double getRefX();
	void setRefX(double refX);
	double getRefY();
	void setRefY(double refY);
	double getRefZ();
	void setRefZ(double refZ);
	double getRefDotX();
	void setRefDotX(double refDotX);
	double getRefDotY();
	void setRefDotY(double refDotY);
	double getRefDotZ();
	void setRefDotZ(double refDotZ);
	double getDotPhiRef();
	void setDotPhiRef(double dotPhiRef);
	double getDotPsiRef();
	void setDotPsiRef(double dotPsiRef);
	double getDotThetaRef();
	void setDotThetaRef(double dotThetaRef);
};

#endif /* REFERENCES_H_ */
