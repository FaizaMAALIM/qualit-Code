#include "amulet.h"
#include "viewManager.h"
#include <iostream>
#include "inertElement.h"

amulet::amulet(const position &p):inertElement{p}{}


void amulet::display(const viewManager& view) const
{
    view.displayAmulet(*this);
}
