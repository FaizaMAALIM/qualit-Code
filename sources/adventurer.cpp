#include "adventurer.h"

adventurer::adventurer(const position &pos):character{pos}{}

bool adventurer::hasAmulet() const
{
    return d_hasAmulet;
}

void adventurer::attack()
{
    //GESTIONNAIRE D ATTAQUE
}

void adventurer::receiveAttack()
{
    //GESTIONNAIRE D ATTAQUE
}

void adventurer::moveAt(const position &pos)
{
    //GESTIONNAIRE DE DEPLACEMENT
}


void adventurer::setAmuletTrue()
{
    d_hasAmulet = true;
}