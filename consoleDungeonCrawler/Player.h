#pragma once
#include "Entity.h"
#include "Shield.h"
#include "Sword.h"

class Player : public Entity
{
	int coins;
	Sword* sword;
	Shield* shield;
public:
	Player();

	int getCoins();
	void setCoins(int cns);

	Sword* getSword();
	void setSword(Sword * swrd);

	Shield* getShield();
	void setShield(Shield* shld);
};

