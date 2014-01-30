#include "Pannel.h"


Panneau::Panneau(string texte,Coordonate* coord) {
	m_texte=texte;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
}

void Panneau::afficher() {
	throw "Not yet implemented";
}

