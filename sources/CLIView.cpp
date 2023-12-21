#include "CLIView.h"
#include "adventurer.h"
#include "amulet.h"
#include "wall.h"
#include "monster.h"
using std::cout;

CLIView::CLIView(){}

void CLIView::displayAdventurer(const adventurer &adv) const
{
    cout<<" $ ";
}


void CLIView::displayWall(const wall &w) const
{
    cout<<" - ";
}

void CLIView::displayAmulet(const amulet &a) const
{
    cout<<" * ";
}

void CLIView::displayMonster(const monster &m) const
{
    cout<<" M ";
}

void CLIView::displayDoor(const door &d) const
{
    cout<<" ^ ";
}






