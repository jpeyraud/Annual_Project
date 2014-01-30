#ifndef __Maison_h__
#define __Maison_h__

#include "Camp.h"
#include "EnvironmentObstacle.h"
#include "Coordonate.h"

class Maison: public EnvironmentObstacle
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;

	public: Maison(Coordonate* coord,Camp* myCamp);

	public: void dormir();
};

#endif
