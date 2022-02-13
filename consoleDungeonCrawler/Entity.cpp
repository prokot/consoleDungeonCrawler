#include "Entity.h"

Entity::Entity() {
}

float Entity::getLives() {
	return lives;
}
int Entity::getDmg() {
	return dmg;
}
int Entity::getDef() {
	return def;
}
float Entity::getAgility() {
	return agility;
}


void Entity::setAgility(float ag) {
	agility = ag;
}
void Entity::setDmg(int dm) {
	dmg = dm;
}
void Entity::setDef(int df) {
	def = df;
}
void Entity::setLives(float lv) {
	lives = lv;
}