#ifndef __Player_h__
#define __Player_h__

#include <exception>
#include <list>
#include "Creature.h"


class Player : public Creature
{

public:
	Player(int toughness, int agility, int power, int weapon, int armor, float protectionTime, string name, string image, int posx, int posy);
	void basicAttack();
	void specialAttack();
	void levelUp();
	int getAgility();
	int getArmor();
	int getExperience();
	int getLevel();
	int getPower();
	float getProtectionTime();
	int getToughness();
	int getWeapon();

private:
	int _experience;
	int _toughness;
	int _agility;
	int _power;
	int _weapon;
	int _armor;
	//list<Item> _inventory;
	int _level;
	float _protectionTime;



};

#endif
