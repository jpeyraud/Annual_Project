#ifndef __Panneau_h__
#define __Panneau_h__

#include "EnvironmentObstacle.h"
#include <iostream>
#include "Coordonate.h"

namespace {
	using std::string;
}

class Pannel: public EnvironmentObstacle
{
	private:
		string m_texte;
		Coordonate* m_coord;



	public:
		void afficher();
		Pannel(string text,Coordonate* coordone,Map* map);
};

#endif
