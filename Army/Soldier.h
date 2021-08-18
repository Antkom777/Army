#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "Sword.h"
#include "Bow.h"

class Soldier : public Unit {
public:
	Soldier(const Point& point = Point(0,0));
	~Soldier();

	void attack(Unit* enemy);
	void takeMagicDamage(int dmg); 
	void changeWeapon();
};

#endif