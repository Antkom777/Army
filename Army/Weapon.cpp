#include <string>
#include "Weapon.h"
#define DEBUG 0

Weapon::Weapon(Unit* owner, const std::string& name, int damage, int radius) {
    this->owner = owner;
    this->name = name;
    this->damage = damage;
    this->radius = radius;
	if (DEBUG) std::cout << "Weapon constructor works" << std::endl;
}

Weapon::~Weapon() {}

std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
    out << weapon.name << ": DMG(" << weapon.damage << ')';

    return out;
}
