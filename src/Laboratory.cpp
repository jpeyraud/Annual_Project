#include "Laboratory.h"

Laboratoire::Laboratoire(Coordonate* coord,Camp* myCamp) {
	m_camp=myCamp;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
	m_numSprite=102;
}

void Laboratoire::craft() {
	throw "Not yet implemented";
}

