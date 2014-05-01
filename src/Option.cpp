/*
 * Option.cpp
 *
 *  Created on: 3 déc. 2013
 *      Author: Altarrys
 */

#include "Option.h"




Option::Option(sf::RenderWindow *app)
{
	m_app=app;

	m_filtreTransparant=sf::RectangleShape(sf::Vector2f(m_app->getSize().x, m_app->getSize().y));

	m_rond.setRadius(100.0);
	m_coord=new Coordonate(0,0);

	// -------------------    Loading Font & Texture    ------------------- //
	if (!m_textFont.loadFromFile("BLKCHCRY.ttf"))  //Sketch Gothic School
	{
		cout << "error fontMenu" << endl;
	}

	// -------------------    Loading Sound & Music    ------------------- //
	if (!m_Music.openFromFile("DST-3rdBallad.ogg"))
	{
		cout << "error openning music menu" << endl;
	}

	// -------------------    Text    ------------------- //
	m_textNotImplemented= sf::Text("Not Yet Implemented - Push Enter", m_textFont, 60);
	m_textNotImplemented.setColor(sf::Color(220,220,220));
	m_textNotImplemented.setPosition(m_app->getSize().x/2 -  m_textNotImplemented.getLocalBounds().width/2, m_app->getSize().y/2 - m_textNotImplemented.getLocalBounds().height/2);
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
	m_filtreTransparant.setTexture(&Gamefreeze);
	m_filtreTransparant.setFillColor(sf::Color(255,255,255,128));
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
		app->draw(m_filtreTransparant);
		app->draw(m_textNotImplemented);
		app->display();
	}
	return(-1);
}
