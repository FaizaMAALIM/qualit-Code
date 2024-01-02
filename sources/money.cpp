#include "money.h"
#include "position.h"
#include "viewManager.h"
#include "inertElement.h"



money::money(const position &p,int value):inertElement{p},d_value{value}{}

void money::display(const viewManager& view) const
{
    view.displayMoney(*this);
}

int money::getValue() const
{
    return d_value;
}
