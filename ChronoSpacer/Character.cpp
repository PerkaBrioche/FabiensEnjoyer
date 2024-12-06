#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"

int palierLevel[7] = { 20,40,70,110,180,260,350 };
struct CharacterInfo
{
    int level;
    int experience;
    int damage;
    int baseLife;
    int actualLife;
};

struct Character
{
    sf::Texture characterTexture;
    CharacterInfo Info;

    int GetDamage(Character chara)
    {
        return (chara.Info.damage * chara.Info.level);
    }
    void ReceiveDamage(int damage)
    {
        Info.actualLife - damage;
    }
    void ReceiveXp(int xp)
    {
        Info.experience += xp;
        CheckIfLevelUp();
    }

    void CheckIfLevelUp()
    {
        if (Info.level >= sizeof(palierLevel)) { return; }
        if (Info.experience > palierLevel[Info.level]) 
        {
            Info.experience = 0;
            Info.level++;
            Info.damage += 5;
        }
    }
};


void InitializeSprite(sf::Sprite& targerImage, std::string assetName, sf::Vector2f targetScale, sf::Vector2f targetPosition)
{
    sf::Texture targetTexture;
    sf::Vector2u targetSize;

    targetTexture.loadFromFile(GetDirectories("Assets") + assetName);
    targerImage.setTexture(targetTexture);
    targetSize = targetTexture.getSize();
    targerImage.setOrigin(sf::Vector2f(targetSize.x / 2.0f, targetSize.y / 2.0f));
    targerImage.setScale(targetScale);
    targerImage.setPosition(targetPosition);
}
