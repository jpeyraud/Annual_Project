//============================================================================
// Name        : Maquete.cpp
// Author      : Bruno
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
#include <iostream>
#include <windows.h>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include "HighView.h"
#include "Minimap.h"
#include "HUD.h"
#include "Creature.h"
using namespace std;
using namespace sf;

int main(){
	ifstream mapFile("map.txt");
	int tailleMap;
	int spawnX;
	int spawnY;
	mapFile >> tailleMap;
	mapFile >> spawnX;
	mapFile >> spawnY;
	int level[tailleMap];
	int visibility=768;
	sf::RenderWindow window(sf::VideoMode(1100, 600), "Maquette");
	window.setFramerateLimit(60);
	sf::Clock clock;
	float speed=256;
	float elapsed;
	float deplacement;
	HighView vueHaute(visibility, spawnX, spawnY);
	Minimap minimap(window.getSize(), visibility, spawnX, spawnY);
	HUD affichageHaut(true, visibility, spawnX, spawnY);
	HUD affichageBas(false, visibility, spawnX, spawnY);
	int i=0;
	Creature player;


		while(i<tailleMap){
			mapFile >> level[i];
			i++;
		}

		// on crée la tilemap avec le niveau défini dans map.txt
		Map map;
		if (!map.load("tilea4.png", sf::Vector2u(32, 32), level, 64, 32))
			return -1;

		while (window.isOpen())
			{
			elapsed = clock.restart().asSeconds();
			deplacement=speed*elapsed;
				// on gère les évènements
						sf::Event event;
						while (window.pollEvent(event))
						{
							if(event.type == sf::Event::Closed)
								window.close();
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							vueHaute.Move(-deplacement, 0);
							minimap.Move(-deplacement, 0);
							player.instantHeal(0.1);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
							vueHaute.Move(deplacement, 0);
							minimap.Move(deplacement, 0);
							player.instantHeal(0.1);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						{
							vueHaute.Move(0, -deplacement);
							minimap.Move(0, -deplacement);
							player.takeDamage(0.1);
						}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
						{
							vueHaute.Move(0, deplacement);
							minimap.Move(0, deplacement);
							player.takeDamage(0.1);

						}

				window.clear();
				vueHaute.Draw(window, map);
				affichageBas.Draw(window, player);
				affichageHaut.Draw(window, player);
				minimap.Draw(window, map);
				window.display();

			}


	return 0;
}
*/

