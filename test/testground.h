#ifndef TESTGROUND_H
#define TESTGROUND_H

#include "doctest.h"
#include "position.h"
#include "ground.h"
#include "amulet.h"
#include <iostream>
#include <memory>
#include <groundElement.h>
#include "adventurer.h"
#include "wall.h"

TEST_CASE("Test de la classe ground")
{
    int nbl=10;
    int nbc=4;
    ground g{nbl,nbc};

    SUBCASE("Test constructeur")
    {
        REQUIRE_EQ(g.getNbLines(),nbl);
        REQUIRE_EQ(g.getNbColumns(),nbc);
    }
    SUBCASE("Test getNbLine")
    {
        REQUIRE_EQ(g.getNbLines(),nbl);
    }
    SUBCASE("Test getNbCol")
    {
        REQUIRE_EQ(g.getNbColumns(),nbc);
    }
    SUBCASE("Test get nombre total d'éléments du ground")
    {
        REQUIRE_EQ(g.getNbTotalElmts(),0);
    }
    SUBCASE("Test type de la case")
    {
        position p{1,1};

        auto adv = std::make_unique<adventurer>(p);
        g.addElementToGround(std::move(adv));
        char t=g.typeOf(0);
        REQUIRE_EQ(t,'P');

    }
}

#endif