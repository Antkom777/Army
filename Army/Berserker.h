#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"

class Berserker : public Unit {
public:
	Berserker(const Point& point = Point(0,0));
	~Berserker();

void attack (Unit* enemy);
void takeMagicDamage(int dmg);
};
#endif
