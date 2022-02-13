#pragma once
#include "Item.h"
class Shield :
    public Item
{
    float defMultiplier;

public:
    Shield();
    Shield(float df);
    float getDefMultiplier();
    void setDefMultiplier(float mltp);

};

