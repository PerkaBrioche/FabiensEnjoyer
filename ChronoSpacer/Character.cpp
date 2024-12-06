#include "Character.h"
const int palierCount = 7;
int palierLevel[palierCount];

void InitializePlayer(Character& player)
{
    // INITIALISE LE JOUEUR ET MODIFIE DIRECTEMENT SES STATS, IMAGE POSITION ECT

    //sf::Sprite playerTexture;

    //InitializeSprite(playerTexture, "player.png", sf::Vector2f{ 400, 300 }, sf::Vector2f{ 0, 0 });

    sf::CircleShape circle;
    CreateCircle(circle, sf::Color::Green, 30.0f, { 150,200 });

    CharacterInfo charaInfo = { false ,0, 0, 5, 1 ,10 };
    player = { circle, charaInfo };
}

Character InitializeEnemy(Character player)
{
    // INITIALISER UN ENNEMI AVEC LE LEVEL DU PLAYER
    int level = player.Info.level;
    int damage = (GetRandomRange(2, 5) * level);
    int baseLife = (GetRandomRange(4, 8) * level);
    // STATS RANDOM DANS LA RANGE DU JOUEUR

    //sf::Sprite EnemyTexture;
    //InitializeSprite(EnemyTexture, "enemy.png", sf::Vector2f{ 400, 300 }, sf::Vector2f{ 0, 0 });

    sf::CircleShape circle;
    CreateCircle(circle, sf::Color::Red, 30.0f, { 200,200 });

    CharacterInfo charaInfo = { true, level, 0, damage, baseLife };
    Character Enemy = { circle, charaInfo };

    return Enemy;
}


void DefinePalierLevel(int* p)
{
    for (int i = 0; i < palierCount; i++) 
    {
        palierLevel[i] = p[i];
    }
}


    //    palierLevel[7] = { 20, 40, 70, 110, 180, 260, 350 };
