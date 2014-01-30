/*
 * Option.h
 *
 *  Created on: 3 déc. 2013
 *      Author: Altarrys
 */

#ifndef OPTION_H_
#define OPTION_H_

#include <exception>
#include <iostream>
#include <windows.h>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include "cScreen.cpp"



class Option : public cScreen
{

private:
	sf::RenderWindow *_app;
	sf::RectangleShape menuPause;
	sf::RectangleShape filtreTransparant;
	sf::CircleShape rond;
	int posx;
	int posy;
	//sf::Sprite Sprite;

public:
	Option(sf::RenderWindow *app);
	virtual ~Option();
	int run (sf::RenderWindow *app);
};


#endif /* OPTION_H_ */
