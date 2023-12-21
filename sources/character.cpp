#include "character.h"


character::character(const position &p):groundElement{p}{}



int character::forcePoints() const
{
    return d_forcePoints;
}

int character::lifePoints() const
{
    return d_lifePoints;
}

void character::setForcePoints(double nouvForce)
{
    d_forcePoints = nouvForce;
}
        
        
void character::setLifePoints(double nouvLife)
{
    d_lifePoints = nouvLife;
}

