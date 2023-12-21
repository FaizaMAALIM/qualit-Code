#include "monster.h"
#include "viewManager.h"
#include <iostream>
#include "ground.h"
        
monster::monster(const position &pos, double hability) : character{pos},d_hability{hability} {}

bool monster::isAtOneCaseAdv(ground &g)
{
    int lineAdv = g.getAdventurerPosition().getLine();
    int colAdv = g.getAdventurerPosition().getColumn();
    int lineMonster = getPosition().getLine();
    int colMonster = getPosition().getColumn();

    int difLine=std::abs(lineMonster-lineAdv);
    int difCol =std::abs(colMonster-colAdv);
   
    return difLine<=1 && difCol<=1;
}


double monster::getHability() const
{
    return d_hability;
}

void monster::display(const viewManager& view) const
{
    //APPEL LAFFICHEUR QUI LAFFICHE (passer lafficheur en parametre)
    view.displayMonster(*this);
}
