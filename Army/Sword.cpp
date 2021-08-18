#include "Sword.h"
#define DEBUG 0

Sword::Sword(Unit* owner) : Weapon(owner, "Sword", 30, 2) {
	if (DEBUG) std::cout << "Sword constructor works" << std::endl;
}

Sword::~Sword() {}

void Sword::action(Unit* target) {
	target->takeDamage(damage);
	if (owner->getDistance(target) <= target->getWeapon()->radius) {
		owner->takeDamage(target->getWeapon()->damage / 2);
	}
	else {
		std::cout << "The enemy can't contrattack, too far" << std::endl;
	}
}

