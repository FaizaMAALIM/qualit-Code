#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "groundElement.h"
class viewManager;
#include "inertElement.h"


class wall : public inertElement
{
    public:
        wall(const position &p);
        void display(const viewManager& view) const override;
};


#endif
