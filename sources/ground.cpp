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
#include <memory>
#include "door.h"
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

void ground::buildGround()   //creer un terrain manuellement
{
    cout<<"\n ----- MANUALLY GENERATION FIELD -------\n";

    int c,li;
    do{
        cout<<"Enter a number of columns : \n"; cin>>c;  
        cout<<"Enter a numer of lines : "; cin>>li;  
    }
    while(c<=0 || li<=0);

    d_nbColumns=c;
    d_nbLines=li;

    char l;
    setSize(d_nbColumns,d_nbLines);
    
    cout<<"\n Code :\nS= a smart monster \nB = a blind monster \nW= a wall \nE= empty case\nA= Amulet\nD = door\nO = Outside\nP=Player\n";

    for(int i=0; i<d_nbLines;i++) 
    {
        for(int j=0;j<d_nbColumns;j++) 
        {
            do{
                cout<<"Enter a caracter for the position "<<i<<","<<j<<":";
                cin >>l;
            }while (!(l=='S' || l=='B' || l=='W'|| l=='E'||l=='A'|| l=='P' || l=='D'||l=='O'));

            position pos{i,j};

            if(l=='S') //Monstre voyant a la case [i][j]
            {
                auto p = std::make_unique<smartMonster>(pos);
                addElementToGround(std::move(p));
            }
            else if(l=='B') //Monstre aveugle à la case [i][j]
            {
                auto p = std::make_unique<blindMonster>(pos);
                addElementToGround(std::move(p));
            }
            else if(l=='W') //Mur a la case [i][j]
            {
                auto p = std::make_unique<wall>(pos);
                addElementToGround(std::move(p));
            }
            else if(l=='A') //Amulette à la case [i][j]
            {
                auto p = std::make_unique<amulet>(pos);
                addElementToGround(std::move(p));            
            }
            else if(l=='P') //Personnage
            {
                auto p = std::make_unique<adventurer>(pos);
                addElementToGround(std::move(p));
            }
            else if(l=='D') //Porte
            {
                auto p = std::make_unique<door>(pos);
                addElementToGround(std::move(p));
            }
            else if(l=='O')
            {
                auto p = std::make_unique<outside>(pos);
                addElementToGround(std::move(p));
            }
        }
    }
}