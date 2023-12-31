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



};




#endif
