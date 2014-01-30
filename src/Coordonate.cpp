/*
 * Coordonate.cpp
 *
 *  Created on: 2 janv. 2014
 *      Author: Amélie
 */

#include "Coordonate.h"



Coordonate::Coordonate(int x,int y) {
	_x = x;
	_y = y;
}

Coordonate::Coordonate() {
	_x = 0;
	_y = 0;
}

int* Coordonate::getCoordonate() {
	int* coord = new int[2];
	coord[0]=_x;
	coord[1]=_y;
	return coord;
}

void Coordonate::setCoordonate(int x,int y) {
	_x = x;
	_y = y;
}
