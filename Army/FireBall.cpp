#include "FireBall.h"
#define DEBUG 0

FireBall::FireBall(const std::string& name, int cost, int power, int radius)
	:Spell(name, cost, power, radius) {
	if (DEBUG) std::cout << "FireBall constructor works" << std::endl;
};

FireBall::~FireBall() {};

void FireBall::action(Unit* target) {
	std::cout << "Hit by FireBall" << std::endl;
	target->takeMagicDamage(power);
}
