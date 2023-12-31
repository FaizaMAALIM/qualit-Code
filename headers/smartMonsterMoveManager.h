 
#ifndef SMARTMONSTERMOVEMANAGER_H_INCLUDED
#define SMARTMONSTERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"
class ground;

class smartMonsterMoveManager : public movementManager
{
    public:
        smartMonsterMoveManager(const position& p);

        position directionPosition(int direction) override;

        bool isNearAdventurer(ground &g) const;
        position aleatoirePosition();


        int choixDirection(int d1,int d2,const ground &g) ;
        position possiblePosition(ground &g) ;

        void move(ground &g, int direction=0)override; //moi


};



#endif
