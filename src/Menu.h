/*
 * Menu.h
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */

#ifndef MENU_H_
#define MENU_H_

#include <exception>
#include <iostream>
#include <windows.h>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include "cScreen.cpp"


namespace
{
	using std::cout;
	using std::endl;
}


class Menu : public cScreen
{

private:

	sf::RenderWindow *_app;

	int movement_step;
	int posx;
	int posy;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	static const int height = 66;
	static const int width = 254;
	static const int space = 90;
	sf::IntRect* insideSprite;
	sf::IntRect* insideSprite1;
	sf::IntRect* insideSprite2;
	sf::View Default_View;

public:
	Menu (sf::RenderWindow* App);
	virtual ~Menu();
	int run (sf::RenderWindow* App);
	bool hitTest(sf::FloatRect rect, int height, int width, sf::Vector2i mouse);

};

#endif /* MENU_H_ */
