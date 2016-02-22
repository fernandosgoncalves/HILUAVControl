/*
 * errors.cpp
 *
 *  Created on: 15/08/2014
 *      Author: fernando
 */

#include "errors.h"

errors::errors() {
	// TODO Auto-generated constructor stub
	erX = 0;
	erY = 0;
	erZ = 0;
	erDotX = 0;
	erDotY = 0;
	erDotZ = 0;

}

errors::~errors() {
	// TODO Auto-generated destructor stub
}

double errors::getErDotX() {
	return erDotX;
}
void errors::setErDotX(double erDotX) {
	this->erDotX = erDotX;
}

double errors::getErDotY() {
	return erDotY;
}

void errors::setErDotY(double erDotY) {
	this->erDotY = erDotY;
}

double errors::getErDotZ() {
	return erDotZ;
}

void errors::setErDotZ(double erDotZ) {
	this->erDotZ = erDotZ;
}

double errors::getErX() {
	return erX;
}

void errors::setErX(double erX) {
	this->erX = erX;
}

double errors::getErY() {
	return erY;
}

void errors::setErY(double erY) {
	this->erY = erY;
}

double errors::getErZ() {
	return erZ;
}

void errors::setErZ(double erZ) {
	this->erZ = erZ;
}

void errors::generateErrors(references ref, position pos, velocity vel) {
	this->setErX(pos.getX() - ref.getRefX());
	this->setErY(pos.getY() - ref.getRefY());
	this->setErZ(pos.getZ() - ref.getRefZ());
	this->setErDotX(vel.getDotX() - ref.getRefDotX());
	this->setErDotY(vel.getDotY() - ref.getRefDotY());
	this->setErDotZ(vel.getDotZ() - ref.getRefDotZ());
}
