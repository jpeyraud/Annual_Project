/*
 * HUD.cpp
 *
 *  Created on: 30 nov. 2013
 *      Author: Akoma
 */

#include "HUD.h"

/*
 * Constructeur qui prend en paramètres la dimension de la fenêtre
 * et le boolean qui lui dit si elle est en haut ou en bas.
 */
HUD::HUD(bool posi, sf::Vector2u visi, float spawnX, float spawnY) {
	Pos=posi;
	visibility=visi;
	visibility.y=visibility.y*0.15;
	/*
	 * Elements commun au deux HUD :
	 * La position de la vue (monde 2D)
	 * Le background
	 * La police de charactère
	 */

	//Le centre de la vue est donc le spawn, ça taille est la longueur de la fenêtre pour 1/15 de sa hauteur de
	//sa hauteur.
	hud.setCenter(sf::Vector2f(spawnX, spawnY));//Centré sur le spawn
	hud.setSize(sf::Vector2f(visibility.x, visibility.y));//En fonction de la visibility pour l'utilisé dans la taille des charactères.


	//Background de l'HUD
	background_texture.loadFromFile("HUDsprite.jpg", sf::IntRect(5, 3, 492, 49));//La texture
	button_texture.loadFromFile("button_texture.png");

	//Le contenant (taille en fonctionde de la visibility)
	//Position du point supèrieure gauche du contenant
	posX=spawnX-(visibility.x/2);//centre de la vue moins moitiers de la longueur du contenant.
	posY=spawnY-(visibility.y/2);//centre de la vue moins la moitier de la hauteur du contenant.


	//On commence par charger la police de texte
	font.loadFromFile("Cardinal.ttf");

	/*
	 * Transtypage int->String
	 */
	//		// créer un flux de sortie
	//		ostringstream oss;
	//		// écrire un nombre dans le flux
	//		oss << visibility.y*0.20;
	//		// récupérer une chaîne de caractères
	//		string result = oss.str();
	//		Power.setString("La taille des caractères est de : "+result);
	/*
	 *
	 */


	/*
	 * ViewPort pour la position de la vue dans la fenêtre, il s'agit ici d'un ratio par rapport à la taille
	 * de la fenêtre en pixels.
	 * les deux premier paramètres sont la position du coin supèrieure gauche de la vue,
	 * les deux dernier sont ses dimension x et y.
	 */
	if(Pos){
		background=sf::RectangleShape(sf::Vector2f(visibility.x, visibility.y));
		background.setPosition(posX, posY);//On définit la position.
		background.setTexture(&background_texture);//et la texture

		hud.setViewport(sf::FloatRect(0, 0, 1, 0.15f));

		reserve.setFont(font);//Assignation police.
		reserve.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		reserve.setStyle(sf::Text::Bold);//Assignation Style.
		reserve.setColor(sf::Color::Black);//Assignation couleur.
		reserve.setPosition(posX+visibility.x*0.1, posY+visibility.y*0.15);//Assignation position

		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(3 * 2 * 4);
		m_tileset.loadFromFile("tilea4.png");
		vector<int> tiles;
		sf::Vector2u textureSize=sf::Vector2u(32, 32);
		sf::Vector2f tileSize=sf::Vector2f(visibility.x*0.025, visibility.x*0.025);
		for(int i=1; i<3*2;i++){
			tiles.push_back(i);
		}
		for (float i = 0; i < 3*2; i+=2)
			for (float j = 0; j < 2*2; j+=2)
			{
				// on récupère le numéro de tuile courant
				int tileNumber = tiles[i/2 + j/2 * 3];

				// on en déduit sa position dans la texture du tileset
				int tu = tileNumber % (m_tileset.getSize().x / textureSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / textureSize.x);

				// on récupère un pointeur vers le quad à définir dans le tableau de vertex
				sf::Vertex* quad = &m_vertices[(i/2 + j/2 * 3) * 4];

				// on définit ses quatre coins
				if(i==0){
					if(j==2){
						quad[0].position = sf::Vector2f(i * tileSize.x+(posX+visibility.x*0.2), (j-0.5) * tileSize.y+(posY+visibility.y*0.16));
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x+(posX+visibility.x*0.2), (j-0.5) * tileSize.y+(posY+visibility.y*0.16));
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x+(posX+visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(posY+visibility.y*0.16));
						quad[3].position = sf::Vector2f(i * tileSize.x+(posX+visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(posY+visibility.y*0.16));
					}
					else{
						quad[0].position = sf::Vector2f(i * tileSize.x+(posX+visibility.x*0.2), j * tileSize.y+(posY+visibility.y*0.16));
						quad[1].position = sf::Vector2f((i + 1) * tileSize.x+(posX+visibility.x*0.2), j * tileSize.y+(posY+visibility.y*0.16));
						quad[2].position = sf::Vector2f((i + 1) * tileSize.x+(posX+visibility.x*0.2), (j + 1) * tileSize.y+(posY+visibility.y*0.16));
						quad[3].position = sf::Vector2f(i * tileSize.x+(posX+visibility.x*0.2), (j + 1) * tileSize.y+(posY+visibility.y*0.16));
					}
				}
				else{
					if(j==2){
						quad[0].position = sf::Vector2f((i+i/4) * tileSize.x+(posX+visibility.x*0.2), (j-0.5) * tileSize.y+(posY+visibility.y*0.16));
						quad[1].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(posX+visibility.x*0.2), (j-0.5) * tileSize.y+(posY+visibility.y*0.16));
						quad[2].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(posX+visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(posY+visibility.y*0.16));
						quad[3].position = sf::Vector2f((i+i/4) * tileSize.x+(posX+visibility.x*0.2), ((j-0.5) + 1) * tileSize.y+(posY+visibility.y*0.16));
					}
					else{
						quad[0].position = sf::Vector2f((i+i/4) * tileSize.x+(posX+visibility.x*0.2), j * tileSize.y+(posY+visibility.y*0.16));
						quad[1].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(posX+visibility.x*0.2), j * tileSize.y+(posY+visibility.y*0.16));
						quad[2].position = sf::Vector2f(((i+i/4) + 1) * tileSize.x+(posX+visibility.x*0.2), (j + 1) * tileSize.y+(posY+visibility.y*0.16));
						quad[3].position = sf::Vector2f((i+i/4) * tileSize.x+(posX+visibility.x*0.2), (j + 1) * tileSize.y+(posY+visibility.y*0.16));
					}
				}


				// on définit ses quatre coordonnées de texture
				quad[0].texCoords = sf::Vector2f(tu * textureSize.x, tv * textureSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * textureSize.x, tv * textureSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * textureSize.x, (tv + 1) * textureSize.y);
				quad[3].texCoords = sf::Vector2f(tu * textureSize.x, (tv + 1) * textureSize.y);
			}


		Button_1=sf::RectangleShape(sf::Vector2f(visibility.x*0.20, visibility.y*0.40));
		Button_1.setPosition(posX+visibility.x*0.50, posY+visibility.y*0.08);//On définit la position.
		Button_1.setTexture(&button_texture);//et la texture

		Button_2=sf::RectangleShape(sf::Vector2f(visibility.x*0.20, visibility.y*0.40));
		Button_2.setPosition(posX+visibility.x*0.50, posY+visibility.y*0.48);//On définit la position.
		Button_2.setTexture(&button_texture);//et la texture


	}
	else{
		background_left=sf::RectangleShape(sf::Vector2f(visibility.x*0.45, visibility.y));
		background_left.setPosition(posX, posY);//On définit la position.
		background_left.setTexture(&background_texture);//et la texture

		background_right=sf::RectangleShape(sf::Vector2f(visibility.x*0.40, visibility.y));
		background_right.setPosition(posX+visibility.x*0.60, posY);//On définit la position.
		background_right.setTexture(&background_texture);//et la texture

		Power.setFont(font);//Assignation police.
		Power.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		Power.setStyle(sf::Text::Bold);//Assignation Style.
		Power.setColor(sf::Color::Black);//Assignation couleur.
		Power.setPosition(posX+visibility.x*0.055, posY+visibility.y*0.15);//Assignation position

		Agility.setFont(font);//Assignation police.
		Agility.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		Agility.setStyle(sf::Text::Bold);//Assignation Style.
		Agility.setColor(sf::Color::Black);//Assignation couleur.
		Agility.setPosition(posX+visibility.x*0.16, posY+visibility.y*0.15);//Assignation position

		Toughness.setFont(font);//Assignation police.
		Toughness.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		Toughness.setStyle(sf::Text::Bold);//Assignation Style.
		Toughness.setColor(sf::Color::Black);//Assignation couleur.
		Toughness.setPosition(posX+visibility.x*0.27, posY+visibility.y*0.15);//Assignation position

		Level.setFont(font);//Assignation police.
		Level.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		Level.setStyle(sf::Text::Bold);//Assignation Style.
		Level.setColor(sf::Color::Black);//Assignation couleur.
		Level.setPosition(posX+visibility.x*0.055, posY+visibility.y*0.55);//Assignation position

		World.setFont(font);//Assignation police.
		World.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		World.setStyle(sf::Text::Bold);//Assignation Style.
		World.setColor(sf::Color::Black);//Assignation couleur.
		World.setPosition(posX+visibility.x*0.655, posY+visibility.y*0.15);//Assignation position

		Monster_Rank.setFont(font);//Assignation police.
		Monster_Rank.setCharacterSize(visibility.y*0.25);//Assignation taille (en fonction de la visibility).
		Monster_Rank.setStyle(sf::Text::Bold);//Assignation Style.
		Monster_Rank.setColor(sf::Color::Black);//Assignation couleur.
		Monster_Rank.setPosition(posX+visibility.x*0.655, posY+visibility.y*0.55);//Assignation position

		Resource_1=sf::RectangleShape(sf::Vector2f(visibility.x*0.025, visibility.x*0.025));
		Resource_1.setPosition(posX+visibility.x*0.805, posY+visibility.y*0.16);//On définit la position.
		Resource_1.setFillColor(sf::Color::Red);//et la texture

		Resource_2=sf::RectangleShape(sf::Vector2f(visibility.x*0.025, visibility.x*0.025));
		Resource_2.setPosition(posX+visibility.x*0.835, posY+visibility.y*0.16);//On définit la position.
		Resource_2.setFillColor(sf::Color::Red);//et la texture

		Resource_3=sf::RectangleShape(sf::Vector2f(visibility.x*0.025, visibility.x*0.025));
		Resource_3.setPosition(posX+visibility.x*0.865, posY+visibility.y*0.16);//On définit la position.
		Resource_3.setFillColor(sf::Color::Red);//et la texture





		/*
		 * Conteneur de la barre de vie.
		 */
		//		barreDeVie_contour.setPosition(posX+(visibility.x*0.13), posY+(visibility.y)*0.25);
		//		barreDeVie_contour.setSize(Vector2f(250, 25));
		//		barreDeVie_contour.setOutlineThickness(2);
		//		barreDeVie_contour.setOutlineColor(Color::Black);
		//		barreDeVie_contour.setFillColor(Color::Black);
		/*
		 * Contenu de la barre de vie.
		 */
		//		barreDeVie.setPosition(posX+(visibility.x*0.13), posY+(visibility.y)*0.25);

		Life_bound.loadFromFile("HUDsprite.png");
		barreDeVie_contour.setPosition(posY+visibility.x*0.475, posY);
		barreDeVie_contour.setSize(sf::Vector2f(visibility.x*0.10, visibility.y));
		barreDeVie_contour.setTexture(&Life_bound);
		barreDeVie.setPosition(posX+visibility.x*0.475, posY);
		barreDeVie.setSize(sf::Vector2f(visibility.x*0.10, visibility.y));

		hud.setViewport(sf::FloatRect(0, 0.851, 1, 0.15f));

	}

	// TODO Auto-generated constructor stub

}

HUD::~HUD() {
	// TODO Auto-generated destructor stub
}


/*
 * Méthode virtuelle qui prend en parametre une référence de la variable de fenêtre
 * et qui défini la vue active par celle-ci, puis dessine tout ce qu'il faut dedans.
 */
void HUD::Draw(sf::RenderWindow* window, Player* player)
{
	stringstream oss;
	float getVal;
	string drawVal;
	window->setView(hud);

	if(Pos){
		window->draw(background);
		reserve.setString("Reserve : ");
		window->draw(reserve);
		window->draw(m_vertices, &m_tileset);
		window->draw(Button_1);
		window->draw(Button_2);
	}
	else{
		window->draw(background_left);
		window->draw(background_right);
		getVal=player->getPower();
		oss << getVal;
		Power.setString("Power : "+oss.str());
		oss.str("");
		getVal=player->getAgility();
		oss << getVal;
		Agility.setString("Agility : "+oss.str());
		oss.str("");
		getVal=player->getToughness();
		oss << getVal;
		Toughness.setString("Toughness : "+oss.str());
		oss.str("");
		getVal=player->getLevel();
		oss << getVal;
		Level.setString("Level : "+oss.str());
		oss.str("");
		World.setString("World : 1-Forest");
		Monster_Rank.setString("Monster rank : 1-5-Easy");
		window->draw(Power);
		window->draw(Agility);
		window->draw(Toughness);
		window->draw(Level);
		window->draw(World);
		window->draw(Monster_Rank);
		window->draw(Resource_1);
		window->draw(Resource_2);
		window->draw(Resource_3);
		float PV=player->getRatioLife();
		barreDeVie.setPosition(posY+visibility.x*0.475, posY+(visibility.y*(1-PV)));
		barreDeVie.setFillColor(sf::Color::Red);
		window->draw(barreDeVie);
		window->draw(barreDeVie_contour);

	}
}


 /* namespace std */
