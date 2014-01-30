/*
 * Coordonate.cpp
 *
 *  Created on: 2 janv. 2014
 *      Author: Amélie
 */

#include "Coordonate.h"



Coordonate::Coordonate(int x,int y) {
	m_x = x;
	m_y = y;
}

Coordonate::Coordonate() {
	m_x = 0;
	m_y = 0;
}

int* Coordonate::getCoordonate() {
	int* coord = new int[2];
	coord[0]=m_x;
	coord[1]=m_y;
	return coord;
}

void Coordonate::setCoordonate(int x,int y) {
	m_x = x;
	m_y = y;
}
