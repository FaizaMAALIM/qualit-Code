#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "character.h"
#include "groundElement.h"

class monster : public character
{
    public:
        virtual ~monster()=default;
        monster(const position &pos);
        void attack() override;
        void receiveAttack() override;
        double getHability() const;
    private:
        double d_hability;
   
};

#endif