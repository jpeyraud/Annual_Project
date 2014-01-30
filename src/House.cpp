#include "House.h"

Maison::Maison(Coordonate* coord,Camp* myCamp) {
	m_camp=myCamp;
	m_numSprite=103;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
}

void Maison::dormir() {
	throw "Not yet implemented";
}

