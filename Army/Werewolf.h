#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "Claws.h"
#include "Sword.h"

class Werewolf : public Unit {
private:
	State* altState;
	Weapon* altWeapon;

public:
	Werewolf(const Point& point = Point(0, 0));
	~Werewolf();

	void attack(Unit* enemy);
	void transform();
	void takeMagicDamage(int dmg);
};

#endif