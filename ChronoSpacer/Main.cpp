#include "Main.h"
Character Player;
Character Enemy;


void main()
{
    Initalization();
}

void Initalization() 
{
    InitializePlayer(Player);
    int paliers[] = { 20, 40, 70, 110, 180, 260, 350 };
    DefinePalierLevel(paliers);
    DisplaySFML();
    NewRound();

}

void DisplaySFML()
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
        window.draw(Player.circleChara);
        window.draw(Enemy.circleChara);
        // Whatever I want to draw goes here
        window.display();
    }

}

void NewRound()
{
    // L'ENNEMI A ETE TUE ON LANCE UN NOUVEAU TOUR
    Enemy = InitializeEnemy(Player);
    ResetRound();

}

void AttackEnemy()
{
    Player.InflictDamage(Enemy);
}
void DefendPlayer() 
{
    Player.Defend();
}

void ResetRound()
{
    // ON RESET LES ACTIONS
    Enemy.isDefending = false;
    Player.isDefending = false;
    PlayerRound();
}

void PlayerRound() 
{
    // FAIRE EN SORTE QUE LE JOUEUR PUISSE BOUGER ENTRE LES BOUTTONS
}

void IARound() 
{
    // C'est a L'IA DE JOUER - DEFENDRE OU ATTAQUER

    int randomAction = GetRandomRange(1, 5);
    if (randomAction > 1 && randomAction < 3) 
    {
        Enemy.InflictDamage(Player);
    }
    else 
    {
        Enemy.Defend();
    }

    ResetRound();
}


