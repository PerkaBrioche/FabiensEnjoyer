#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Tools.h"
#include "Character.h"


void main()
{

}

Character InitializeCharacter()
{
    sf::Sprite playerTexture;

    InitializeSprite(playerTexture, "player.png", sf::Vector2f{ 400, 300 }, sf::Vector2f{ 0, 0 });

    Character player;
    player.characterTexture = playerTexture;
    player.Info = { 0, 0, 5, 10, 10 };

    return player;
}
// void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition);
