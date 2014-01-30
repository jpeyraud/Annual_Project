#include "Camp.h"

Camp::Camp(Coordonate* coord,Map* map) {
	EnvironmentObstacle(coord->getCoordonate()[0],coord->getCoordonate()[1],map);
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
	m_numSprite=100;
}

