#pragma once
#include "Item.h"
#include <iostream>
using namespace std;

class Sword :
    public Item
{
    float dmgMultiplier;
public:
    Sword();
    Sword(float dmgMultiplier);
    float getDmgMultiplier();
    void setDmgMultiplier(float mltp);
};

