#include "Shield.h"


Shield::Shield(float df) : defMultiplier {df} 
{
}

float Shield::getDefMultiplier() {
	return defMultiplier;
}
void Shield::setDefMultiplier(float mltp) {
	defMultiplier = mltp;
}