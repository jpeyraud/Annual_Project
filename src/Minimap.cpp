/*
 * Minimap.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: Utilisateur
 */

#include "Minimap.h"


Minimap::Minimap(sf::Vector2u windowSize, sf::Vector2u visibility, float spawnX, float spawnY)
{
	textureminimap.loadFromFile("HUDsprite.png");
	sf::Vector2f ViewCenter(spawnX, spawnY);
	sf::Vector2f ViewSize(visibility.x*1.5, visibility.y*1.5);
	vue.setCenter(ViewCenter);
	vue.setSize(ViewSize);
	float ratioX=(windowSize.y*0.30)/windowSize.x;
	vue.setViewport(sf::FloatRect(.99f-ratioX, 0.065f, ratioX, 0.30f));
	float posX=spawnX-(visibility.x*1.5)/2;
	float posY=spawnY-(visibility.y*1.5)/2;
	sprite.setSize(sf::Vector2f(visibility.x*1.5, visibility.y*1.5));
	sprite.setPosition(posX, posY);
	sprite.setTexture(&textureminimap);



	//contour.setSize(Vector2f(windowSize.x*0.25f, windowSize.y*0.25f));
	// TODO Auto-generated constructor stub

}

Minimap::~Minimap() {
	// TODO Auto-generated destructor stub
}

void Minimap::Move(float x, float y){
	vue.move(x, y);
	sprite.move(x, y);
}

void Minimap::Draw(sf::RenderWindow* window, Map map){
	window->setView(vue);
	window->draw(map);
	window->draw(sprite);
}

