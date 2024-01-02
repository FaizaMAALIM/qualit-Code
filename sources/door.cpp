#include "door.h"
#include "viewManager.h"
#include "inertElement.h"


door::door(const position &p):inertElement{p}{}



void door::display(const viewManager& view) const
{
    view.displayDoor(*this);
}
