#ifndef __Player_h__
#define __Player_h__

#include <exception>
#include <list>
#include "Creature.h"


class Player : public Creature
{

public:
	Player(int toughness, int agility, int power, int weapon, int armor, float protectionTime, string name, string image, int posx, int posy);
	void move(sf::Keyboard::Key direction, float mvt);
	void basicAttack(int index);
	void specialAttack();
	void levelUp();
	int getAgility() const;
	int getArmor() const;
	int getExperience() const;
	int getLevel() const;
	int getPower() const;
	float getProtectionTime() const;
	int getToughness() const;
	int getWeapon() const;

protected:
	int m_experience;
	int m_toughness;
	int m_agility;
	int m_power;
	int m_weapon;
	int m_armor;
	//list<Item> m_inventory;
	int m_level;
	float m_protectionTime;



};

#endif
