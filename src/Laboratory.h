#ifndef __Laboratoire_h__
#define __Laboratoire_h__

#include "Camp.h"
#include "Coordonate.h"
#include "EnvironmentObstacle.h"

class Laboratory : public EnvironmentObstacle
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;


	public:
		Laboratory(Coordonate* coord,Camp* myCamp,Map* map);
		void craft();
};

#endif
