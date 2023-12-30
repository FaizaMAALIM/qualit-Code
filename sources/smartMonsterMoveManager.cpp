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

//VRAI SI LE MONSTRE EST A - DE 8 CASES DE L AVENTURIER
bool smartMonsterMoveManager::isNearAdventurer(ground &g) const
{
    int lineAdv = g.getAdventurerPosition().getLine();
    int colAdv = g.getAdventurerPosition().getColumn();
    int lineMonster = getPos().getLine();
    int colMonster = getPos().getColumn();

    int difLine=std::abs(lineMonster-lineAdv);
    int difCol =std::abs(colMonster-colAdv);

    return difLine<8 && difCol<8;
}

position smartMonsterMoveManager::aleatoirePosition()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> directionsTab = {2, 4, 6, 8};
    std::uniform_int_distribution<> distrib(0, directionsTab.size() - 1);
    int i = distrib(gen);

    int directionAleat = directionsTab[i];
    return directionPosition(directionAleat);
}

int smartMonsterMoveManager::choixDirection(int d1,int d2,const ground &g)
{
   int direction;

   position p1{directionPosition(d1)};
   position p2{directionPosition(d2)};

   int nbElem1 = g.nbElmtsPos(p1);
   int nbElem2 = g.nbElmtsPos(p2);

    if(nbElem1>1)
    {
        direction = d2;
    }
    else if(nbElem2>1)
    {
        direction = d1;
    }
    else if(nbElem1<2 && nbElem2<2)
    {
        int i1=g.indicePos(p1);
        int i2=g.indicePos(p2);

        char t1=g.typeOf(i1);
        char t2=g.typeOf(i2);

        if(t1=='W'|| t1=='B' ||t1=='S')
        {
            direction = d2;
        }
        else
        {
            direction = d1;
        }
    }

    return direction;
}
