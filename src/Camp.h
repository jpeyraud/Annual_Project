#ifndef __Campement_h__
#define __Campement_h__

#include "Coordonate.h"

class Camp
{
	public:
		Camp(Coordonate* coord);

	private :
		Coordonate*	m_coord;
		int m_numSprite;
};

#endif
