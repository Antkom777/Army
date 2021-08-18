#include <string>
#include "Soldier.h"
#include "Sword.h"
#include "Bow.h"

#define DEBUG 0

Soldier::Soldier(const Point& point)
	: Unit(new State("Sr", "Soldier", 100, UnitType::SOLDIER), new Sword(this)) {
	this->location = Location::getValidLocation(point);
	if (DEBUG) std::cout << "Soldier constructor works" << std::endl;
	if (DEBUG) std::cout << this->location->getToken() << std::endl;
	this->location->setToken(this);

	if (DEBUG) std::cout << this->location->getToken()->getState()->label << std::endl;
}
Soldier::~Soldier() {}

void Soldier::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	}
	else {
		std::cout << "The enemy is too far" << std::endl;
	}
}
void Soldier::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}
void Soldier::changeWeapon() {
	delete weapon;
	this->weapon = new Bow(this);
}