
#ifndef __Reserve_h__
#define __Reserve_h__

#include "EnvironmentObstacle.h"
#include "Coordonate.h"
#include "Camp.h"
#include <vector>

class Reserve: public EnvironmentObstacle
{
	private:
		Coordonate *m_coord;
		vector<int> m_listNourriture;
		Camp *m_camp;
		int m_numSprite;

	public:
		Reserve(Coordonate* coord,Camp *myCamp);

};

#endif
