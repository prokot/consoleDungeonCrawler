#include "Player.h"
#include <time.h>
#include <ios>
#include "Shield.h"
#include "Sword.h"


Player::Player() {
	srand(time(NULL));
	setLives(100.0);
	setAgility((float)(rand() % 30)/100);
	setDef(rand() % 15 + 1);
	setDmg(rand() % 20 + 1);
	Shield* shld = new Shield(1.1);
	shield = shld;
	Sword* swrd = new Sword(1.1);
	sword = swrd;

}


int Player::getCoins() {
	return coins;
}
void Player::setCoins(int cns) {
	coins = cns;
}

Sword* Player::getSword() {
	return sword;
}
void Player::setSword(Sword* swrd) {
	sword = swrd;
}

Shield* Player::getShield() {
	return shield;
}
void Player::setShield(Shield* shld) {
	shield = shld;
}