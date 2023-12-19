#ifndef TESTSMARTMONSTER_H
#define TESTSMARTMONSTER_H

#include "doctest.h"
#include "smartMonster.h"
#include "position.h"

TEST_CASE("Test de la classe smartMonster")
{
    int i=1,j=2;
    position p{i,j};
    smartMonster m{p};

    SUBCASE("Test constructeur")
    {
        REQUIRE_EQ(m.getPosition().getLine(),i);
        REQUIRE_EQ(m.getPosition().getColumn(),j);
    }
}


#endif