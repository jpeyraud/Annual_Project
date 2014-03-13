/*
 * Menu.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */


#include "Menu.h"


Menu::Menu (sf::RenderWindow* app)
{
	m_app=app;

	m_DefaultView=m_app->getDefaultView();
	m_movementStep = 5;
	m_coord = new Coordonate(320,240);

	if (!m_textFont.loadFromFile("Flesh Wound.ttf"))  //Sketch Gothic School
	{
		cout << "error fontMenu" << endl;
	}
	if (!m_textureMenuButton.loadFromFile("MenuButtonTexture.png"))
	{
		cout << "error texturePlay button" << endl;
	}
	if (!m_textureMenuFond.loadFromFile("stoneMenuFond.jpg"))
	{
		cout << "error textureMenuFond button" << endl;
	}

	int posButtonX = (m_app->getSize ().x - m_width)/2;
	int posButtonY = (m_app->getSize().y - m_height)/2;

	m_textPlay= sf::Text("PLAY", m_textFont, 60);
	m_textOption= sf::Text("OPTION", m_textFont, 60);
	m_textExit= sf::Text("EXIT", m_textFont, 60);

	m_textPlay.setPosition(m_app->getSize().x/2 - 50, posButtonY+m_height/5-m_space);
	m_textOption.setPosition(m_app->getSize().x/2 - 80, posButtonY+m_height/5);
	m_textExit.setPosition(m_app->getSize().x/2 - 50, posButtonY+m_height/5+m_space);

	m_textPlay.setColor(sf::Color(0,0,0));
	m_textOption.setColor(sf::Color(0,0,0));
	m_textExit.setColor(sf::Color(0,0,0));

	m_spritePlay.setTexture(m_textureMenuButton);
	m_spritePlay.setPosition( posButtonX, posButtonY - m_space );

	m_spriteOption.setTexture(m_textureMenuButton);
	m_spriteOption.setPosition( posButtonX, posButtonY );

	m_spriteExit.setTexture(m_textureMenuButton);
	m_spriteExit.setPosition( posButtonX, posButtonY + m_space);

	m_textureMenuFond.setRepeated(true);
	m_spriteMenuFond.setTexture(m_textureMenuFond);

	m_insideSpritePlay = new sf::IntRect(0,0,m_width,m_height);
	m_insideSpriteMenuFond = new sf::IntRect(0,0,app->getSize().x,app->getSize().y);
	m_insideSpriteOption = new sf::IntRect(0,0,m_width,m_height);
	m_insideSpriteExit = new sf::IntRect(0,0,m_width,m_height);
}

Menu::~Menu()
{

}

int Menu::run (sf::RenderWindow* app)
{
	sf::Event Event;
	bool Running = true;
	int nextScreen=-1;

	//Clearing screen
	while (Running)
	{
		sf::Vector2i mouse = sf::Mouse::getPosition(*(sf::Window*) app);

		//Verifying events
		while (app->pollEvent(Event))
		{
			//Event event;
			if (Event.type == sf::Event::Closed)
			{
				Running = false;
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				//change Screen
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					//On button click
					if (hitTest( (sf::FloatRect) m_spritePlay.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = 0;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) m_spriteOption.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = 2;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) m_spriteExit.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = -1;
						Running = false;
					}
				}
			}
		}

		//--------------- BUTTONS MENU ---------------//
		//Hoover sprite
		if (hitTest( (sf::FloatRect) m_spritePlay.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSpritePlay = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSpritePlay = new sf::IntRect(0,0,m_width,m_height);
		}
		if (hitTest( (sf::FloatRect) m_spriteOption.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSpriteOption = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSpriteOption = new sf::IntRect(0,0,m_width,m_height);
		}
		if (hitTest( (sf::FloatRect) m_spriteExit.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSpriteExit = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSpriteExit = new sf::IntRect(0,0,m_width,m_height);
		}
		m_spritePlay.setTextureRect(*m_insideSpritePlay);
		m_spriteOption.setTextureRect(*m_insideSpriteOption);
		m_spriteExit.setTextureRect(*m_insideSpriteExit);
		m_spriteMenuFond.setTextureRect(*m_insideSpriteMenuFond);

		//Drawing
		app->clear(sf::Color(255, 255, 255));
		app->setView(m_DefaultView);
		app->draw(m_spriteMenuFond);
		app->draw(m_spritePlay);
		app->draw(m_spriteOption);
		app->draw(m_spriteExit);
		app->draw(m_textPlay);
		app->draw(m_textOption);
		app->draw(m_textExit);
		app->display();
		//Running = false;
	}


	//Exit the Application
	return nextScreen;
}


bool Menu::hitTest(sf::FloatRect rect, int height, int width, sf::Vector2i mouse)
{
	return (mouse.x > rect.left) && (mouse.x < rect.left + height) &&
			(mouse.y > rect.top)  && (mouse.y < rect.top + width);
}


