/*
 * Minimap.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: Utilisateur
 */

#include "Minimap.h"


Minimap::Minimap(sf::Vector2u windowSize, sf::Vector2u visibility, float spawnX, float spawnY)
{
	m_textureminimap.loadFromFile("HUDsprite.png");
	sf::Vector2f ViewCenter(spawnX, spawnY);
	sf::Vector2f ViewSize(visibility.x*1.5, visibility.y*1.5);
	m_vue.setCenter(ViewCenter);
	m_vue.setSize(ViewSize);
	m_vue.setViewport(sf::FloatRect(0.75f, 0.065, 0.20f, 0.30f));
	float posX=spawnX-(visibility.x*1.5)/2;
	float posY=spawnY-(visibility.y*1.5)/2;
	m_sprite.setSize(sf::Vector2f(visibility.x*1.5, visibility.y*1.5));
	m_sprite.setPosition(posX, posY);
	m_sprite.setTexture(&m_textureminimap);



	//contour.setSize(Vector2f(windowSize.x*0.25f, windowSize.y*0.25f));
	// TODO Auto-generated constructor stub

}

Minimap::~Minimap() {
	// TODO Auto-generated destructor stub
}

void Minimap::Move(float x, float y){
	m_vue.move(x, y);
	m_sprite.move(x, y);
}

void Minimap::Draw(sf::RenderWindow* window, Map map){
	window->setView(m_vue);
	window->draw(map);
	window->draw(m_sprite);
}

