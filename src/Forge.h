#ifndef __Forge_h__
#define __Forge_h__

#include "Coordonate.h"
#include "Camp.h"
#include "EnvironmentObstacle.h"

class Forge : public EnvironmentObstacle
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;


	public:
		Forge(Coordonate* coord,Camp* myCamp,Map* map);
		void craft();
};

#endif
