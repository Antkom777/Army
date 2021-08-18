#ifndef FANGS_H
#define FANGS_H

#include "Weapon.h"

class Fangs : public Weapon {
public:
	int chanceToInfect;

	Fangs(Unit* owner);
	~Fangs();

	void action(Unit* target);
};

#endif
