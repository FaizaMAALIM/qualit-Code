#ifndef TESTAMULET_H
#define TESTAMULET_H

#include "doctest.h"
#include "position.h"
#include "amulet.h"

TEST_CASE("Test de la classe amulet")
{
    int i=1,j=2;
    position p{i,j};
    amulet a{p};

    SUBCASE("Test constructeur")
    {
        REQUIRE_EQ(a.getPosition().getLine(),i);
        REQUIRE_EQ(a.getPosition().getColumn(),j);
    }
}


#endif