#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"

class Rogue : public Unit {
public:
	Rogue(const Point& point = Point(0, 0));
	~Rogue();

	void attack(Unit* enemy);
	void takeMagicDamage(int dmg);

};
#endif
