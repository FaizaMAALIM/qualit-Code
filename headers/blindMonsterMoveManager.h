#ifndef BLINDMONSTERMOVEMANAGER_H_INCLUDED
#define BLINDMONSTERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"

#include "monsterMoveManager.h"
class ground;


class blindMonsterMoveManager : public monsterMoveManager
{
    public:
        blindMonsterMoveManager(const position &p);
        position directionPosition(int direction) override;
        position possiblePosition(ground &g) override;
        void move(ground &g,int direction=0) override;
        int directionAleatoire() const override;

};


#endif
