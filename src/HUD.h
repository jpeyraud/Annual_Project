/*
 * HUD.h
 *
 *  Created on: 30 nov. 2013
 *      Author: Utilisateur
 */

#ifndef HUD_H_
#define HUD_H_

#include <iostream>
#include <windows.h>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>

#include "Map.h"
#include "Player.h"


namespace
{
	using std::vector;
	using std::stringstream;
}

class HUD
{

public:
	HUD(bool posi, sf::Vector2u visi, float spawnX, float spawnY);
	virtual ~HUD();
	void Draw(sf::RenderWindow* window, Player* player);

private:
	sf::View hud;
	bool Pos;
	sf::Font font;
	sf::RectangleShape background;
	sf::RectangleShape background_left;
	sf::RectangleShape background_right;
	sf::RectangleShape barreDeVie_contour;
	sf::RectangleShape barreDeVie;
	sf::RectangleShape Button_1;
	sf::RectangleShape Button_2;
	sf::RectangleShape Resource_1;
	sf::RectangleShape Resource_2;
	sf::RectangleShape Resource_3;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	sf::Texture background_texture;
	sf::Texture Life_bound;
	sf::Texture foods_texture;
	sf::Texture potions_texture;
	sf::Texture button_texture;
	sf::Text Power;
	sf::Text Agility;
	sf::Text Toughness;
	sf::Text Level;
	sf::Text World;
	sf::Text Monster_Rank;
	sf::Text reserve;
	sf::Vector2u visibility;
	float posX;
	float posY;

};


#endif /* HUD_H_ */
