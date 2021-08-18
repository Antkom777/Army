#include "Bow.h"
#define DEBUG 0

Bow::Bow(Unit* owner) : Weapon(owner, "Bow", 10, 8) {
	if (DEBUG) std::cout << "Bow constructor works" << std::endl;
}

Bow::~Bow() {}

void Bow::action(Unit* target) {
   	target->takeDamage(damage);
}

