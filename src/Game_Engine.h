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

#define X 1120
#define Y 640

namespace
{
	using std::vector;
}

class Game_Engine
{
private:
	sf::RenderWindow* _app;
	cScreen *_menu;
	cScreen *_game;
	cScreen *_option;
	int _timePlayed;
	string _playerSprites;


public:
	Game_Engine();
	void start();

};

#endif
