#include "Vampire.h"
#define DEBUG 0

Vampire::Vampire(const Point& point) 
	: Unit(new State("Vm","Vampire", 100, UnitType::VAMPIRE), new Fangs(this)) {
		if (DEBUG) std::cout << "Vampire constructor works" << std::endl;
		this->location = Location::getValidLocation(point);
		this->location->setToken(this);
}
	
Vampire::~Vampire() {}

void Vampire::attack(Unit* enemy) {
	if(this->getDistance(enemy) <= this->getWeapon()->radius ) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	} else {
    	std::cout << "The enemy is too far" << std::endl;
    }
}
void Vampire::takeMagicDamage(int dmg) {
  	takeDamage(dmg);
}