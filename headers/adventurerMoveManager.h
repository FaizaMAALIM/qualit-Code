 #ifndef ADVENTURERMOVEMANAGER_H_INCLUDED
#define ADVENTURERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"
class ground;

class adventurerMoveManager : public movementManager
{
    public:
        adventurerMoveManager(const position&pos);

        position directionPosition(int direction) override;

         void move(ground &g,int direction) override;




};


#endif
