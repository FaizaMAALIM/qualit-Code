#ifndef TESTBLINDMONSTER_H
#define TESTBLINDMONSTER_H

#include "doctest.h"
#include "position.h"
#include "blindMonster.h"

TEST_CASE("Test de la classe BlindMonster")
{
    int i=1,j=2;
    position p{i,j};
    blindMonster bm{p};

    SUBCASE("Test constructeur")
    {
        REQUIRE_EQ(bm.getPosition().getLine(),i);
        REQUIRE_EQ(bm.getPosition().getColumn(),j);
    }
}


#endif