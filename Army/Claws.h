#ifndef CLAWS_H
#define CLAWS_H

#include "Weapon.h"

class Claws : public Weapon {
private:
	int chanceToInfect;
public:
	Claws(Unit* owner);
	~Claws();

	void action(Unit* target);
};

#endif
