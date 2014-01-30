
#ifndef MAP_H
#define MAP_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Coordonate.h"

namespace
{
	using std::string;
	using std::vector;

}


class Map : public sf::Drawable, public sf::Transformable
{

public:

    bool load(const string& tileset, sf::Vector2u tileSize, vector<int> tiles, unsigned int width, unsigned int height);
    void setObstacle(Coordonate* coord);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void loadObstacle();
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    bool** m_mapObstacle;
    unsigned int m_width;
    unsigned int m_height;


};

#endif
