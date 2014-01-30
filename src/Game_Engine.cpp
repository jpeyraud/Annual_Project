#include <exception>
#include <iostream>
#include "Game_Engine.h"


Game_Engine::Game_Engine()
{
	_app = new sf::RenderWindow(sf::VideoMode(X, Y), " Annual Project ");
	_game = new Game(_app);
	_menu = new Menu(_app);
	_option = new Option(_app);
	_timePlayed = 0;
}

void Game_Engine::start()
{
	vector<cScreen*> Screens;
	int screen=1;//0->game 1->menu 2->option
	Screens.push_back(_game);
	Screens.push_back(_menu);
	Screens.push_back(_option);

	while(screen>=0)
	{
		screen=Screens[screen]->run(_app);
	}

}


