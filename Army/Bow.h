#ifndef BOW_H
#define BOW_H

#include "Weapon.h"

class Bow : public Weapon {
public:
	Bow(Unit* owner);
	~Bow();

	void action(Unit* target);
};

#endif
