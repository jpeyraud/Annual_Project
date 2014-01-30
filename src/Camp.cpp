#include <exception>
using namespace std;

#include "Camp.h"

Camp::Camp(Coordonate* coord) {
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
	m_numSprite=100;
}

