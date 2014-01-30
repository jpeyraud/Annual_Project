#ifndef __Forge_h__
#define __Forge_h__

#include "Coordonate.h"
#include "Camp.h"

class Forge
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;


	public:
		Forge(Coordonate* coord,Camp* myCamp);
		void craft();
};

#endif
