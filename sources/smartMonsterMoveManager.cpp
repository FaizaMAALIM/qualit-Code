 #include "smartMonsterMoveManager.h"
#include "ground.h"
#include "smartMonster.h"
#include <cmath>
#include <random>
#include <iostream>
#include "attackManager.h"
#include "monsterAttackManager.h"
#include "adventurer.h"
#include "adventurerAttackManager.h"
smartMonsterMoveManager::smartMonsterMoveManager(const position& p):movementManager{p}{}


//UN MONSTRE INTELLIGENT SE DEPLACE DANS 4 DIRECTIONS: 2 4 6 ou 8
/*
  2
4 $ 6
  8
*/


position smartMonsterMoveManager::directionPosition(int direction)
{
    position p{};
    switch (direction)
    {
    case 2:  // VERS LE HAUT = ligne d'en haut meme colonne
        p = {getPos().getLine()-1,getPos().getColumn()};
        break;
    case 8: // VERS LE BAS = ligne d'en bas meme colonne
        p = {getPos().getLine()+1,getPos().getColumn()};
        break;
    case 4: // VERS LA GAUCHE = meme ligne colonne de gauche
        p = {getPos().getLine(),getPos().getColumn()-1};
        break;
    case 6: // VERS LA DROITE = meme ligne colonne de droite
        p = {getPos().getLine(),getPos().getColumn()+1};
        break;
    default:
        break;
    }

    return p;
}
