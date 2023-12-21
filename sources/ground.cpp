#include <iostream>

#include "ground.h"
#include "position.h"
#include "groundElement.h"
#include "character.h"
#include "monster.h"
#include "smartMonster.h"
#include "blindMonster.h"
#include "adventurer.h"
#include "wall.h"
#include "amulet.h"
#include "outside.h"

#include "viewManager.h"
#include <fstream>



using std::cout;
using std::cin;
using std::ifstream;


ground::ground(){}

ground::ground(int nbl,int nbc):d_nbLines{nbl},d_nbColumns{nbc}{}


int ground::getNbColumns() const
{
    return d_nbColumns;
}
int ground::getNbLines() const
{
    return d_nbLines;
}

int ground::getNbTotalElmts() const
{
    return d_groundElementsTab.size();
}


void ground::setSize(int length,int width) 
{
    d_nbColumns = length;  
    d_nbLines = width;     
} 

void ground::addElementToGround(std::unique_ptr<groundElement> element)
{
    d_groundElementsTab.push_back(std::move(element));
}



void ground::removeElement(int indice)
{
    d_groundElementsTab.erase(d_groundElementsTab.begin() + indice);
}

