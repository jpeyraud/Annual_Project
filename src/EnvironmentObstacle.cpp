
#include "EnvironmentObstacle.h"


EnvironmentObstacle::EnvironmentObstacle(int x,int y,Map* map){
	Coordonate *coord=new Coordonate(x,y);
	map->setObstacle(coord);
}

EnvironmentObstacle::EnvironmentObstacle(){

}
