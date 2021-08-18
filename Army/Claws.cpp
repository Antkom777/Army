#include "Claws.h"
#define DEBUG 0

Claws::Claws(Unit* owner) : Weapon(owner, "Claws", 60) {
	this->chanceToInfect = 1;
	if (DEBUG) std::cout << "Claws constructor works" << std::endl;
}

Claws::~Claws() {}

void Claws::action(Unit* target) {
	target->takeDamage(damage);
	if (chanceToInfect % 2 == 0 && (target->getState()->type != UnitType::WEREWOLF)
		&& (target->getState()->type != UnitType::VAMPIRE)) {
		target->setState(new State("Ww", "Werewolf", target->getState()->hp * 2, UnitType::WEREWOLF));
		target->changeWeapon(new Claws(target));
	}
	chanceToInfect += 1;
	if (owner->getDistance(target) <= target->getWeapon()->radius) {
		owner->takeDamage(target->getWeapon()->damage / 2);
	}
	else {
		std::cout << "The enemy can't contrattack, too far" << std::endl;
	}
}
