#include "Healer.h"
#define DEBUG 0

Healer::Healer(const Point& point)
	:Spellcaster(new MagicState(100, MagicType::PEACE),point) {
	state = new State("HL", "Healer", 60, UnitType::HEALER);
	this->location->setToken(this);

	if (DEBUG) std::cout << "Healer constructor works" << std::endl;
	addSpell(new FireBall("FIREBALL", 30, 15));
	addSpell(new Heal("HEAL", 30, 30));
}

Healer::~Healer() {}

void Healer::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	}
	else {
		std::cout << "The enemy is too far" << std::endl;
	}
}
void Healer::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}