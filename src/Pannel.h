#ifndef __Panneau_h__
#define __Panneau_h__

#include "EnvironmentObstacle.h"
#include <iostream>
#include "Coordonate.h"

namespace {
	using std::string;
}

class Panneau: public EnvironmentObstacle
{
	private:
		string m_texte;
		Coordonate* m_coord;

	Panneau::Panneau(string text,Coordonate* coordone);

	public: void afficher();
};

#endif
