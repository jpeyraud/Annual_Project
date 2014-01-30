/*
 * HighView.cpp
 *
 *  Created on: 27 nov. 2013
 *      Author: Utilisateur
 */

#include "HighView.h"


HighView::HighView(sf::Vector2u visibility, float spawnX, float spawnY) {
	sf::Vector2f ViewCenter(spawnX, spawnY);
	sf::Vector2f ViewSize(visibility.x, visibility.y);
	vuehaute.setCenter(ViewCenter);
	vuehaute.setSize(ViewSize);
	// TODO Auto-generated constructor stub

}

HighView::~HighView() {
	// TODO Auto-generated destructor stub
}

void HighView::Move(float x, float y){
	vuehaute.move(x, y);
}

void HighView::Draw(sf::RenderWindow* window, Map map)
{
	window->setView(vuehaute);

	window->draw(map);
}

