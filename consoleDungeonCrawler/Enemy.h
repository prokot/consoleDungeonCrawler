#pragma once
#include "Entity.h"

class Enemy :
    public Entity
{
    int reward;
public:
    Enemy(float lvs,int dm,int df,float agl,int rward);
    int getReward();
    void setReward(int rwrd);
    void displayStats();
};

