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
	Creature(int nbPV, string name, string image, int posx, int posy);
	virtual ~Creature();
	float getRatioLife();
	void takeDamage(float damage);
	void instantHeal(float heal);
	void move(sf::Keyboard::Key direction, float mvt);
	float getLife();
	string getName();
	void setSprite(int i);
	sf::Sprite getSprite();

private :
	string m_name;
	// nombre de points de vie courant et nombre de points de vie total
	float m_life[2];

	// position de la Creature
	Coordonate m_position;
	// Chaque case correspond à une image de la Creature
	sf::IntRect m_tabOrientation[12];
	// Donne l'orientation de la Creature
	int m_orientation;

	sf::Texture m_texture;
	sf::Sprite m_S_orientation;
	sf::Clock m_frameclock;
	float m_elapsed;
	int m_next;
};

#endif /* CREATURE_H_ */
