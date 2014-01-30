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
	if (!m_texture.loadFromFile("button.png"))
	{
		cout << "error texture button" << endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition( (m_app->getSize ().x - m_width)/2, (m_app->getSize().y - m_height)/2 - m_space );


	m_sprite1.setTexture(m_texture);
	m_sprite1.setPosition( (m_app->getSize ().x - m_width)/2, (m_app->getSize().y - m_height)/2 );


	m_sprite2.setTexture(m_texture);
	m_sprite2.setPosition( (m_app->getSize ().x - m_width)/2, (m_app->getSize().y - m_height)/2 + m_space);

	m_insideSprite = new sf::IntRect(0,0,m_width,m_height);
	m_insideSprite1 = new sf::IntRect(0,0,m_width,m_height);
	m_insideSprite2 = new sf::IntRect(0,0,m_width,m_height);
}

Menu::~Menu()
{

}

int Menu::run (sf::RenderWindow* _app)
{
	sf::Event Event;
	bool Running = true;
	int nextScreen=-1;

	//Clearing screen
	while (Running)
	{
		sf::Vector2i mouse = sf::Mouse::getPosition(*(sf::Window*) _app);

		//Verifying events
		while (_app->pollEvent(Event))
		{
			//Event event;
			if (Event.type == sf::Event::Closed)
			{
				Running = false;
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				//changement de Screen
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					if (hitTest( (sf::FloatRect) m_sprite.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = 0;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) m_sprite1.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = 2;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) m_sprite2.getGlobalBounds(), m_width, m_height,  mouse))
					{
						nextScreen = -1;
						Running = false;
					}
				}
			}
		}

		//--------------- BUTTONS MENU ---------------//
		//Game
		if (hitTest( (sf::FloatRect) m_sprite.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSprite = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSprite = new sf::IntRect(0,0,m_width,m_height);
		}
		if (hitTest( (sf::FloatRect) m_sprite1.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSprite1 = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSprite1 = new sf::IntRect(0,0,m_width,m_height);
		}
		if (hitTest( (sf::FloatRect) m_sprite2.getGlobalBounds(), m_width, m_height,  mouse))
		{
			m_insideSprite2 = new sf::IntRect(0,m_height,m_width,m_height);
		}
		else
		{
			m_insideSprite2 = new sf::IntRect(0,0,m_width,m_height);
		}
		m_sprite.setTextureRect(*m_insideSprite);
		m_sprite1.setTextureRect(*m_insideSprite1);
		m_sprite2.setTextureRect(*m_insideSprite2);

		//Drawing
		_app->clear(sf::Color(255, 255, 255));
		_app->setView(m_DefaultView);
		_app->draw(m_sprite1);
		_app->draw(m_sprite);
		_app->draw(m_sprite2);
		_app->display();
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


