#ifndef HEALER_H
#define HEALER_H

#include "Spellcaster.h"
#include "Fireball.h"
#include "Heal.h"

class Healer : public Spellcaster {
public:
	Healer(const Point& point = Point(0, 0));
	~Healer();

	void attack(Unit* enemy);
	void takeMagicDamage(int dmg);
};

#endif // Healer_H
