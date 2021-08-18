#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"

class Sword : public Weapon {
public:
	Sword(Unit* owner);
	~Sword();

	void action(Unit* target);
};

#endif
