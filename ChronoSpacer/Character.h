<<<<<<< HEAD
struct CharacterInfo
{
    int level;
    int experience;
    int damage;
    int baseLife;
    int actualLife;
};
struct Character {

    int GetDamage(Character chara);
    void ReceiveDamage(int damage);
    void ReceiveXp(int xp);
};
=======
#include "Character.cpp"


struct Character;
int GetDamage(Character chara);
void ReceiveDamage(int damage);
void ReceiveXp(int xp);
>>>>>>> main

