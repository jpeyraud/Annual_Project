/*
 * Map.cpp
 *
 *  Created on: 16 sept. 2013
 *      Author: Utilisateur
 */

#include "Map.h"



bool Map::load(const string& tileset, sf::Vector2u tileSize,  vector<int> tiles, vector<int> tiles2, unsigned int width, unsigned int height)
{
	m_width=width*TILE_SIZE;
	m_height=height*TILE_SIZE;
	loadObstacle();
	sf::Sprite sprite;
	// on charge la texture du tileset
	if (!m_tileset.loadFromFile(tileset))
		return false;

	sprite.setTexture(m_tileset);
	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// on remplit le tableau de vertex, avec un quad par tuile
	for (unsigned int i = 0; i < width; ++i){
		for (unsigned int j = 0; j < height; ++j)
		{
			// on r�cup�re le num�ro de tuile courant
			int tileNumber = tiles[i + (j * width)];
			int tileNumber2 = tiles2[i + (j * width)];

			// on en d�duit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// on r�cup�re un pointeur vers le quad � d�finir dans le tableau de vertex
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// on d�finit ses quatre coins
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// on d�finit ses quatre coordonn�es de texture
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

			if (tileNumber2!=-1){
				int colonne= (tileNumber2%6)*TILE_SIZE;
				int ligne= (tileNumber2/6)*TILE_SIZE;
				sprite.setTextureRect(sf::IntRect(colonne,ligne,tileSize.x,tileSize.y));
				sprite.setPosition(i * tileSize.x, j * tileSize.y);
				m_vectSprite.push_back(sprite);
				setSpriteObstacle(sprite);
			}
		}
	}
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

	for (unsigned int i=0;i<m_vectSprite.size();i++){
		target.draw(m_vectSprite[i],states);
	}
}

void Map::loadObstacle(){
	m_mapObstacle=new bool*[m_height];
	for (int i=0;i<m_height;i++){
		m_mapObstacle[i]=new bool[m_width];
	}
	for (int i=0;i<m_height;i++){
		for (int j=0;j<m_width;j++){
			m_mapObstacle[i][j]=0;
		}
	}
}

void Map::setSpriteObstacle (sf::Sprite sp){
	int top = (int)round(sp.getGlobalBounds().top);
	int left = (int)round(sp.getGlobalBounds().left);
	int width = (int)round(sp.getGlobalBounds().width);
	int height = (int)round(sp.getGlobalBounds().height);

	for (int x=top;x<top+height;x++){
		for (int y=left;y<left+width;y++){
			setObstacle(x,y);
		}
	}
}


void Map::setObstacle(Coordonate *coord){
	if(coord->getCoordonate()[0]<m_width && coord->getCoordonate()[1]<m_height){
		m_mapObstacle[coord->getCoordonate()[0]][coord->getCoordonate()[1]]=1;
	}

}

void Map::setObstacle(int x, int y){
	if(x<m_width*32 && y<m_height*32){
		m_mapObstacle[x][y]=1;
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

vector<sf::Sprite> Map::getSprites(){
	return m_vectSprite;
}


