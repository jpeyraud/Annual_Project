/*
 * Creature.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Utilisateur
 */

#include "Creature.h"


Creature::Creature(int nbPV, string name, string image, int posx, int posy)
{
	_name = name;
	life[0] = 100.0;
	life[1] = 100.0;
	position.setCoordonate(posx,posy);
	tabOrientation[0] = sf::IntRect(0,0,32,32);
	tabOrientation[1] = sf::IntRect(32,0,32,32);
	tabOrientation[2] = sf::IntRect(64,0,32,32);
	tabOrientation[3] = sf::IntRect(0,32,32,32);
	tabOrientation[4] = sf::IntRect(32,32,32,32);
	tabOrientation[5] = sf::IntRect(64,32,32,32);
	tabOrientation[6] = sf::IntRect(0,64,32,32);
	tabOrientation[7] = sf::IntRect(32,64,32,32);
	tabOrientation[8] = sf::IntRect(64,64,32,32);
	tabOrientation[9] = sf::IntRect(0,96,32,32);
	tabOrientation[10] = sf::IntRect(32,96,32,32);
	tabOrientation[11] = sf::IntRect(64,96,32,32);
	orientation = 1;
	texture.loadFromFile(image, sf::IntRect(0,0,96,128));
	S_orientation.setTexture(texture);
	S_orientation.setTextureRect(tabOrientation[1]);
	S_orientation.setPosition(posx, posy);
	elapsed=0;
		next=1;
}

Creature::~Creature()
{
	// TODO Auto-generated destructor stub
}

// Retourne le ratio de vie
float Creature::getRatioLife(){
	return (life[0] / life[1]);
}

// Modifie le nombre de points de vie lorsque la Creature reçoit des dégâts
void Creature::takeDamage(float damage){
	if(life[0] - damage > 0)
	{
		life[0] -= damage;
	}
	else
	{
		life[0] = 0;
		cout << "Vous êtes décédé, c'est balo !" << endl;
	}
}

// Modifie le nombre de points de vie lorsque la Creature se soigne
void Creature::instantHeal(float heal){
	if(life[0] + heal < life[1])
	{
		life[0] += heal;
	}
	else
	{
		life[0] = life[1];
	}
}


void Creature::move(sf::Keyboard::Key direction, float mvt){
	int* pos = position.getCoordonate();

	// Déplacement à gauche
	if (direction == sf::Keyboard::Left)
	{
		// Modifie les coordonnées
		position.setCoordonate(pos[0]-1,pos[1]);
		S_orientation.move(sf::Vector2f(-mvt, 0));
		elapsed = frameclock.getElapsedTime().asSeconds();

		if(elapsed > 0.15)
		{
			switch (orientation)
			{
			case 3 :
				setSprite(orientation);
				orientation++;
				break;
			case 4:
				setSprite(orientation);
				orientation+=next;
				next=-next;
				break;
			case 5:
				setSprite(orientation);
				orientation--;
				break;
			default:
				setSprite(4);
				orientation= 4+next;
				next=-next;
				break;
			}
			frameclock.restart();
		}
	}

	// Déplacement à droite
	if (direction == sf::Keyboard::Right)
	{
		position.setCoordonate(pos[0]+1,pos[1]);
		S_orientation.move(sf::Vector2f(mvt, 0));
		elapsed = frameclock.getElapsedTime().asSeconds();

		if(elapsed > 0.15)
		{
			switch (orientation)
			{
			case 6:
				setSprite(orientation);
				orientation++;
				break;
			case 7:
				setSprite(orientation);
				orientation+=next;
				next=-next;
				break;
			case 8:
				setSprite(orientation);
				orientation--;
				break;
			default:
				setSprite(7);
				orientation=7+next;
				next=-next;
				break;
			}
			frameclock.restart();
		}
	}

	// Déplacement vers le bas
	if (direction == sf::Keyboard::Up)
	{
		position.setCoordonate(pos[0],pos[1]+1);
		S_orientation.move(sf::Vector2f(0, -mvt));
		elapsed = frameclock.getElapsedTime().asSeconds();

		if(elapsed > 0.15)
		{
			switch (orientation)
			{
			case 9:
				setSprite(orientation);
				orientation++;
				break;
			case 10:
				setSprite(orientation);
				orientation+=next;
				next=-next;
				break;
			case 11:
				setSprite(orientation);
				orientation--;
				break;
			default:
				setSprite(10);
				orientation=10+next;
				next=-next;
				break;
			}
			frameclock.restart();
		}
	}

	// Déplacement vers le haut
	if (direction == sf::Keyboard::Down)
	{
		position.setCoordonate(pos[0],pos[1]-1);
		S_orientation.move(sf::Vector2f(0, mvt));
		elapsed = frameclock.getElapsedTime().asSeconds();

		if(elapsed > 0.15)
		{
			switch (orientation)
			{
			case 0:
				setSprite(orientation);
				orientation++;
				break;
			case 1:
				setSprite(orientation);
				orientation+=next;
				next=-next;
				break;
			case 2:
				setSprite(orientation);
				orientation--;
				break;
			default:
				setSprite(1);
				orientation=1+next;
				next=-next;
				break;
			}
			frameclock.restart();
		}
	}
}

// Retourne le nombre de points de vie courant
float Creature::getLife(){
	return this->life[0];
}

// Retourne le nom
string Creature::getName(){
	return this->_name;
}

// Modifie le Sprite
/* Utilisé lors d'un déplacement */
void Creature::setSprite(int i){
	S_orientation.setTextureRect(tabOrientation[i]);
}

sf::Sprite Creature::getSprite(){
	return this->S_orientation;
}

/* namespace std */
