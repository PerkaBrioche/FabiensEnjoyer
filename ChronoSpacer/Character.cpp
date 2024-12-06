#pragma once
#include <iostream>
#include "Tools.h"

int palierLevel[7] = { 20, 40, 70, 110, 180, 260, 350 };

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
    sf::Sprite characterTexture;
    CharacterInfo Info;

    int GetDamage() const
    {
        return Info.damage * Info.level;
    }

    void ReceiveDamage(int damage)
    {
        Info.actualLife -= damage;
        if (Info.actualLife < 0) Info.actualLife = 0;
    }

    void ReceiveXp(int xp)
    {
        Info.experience += xp;
        CheckIfLevelUp();
    }

    void CheckIfLevelUp()
    {
        int maxLevels = sizeof(palierLevel) / sizeof(palierLevel[0]);
        if (Info.level >= maxLevels) return;

        if (Info.experience >= palierLevel[Info.level])
        {
            Info.experience = 0;
            Info.level++;
            Info.damage += 5;
            Info.actualLife = Info.baseLife;
        }
    }
};