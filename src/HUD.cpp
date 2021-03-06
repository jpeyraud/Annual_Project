/*
 * HUD.cpp
 *
 *  Created on: 30 nov. 2013
 *      Author: Akoma
 */

#include "HUD.h"
/*
 * Constructeur qui prend en param�tres la dimension de la fen�tre
 * et le boolean qui lui dit si elle est en haut ou en bas.
 */
HUD::HUD(bool posi, sf::Vector2u visi, float spawnX, float spawnY) {
	m_Pos=posi;
	m_visibility=visi;
	m_visibility.y=m_visibility.y*0.15;
	std::cout << m_visibility.y;
	m_characterSize=m_visibility.y*0.20;
	m_spawnX=spawnX;
	m_spawnY=spawnY;
	/*
	 * Elements commun au deux HUD :
	 * La position de la vue (monde 2D)
	 * Le background
	 * La police de charact�re
	 */

	//Le centre de la vue est donc le spawn, �a taille est la longueur de la fen�tre pour 1/15 de sa hauteur de
	//sa hauteur.
	m_hud.setCenter(sf::Vector2f(spawnX, spawnY));//Centr� sur le spawn
	m_hud.setSize(sf::Vector2f(m_visibility.x, m_visibility.y));//En fonction de la visibility pour l'utilis� dans la taille des charact�res.




	//Le contenant (taille en fonctionde de la visibility)
	//Position du point sup�rieure gauche du contenant
	m_coord= new Coordonate(spawnX-(m_visibility.x/2),spawnY-(m_visibility.y/2));//centre de la vue moins moitiers de la longueur du contenant.
	//centre de la vue moins la moitier de la hauteur du contenant.


	//On commence par charger la police de texte
	m_font.loadFromFile("BLKCHCRY.ttf");

	/*
	 * Transtypage int->String
	 */
	//		// cr�er un flux de sortie
	//		ostringstream oss;
	//		// �crire un nombre dans le flux
	//		oss << visibility.y*0.20;
	//		// r�cup�rer une cha�ne de caract�res
	//		string result = oss.str();
	//		Power.setString("La taille des caract�res est de : "+result);
	/*
	 *
	 */


	/*
	 * ViewPort pour la position de la vue dans la fen�tre, il s'agit ici d'un ratio par rapport � la taille
	 * de la fen�tre en pixels.
	 * les deux premier param�tres sont la position du coin sup�rieure gauche de la vue,
	 * les deux dernier sont ses dimension x et y.
	 */
	if(m_Pos){

		//Background de l'HUD
		m_background_texture.loadFromFile("HUDtexture.png");//La texture
		m_background_texture.setRepeated(true);
		m_button_texture.loadFromFile("button_texture.png");


		m_texturRect_background= new sf::IntRect(0,0,m_visibility.x, m_visibility.y);
		m_background.setPosition(m_coord->getCoordonate()[0], m_coord->getCoordonate()[1]);//On d�finit la position.
		m_background.setTexture(m_background_texture);//et la texture
		m_background.setTextureRect(*m_texturRect_background);

		m_hud.setViewport(sf::FloatRect(0, 0, 1, 0.15f));

		m_reserve.setFont(m_font);//Assignation police.
		m_reserve.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).
		m_reserve.setStyle(sf::Text::Bold);//Assignation Style.
		m_reserve.setColor(sf::Color::Black);//Assignation couleur.
		m_reserve.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.1, m_coord->getCoordonate()[1]+m_visibility.y*0.15);//Assignation position

		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(3 * 2 * 4);
		m_tileset.loadFromFile("tilea4.png");
		vector<int> tiles;
		sf::Vector2u textureSize=sf::Vector2u(32, 32);
		sf::Vector2f tileSize=sf::Vector2f(m_visibility.x*0.025, m_visibility.x*0.025);
		for(int i=1; i<3*2;i++){
			tiles.push_back(i);
		}
		for (float i = 0; i < 3*2; i+=2)
			for (float j = 0; j < 2*2; j+=2)
			{
				// on r�cup�re le num�ro de tuile courant
				int tileNumber = tiles[i/2 + j/2 * 3];

				// on en d�duit sa position dans la texture du tileset
				int tu = tileNumber % (m_tileset.getSize().x / textureSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / textureSize.x);

				// on r�cup�re un pointeur vers le quad � d�finir dans le tableau de vertex
				sf::Vertex* quad = &m_vertices[(i/2 + j/2 * 3) * 4];

				// on d�finit ses quatre coins
				if(i==0){
					if(j==2){
						quad[0].position = sf::Vector2f(i * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j-0.5) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j-0.5) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[3].position = sf::Vector2f(i * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
					}
					else{
						quad[0].position = sf::Vector2f(i * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), j * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), j * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[3].position = sf::Vector2f(i * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
					}
				}
				else{
					if(j==2){
						quad[0].position = sf::Vector2f((i+i/4) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j-0.5) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[1].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j-0.5) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[2].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[3].position = sf::Vector2f((i+i/4) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
					}
					else{
						quad[0].position = sf::Vector2f((i+i/4) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), j * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[1].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), j * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[2].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
						quad[3].position = sf::Vector2f((i+i/4) * tileSize.x+(m_coord->getCoordonate()[0]+m_visibility.x*0.2), (j + 1) * tileSize.y+(m_coord->getCoordonate()[1]+m_visibility.y*0.16));
					}
				}


				// on d�finit ses quatre coordonn�es de texture
				quad[0].texCoords = sf::Vector2f(tu * textureSize.x, tv * textureSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * textureSize.x, tv * textureSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * textureSize.x, (tv + 1) * textureSize.y);
				quad[3].texCoords = sf::Vector2f(tu * textureSize.x, (tv + 1) * textureSize.y);
			}



		m_option.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.50, m_coord->getCoordonate()[1]+m_visibility.y*0.08);//On d�finit la position.
		m_option.setTexture(m_button_texture);//et la texture
		m_text_option= sf::Text("Option", m_font, m_characterSize-2);
		m_text_option.setPosition((m_coord->getCoordonate()[0]+m_visibility.x*0.50)+0.25*m_width, m_coord->getCoordonate()[1]+m_visibility.y*0.08);
		m_text_option.setColor(sf::Color(0,0,0));

		m_menu.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.50, m_coord->getCoordonate()[1]+m_visibility.y*0.48);//On d�finit la position.
		m_menu.setTexture(m_button_texture);//et la texture
		m_text_menu= sf::Text("Menu", m_font, m_characterSize);
		m_text_menu.setPosition((m_coord->getCoordonate()[0]+m_visibility.x*0.50)+0.25*m_width, m_coord->getCoordonate()[1]+m_visibility.y*0.48);
		m_text_menu.setColor(sf::Color(0,0,0));
		// -------------------    Text    ------------------- //
		//		m_menu= sf::Text("MENU", m_font, m_characterSize);
		//		m_option= sf::Text("OPTION", m_font, m_characterSize);

		m_inside_option=new sf::IntRect(10,10,m_width,m_height);
		m_option.setTextureRect(*m_inside_option);
		m_inside_menu=new sf::IntRect(10,10,m_width,m_height);
		m_menu.setTextureRect(*m_inside_menu);
	}
	else{

		//Background de l'HUD
		m_background_texture_left.loadFromFile("HUDTexture_left.png");//La texture
		m_background_texture_left.setRepeated(true);


		m_texturRect_background_left=new sf::IntRect(0,0,m_visibility.x*0.45, m_visibility.y);
		m_background_left.setPosition(m_coord->getCoordonate()[0], m_coord->getCoordonate()[1]);//On d�finit la position.
		m_background_left.setTexture(m_background_texture_left);//et la texture
		m_background_left.setTextureRect(*m_texturRect_background_left);

		//Background de l'HUD
		m_background_texture_right.loadFromFile("HUDTexture_right.png");//La texture
		m_background_texture_right.setRepeated(true);


		m_texturRect_background_right= new sf::IntRect(0,0,m_visibility.x*0.40, m_visibility.y);
		m_background_right.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.60, m_coord->getCoordonate()[1]);//On d�finit la position.
		m_background_right.setTexture(m_background_texture_right);//et la texture
		m_background_right.setTextureRect(*m_texturRect_background_right);

		m_Power.setFont(m_font);//Assignation police.
		m_Power.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_Power.setColor(sf::Color::Black);//Assignation couleur.
		m_Power.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.055, m_coord->getCoordonate()[1]+m_visibility.y*0.15);//Assignation position

		m_Agility.setFont(m_font);//Assignation police.
		m_Agility.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_Agility.setColor(sf::Color::Black);//Assignation couleur.
		m_Agility.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.16, m_coord->getCoordonate()[1]+m_visibility.y*0.15);//Assignation position

		m_Toughness.setFont(m_font);//Assignation police.
		m_Toughness.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_Toughness.setColor(sf::Color::Black);//Assignation couleur.
		m_Toughness.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.27, m_coord->getCoordonate()[1]+m_visibility.y*0.15);//Assignation position

		m_Level.setFont(m_font);//Assignation police.
		m_Level.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_Level.setColor(sf::Color::Black);//Assignation couleur.
		m_Level.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.055, m_coord->getCoordonate()[1]+m_visibility.y*0.55);//Assignation position

		m_World.setFont(m_font);//Assignation police.
		m_World.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_World.setColor(sf::Color::Black);//Assignation couleur.
		m_World.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.655, m_coord->getCoordonate()[1]+m_visibility.y*0.15);//Assignation position

		m_Monster_Rank.setFont(m_font);//Assignation police.
		m_Monster_Rank.setCharacterSize(m_characterSize);//Assignation taille (en fonction de la visibility).

		m_Monster_Rank.setColor(sf::Color::Black);//Assignation couleur.
		m_Monster_Rank.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.655, m_coord->getCoordonate()[1]+m_visibility.y*0.55);//Assignation position

		m_Resource_1=sf::RectangleShape(sf::Vector2f(m_visibility.x*0.025, m_visibility.x*0.025));
		m_Resource_1.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.815, m_coord->getCoordonate()[1]+m_visibility.y*0.16);//On d�finit la position.
		m_Resource_1.setFillColor(sf::Color::Red);//et la texture

		m_Resource_2=sf::RectangleShape(sf::Vector2f(m_visibility.x*0.025, m_visibility.x*0.025));
		m_Resource_2.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.845, m_coord->getCoordonate()[1]+m_visibility.y*0.16);//On d�finit la position.
		m_Resource_2.setFillColor(sf::Color::Red);//et la texture

		m_Resource_3=sf::RectangleShape(sf::Vector2f(m_visibility.x*0.025, m_visibility.x*0.025));
		m_Resource_3.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.875, m_coord->getCoordonate()[1]+m_visibility.y*0.16);//On d�finit la position.
		m_Resource_3.setFillColor(sf::Color::Red);//et la texture







		m_Life_bound.loadFromFile("HUDsprite.png");
		m_barreDeVie_contour.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.475, m_coord->getCoordonate()[1]);
		m_barreDeVie_contour.setSize(sf::Vector2f(m_visibility.x*0.10, m_visibility.y));
		m_barreDeVie_contour.setTexture(&m_Life_bound);
		m_barreDeVie.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.475, m_coord->getCoordonate()[1]);
		m_barreDeVie.setSize(sf::Vector2f(m_visibility.x*0.10, m_visibility.y));

		m_hud.setViewport(sf::FloatRect(0, 0.85, 1, 0.15f));

	}

	// TODO Auto-generated constructor stub

}

HUD::~HUD() {
	// TODO Auto-generated destructor stub
}


/*
 * M�thode virtuelle qui prend en parametre une r�f�rence de la variable de fen�tre
 * et qui d�fini la vue active par celle-ci, puis dessine tout ce qu'il faut dedans.
 */
void HUD::Draw(sf::RenderWindow* window, Player* player)
{
	stringstream oss;
	float getVal;
	string drawVal;
	window->setView(m_hud);

	if(m_Pos){
		window->draw(m_background);
		m_reserve.setString("Reserve : ");
		window->draw(m_reserve);
		window->draw(m_vertices, &m_tileset);
		window->draw(m_option);
		window->draw(m_text_option);
		window->draw(m_menu);
		window->draw(m_text_menu);
	}
	else{
		window->draw(m_background_left);
		window->draw(m_background_right);
		getVal=player->getPower();
		oss << getVal;
		m_Power.setString("Power : "+oss.str());
		oss.str("");
		getVal=player->getAgility();
		oss << getVal;
		m_Agility.setString("Agility : "+oss.str());
		oss.str("");
		getVal=player->getToughness();
		oss << getVal;
		m_Toughness.setString("Toughness : "+oss.str());
		oss.str("");
		getVal=player->getLevel();
		oss << getVal;
		m_Level.setString("Level : "+oss.str());
		oss.str("");
		m_World.setString("World : 1-Forest");
		m_Monster_Rank.setString("Monster rank : 1-5-Easy");
		window->draw(m_Power);
		window->draw(m_Agility);
		window->draw(m_Toughness);
		window->draw(m_Level);
		window->draw(m_World);
		window->draw(m_Monster_Rank);
		window->draw(m_Resource_1);
		window->draw(m_Resource_2);
		window->draw(m_Resource_3);
		float PV=player->getRatioLife();
		m_barreDeVie.setPosition(m_coord->getCoordonate()[0]+m_visibility.x*0.475, m_coord->getCoordonate()[1]+(m_visibility.y*(1-PV)));
		m_barreDeVie.setFillColor(sf::Color::Red);
		window->draw(m_barreDeVie);
		window->draw(m_barreDeVie_contour);

	}
}

sf::FloatRect HUD::getOption(){
	sf::FloatRect Bounds=m_option.getGlobalBounds();
	//	std::cout << m_spawnY << " " << m_coord->getCoordonate()[1] << std::endl;
	Bounds.top=Bounds.top-m_coord->getCoordonate()[1];
	Bounds.left=Bounds.left-m_coord->getCoordonate()[0];
	return Bounds;
}
sf::FloatRect HUD::getMenu(){
	sf::FloatRect Bounds=m_menu.getGlobalBounds();
	Bounds.top=Bounds.top-m_coord->getCoordonate()[1];
	Bounds.left=Bounds.left-m_coord->getCoordonate()[0];
	return Bounds;
}
int HUD::getHeight(){
	return m_height;
}
int HUD::getWidth(){
	return m_width;
}
/* namespace std */
