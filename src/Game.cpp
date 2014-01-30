/*
 * Game.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */


#include "Game.h"


Game::Game (sf::RenderWindow *app)
{
	_app=app;
	movement_step = 5;
	posx = 320;
	posy = 240;
	ifstream mapFile("map.txt");
	mapFile >> tailleMap;
	mapFile >> spawnX;
	mapFile >> spawnY;
	visibility=app->getSize();
	app->setFramerateLimit(60);
	speed=256;
	_vueHaute=new HighView(visibility, spawnX, spawnY);
	_minimap=new Minimap(app->getSize(), visibility, spawnX, spawnY);
	_affichageHaut=new HUD(true, visibility, spawnX, spawnY);
	_affichageBas=new HUD(false, visibility, spawnX, spawnY);
	int i=0;
	_player=new Player(0, 0, 5, 100, 100, 30, "Lulu", "character.png", spawnX, spawnY);
	int tile;

	while(i<tailleMap){
		mapFile >> tile;
		level.push_back(tile);
		i++;
	}

	// on crée la tilemap avec le niveau défini dans map.txt

	map.load("tilea4.png", sf::Vector2u(32, 32), level, 64, 32);


}

Game::~Game()
{

}

int Game::run (sf::RenderWindow *app){

	bool Running = true;
	while(Running){

		while (app->isOpen())
		{
			elapsed = clock.restart().asSeconds();
			deplacement=speed*elapsed;
			// on gère les évènements
			sf::Event event;
			while (app->pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
					return -1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				_vueHaute->Move(-deplacement, 0);
				_minimap->Move(-deplacement, 0);
				_player->instantHeal(0.1);
				_player->move(sf::Keyboard::Left, deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				_vueHaute->Move(deplacement, 0);
				_minimap->Move(deplacement, 0);
				_player->instantHeal(0.1);
				_player->move(sf::Keyboard::Right, deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				_vueHaute->Move(0, -deplacement);
				_minimap->Move(0, -deplacement);
				_player->takeDamage(0.1);
				_player->move(sf::Keyboard::Up, deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				_vueHaute->Move(0, deplacement);
				_minimap->Move(0, deplacement);
				_player->takeDamage(0.1);
				_player->move(sf::Keyboard::Down, deplacement);

			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				return 1;
			}
			if (event.type == sf::Event::LostFocus){
				return 1;
			}

			app->clear();
			_vueHaute->Draw(app, map);
			app->draw(_player->getSprite());
			_affichageBas->Draw(app, _player);
			_affichageHaut->Draw(app, _player);
			_minimap->Draw(app, map);
			app->display();

		}
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}


