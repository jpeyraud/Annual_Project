
#include "EnvironmentObstacle.h"


EnvironmentObstacle::EnvironmentObstacle(int x,int y,Map* map){
	Coordonate *coord=new Coordonate(x,y);
	map->setObstacle(coord);
}

EnvironmentObstacle::EnvironmentObstacle(){

}

float Collision::getCollision(Creature *character,Map map,float speed)
{
	bool **mapObstacle=map.getMapObstacle();
	//int topMap=map.getHeight();
	//int leftMap=map.getWidth();
	int top=(int)round(character->getSprite().getGlobalBounds().top);
	int left=(int)round(character->getSprite().getGlobalBounds().left);
	int height=(int)round(character->getSprite().getGlobalBounds().height);
	int width=(int)round(character->getSprite().getGlobalBounds().width);
	std::cout<<top<<" "<<left<<std::endl;
	if (character->getOrientation()/3==0)//sud
	{
		for(int i=0;i<=int(speed);i++){
			if (top+i+height==1023){
				speed=float(i);
				break;
			}
			if(mapObstacle[top+i][left]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==1)//sud-ouest
	{
		for(int i=0;i<=int(speed);i++){
			if (top+i+height==1023 || left-i==0){
				speed=float(i);
				break;
			}
			if(mapObstacle[top+i][left-i]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==2)//ouest
	{
		for(int i=0;i<=int(speed);i++){
			if (left-i==0){
				speed=float(i);
				break;
			}
			if(mapObstacle[top][left-i]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==3)//nord-ouest
	{
		for(int i=0;i<=int(speed);i++){
			if (top-i==0|| left-i==0){
				speed=float(i);
				break;
			}
			if(mapObstacle[top-i][left-i]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==4)//nord
	{
		for(int i=0;i<=int(speed);i++){

			if (top-i==0){
				speed=float(i);
				break;
			}
			if(mapObstacle[top-i][left]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==5)//nord-est
	{
		for(int i=0;i<=int(speed);i++){
			if (top-i==0 || left+i+width==2047){
				speed=float(i);
				break;
			}
			if(mapObstacle[top-i][left+i]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==6)//est
	{
		for(int i=0;i<=int(speed);i++){
			if (left+i+width==2047){
				speed=float(i);
				break;
			}
			if(mapObstacle[top][left+i]==1){
				speed=float(i);
				break;
			}
		}
	}
	else if(character->getOrientation()/3==7)//sud-est
	{
		for(int i=0;i<=int(speed);i++){
			if (top+i+height==1023 || left+i+width==2047){
				speed=float(i);
				break;
			}
			if(mapObstacle[top+i][left+i]==1){
				speed=float(i);
				break;
			}
		}
	}
	return speed;
}

float Collision::enterInCollision(sf::Sprite character,sf::Sprite Item){
	if(		(character.getGlobalBounds().top+character.getGlobalBounds().height)<=Item.getGlobalBounds().top
			|| character.getGlobalBounds().top>=(Item.getGlobalBounds().top+Item.getGlobalBounds().height)
			||(character.getGlobalBounds().left+character.getGlobalBounds().width)<=Item.getGlobalBounds().left
			||character.getGlobalBounds().left>=(Item.getGlobalBounds().left+Item.getGlobalBounds().width))
	{
		return false;
	}
	else{
		return true;
	}
}
