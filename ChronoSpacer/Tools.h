#pragma once
#include <iostream>
#include "Tools.cpp"
std::string GetDirectories(std::string dname);
std::string GetAppPath();
void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition);
