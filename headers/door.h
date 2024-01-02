#ifndef DOOR_H_INCLUDED
#define DOOR_H_INCLUDED
#include "groundElement.h"
class viewManager;

#include "inertElement.h"


class door : public inertElement
{
    public:
        door(const position &p);
        void display(const viewManager& view) const override;

};


#endif
