
#ifndef MAP_H
#define MAP_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Coordonate.h"
#include <vector>
#include "math.h"

#define TILE_SIZE 32;

namespace
{
	using std::string;
	using std::vector;

}


class Map : public sf::Drawable, public sf::Transformable
{

public:

    bool load(const string& tileset, sf::Vector2u tileSize, vector<int> tiles,vector<int> tiles2, unsigned int width, unsigned int height);
    void setObstacle(Coordonate* coord);
    void Map::setObstacle(int x, int y);
    void setSpriteObstacle (sf::Sprite sp);
    bool **getMapObstacle();
    int getWidth();
    int getHeight();
    vector<sf::Sprite> getSprites();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void loadObstacle();
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    bool** m_mapObstacle;
    int m_width;
    int m_height;
    vector<sf::Sprite> m_vectSprite;


};

#endif
