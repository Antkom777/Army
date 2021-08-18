#include "Staff.h"
#define DEBUG 0

Staff::Staff(Unit* owner) : Weapon(owner, "Staff", 10) {
	if (DEBUG) std::cout << "Staff constructor works" << std::endl;
}

Staff::~Staff() {}

void Staff::action(Unit* target) {
	target->takeDamage(damage);
	if (owner->getDistance(target) <= target->getWeapon()->radius) {
		owner->takeDamage(target->getWeapon()->damage / 2);
	}
	else {
		std::cout << "The enemy can't contrattack, too far" << std::endl;
	}
}
