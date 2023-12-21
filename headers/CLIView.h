#ifndef CLIView_H_INCLUDED
#define CLIView_H_INCLUDED
#include <iostream>
#include "viewManager.h"


class CLIView : public viewManager
{
    public:
        CLIView();
        void displayAdventurer(const adventurer &adv) const override;
        void displayWall(const wall &w) const override;
        void displayAmulet(const amulet &a) const override;
        void displayMonster(const monster &m) const override;
        void displayDoor(const door &d) const override;
        void displayOutside(const outside &o) const override;



};



#endif