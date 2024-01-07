#ifndef SMARTMONSTERMOVEMANAGER_H_INCLUDED
#define SMARTMONSTERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"

#include "monsterMoveManager.h"

class ground;

class smartMonsterMoveManager : public monsterMoveManager
{
    public:
        smartMonsterMoveManager(const position& p);
        void move(ground &g, int direction=0)override;

        void deplacementProche(ground&g);
        void deplacementAleatoire(ground &g);

        position directionPosition(int direction) override;
        position possiblePosition(ground &g) override;
        int directionAleatoire() const override;


        int choixDirection(int d1,int d2,const ground &g) ;

        bool isNearAdventurer(ground &g) const;

};



#endif
