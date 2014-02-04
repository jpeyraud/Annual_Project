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
	sf::View m_hud;
	bool m_Pos;
	sf::Font m_font;
	int m_characterSize;
	sf::RectangleShape m_background;
	sf::RectangleShape m_background_left;
	sf::RectangleShape m_background_right;
	sf::RectangleShape m_barreDeVie_contour;
	sf::RectangleShape m_barreDeVie;
	sf::RectangleShape m_Button_1;
	sf::RectangleShape m_Button_2;
	sf::RectangleShape m_Resource_1;
	sf::RectangleShape m_Resource_2;
	sf::RectangleShape m_Resource_3;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	sf::Texture m_background_texture;
	sf::Texture m_Life_bound;
	sf::Texture m_foods_texture;
	sf::Texture m_potions_texture;
	sf::Texture m_button_texture;
	sf::Text m_Power;
	sf::Text m_Agility;
	sf::Text m_Toughness;
	sf::Text m_Level;
	sf::Text m_World;
	sf::Text m_Monster_Rank;
	sf::Text m_reserve;
	sf::Vector2u m_visibility;
	Coordonate *m_coord;

};


#endif /* HUD_H_ */
