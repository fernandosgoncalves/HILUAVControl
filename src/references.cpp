/*
 * references.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "references.h"

references::references() {
	// TODO Auto-generated constructor stub
	refX = 0.1;
	refY = 0.1;
	refZ = 0.1;
	refDotX = 0;
	refDotY = 0;
	refDotZ = 0;
	dotPhiRef = 0;
	dotPsiRef = 0;
	dotThetaRef = 0;
}

references::~references() {
	// TODO Auto-generated destructor stub
}

double references::getRefX() {
	return refX;
}

void references::setRefX(double refX) {
	this->refX = refX;
}

double references::getRefY() {
	return refY;
}

void references::setRefY(double refY) {
	this->refY = refY;
}

double references::getRefZ() {
	return refZ;
}

void references::setRefZ(double refZ) {
	this->refZ = refZ;
}

double references::getRefDotX() {
	return refDotX;
}

void references::setRefDotX(double refDotX) {
	this->refDotX = refDotX;
}

double references::getRefDotY(){
	return refDotY;
}

void references::setRefDotY(double refDotY) {
	this->refDotY = refDotY;
}

double references::getRefDotZ(){
	return refDotZ;
}

void references::setRefDotZ(double refDotZ) {
	this->refDotZ = refDotZ;
}

double references::getDotPhiRef() {
	return dotPhiRef;
}

void references::setDotPhiRef(double dotPhiRef) {
	this->dotPhiRef = dotPhiRef;
}

double references::getDotPsiRef() {
	return dotPsiRef;
}

void references::setDotPsiRef(double dotPsiRef) {
	this->dotPsiRef = dotPsiRef;
}

double references::getDotThetaRef() {
	return dotThetaRef;
}

void references::setDotThetaRef(double dotThetaRef) {
	this->dotThetaRef = dotThetaRef;
}
