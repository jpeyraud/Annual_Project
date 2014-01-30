/*
 * Creature.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Utilisateur
 */

#include "Creature.h"


Creature::Creature(int nbPV, string name, string image, int posx, int posy)
{
	m_name = name;
	m_life[0] = 100.0;
	m_life[1] = 100.0;
	m_position.setCoordonate(posx,posy);
	m_tabOrientation[0] = sf::IntRect(0,0,32,32);
	m_tabOrientation[1] = sf::IntRect(32,0,32,32);
	m_tabOrientation[2] = sf::IntRect(64,0,32,32);
	m_tabOrientation[3] = sf::IntRect(0,32,32,32);
	m_tabOrientation[4] = sf::IntRect(32,32,32,32);
	m_tabOrientation[5] = sf::IntRect(64,32,32,32);
	m_tabOrientation[6] = sf::IntRect(0,64,32,32);
	m_tabOrientation[7] = sf::IntRect(32,64,32,32);
	m_tabOrientation[8] = sf::IntRect(64,64,32,32);
	m_tabOrientation[9] = sf::IntRect(0,96,32,32);
	m_tabOrientation[10] = sf::IntRect(32,96,32,32);
	m_tabOrientation[11] = sf::IntRect(64,96,32,32);
	m_orientation = 1;
	m_texture.loadFromFile(image, sf::IntRect(0,0,96,128));
	m_S_orientation.setTexture(m_texture);
	m_S_orientation.setTextureRect(m_tabOrientation[1]);
	m_S_orientation.setPosition(posx, posy);
	m_elapsed=0;
		m_next=1;
}

Creature::~Creature()
{
	// TODO Auto-generated destructor stub
}

// Retourne le ratio de vie
float Creature::getRatioLife(){
	return (m_life[0] / m_life[1]);
}

// Modifie le nombre de points de vie lorsque la Creature reçoit des dégâts
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

// Modifie le nombre de points de vie lorsque la Creature se soigne
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


void Creature::move(sf::Keyboard::Key direction, float mvt){
	int* pos = m_position.getCoordonate();

	// Déplacement à gauche
	if (direction == sf::Keyboard::Left)
	{
		// Modifie les coordonnées
		m_position.setCoordonate(pos[0]-1,pos[1]);
		m_S_orientation.move(sf::Vector2f(-mvt, 0));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 3 :
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 4:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 5:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(4);
				m_orientation= 4+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Déplacement à droite
	if (direction == sf::Keyboard::Right)
	{
		m_position.setCoordonate(pos[0]+1,pos[1]);
		m_S_orientation.move(sf::Vector2f(mvt, 0));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 6:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 7:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 8:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(7);
				m_orientation=7+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Déplacement vers le bas
	if (direction == sf::Keyboard::Up)
	{
		m_position.setCoordonate(pos[0],pos[1]+1);
		m_S_orientation.move(sf::Vector2f(0, -mvt));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 9:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 10:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 11:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(10);
				m_orientation=10+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Déplacement vers le haut
	if (direction == sf::Keyboard::Down)
	{
		m_position.setCoordonate(pos[0],pos[1]-1);
		m_S_orientation.move(sf::Vector2f(0, mvt));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 0:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 1:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 2:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(1);
				m_orientation=1+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}
}

// Retourne le nombre de points de vie courant
float Creature::getLife(){
	return this->m_life[0];
}

// Retourne le nom
string Creature::getName(){
	return this->m_name;
}

// Modifie le Sprite
/* Utilisé lors d'un déplacement */
void Creature::setSprite(int i){
	m_S_orientation.setTextureRect(m_tabOrientation[i]);
}

sf::Sprite Creature::getSprite(){
	return this->m_S_orientation;
}

/* namespace std */
