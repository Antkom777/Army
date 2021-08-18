#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include "Spell.h"

class FireBall : public Spell {
public:
	FireBall(const std::string& name, int cost, int power, int radius = 5);
	~FireBall();

	void action(Unit* target);
};

#endif //FIRE_BALL_H
