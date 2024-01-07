#include <iostream>
#include "adventurerAttackManager.h"
#include "ground.h"
#include "adventurer.h"
#include "monster.h"
#include "weapon.h"
#include "attackManager.h"
#include "memory"

adventurerAttackManager::adventurerAttackManager(){}


double adventurerAttackManager::attack(groundElement *elem)
{
    auto adv=dynamic_cast<adventurer*>(elem);

    sword s = adv->getSword();
    double swordSolidity = s.getSolidity();
    double force;


    if(swordSolidity<=0)
    {
        force =0;
    }
    else
    {
        force =adv->forcePoints() + swordSolidity;
        double randomnb = pickRandom();

        if(randomnb>PROBA_RECOIT_ATTAQUE)
        {
            force *= POURCENT_FORCE_ATTAQUE;
        }

        adv->setSwordSolidity(swordSolidity-1);
    }

    return force;
}


bool adventurerAttackManager::receiveAttack(groundElement *elem,double force)
{
    auto adv=dynamic_cast<adventurer*>(elem);
    double reste;
    bool mort = false;
    double pfAbsorbesArmure = POURCENT_ABSORPTION_ATTAQUE * force;
    double armorSolidity = adv->getArmor().getSolidity();

    if(armorSolidity > (0.5)*pfAbsorbesArmure)
    {

        double nouvsol = armorSolidity - (0.5)*pfAbsorbesArmure;

        adv->setArmorSolidity(nouvsol);
        reste = PART_NON_ASBORBEE*force;

    }
    else
    {
        adv->setArmorSolidity(0);
        reste =  force - (2*armorSolidity);
    }

    if(reste >= adv->lifePoints())
    {
        adv->setLifePoints(0);
        mort = true;
    }
    else
    {   double lp = adv->lifePoints();
        adv->setLifePoints(lp - reste);
    }

    return mort;
}
