#include "outside.h"
#include "viewManager.h"

outside::outside(const position &p):inertElement{p}{}



void outside::display(const viewManager& view) const
{
    view.displayOutside(*this);
}
