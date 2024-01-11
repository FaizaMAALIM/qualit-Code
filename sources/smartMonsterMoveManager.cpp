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

#include "monsterMoveManager.h"

smartMonsterMoveManager::smartMonsterMoveManager(const position& p):monsterMoveManager{p}{}



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
    case HAUT:
        p = {getPos().getLine()-1,getPos().getColumn()};
        break;
    case BAS:
        p = {getPos().getLine()+1,getPos().getColumn()};
        break;
    case GAUCHE:
        p = {getPos().getLine(),getPos().getColumn()-1};
        break;
    case DROITE:
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





int smartMonsterMoveManager::choixDirection(int d1,int d2,const ground &g)
{
   int direction;

   position p1{directionPosition(d1)};
   position p2{directionPosition(d2)};

   int nbElem1 = g.nbElmtsPos(p1);
   int nbElem2 = g.nbElmtsPos(p2);

    if(nbElem1>1) //plus qu'une personne en d1 => il ny va pas
    {
        direction = d2;
    }
    else if(nbElem2>1) //plus qu'une personne en d2 => il ny va pas
    {
        direction = d1;
    }
    else if(nbElem1<2 && nbElem2<2)
    {
        int i1=g.indicePos(p1);
        int i2=g.indicePos(p2);

        char t1=g.typeOf(i1);
        char t2=g.typeOf(i2);

        if(t1==WALL || t1==BLINDMONSTER ||t1== SMARTMONSTER)
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



position smartMonsterMoveManager::possiblePosition(ground&g)
{
    //ON CHERCHE DANS QUELLE DIRECTION LE MONSTRE DOIT ALLER PR ALLER VERS AVENTURIER

    int lineAdv = g.getAdventurerPosition().getLine();
    int colAdv = g.getAdventurerPosition().getColumn();
    int lineMonster = getPos().getLine();
    int colMonster = getPos().getColumn();
    position pos{};
    position posError{-1,-1};

    /*
      2
    4 $ 6
      8
    */

    if(lineAdv==lineMonster && colMonster==colAdv)
    {
        pos ={getPos().getLine(),getPos().getColumn()};
        return pos;
    }


    if(lineMonster>lineAdv) // LE MONSTRE EST AU DESSUS DE LAVENTURIER
    {
        if(colMonster<colAdv)  //AU DESSUS A GAUCHE : aller en 2 ou 6
        {
           int direction = choixDirection(HAUT,DROITE,g);
           pos = directionPosition(direction);
        }
        else if(colMonster>colAdv)  //AU DESSUS A DROITE : aller en 4 ou 2
        {
           int direction = choixDirection(GAUCHE,HAUT,g);
           pos = directionPosition(direction);

        }
        else{ // AU DESSUS SUR LA MEME COLONNE 1 DIRECTIONS POSSIBLE : 2
            position ps = directionPosition(HAUT);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }

        }
    }
    else if(lineMonster<lineAdv)
    {
        if(colMonster<colAdv)
        {
            int direction = choixDirection(BAS,DROITE,g);
            pos = directionPosition(direction);
        }
        else if(colMonster>colAdv)
        {
           int direction = choixDirection(BAS,GAUCHE,g);
           pos = directionPosition(direction);

        }
        else{

            position ps = directionPosition(BAS);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }
        }
    }
    else if (lineMonster==lineAdv)
    {
        if(colMonster<colAdv){
            position ps = directionPosition(DROITE);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }
        }
        else{

            position ps = directionPosition(GAUCHE);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }
        }
    }
    else if(colMonster==colAdv)
    {
        if(lineMonster>lineAdv){

            position ps = directionPosition(HAUT);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }
        }
        else{
            position ps = directionPosition(BAS);
            if(g.nbElmtsPos(ps)<2)
            {
                pos = ps;
            }
            else{
                pos=posError;
            }
        }
    }

    return pos;
}


int smartMonsterMoveManager::directionAleatoire() const
{
    /*
      2
    4 $ 6
      8
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> directionsTab = {HAUT, DROITE, GAUCHE, BAS};
    std::uniform_int_distribution<> distrib(0, directionsTab.size() - 1);
    int i = distrib(gen);

    int directionAleat = directionsTab[i];
    return directionAleat;
}


void smartMonsterMoveManager::deplacementProche(ground&g)
{
    position p{possiblePosition(g)};

        if(p.getColumn()!=-1 && p.getLine()!=-1 && p.getColumn()<g.getNbColumns() && p.getLine()<g.getNbLines())
        {
            int indiceMonstre = g.getIndiceElmt(getPos(),'S');
            int indice = g.indicePos(p);

            if(g.nbElmtsPos(p)==2)
            {
                std::vector<int> tabIndices = g.getIndicePos(p);
                for(int i=0;i<tabIndices.size();i++)
                {
                    if(tabIndices[i]!=indiceMonstre)
                    {
                        indice =tabIndices[i];
                    }
                }
            }


            char typeCase = g.typeOf(indice);
            auto monster = dynamic_cast<smartMonster*>(g.getElementsTable()[indiceMonstre].get());


            if(typeCase==VIDE)
            {
                monster->changePosition(p);
            }
            else if((typeCase==AVENTURIER &&g.nbElmtsPos(p)<2 )||( p.getLine()== getPos().getLine() && p.getColumn()==getPos().getColumn()))
            {
                int indiceAdv = g.getIndiceAdventurer();

                monster->changePosition(p);
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

void smartMonsterMoveManager::deplacementAleatoire(ground &g)
{
    int dirAleat =  directionAleatoire();
       position p{directionPosition(dirAleat)};


        int nbElm= g.nbElmtsPos(p);

        if(nbElm<2 && p.getColumn()<g.getNbColumns()&& p.getColumn()>=0 && p.getLine()<g.getNbLines() && p.getLine()>=0)
        {

            int indice = g.indicePos(p);
            char t = g.typeOf(indice);

            int indiceMonstre = g.getIndiceElmt(getPos(),'S');
            auto monster = g.getElementsTable()[indiceMonstre].get();



            if(t==VIDE)
            {
                monster->changePosition(p);
            }

        }

}



void smartMonsterMoveManager::move(ground &g,int direction)
{

    if(isNearAdventurer(g))
    {
        deplacementProche(g);

    }
    else{
        deplacementAleatoire(g);
    }


}


