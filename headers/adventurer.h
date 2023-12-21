#ifndef ADVENTURER_H_INCLUDED
#define ADVENTURER_H_INCLUDED
#include "character.h"
#include "sword.h"
#include "armory.h"
class viewManager;

class adventurer : public character
{
    public:
        adventurer(const position & pos,double swordSolidity=10.0,double armorySolidity=10.0);
     
        bool hasAmulet() const;
        void setAmuletTrue();
        bool isOutWithAmulet() const ;
        sword getSword() const;
        armory getArmor() const;
        void display(const viewManager& view) const override;
        void setSwordSolidity(double sol);
        void setArmorSolidity(double sol);
        void setIsOutTrue();

    private:
        sword d_sword;
        armory d_armor;
        bool d_hasAmulet;
        bool d_isOut;


};
//testcommit

#endif