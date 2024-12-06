#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <random>

std::string GetDirectories(std::string dname);
std::string GetAppPath();
int GetRandomRange(int min, int max);
void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition);
void CreateRect(sf::RectangleShape& carre, float longueur, float hauteur, sf::Color fillColor, sf::Color colorOutline, float tailleOutline, float pos_x, float pos_y);
void CreateCircle(sf::CircleShape& circle, sf::Color color, float taille, sf::Vector2f postionVector);
