/*
 * Creature.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Utilisateur
 */

#include "Creature.h"

namespace
{
using std::string;
using std::cout;
using std::endl;
}

Creature::Creature()
{
	m_life[0] = 100.0;
	m_life[1] = 100.0;
	m_orientation = 1;
	m_elapsed = 0;
	m_next = 1;
}

Creature::~Creature()
{
	// TODO Auto-generated destructor stub
}

// Returns the ratio of life
float Creature::getRatioLife() const{
	return (m_life[0] / m_life[1]);
}

// Changes the number of life points when the Creature takes damage
void Creature::takeDamage(float damage){
	if(m_life[0] - damage > 0)
	{
		m_life[0] -= damage;
	}
	else
	{
		m_life[0] = 0;
		cout << "Vous êtes décédé, c'est balo !" << endl;
	}
}

// Changes the number of life points when the Creature heals
void Creature::instantHeal(float heal){
	if(m_life[0] + heal < m_life[1])
	{
		m_life[0] += heal;
	}
	else
	{
		m_life[0] = m_life[1];
	}
}

// Returns the number of current points of life
float Creature::getLife() const{
	return m_life[0];
}

string Creature::getName() const{
	return m_name;
}

//returns the orientation of the creature
int Creature::getOrientation() const{
	return m_orientation;
}

// Changes Sprite
/* Use during move */
void Creature::setSprite(int i){
	m_S_orientation.setTextureRect(m_tabOrientation[i]);
}

sf::Sprite Creature::getSprite() const{
	return m_S_orientation;
}

/* namespace std */
