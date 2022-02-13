#include "Enemy.h"
#include <iostream>
using namespace std;


Enemy::Enemy(float lvs, int dm, int df, float agl,int rwrd) {
	setLives(lvs);
	setDmg(dm);
	setDef(df);
	setAgility(agl);
	reward = rwrd;

}


void Enemy::setReward(int rwrd) {
	reward = rwrd;
}
int Enemy::getReward() {
	return reward;
}

void Enemy::displayStats() {
	cout << "Life points:" << getLives() << " Damage:" << getDmg() << "Defense:" << getDef() << "Evade chance:" << getAgility() * 100 << "%" << endl;
}