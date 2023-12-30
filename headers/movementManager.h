 
#ifndef MOVEMENTMANAGER_H_INCLUDED
#define MOVEMENTMANAGER_H_INCLUDED
#include "position.h"
#include "vector"
#include "ground.h"
class movementManager
{
    public:
         movementManager(const position&pos);
        virtual ~movementManager()=default;
        position getPos() const;

        virtual position directionPosition(int direction)=0;


  private:
        position d_position;

};

#endif
