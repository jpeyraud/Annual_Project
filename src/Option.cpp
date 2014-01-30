/*
 * Option.cpp
 *
 *  Created on: 3 déc. 2013
 *      Author: Altarrys
 */

#include "Option.h"




Option::Option(sf::RenderWindow *app)
{
	_app=app;

	filtreTransparant=sf::RectangleShape(sf::Vector2f(1100, 600));

	rond.setRadius(100.0);
	posx=0;
	posy=0;

}

Option::~Option()
{

}

int Option::run(sf::RenderWindow *app)
{
	bool Running = true;
	sf::Image imgGame;
	sf::Event Event;
	imgGame=app->capture();
	sf::Texture Gamefreeze;
	Gamefreeze.loadFromImage(imgGame);
	filtreTransparant.setTexture(&Gamefreeze);
	filtreTransparant.setFillColor(sf::Color(255,255,255,128));
	while(Running){
		while (app->pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
					return 1;
				}
			}
		}
		app->clear();
		app->setView(app->getDefaultView());
		app->draw(filtreTransparant);
		app->draw(rond);
		app->display();
	}
	return(-1);
}
