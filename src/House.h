#ifndef __Maison_h__
#define __Maison_h__

#include "Camp.h"
#include "EnvironmentObstacle.h"
#include "Coordonate.h"


class House: public EnvironmentObstacle
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;

	public:
		House(Coordonate* coord,Camp* myCamp,Map* map);
		void dormir();
};

#endif
