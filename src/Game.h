/*
 * Game.h
 *
 *  Created on: 2 déc. 2013
 *      Author: Altarrys
 */

#ifndef GAME_H_
#define GAME_H_

#include <exception>
#include <cmath>
#include <fstream>
#include "cScreen.cpp"
#include "HighView.h"
#include "HUD.h"
#include "Minimap.h"
#include "Player.h"

namespace
{
	using std::ifstream;
	using std::vector;
}

class Game : public cScreen
{

private:
	sf::RenderWindow *_app;
	HighView *_vueHaute;
	HUD *_affichageHaut;
	HUD *_affichageBas;
	Minimap *_minimap;
	Player *_player;
	Map map;
	int movement_step;
	int posx;
	int posy;
	int tailleMap;
	int spawnX;
	int spawnY;
	vector<int> level;
	sf::Vector2u visibility;
	sf::Clock clock;
	float speed;
	float elapsed;
	float deplacement;
	int i;

public:
	Game (sf::RenderWindow *app);
	virtual ~Game();
	int run (sf::RenderWindow *app);

};

#endif /* MENU_H_ */
