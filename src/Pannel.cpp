#include "Pannel.h"


Pannel::Pannel(string texte,Coordonate* coord,Map* map) {
	EnvironmentObstacle(coord->getCoordonate()[0],coord->getCoordonate()[1],map);
	m_texte=texte;
	m_coord=new Coordonate(coord->getCoordonate()[0],coord->getCoordonate()[1]);
}

void Pannel::afficher() {
	throw "Not yet implemented";
}

