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

	// -------------------    Loading Sound & Music    ------------------- //
	if (!m_Music.openFromFile("DST-AmbientKingdom.wav"))
	{
		cout << "error openning music menu" << endl;
	}
	m_Music.setVolume(20);
	m_Music.setLoop(true);

	m_movement_step = 5;
	m_coord= new Coordonate(320,240);
	ifstream mapFile("map.txt");
	ifstream superFile("super.txt");
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
	m_player=new Player(0, 0, 5, 100, 100, 30, "Lulu", "playerAttack.png", m_spawnX, m_spawnY);
	m_monster = new Monster(1, 5, "Loup", "wolf.png", m_spawnX, m_spawnY,0,0);
	int tile;

	while(i<m_tailleMap)
	{
		mapFile >> tile;
		m_level.push_back(tile);
		i++;
	}
	i=0;
	while(i<m_tailleMap)
	{
		superFile >> tile;
		m_level2.push_back(tile);
		i++;
	}

	// on crée la tilemap avec le niveau défini dans map.txt

	m_map.load("tiles.png", sf::Vector2u(32, 32), m_level,m_level2, 64, 32);



}

Game::~Game()
{

}

int Game::run (sf::RenderWindow *app){
	float deplacement;
	int index = 0;
	Running = true;
	m_Music.play();
	vector <sf::Sprite>vectSprite=m_map.getSprites();
	sf::Vector2i mouse = sf::Mouse::getPosition(*(sf::Window*) app);
	while(Running){


		mouse = sf::Mouse::getPosition(*(sf::Window*) app);
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
				{
					m_Music.stop();
					return 1;
				}

				//Les Boutton de l'interface
				if (event.type == sf::Event::MouseButtonPressed)
				{
					//change Screen
					if (event.mouseButton.button == sf::Mouse::Left)
					{

						mouse = sf::Mouse::getPosition(*(sf::Window*) app);
						//On button click
						if (hitTest( (sf::FloatRect) m_affichageHaut->getOption(), m_affichageHaut->getWidth(), m_affichageHaut->getHeight(),  mouse))
						{
							Running = false;
							return 2;
						}
						if (hitTest( (sf::FloatRect) m_affichageHaut->getMenu(), m_affichageHaut->getWidth(), m_affichageHaut->getHeight(),  mouse))
						{
							Running = false;
							return 1;
						}


						cout << "Top : " << m_affichageHaut->getOption().top << endl;
						cout << "left : " << m_affichageHaut->getOption().left << endl;
						cout << "height : " << m_affichageHaut->getOption().height << endl;
						cout << "width : " << m_affichageHaut->getOption().width << endl;
						cout << mouse.x << " " << mouse.y << endl;
					}
				}


			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				m_player->basicAttack(index);
				if(index == 2){
					index = 0;
				}
				else
					index++;
			}
			else {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{
					if (m_player->getOrientation()!=4&&m_player->getOrientation()!=5&&m_player->getOrientation()!=3)
						m_player->setOrientation(4);
					deplacement=Collision::getCollision((Creature*)m_player,m_map,m_deplacement);
					m_vueHaute->Move(-deplacement, 0);
					m_minimap->Move(-deplacement, 0);
					m_player->instantHeal(0.1);
					m_player->move(sf::Keyboard::Left, deplacement);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
					if (m_player->getOrientation()!=6&&m_player->getOrientation()!=7&&m_player->getOrientation()!=8)
						m_player->setOrientation(7);
					deplacement=Collision::getCollision((Creature*)m_player,m_map,m_deplacement);
					m_vueHaute->Move(deplacement, 0);
					m_minimap->Move(deplacement, 0);
					m_player->instantHeal(0.1);
					m_player->move(sf::Keyboard::Right, deplacement);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				{
					if (m_player->getOrientation()!=9&&m_player->getOrientation()!=10&&m_player->getOrientation()!=11)
						m_player->setOrientation(10);
					deplacement=Collision::getCollision((Creature*)m_player,m_map,m_deplacement);
					m_vueHaute->Move(0, -deplacement);
					m_minimap->Move(0, -deplacement);
					m_player->takeDamage(0.1);
					m_player->move(sf::Keyboard::Up, deplacement);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					if (m_player->getOrientation()!=0&&m_player->getOrientation()!=1&&m_player->getOrientation()!=2)
						m_player->setOrientation(1);
					deplacement=Collision::getCollision((Creature*)m_player,m_map,m_deplacement);
					m_vueHaute->Move(0, deplacement);
					m_minimap->Move(0, deplacement);
					m_player->takeDamage(0.1);
					m_player->move(sf::Keyboard::Down, deplacement);

				}
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Music.stop();
				return 1;
			}
			m_elapsed_monster=m_clock_monster.getElapsedTime().asSeconds();
			if(m_elapsed_monster>0.20){
				deplacement=Collision::getCollision((Creature *)m_monster,m_map,m_deplacement);
				m_monster->move(deplacement);
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

	m_Music.stop();
	//Exit this screen
	return -1;
}

bool Game::hitTest(sf::FloatRect rect, int height, int width, sf::Vector2i mouse)
{
	return (mouse.x > rect.left) && (mouse.x < rect.left + height) &&
			(mouse.y > rect.top)  && (mouse.y < rect.top + width);
}
