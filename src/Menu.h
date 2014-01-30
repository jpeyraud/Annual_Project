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
#include "Coordonate.h"


namespace
{
	using std::cout;
	using std::endl;
}


class Menu : public cScreen
{

private:

	sf::RenderWindow *m_app;

	int m_movementStep;
	Coordonate* m_coord;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite1;
	sf::Sprite m_sprite2;
	static const int m_height = 66;
	static const int m_width = 254;
	static const int m_space = 90;
	sf::IntRect* m_insideSprite;
	sf::IntRect* m_insideSprite1;
	sf::IntRect* m_insideSprite2;
	sf::View m_DefaultView;

public:
	Menu (sf::RenderWindow* App);
	virtual ~Menu();
	int run (sf::RenderWindow* App);
	bool hitTest(sf::FloatRect rect, int height, int width, sf::Vector2i mouse);

};

#endif /* MENU_H_ */
