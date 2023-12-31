#include "blindMonsterMoveManager.h"
#include "blindMonster.h"
#include "ground.h"
#include <cmath>
#include <random>
#include <iostream>
#include "adventurerAttackManager.h"
#include "monsterAttackManager.h"
#include "blindMonsterMoveManager.h"
#include "adventurer.h"

blindMonsterMoveManager::blindMonsterMoveManager(const position&pos):movementManager{pos}{}

position blindMonsterMoveManager::directionPosition(int direction)
{
    position p{};
    switch (direction)
    {

    case 1 :
        p={getPos().getLine()-1,getPos().getColumn()-1};
        break;

    case 2 :
        p = {getPos().getLine()-1,getPos().getColumn()};
        break;

    case 3 :
        p = {getPos().getLine()-1, getPos().getColumn()+1};
        break;

    case 4 :
        p = {getPos().getLine(),getPos().getColumn()-1};
        break;

    case 6 :
        p = {getPos().getLine(),getPos().getColumn()+1};
        break;

    case 7 :
        p = {getPos().getLine()+1, getPos().getColumn()-1};
        break;

    case 8 :
        p = {getPos().getLine()+1,getPos().getColumn()};
        break;

    case 9 :
        p= {getPos().getLine()+1, getPos().getColumn()+1};
        break;

    default:
        break;
    }

    return p;
}


int blindMonsterMoveManager::directionAleatoire() const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> directionsTab = {1, 2, 3, 4, 6, 7, 8, 9};
    std::uniform_int_distribution<> distrib(0, directionsTab.size() - 1);
    int i = distrib(gen);
    int direction= directionsTab[i];

    return direction;
}
