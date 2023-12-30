 
#ifndef SMARTMONSTERMOVEMANAGER_H_INCLUDED
#define SMARTMONSTERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"
class ground;

class smartMonsterMoveManager : public movementManager
{
    public:
        smartMonsterMoveManager(const position& p);

        position directionPosition(int direction) override;


};



#endif
