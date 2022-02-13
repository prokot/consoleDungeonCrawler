#pragma once
class Entity
{
	int dmg,def;
	float lives, agility;

public:
	Entity();
	float getLives();
	int getDmg();
	int getDef();
	float getAgility();


	void setAgility(float ag);
	void setDmg(int dm);
	void setDef(int df);
	void setLives(float lv);
};

