#ifndef AMULET_H_INCLUDED
#define AMULET_H_INCLUDED
#include "groundElement.h"
class viewManager;
#include "inertElement.h"

class amulet : public inertElement
{
    public:
        amulet(const position &p);
        void display(const viewManager& view) const override;
};





#endif
