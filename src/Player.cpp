
#include "Player.h"


Player::Player(int toughness, int agility, int power, int weapon, int armor, float protectionTime, string name, string image, int posx, int posy) : Creature()
{
	m_name = name;
	m_position.setCoordonate(posx,posy);
	m_tabOrientation[0] = sf::IntRect(0,0,32,48);
	m_tabOrientation[1] = sf::IntRect(32,0,32,48);
	m_tabOrientation[2] = sf::IntRect(64,0,32,48);
	m_tabOrientation[3] = sf::IntRect(0,48,32,48);
	m_tabOrientation[4] = sf::IntRect(32,48,32,48);
	m_tabOrientation[5] = sf::IntRect(64,48,32,48);
	m_tabOrientation[6] = sf::IntRect(0,96,32,48);
	m_tabOrientation[7] = sf::IntRect(32,96,32,48);
	m_tabOrientation[8] = sf::IntRect(64,96,32,48);
	m_tabOrientation[9] = sf::IntRect(0,144,32,48);
	m_tabOrientation[10] = sf::IntRect(32,144,32,48);
	m_tabOrientation[11] = sf::IntRect(64,144,32,48);
	m_texture.loadFromFile(image, sf::IntRect(0,0,96,192));
	m_S_orientation.setTexture(m_texture);
	m_S_orientation.setTextureRect(m_tabOrientation[1]);
	m_S_orientation.setPosition(posx, posy);

	m_toughness = toughness;
	m_agility = agility;
	m_power = power;
	m_weapon = weapon;
	m_armor = armor;
	m_protectionTime = protectionTime;
	m_experience = 0;
	m_level = 0;
}

void Player::move(sf::Keyboard::Key direction, float mvt)
{
	int* pos = m_position.getCoordonate();

	// Move left
	if (direction == sf::Keyboard::Left)
	{
		// Changes the coordinates
		m_position.setCoordonate(pos[0]-1,pos[1]);
		m_S_orientation.move(sf::Vector2f(-mvt, 0));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 3 :
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 4:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 5:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(4);
				m_orientation= 4+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Move right
	if (direction == sf::Keyboard::Right)
	{
		m_position.setCoordonate(pos[0]+1,pos[1]);
		m_S_orientation.move(sf::Vector2f(mvt, 0));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 6:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 7:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 8:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(7);
				m_orientation=7+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Move up
	if (direction == sf::Keyboard::Up)
	{
		m_position.setCoordonate(pos[0],pos[1]+1);
		m_S_orientation.move(sf::Vector2f(0, -mvt));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 9:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 10:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 11:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(10);
				m_orientation=10+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}

	// Move down
	if (direction == sf::Keyboard::Down)
	{
		m_position.setCoordonate(pos[0],pos[1]-1);
		m_S_orientation.move(sf::Vector2f(0, mvt));
		m_elapsed = m_frameclock.getElapsedTime().asSeconds();

		if(m_elapsed > 0.15)
		{
			switch (m_orientation)
			{
			case 0:
				setSprite(m_orientation);
				m_orientation++;
				break;
			case 1:
				setSprite(m_orientation);
				m_orientation+=m_next;
				m_next=-m_next;
				break;
			case 2:
				setSprite(m_orientation);
				m_orientation--;
				break;
			default:
				setSprite(1);
				m_orientation=1+m_next;
				m_next=-m_next;
				break;
			}
			m_frameclock.restart();
		}
	}
}

void Player::basicAttack()
{
	throw "Not yet implemented";
}

void Player::specialAttack()
{
	throw "Not yet implemented";
}

// Win a level
void Player::levelUp()
{
	m_level ++;
}

/* ***************** */
/* **** Getters **** */
/* ***************** */
int Player::getAgility() const
{
	return m_agility;
}

int Player::getArmor() const
{
	return m_armor;
}

int Player::getExperience() const
{
	return m_experience;
}

int Player::getLevel() const
{
	return m_level;
}

int Player::getPower() const
{
	return m_power;
}

float Player::getProtectionTime() const
{
	return m_protectionTime;
}

int Player::getToughness() const
{
	return m_toughness;
}

int Player::getWeapon() const
{
	return m_weapon;
}

