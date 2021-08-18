#ifndef SPELL_H
#define SPELL_H

#include "Unit.h"

class Spell {
protected:
	std::string name;
	int cost;
	int power;
	int radius;

public:
	Spell(const std::string& name, int cost = 30, int power = 30, int radius = 1);
	virtual ~Spell();

	int getCost() const;
	int getPower() const;
	int getRadius() const;
	const std::string& getName() const;
	void setPower(int newPower);
	virtual void action(Unit* target) = 0;
};


#endif //SPELL_H
