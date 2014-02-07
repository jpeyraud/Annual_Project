#ifndef __Game_Engine_h__
#define __Game_Engine_h__

#include <exception>
#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include "Menu.h"
#include "Game.h"
#include "Option.h"

#define X 1024
#define Y 768

namespace
{
	using std::vector;
}

class Game_Engine
{
private:
	sf::RenderWindow* m_app;
	cScreen *m_menu;
	cScreen *m_game;
	cScreen *m_option;
	int m_timePlayed;
	string m_playerSprites;


public:
	Game_Engine();
	void start();

};

#endif
