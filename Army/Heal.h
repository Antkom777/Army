#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal : public Spell {
public:
	Heal(const std::string& name, int cost, int power, int radius = 2);
	~Heal();

	void action(Unit* target);
};

#endif //HEAL_H
