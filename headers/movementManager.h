#ifndef MOVEMENTMANAGER_H_INCLUDED
#define MOVEMENTMANAGER_H_INCLUDED
#include "position.h"
#include "vector"
#include "ground.h"
class movementManager
{
    public:
        movementManager(const position&pos);
        virtual ~movementManager()=default;
        position getPos() const;

        virtual position directionPosition(int direction)=0;
        virtual void move(ground &g,int direction)=0;

        //Constantes pour les directions

           /* 1 2 3
              4 ⑤ 6
              7 8 9  */
            

      static const int HAUT_GAUCHE {1};
      static const int HAUT {2};
      static const int HAUT_DROITE {3};
      static const int GAUCHE {4};
      static const int NE_BOUGE_PAS {5};
      static const int DROITE {6};
      static const int BAS_GAUCHE {7};
      static const int BAS {8};
      static const int BAS_DROITE {9};

    //Constantes pour les types

    const char BLINDMONSTER{'B'};
    const char SMARTMONSTER{'S'};
    const char AVENTURIER{'P'};
    const char AMULET{'A'};
    const char WALL{'W'};
    const char VIDE{'E'};
    const char MONEY{'M'};
    const char SORTIE{'D'};

       

      

  protected:
        position d_position;

};

#endif
