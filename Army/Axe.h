#ifndef AXE_H
#define AXE_H

#include "Weapon.h"

class Axe : public Weapon {
public:
	Axe(Unit* owner);
	~Axe();

	void action(Unit* target);
};

#endif
