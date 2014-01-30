
#include "Player.h"


Player::Player(int toughness, int agility, int power, int weapon, int armor, float protectionTime, string name, string image, int posx, int posy) : Creature(20, name, image, posx, posy)
{
	m_toughness = toughness;
	m_agility = agility;
	m_power = power;
	m_weapon = weapon;
	m_armor = armor;
	m_protectionTime = protectionTime;
	m_experience = 0;
	m_level = 0;
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
	m_level ++;
}

/* ***************** */
/* **** Getters **** */
/* ***************** */
int Player::getAgility()
{
	return m_agility;
}

int Player::getArmor()
{
	return m_armor;
}

int Player::getExperience()
{
	return m_experience;
}

int Player::getLevel()
{
	return m_level;
}

int Player::getPower()
{
	return m_power;
}

float Player::getProtectionTime()
{
	return m_protectionTime;
}

int Player::getToughness()
{
	return m_toughness;
}

int Player::getWeapon()
{
	return m_weapon;
}

