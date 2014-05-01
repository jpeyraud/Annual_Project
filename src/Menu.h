
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
#include <SFML/Audio.hpp>
#include <fstream>
#include <windows.h>
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
	sf::Texture m_textureMenuButton;
	sf::Texture m_textureMenuFond;
	sf::Sprite m_spritePlay;
	sf::Sprite m_spriteOption;
	sf::Sprite m_spriteExit;
	sf::Font m_textFont;
	sf::Text m_textPlay;
	sf::Text m_textOption;
	sf::Text m_textExit;
	sf::Sprite m_spriteMenuFond;
	static const int m_height = 250/2;
	static const int m_width = 376;
	static const int m_space = 150;
	sf::IntRect* m_insideSpritePlay;
	sf::IntRect* m_insideSpriteOption;
	sf::IntRect* m_insideSpriteExit;
	sf::IntRect* m_insideSpriteMenuFond;
	sf::View m_DefaultView;
	sf::Music m_Music;
	sf::Music m_ButtonBip;
	bool inButtonPlay;
	bool inButtonOption;
	bool inButtonExit;

public:
	Menu (sf::RenderWindow* App);
	virtual ~Menu();
	int run (sf::RenderWindow* App);
	bool hitTest(sf::FloatRect rect, int height, int width, sf::Vector2i mouse);

};

#endif /* MENU_H_ */
