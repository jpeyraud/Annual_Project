#include "House.h"

House::House(Coordonate* coord,Camp* myCamp,Map* map) {
	EnvironmentObstacle(coord->getCoordonate()[0],coord->getCoordonate()[1],map);
	m_camp=myCamp;
	m_numSprite=103;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
}

void House::dormir() {
	throw "Not yet implemented";
}

