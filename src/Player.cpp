
#include "Player.h"


Player::Player(int toughness, int agility, int power, int weapon, int armor, float protectionTime, string name, string image, int posx, int posy) : Creature(20, name, image, posx, posy)
{
	_toughness = toughness;
	_agility = agility;
	_power = power;
	_weapon = weapon;
	_armor = armor;
	_protectionTime = protectionTime;
	_experience = 0;
	_level = 0;
}

void Player::basicAttack()
{
	throw "Not yet implemented";
}

void Player::specialAttack()
{
	throw "Not yet implemented";
}

// Gagne un niveau
void Player::levelUp()
{
	_level ++;
}

/* ***************** */
/* **** Getters **** */
/* ***************** */
int Player::getAgility()
{
	return _agility;
}

int Player::getArmor()
{
	return _armor;
}

int Player::getExperience()
{
	return _experience;
}

int Player::getLevel()
{
	return _level;
}

int Player::getPower()
{
	return _power;
}

float Player::getProtectionTime()
{
	return _protectionTime;
}

int Player::getToughness()
{
	return _toughness;
}

int Player::getWeapon()
{
	return _weapon;
}

