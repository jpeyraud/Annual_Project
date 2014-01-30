
#ifndef __Reserve_h__
#define __Reserve_h__

#include "EnvironmentObstacle.h"
#include "Coordonate.h"
#include "Camp.h"
#include <vector>

class Supply: public EnvironmentObstacle
{
	private:
		Coordonate *m_coord;
		vector<int> m_listNourriture;
		Camp *m_camp;
		int m_numSprite;

	public:
		Supply(Coordonate* coord,Camp *myCamp,Map* map);

};

#endif
