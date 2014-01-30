/*
 * Coordonate.h
 *
 *  Created on: 2 janv. 2014
 *      Author: Amélie
 */

#ifndef COORDONATE_H_
#define COORDONATE_H_

class Coordonate
{

public :
	Coordonate(int,int);
	Coordonate();
	int* getCoordonate();
	void setCoordonate(int x,int y);

private:
	int m_x;
	int m_y;

};

#endif /* COORDONATE_H_ */
