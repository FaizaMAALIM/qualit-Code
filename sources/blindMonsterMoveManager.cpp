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

#include "monsterMoveManager.h"
blindMonsterMoveManager::blindMonsterMoveManager(const position&pos):monsterMoveManager{pos}{}


//UN MONSTRE AVEUGLE SE DEPLACE DANS 8 DIRECTIONS:
/*
1 2 3
4 * 6
7 8 9
*/

position blindMonsterMoveManager::directionPosition(int direction)
{
    position p{};
    switch (direction)
    {

    case HAUT_GAUCHE :
        p={getPos().getLine()-1,getPos().getColumn()-1};
        break;

    case HAUT :
        p = {getPos().getLine()-1,getPos().getColumn()};
        break;

    case HAUT_DROITE :
        p = {getPos().getLine()-1, getPos().getColumn()+1};
        break;

    case GAUCHE :
        p = {getPos().getLine(),getPos().getColumn()-1};
        break;

    case DROITE :
        p = {getPos().getLine(),getPos().getColumn()+1};
        break;

    case BAS_GAUCHE :
        p = {getPos().getLine()+1, getPos().getColumn()-1};
        break;

    case BAS :
        p = {getPos().getLine()+1,getPos().getColumn()};
        break;

    case BAS_DROITE :
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
    std::vector<int> directionsTab = {HAUT_GAUCHE, HAUT, HAUT_DROITE, GAUCHE, DROITE, BAS_GAUCHE, BAS, BAS_DROITE};
    std::uniform_int_distribution<> distrib(0, directionsTab.size() - 1);
    int i = distrib(gen);
    int direction= directionsTab[i];

    return direction;
}


position blindMonsterMoveManager::possiblePosition(ground &g)
{

   position posAdv = g.getAdventurerPosition();

    if((posAdv.getLine()== getPos().getLine() && posAdv.getColumn()==getPos().getColumn()))
    {
        position pos{getPos()};
        return pos;
    }

    int direction  = directionAleatoire();

    return directionPosition(direction);

}


void blindMonsterMoveManager::move(ground &g, int direction)
{
    position nouvPos{possiblePosition(g)};


    if((nouvPos.getColumn()<g.getNbColumns() && nouvPos.getColumn()>=0 && nouvPos.getLine()<g.getNbLines()&& nouvPos.getLine()>=0))
    {
        position anciennePos{getPos()};
        int indice = g.getIndiceElmt(anciennePos,'B');

        auto monster = dynamic_cast<blindMonster*>(g.getElementsTable()[indice].get());
        int indiceNouv = g.indicePos(nouvPos);

        if(g.nbElmtsPos(nouvPos)==2)
        {
            std::vector<int> tabIndices = g.getIndicePos(nouvPos);
            for(int i=0;i<tabIndices.size();i++)
            {
                if(tabIndices[i]!=indice)
                {
                    indiceNouv =tabIndices[i];
                }
            }
        }

        char typeCase=g.typeOf(indiceNouv);

        if(typeCase==VIDE)
        {
            monster->changePosition(nouvPos);
        }
        else if((typeCase==AVENTURIER && g.nbElmtsPos(nouvPos)<2 )||(nouvPos.getLine()== getPos().getLine() && nouvPos.getColumn()==getPos().getColumn()))
        {
            monster->changePosition(nouvPos);

            int indiceAdv = g.getIndiceAdventurer();
            auto adv = dynamic_cast<adventurer*>(g.getElementsTable()[indiceAdv].get()) ;

            //LE MONSTRE LANCE UNE ATTAQUE
            monsterAttackManager mnstrAttackManager;
            double force = monster->attack(mnstrAttackManager);

            // L'ADV RECOIT L ATTAQUE
            adventurerAttackManager advAttackManager;
            bool mort = adv->receiveAttack(advAttackManager,force);
        }
    }

}
