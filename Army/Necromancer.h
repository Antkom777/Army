#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Spellcaster.h"


class Necromancer : public Spellcaster {
public:
	Necromancer(const Point& point = Point(0, 0));
	~Necromancer();
	void cast(const std::string& spellName, Unit* target);
	void attack(Unit* enemy);
	void takeMagicDamage(int dmg);
};

std::ostream& operator<<(std::ostream& out, Necromancer& sc);

#endif // NECROMANCER_H
