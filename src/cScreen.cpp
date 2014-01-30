/*
 * cScreen.cpp
 *
 *  Created on: 3 déc. 2013
 *      Author: Altarrys
 */


#ifndef CSCREEN_CPP_
#define CSCREEN_CPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class cScreen
{

public :
    virtual int run (sf::RenderWindow *App) = 0;

protected :
    sf::Event _event;

};

#endif /* CSCREEN_CPP_ */
