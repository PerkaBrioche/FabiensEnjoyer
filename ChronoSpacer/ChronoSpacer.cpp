
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
sf::CircleShape CreateCircle(float radiusValue, sf::Color circleColor);
std::string GetAppPath();
std::string GetDirectories(std::string dname);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
    sf::Clock clock;
    sf::Sprite img;
    sf::Font arialFont;
    sf::Text petitTexte;
    sf::Texture texture;

    sf::Vector2u textureSize;
    sf::CircleShape circle; // Déclaration de "circle" (sans affectation)

    arialFont.loadFromFile(GetDirectories("Assets") + "arial.ttf");
    texture.loadFromFile(GetAppPath() + "Maison.jpg");
    img.setTexture(texture);
    textureSize = texture.getSize();
    img.setOrigin(sf::Vector2f(textureSize.x / 2.0f, textureSize.y / 2.0f));
    img.setScale(0.05f, 0.05f);
    img.setPosition(400, 300);

    petitTexte.setFont(arialFont);
    petitTexte.setPosition(200, 500);
    petitTexte.setString("RER B");

    circle.setRadius(100.0f); // Appel de méthode qui travaille sur "circle"
    circle.setFillColor(sf::Color::Red);
    // Initialise everything below
    // Game loop
    while (window.isOpen()) {
        sf::Event event;


        while (window.pollEvent(event)) {
            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }



        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();



        const float turnPerSecond = 1.0f;
        float deltaAngle = deltaTime * 360 * turnPerSecond;


        img.rotate(deltaAngle);


        // Whatever I want to draw goes here

        window.clear();
        window.draw(circle);
        window.draw(img);
        window.draw(petitTexte);

        window.display();
    }
}

sf::CircleShape CreateCircle(float radiusValue, sf::Color circleColor)
{
	sf::CircleShape Circle;
	Circle.setRadius(radiusValue);
	Circle.setFillColor(circleColor);
	return Circle;
}

std::string GetDirectories(std::string dname) 
{
    std::string appPath = GetAppPath(256);
    appPath = appPath + dname + "\"";
    return appPath;
}

std::string GetAppPath()
{
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath,256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	return appPath;
}


