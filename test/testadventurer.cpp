#ifndef TESTADVENTURER_H
#define TESTADVENTURER_H

#include "doctest.h"
#include "position.h"
#include "adventurer.h"


TEST_CASE("Test de la classe adventurer")
{
    int i=1,j=2;
    position p{i,j};
    adventurer a{p};

    SUBCASE("Test constructeur")
    {
        REQUIRE_EQ(a.getPosition().getLine(),i);
        REQUIRE_EQ(a.getPosition().getColumn(),j);
    }
    SUBCASE("Test a l'amulette")
    {
        a.setAmuletTrue();
        REQUIRE_EQ(a.hasAmulet(),true);
    }
}



#endif