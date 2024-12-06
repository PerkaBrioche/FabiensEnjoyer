#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

std::string GetDirectories(std::string dname)
{
	std::string appPath = GetAppPath();
	appPath = appPath + dname + "\"";
	return appPath;
}

std::string GetAppPath()
{
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	return appPath;
}

void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition)
{
	sf::Texture targetTSexture;
	sf::Vector2u targetize;

	targetTexture.loadFromFile(GetDirectories("Assets") + assetName);
	targerImage.setTexture(targetTexture);
	targetSize = targetTexture.getSize();
	targerImage.setOrigin(sf::Vector2f(targetSize.x / 2.0f, targetSize.y / 2.0f));
	targerImage.setScale(targetScale);
	targerImage.setPosition(targetPosition);
}


