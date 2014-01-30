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
	string _name;
	// nombre de points de vie courant et nombre de points de vie total
	float life[2];

	// position de la Creature
	Coordonate position;
	// Chaque case correspond à une image de la Creature
	sf::IntRect tabOrientation[12];
	// Donne l'orientation de la Creature
	int orientation;

	sf::Texture texture;
	sf::Sprite S_orientation;
	sf::Clock frameclock;
	float elapsed;
	int next;
};

#endif /* CREATURE_H_ */
