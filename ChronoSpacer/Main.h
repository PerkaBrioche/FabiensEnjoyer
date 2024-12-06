#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Tools.h"
#include "Character.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ChronoSpacer");
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
		window.clear();
		// Whatever I want to draw goes here
		window.display();
	}
}

