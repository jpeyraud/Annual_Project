#ifndef __Campement_h__
#define __Campement_h__

#include "Coordonate.h"
#include "EnvironmentObstacle.h"

class Camp : public EnvironmentObstacle
{
	public:
		Camp(Coordonate* coord,Map* map);

	private :
		Coordonate*	m_coord;
		int m_numSprite;
};

#endif
