/*
 * Minimap.h
 *
 *  Created on: 27 nov. 2013
 *      Author: Utilisateur
 */

#ifndef MINIMAP_H_
#define MINIMAP_H_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Map.h"


class Minimap
{

public:
	Minimap(sf::Vector2u windowSize, sf::Vector2u visibility, float spawnX, float spawnY);
	virtual ~Minimap();
	void Move(float x, float y);
	virtual void Draw(sf::RenderWindow* window, Map map);

private:
	sf::View m_vue;
	sf::Texture m_textureminimap;
	sf::RectangleShape m_sprite;

};


#endif /* MINIMAP_H_ */
