#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "Fangs.h"

class Vampire : public Unit {
public:
	Vampire(const Point& point = Point(0, 0));
	~Vampire();

	void attack(Unit* enemy);
	void takeMagicDamage(int dmg);
};

#endif