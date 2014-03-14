/*
 * Game.cpp
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */


#include "Game.h"


Game::Game (sf::RenderWindow *app)
{
	Running = false;
	m_movement_step = 5;
	m_coord= new Coordonate(320,240);
	ifstream mapFile("map.txt");
	mapFile >> m_tailleMap;
	mapFile >> m_spawnX;
	mapFile >> m_spawnY;
	m_visibility=app->getSize();
	app->setFramerateLimit(60);
	m_speed=256;
	m_vueHaute=new HighView(m_visibility, m_spawnX, m_spawnY);
	m_minimap=new Minimap(app->getSize(), m_visibility, m_spawnX, m_spawnY);
	m_affichageHaut=new HUD(true, m_visibility, m_spawnX, m_spawnY);
	m_affichageBas=new HUD(false, m_visibility, m_spawnX, m_spawnY);
	int i=0;
	m_player=new Player(0, 0, 5, 100, 100, 30, "Lulu", "character.png", m_spawnX, m_spawnY);
	m_monster = new Monster(1, 5, "Loup", "character.png", m_spawnX, m_spawnY);
	int tile;

	while(i<m_tailleMap)
	{
		mapFile >> tile;
		m_level.push_back(tile);
		i++;
	}

	// on crée la tilemap avec le niveau défini dans map.txt

	m_map.load("tilea4.png", sf::Vector2u(32, 32), m_level, 64, 32);


}

Game::~Game()
{

}

int Game::run (sf::RenderWindow *app){

	Running = true;
	while(Running){

		while (app->isOpen())
		{
			m_elapsed_speed = m_clock_speed.restart().asSeconds();
			m_deplacement=m_speed*m_elapsed_speed;
			// on gère les évènements
			sf::Event event;
			while (app->pollEvent(event))
			{
				if(event.type == sf::Event::Closed)
					return -1;
				if (event.type == sf::Event::LostFocus)
					return 1;

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				m_vueHaute->Move(-m_deplacement, 0);
				m_minimap->Move(-m_deplacement, 0);
				m_player->instantHeal(0.1);
				m_player->move(sf::Keyboard::Left, m_deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				m_vueHaute->Move(m_deplacement, 0);
				m_minimap->Move(m_deplacement, 0);
				m_player->instantHeal(0.1);
				m_player->move(sf::Keyboard::Right, m_deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				m_vueHaute->Move(0, -m_deplacement);
				m_minimap->Move(0, -m_deplacement);
				m_player->takeDamage(0.1);
				m_player->move(sf::Keyboard::Up, m_deplacement);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_vueHaute->Move(0, m_deplacement);
				m_minimap->Move(0, m_deplacement);
				m_player->takeDamage(0.1);
				m_player->move(sf::Keyboard::Down, m_deplacement);

			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				return 1;
			}
			m_elapsed_monster=m_clock_monster.getElapsedTime().asSeconds();
			if(m_elapsed_monster>0.15){
				m_monster->move(m_deplacement);
				m_clock_monster.restart();
			}
			app->clear();
			m_vueHaute->Draw(app, m_map);
			app->draw(m_player->getSprite());
			app->draw(m_monster->getSprite());
			m_affichageBas->Draw(app, m_player);
			m_affichageHaut->Draw(app, m_player);
			m_minimap->Draw(app, m_map);
			app->display();

		}
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}


