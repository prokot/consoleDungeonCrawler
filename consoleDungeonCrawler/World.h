#pragma once
#include <ios>
#include <time.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

using namespace std;

class World
{
	Player* player;
	int lvl,maxLvl,maxFights;

public:
	World();

	void fight();

	void shop();

	void game();

	~World();
};

