#include "Forge.h"


Forge::Forge(Coordonate* coord,Camp* myCamp,Map* map) {
	EnvironmentObstacle(coord->getCoordonate()[0],coord->getCoordonate()[1],map);
	m_camp=myCamp;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
	m_numSprite=101;
}

void Forge::craft() {
	throw "Not yet implemented";
}

