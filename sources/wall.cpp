#include "wall.h"
#include "viewManager.h"

wall::wall(const position &p):inertElement{p}{}



void wall::display(const viewManager& view) const
{
    view.displayWall(*this);
}
