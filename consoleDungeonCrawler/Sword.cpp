#include "Sword.h"


Sword::Sword(float dmg) : dmgMultiplier{dmg}
{}

float Sword::getDmgMultiplier() {
	return dmgMultiplier;
}
void Sword::setDmgMultiplier(float mltp) {
	dmgMultiplier = mltp;
}