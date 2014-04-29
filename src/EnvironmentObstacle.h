

#ifndef __EnvironmentObstacle_h__
#define __EnvironmentObstacle_h__

#include <exception>
#include "Coordonate.h"
#include <vector>
#include "Map.h"
#include "Creature.h"

class EnvironmentObstacle
{
	public:
	EnvironmentObstacle(int x,int y,Map* map);
	EnvironmentObstacle();
};

class Collision{
public:
	static float Collision::getCollision(Creature *character,Map map,float speed);
	float enterInCollision(sf::Sprite character,sf::Sprite Item);
};

#endif
