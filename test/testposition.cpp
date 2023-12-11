#ifndef TESTPOSITION_H
#define TESTPOSITION_H

#include "doctest.h"
#include "position.h"

TEST_CASE("Test de la classe Position")
{
    int i=1,j=2;
    position p{i,j};
    SUBCASE("Test constructeur par défaut")
    {
        position p{};
        REQUIRE_EQ(p.getLine(),0);
        REQUIRE_EQ(p.getColumn(),0);
    }
    SUBCASE("Test getLine")
    {
        REQUIRE_EQ(p.getLine(),i);
    }
    SUBCASE("Test getColonne")
    {
        REQUIRE_EQ(p.getColumn(),j);
    }
}


#endif