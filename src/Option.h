/*
 * Option.h
 *
 *  Created on: 3 d�c. 2013
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
#include <SFML/Audio.hpp>
#include <fstream>
#include "cScreen.cpp"
#include "Coordonate.h"

namespace
{
	using std::cout;
	using std::endl;
}

class Option : public cScreen
{

private:
	sf::RenderWindow *m_app;
	sf::RectangleShape m_menuPause;
	sf::RectangleShape m_filtreTransparant;
	sf::CircleShape m_rond;
	Coordonate *m_coord;
	sf::Music m_Music;
	sf::Font m_textFont;
	sf::Text m_textNotImplemented;
	//sf::Sprite Sprite;

public:
	Option(sf::RenderWindow *app);
	virtual ~Option();
	int run (sf::RenderWindow *app);
};


#endif /* OPTION_H_ */
