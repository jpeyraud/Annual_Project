#include "Supply.h"

Reserve::Reserve(Coordonate* coord,Camp* myCamp) {
	m_camp=myCamp;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
	m_numSprite=104;
}
