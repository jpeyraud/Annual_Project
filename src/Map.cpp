/*
 * Map.cpp
 *
 *  Created on: 16 sept. 2013
 *      Author: Utilisateur
 */

#include "Map.h"



bool Map::load(const string& tileset, sf::Vector2u tileSize,  vector<int> tiles, unsigned int width, unsigned int height)
{
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// on récupère le numéro de tuile courant
			int tileNumber = tiles[i + j * width];

			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	m_width=width;
	m_height=height;
	loadObstacle();
	return true;
}



void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();


	// on applique la texture du tileset
	states.texture = &m_tileset;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}

void Map::loadObstacle(){
	m_mapObstacle=new bool*[1024];
	for (int i=0;i<1024;i++){
		m_mapObstacle[i]=new bool[2048];
	}
	for (int i=0;i<1024;i++){
		for (int j=0;j<2048;j++){
			m_mapObstacle[i][j]=0;
		}
	}
}

void Map::setObstacle(Coordonate *coord){
	if(coord->getCoordonate()[0]<m_width && coord->getCoordonate()[1]<m_height){
		m_mapObstacle[coord->getCoordonate()[0]][coord->getCoordonate()[1]]=1;
	}

}

bool **Map::getMapObstacle()
{
	return m_mapObstacle;
}

int Map::getWidth(){
	return m_width;
}

int Map::getHeight(){
	return m_height;
}


