/*
 * Menu.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */


#include "Menu.h"


Menu::Menu (sf::RenderWindow* app)
{
	_app=app;

	Default_View=_app->getDefaultView();
	movement_step = 5;
	posx = 320;
	posy = 240;
	if (!texture.loadFromFile("button.png"))
	{
		cout << "error texture button" << endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition( (_app->getSize ().x - width)/2, (_app->getSize().y - height)/2 - space );


	sprite1.setTexture(texture);
	sprite1.setPosition( (_app->getSize ().x - width)/2, (_app->getSize().y - height)/2 );


	sprite2.setTexture(texture);
	sprite2.setPosition( (_app->getSize ().x - width)/2, (_app->getSize().y - height)/2 + space);

	insideSprite = new sf::IntRect(0,0,width,height);
	insideSprite1 = new sf::IntRect(0,0,width,height);
	insideSprite2 = new sf::IntRect(0,0,width,height);
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
					if (hitTest( (sf::FloatRect) sprite.getGlobalBounds(), width, height,  mouse))
					{
						nextScreen = 0;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) sprite1.getGlobalBounds(), width, height,  mouse))
					{
						nextScreen = 2;
						Running = false;
					}
					if (hitTest( (sf::FloatRect) sprite2.getGlobalBounds(), width, height,  mouse))
					{
						nextScreen = -1;
						Running = false;
					}
				}
			}
		}

		//--------------- BUTTONS MENU ---------------//
		//Game
		if (hitTest( (sf::FloatRect) sprite.getGlobalBounds(), width, height,  mouse))
		{
			insideSprite = new sf::IntRect(0,height,width,height);
		}
		else
		{
			insideSprite = new sf::IntRect(0,0,width,height);
		}
		if (hitTest( (sf::FloatRect) sprite1.getGlobalBounds(), width, height,  mouse))
		{
			insideSprite1 = new sf::IntRect(0,height,width,height);
		}
		else
		{
			insideSprite1 = new sf::IntRect(0,0,width,height);
		}
		if (hitTest( (sf::FloatRect) sprite2.getGlobalBounds(), width, height,  mouse))
		{
			insideSprite2 = new sf::IntRect(0,height,width,height);
		}
		else
		{
			insideSprite2 = new sf::IntRect(0,0,width,height);
		}
		sprite.setTextureRect(*insideSprite);
		sprite1.setTextureRect(*insideSprite1);
		sprite2.setTextureRect(*insideSprite2);

		//Drawing
		_app->clear(sf::Color(255, 255, 255));
		_app->setView(Default_View);
		_app->draw(sprite1);
		_app->draw(sprite);
		_app->draw(sprite2);
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


