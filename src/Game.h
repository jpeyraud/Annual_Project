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
#include "Coordonate.h"
#include "Monster.h"

namespace
{
	using std::ifstream;
	using std::vector;
}

class Game : public cScreen
{

private:

	HighView *m_vueHaute;
	HUD *m_affichageHaut;
	HUD *m_affichageBas;
	Minimap *m_minimap;
	Player *m_player;
	Monster *m_monster;
	Map m_map;
	int m_movement_step;
	Coordonate *m_coord;
	int m_tailleMap;
	int m_spawnX;
	int m_spawnY;
	vector<int> m_level;
	sf::Vector2u m_visibility;
	sf::Clock m_clock_speed;
	sf::Clock m_clock_monster;
	float m_elapsed_monster;
	float m_speed;
	float m_elapsed_speed;
	float m_deplacement;
	int m_i;

public:
	Game (sf::RenderWindow *app);
	virtual ~Game();
	int run (sf::RenderWindow *app);

};

#endif /* MENU_H_ */
