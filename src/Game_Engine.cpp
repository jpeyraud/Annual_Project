#include <exception>
#include <iostream>
#include "Game_Engine.h"


Game_Engine::Game_Engine()
{
	m_app = new sf::RenderWindow(sf::VideoMode(X, Y), " Annual Project ", sf::Style::Fullscreen);
	m_game = new Game(m_app);
	m_menu = new Menu(m_app);
	m_option = new Option(m_app);
	m_timePlayed = 0;
}

void Game_Engine::start()
{
	vector<cScreen*> Screens;
	int screen=1;//0->game 1->menu 2->option
	Screens.push_back(m_game);
	Screens.push_back(m_menu);
	Screens.push_back(m_option);

	while(screen>=0)
	{
		screen=Screens[screen]->run(m_app);
	}

}


