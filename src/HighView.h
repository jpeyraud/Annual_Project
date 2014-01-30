/*
 * HighView.h
 *
 *  Created on: 27 nov. 2013
 *      Author: Utilisateur
 */

#ifndef HIGHVIEW_H_
#define HIGHVIEW_H_

#include "Map.h"

class HighView
{

public:
	HighView(sf::Vector2u visibility, float spawnX, float spawnY);
	virtual ~HighView();
	void Move(float x, float y);
	void Draw(sf::RenderWindow* window, Map map);

private:
	sf::View vue;
	sf::View vuehaute;

};

#endif /* HIGHVIEW_H_ */
