#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <string>
#include <memory>
class ground;
class monster;
#include "viewManager.h"
#include <vector>
#include "monster.h"


class game
{
    public:
     game();
     void clear();
     void rules();
     std::unique_ptr<viewManager> createView(int choix);
     void gererErreurSaisie();
     void startDisplay();
     int choixView();
     void chargerGround(ground &g);
     void useBourse(adventurer *adv);
     void play();
     std::vector<monster*> deplacerMonstres(ground&g);

     void afficherInfosAdv(const adventurer*adv);
     void afficherInfosMonstresProches(const std::vector<monster*> &tabMonstres) ;






};




#endif
