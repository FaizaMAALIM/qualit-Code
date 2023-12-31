#include "adventurerMoveManager.h"
#include "character.h"
#include "smartMonster.h"
#include "blindMonster.h"
#include "adventurer.h"
#include "smartMonsterMoveManager.h"
#include "blindMonsterMoveManager.h"
#include <memory>
#include "monster.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <iomanip>



game::game(){}

void game::clear()
{
    system("clear || cls");
}


void game::gererErreurSaisie()
{
    if (!std::cin.good())
    {
        std::cout << "\n Veuillez entrer un caractère valide\n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void game::startDisplay()
{
    std::cout<<" +-+-+-+-+-+-+-+-+-+-+ BIENVENUE DANS DUNGEON II +-+-+-+-+-+-+-+-+-+-+\n\n";
    std::cout<<" Ressortez en vie du donjon avec l'amulette  ! \n\n";
}

void game::rules()
{
    std::cout<<"\n +-+-+-+-+-+-+-+-+-+-+-+-+-+ REGLES DU JEU +-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
    std::cout<<"\n Vous devez récupérer l'amulette et réussir à atteindre la sortie en vie. \n Vous croiserez des monstres sur votre chemin que vous devrez combattre avec \n votre épée. Vous trouverez des tas de pièces qui vous permettront de réparer \n votre équipement. Vous pouvez vous déplacer dans les 9 directions ou rester \n à votre place. \n Les smart monster se dirigeront vers vous tandis que les blind monster se\n déplacent au hasard. \n\n NB:\n -Vous ne pouvez pas vous déplacer dans un mur ni dans une case extérieure,\n et vous ne pouvez pas sortir sans l'amulette.\n -Lors d'une bataille, vous pouvez continuer à vous battre en restant à la \n meme case ou fuir. \n\n A vous de jouer !\n\n";
}


int game::choixView()
{
   int choix;
   do
   {
    std::cout<<" Quel type d'interface voulez vous ?\n 1- Affichage texte\n 2- Affichage coloré\n\n > ";
    std::cin>>choix;

    gererErreurSaisie();

   } while (!std::cin.good() ||!(choix==1 || choix==2));


    return choix;
}

std::unique_ptr<viewManager> game::createView(int choix)
{

    if(choix==1)
    {
        auto v=std::make_unique<CLIView>();
        return v;
    }
    else if(choix==2)
    {
        auto v=std::make_unique<colorView>();
        return v;
    }
    else
    {
        return 0;
    }
}

