#ifndef STAFF_H
#define STAFF_H

#include "Weapon.h"

class Staff : public Weapon {
public:
	Staff(Unit* owner);
	~Staff();

	void action(Unit* target);
};

#endif
