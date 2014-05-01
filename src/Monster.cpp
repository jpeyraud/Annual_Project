
#include "Monster.h"



Monster::Monster(int id, int coeffpower, string name, string image, int posx, int posy, int xDepart, int yDepart)
{
	Creature();
	m_id = id;
	m_coeffpower = coeffpower;
	m_direction=0;
	m_nb_mvt=0;
	m_name = name;
	m_position.setCoordonate(posx,posy);
	m_tabOrientation[0] = sf::IntRect(xDepart,yDepart,48,48);
	m_tabOrientation[1] = sf::IntRect(xDepart+48,yDepart,48,48);
	m_tabOrientation[2] = sf::IntRect(xDepart+96,yDepart,48,48);
	m_tabOrientation[3] = sf::IntRect(xDepart,yDepart+48,48,48);
	m_tabOrientation[4] = sf::IntRect(xDepart+48,yDepart+48,48,48);
	m_tabOrientation[5] = sf::IntRect(xDepart+96,yDepart+48,48,48);
	m_tabOrientation[6] = sf::IntRect(xDepart,yDepart+96,48,48);
	m_tabOrientation[7] = sf::IntRect(xDepart+48,yDepart+96,48,48);
	m_tabOrientation[8] = sf::IntRect(xDepart+96,yDepart+96,48,48);
	m_tabOrientation[9] = sf::IntRect(xDepart,yDepart+144,48,48);
	m_tabOrientation[10] = sf::IntRect(xDepart+48,yDepart+144,48,48);
	m_tabOrientation[11] = sf::IntRect(xDepart+96,yDepart+144,48,48);
	m_texture.loadFromFile(image, sf::IntRect(0,0,144,192));
	m_S_orientation.setTexture(m_texture);
	m_S_orientation.setTextureRect(m_tabOrientation[1]);
	m_S_orientation.setPosition(posx, posy);

}

void Monster::move(float mvt){
	int* pos = m_position.getCoordonate();
	if(m_direction==0){
		m_direction = rand()%(6-1) + 1;
		m_nb_mvt = rand()%(6-3)+1;
	}
	// Move left
	if (m_direction == 1)
	{
		m_nb_mvt--;
		if(m_nb_mvt==0){
			m_direction=0;
		}
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
	if (m_direction == 2)
	{
		m_nb_mvt--;
		if(m_nb_mvt==0){
			m_direction=0;
		}
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
	if (m_direction == 3)
	{
		m_nb_mvt--;
		if(m_nb_mvt==0){
			m_direction=0;
		}
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
	if (m_direction == 4)
	{
		m_nb_mvt--;
		if(m_nb_mvt==0){
			m_direction=0;
		}
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
	//No move
	if(m_direction==5){
		m_nb_mvt--;
		if(m_nb_mvt==0){
			m_direction=0;
		}
	}
}

void Monster::attack() {
	throw "Not yet implemented";
}

