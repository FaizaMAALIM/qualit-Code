#include "adventurerMoveManager.h"
#include "adventurerAttackManager.h"
#include "monsterAttackManager.h"
#include "ground.h"
#include "adventurer.h"
#include "monster.h"
#include "money.h"
#include <iostream>
#include <memory>



adventurerMoveManager::adventurerMoveManager(const position&pos):movementManager{pos}{}


position adventurerMoveManager::directionPosition(int direction)
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

    case NE_BOUGE_PAS : 
        p = {getPos()};
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


void adventurerMoveManager::move(ground&g,int direction)
{
    position nouvPos{directionPosition(direction)};


    int indiceAdv{g.getIndiceAdventurer()};
    char type;
    auto adv=dynamic_cast<adventurer*>(g.getElementsTable()[indiceAdv].get());

    if(nouvPos.getColumn()<g.getNbColumns()&& nouvPos.getColumn()>=0 && nouvPos.getLine()<g.getNbLines() && nouvPos.getLine()>=0)
    {
        int indice = g.indicePos(nouvPos);

        type=g.typeOf(indice);

        if(g.nbElmtsPos(nouvPos)==2)
        {
           std::vector<int> tabElmt = g.getIndicePos(nouvPos);
           for(int i=0; i<tabElmt.size();i++)
           {
                if(g.typeOf(tabElmt[i])!='P')
                {
                    type = g.typeOf(tabElmt[i]);
                }
           }
        }


        if(type=='E') //vide => laventurier y va
        {
            adv->changePosition(nouvPos);
        }
        else if(type=='S' || type=='B') //MONSTRE => L'AVENTURIER y va + L ATTAQUE
        {
            adv->changePosition(nouvPos);
            int indiceMonstre = g.getIndiceElmt(nouvPos,type);
            auto monstreptr =  dynamic_cast<monster*>(g.getElementsTable()[indiceMonstre].get());

            adventurerAttackManager advAttackManager;
            double force = adv->attack(advAttackManager);

            //LE MONSTRE RECOIT UNE ATTAQUE
            monsterAttackManager mnstrAttackManager;
            bool mort=monstreptr->receiveAttack(mnstrAttackManager,force);

            if(mort) //SI LE MONSTRE SUCCOMBE A L ATTAQUE
            {
                double pfmonstre = monstreptr->forcePoints();
                double quart = 0.25 * pfmonstre;
                double reste = pfmonstre - quart;

                adv->setForcePoints(adv->forcePoints()+quart);
                adv->setLifePoints(adv->lifePoints()+reste);

                g.removeElement(indiceMonstre);
            }
        }
        else if(type=='A') //AMULETTE
        {
           g.removeElement(indice);
           adv->changePosition(nouvPos);
           adv->setAmuletTrue();

        }
        else if(type=='D') //case de sortie
        {
            if(adv->hasAmulet())
            {
                adv->setIsOutTrue();
            }

        }
        else if(type=='M') //tas de pièces
        {
            int val = recupMoney(nouvPos,g);
            adv->addToBourse(val);

           g.removeElement(indice);
           adv->changePosition(nouvPos);
           

        }

    }


}




int adventurerMoveManager::recupMoney(const position &nouvPos,ground &g)
{
    int indiceMoney = g.getIndiceElmt(nouvPos,'M');
    auto moneyPtr =  dynamic_cast<money*>(g.getElementsTable()[indiceMoney].get());

    int val = moneyPtr->getValue();
    return val;


}