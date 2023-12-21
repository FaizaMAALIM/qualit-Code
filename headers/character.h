#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "groundElement.h"
#include "position.h"
class attackManager;
class ground;

//CLASS REPRESENTANT UN PERSONNAGE DU TERRAIN ( monstres ou aventurier )


class character : public groundElement
{
    public:
        character(const position &p);
        virtual ~character()= default;
        
        //GETTERS
        int forcePoints() const;
        int lifePoints() const;

        //SETTERS
        void setForcePoints(double nouvForce);
        void setLifePoints(double nouvLife);

    
    private:
        int d_forcePoints=100;
        int d_lifePoints=1000;

};




#endif