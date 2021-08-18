#ifndef WEAPON_H
#define WEAPON_H

#include "Unit.h"

class Unit;

class Weapon {
public:
	Unit* owner;
	std::string name;
	int damage;
	int radius;

	Weapon(Unit* owner, const std::string& name, int damage, int radius = 1);
	virtual ~Weapon();

	virtual void action(Unit* target) = 0;
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

#endif
