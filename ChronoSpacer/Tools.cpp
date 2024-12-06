#include "Tools.h"

std::string GetAppPath()
{
	// RETOURNE LE FICHIER ACTUEL DU PROJET

	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	return appPath;
}

std::string GetDirectories(std::string dname)
{
	// RETOURNE UN FICHIER PRECIS AVEC UN NOM EN PARAMETRES EX : "Assets" VA RETOURNE LE FICHER ASSETS DANS LE FICHIER DU PROJET 

	std::string appPath = GetAppPath();
	appPath = appPath + dname + "\\";
	return appPath;
}

void CreateCircle(sf::CircleShape& circle, sf::Color color, float taille, sf::Vector2f postionVector)
{
	circle.setRadius(taille);
	circle.setFillColor(color);
	circle.setPosition(postionVector);
}

void CreateRect(sf::RectangleShape& carre, float longueur, float hauteur, sf::Color fillColor, sf::Color colorOutline, float tailleOutline, float pos_x, float pos_y) {

	sf::Vector2f rec = sf::Vector2f(longueur, hauteur);
	carre.setSize(rec);
	carre.setPosition(pos_x, pos_y);
	carre.setFillColor(fillColor);
	carre.setOutlineColor(colorOutline);
	carre.setOutlineThickness(tailleOutline);
}

void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition)
{
	// INITIALISE LE SPRITE D'UN CHARACTER COMPLEMENT DU INITIALISE PLAYER OU ENNEMY
	sf::Texture targetTexture;
	sf::Vector2u targetize;

	targetTexture.loadFromFile(GetDirectories("Assets") + assetName);
	targerImage.setTexture(targetTexture);
	targetize = targetTexture.getSize();
	targerImage.setOrigin(sf::Vector2f(targetize.x / 2.0f, targetize.y / 2.0f));
	targerImage.setScale(targetScale);
	targerImage.setPosition(targetPosition);
}

int GetRandomRange(int min, int max)
{
	// RETOURNE UN INT ENTRE UNE RANGE

	return min + rand() % ((max) - min);
}
