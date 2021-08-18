#include "Dagger.h"
#define DEBUG 0


Dagger::Dagger(Unit* owner) : Weapon(owner, "Dagger", 20) {
	if (DEBUG) std::cout << "Dagger constructor works" << std::endl;
}

Dagger::~Dagger() {}

void Dagger::action(Unit* target) {
    target->takeDamage(damage);
}
