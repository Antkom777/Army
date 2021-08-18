#include "Heal.h"
#define DEBUG 0

Heal::Heal(const std::string& name, int cost, int power, int radius)
	:Spell(name, cost, power, radius) {
	if (DEBUG) std::cout << "Heal constructor works" << std::endl;
};
Heal::~Heal() {};

void Heal::action(Unit* target) {
	std::cout << "I try to treat" << std::endl;
	target->addHp(power);
}