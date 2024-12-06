#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tools.h"

extern const int palierCount;
extern int palierLevel[];
struct Character;
struct CharacterInfo;

struct CharacterInfo
{
    bool isEnemy = true;
    int level;
    int experience;
    int damage;
    int defense;
    int baseLife;
    int actualLife = baseLife;
};

struct Character
{
    //sf::Sprite characterTexture;
    sf::CircleShape circleChara;
    CharacterInfo Info;
    bool isDefending = false;

    int GetDamage()
    {
        return Info.damage * Info.level;
    }

    void ReceiveDamage(int damage)
    {
        if (isDefending) 
        {
            damage -= Info.defense;
            if (damage < 0) { damage = 0; }
        }
        Info.actualLife -= damage;
        if (Info.actualLife < 0) {
            Info.actualLife = 0;

        }
    }

    void Defend() 
    {
        isDefending = true;
    }

    void InflictDamage(Character& chara) 
    {
        chara.ReceiveDamage(GetDamage());
    }

    void ReceiveXp(int xp)
    {
        Info.experience += xp;
        CheckIfLevelUp();
    }

    void CheckIfLevelUp()
    {
        if (Info.level >= palierCount) return;

        if (Info.experience >= palierLevel[Info.level])
        {
            Info.experience = 0;
            Info.level++;
            Info.damage += 5;
            Info.actualLife = Info.baseLife;
        }
    }
};

int GetDamage();
void ReceiveDamage(int damage);
void ReceiveXp(int xp);
void CheckIfLevelUp();
void DefinePalierLevel(int* p);

void InitializePlayer(Character& player);
Character InitializeEnemy(Character player);
