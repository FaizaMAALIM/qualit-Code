#include "monster.h"
#include <iostream>
        
monster::monster(const position &pos) : character{pos} {}

void monster::attack()
{
    //LANCE UNE ATTAQUE : APPELLE LE GESTIONNAIRE D ATTAQUE
}

void monster::receiveAttack()
{
    //RECOIT UNE ATTAQUE : APPELLE LE GESTIONNAIRE D ATTAQUE
}

double monster::getHability() const
{
    return d_hability;
}

