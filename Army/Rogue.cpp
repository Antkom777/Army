#include "Rogue.h"
#define DEBUG 0


Rogue::Rogue(const Point& point)
	:Unit(new State("Rg","Rogue", 80, UnitType::ROGUE), new Dagger(this)){
		if (DEBUG) std::cout << "Rogue constructor works" << std::endl;
		this->location = Location::getValidLocation(point);
		this->location->setToken(this);

	}

Rogue::~Rogue() {}

void Rogue::attack (Unit* enemy) {
	if(this->getDistance(enemy) <= this->getWeapon()->radius ) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	} else {
    	std::cout << "The enemy is too far" << std::endl;
    }
}
void Rogue::takeMagicDamage(int dmg) {
  	takeDamage(dmg);
}