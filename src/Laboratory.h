#ifndef __Laboratoire_h__
#define __Laboratoire_h__

#include "Camp.h"
#include "Coordonate.h"

class Laboratoire
{
	private:
		Coordonate* m_coord;
		int m_numSprite;
		Camp* m_camp;


	public:
		Laboratoire(Coordonate* coord,Camp* myCamp);
		void craft();
};

#endif
