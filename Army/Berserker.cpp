#include "Berserker.h"
#include "Axe.h"

#define DEBUG 0

Berserker::Berserker(const Point& point)
	:Unit(new State("Bs", "Berserker", 150, UnitType::BERSERKER),
		new Axe(this), point) {
	this->location->setToken(this);

}

Berserker::~Berserker() {}

void Berserker::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	}
	else {
		std::cout << "The enemy is too far" << std::endl;
	}
}
void Berserker::takeMagicDamage(int dmg) {
	std::cout << "Magic doesn't work" << std::endl;
}

