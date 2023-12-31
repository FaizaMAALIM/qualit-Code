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

        if(randomnb>0.8)
        {
            force *= 0.9;
        }

        adv->setSwordSolidity(swordSolidity-1);
    }

    return force;
}
