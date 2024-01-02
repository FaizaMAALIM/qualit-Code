#ifndef MONSTERMOVEMANAGER_H_INCLUDED
#define MONSTERMOVEMANAGER_H_INCLUDED
#include "movementManager.h"
#include "position.h"


class monsterMoveManager : public movementManager
{
    public:
      monsterMoveManager(const position&pos);
      ~monsterMoveManager() = default;
      virtual position possiblePosition(ground &g) =0;
      virtual int directionAleatoire() const = 0;
      

};


#endif
