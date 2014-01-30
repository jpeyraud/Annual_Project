

#ifndef __EnvironmentObstacle_h__
#define __EnvironmentObstacle_h__

#include <exception>
#include "Coordonate.h"
#include <vector>
#include "Map.h"

class EnvironmentObstacle
{
	public:
	EnvironmentObstacle(int x,int y,Map* map);
	EnvironmentObstacle();
};

#endif
