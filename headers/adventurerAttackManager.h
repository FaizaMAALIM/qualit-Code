#ifndef ADVENTURERATTACKMANAGER_H_INCLUDED
#define ADVENTURERATTACKMANAGER_H_INCLUDED
#include "attackManager.h"
#include "ground.h"


class adventurerAttackManager : public attackManager
{
    public :
        adventurerAttackManager();
        double attack(groundElement *elem) override;
        bool receiveAttack(groundElement *elem,double force) override;

        const double PROBA_RECOIT_ATTAQUE{0.8};
        const double POURCENT_FORCE_ATTAQUE{0.9};
        const double POURCENT_ABSORPTION_ATTAQUE{0.75};
        const double PART_NON_ASBORBEE{0.25};
};

#endif

