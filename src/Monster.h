#ifndef __Monster_h__
#define __Monster_h__


#include <exception>
#include "Creature.h"

class Monster : public Creature
{

protected:
	int m_coeffpower;
	int m_id;

public:
	Monster(int id, int coeffpower, string name, string image, int posx, int posy);
	void move(float mvt);
	void attack();

};

#endif
