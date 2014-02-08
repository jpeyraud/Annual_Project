/*
 * Creature.h
 *
 *  Created on: 2 déc. 2013
 *      Author: Utilisateur
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <cmath>
#include <windows.h>
#include "Map.h"
#include "Coordonate.h"

namespace
{
using std::string;
using std::cout;
using std::endl;
}

class Creature {

public:
	Creature();
	virtual ~Creature();
	float getRatioLife() const;
	void takeDamage(float damage);
	void instantHeal(float heal);
	float getLife() const;
	string getName() const;
	void setSprite(int i);
	sf::Sprite getSprite() const;

protected :
	string m_name;
	// position of Creature
	Coordonate m_position;
	// Each box corresponds to an image of Creature
	sf::IntRect m_tabOrientation[12];
	sf::Texture m_texture;
	sf::Sprite m_S_orientation;
	// Give the orientation of Creature
	int m_orientation;
	sf::Clock m_frameclock;
	float m_elapsed;
	int m_next;
	// number of current hit points and total hit points
	float m_life[2];

};

#endif /* CREATURE_H_ */
