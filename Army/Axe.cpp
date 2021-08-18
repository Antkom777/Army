#include "Axe.h"
#define DEBUG 0

Axe::Axe(Unit* owner) : Weapon(owner, "Axe", 50, 2) {
	if (DEBUG) std::cout << "Axe constructor works" << std::endl;
}

Axe::~Axe() {}

void Axe::action(Unit* target) {
	target->takeDamage(damage);
	if (owner->getDistance(target) <= target->getWeapon()->radius) {
		owner->takeDamage(target->getWeapon()->damage / 2);
	}
	else {
		std::cout << "The enemy can't contrattack, too far" << std::endl;
	}
}

