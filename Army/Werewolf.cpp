#include "Werewolf.h"
#define DEBUG 0

Werewolf::Werewolf(const Point& point) 
	: Unit(new State("Ww","Werewolf", 100, UnitType::SOLDIER), new Sword(this)) {
		this->altState = new State("Ww","Werewolf", 200, UnitType::WEREWOLF);
		this->altWeapon = new Claws(this);
		if (DEBUG) std::cout << "Werewolf constructor works" << std::endl;
		this->location = Location::getValidLocation(point);
		this->location->setToken(this);

}

Werewolf::~Werewolf() {
	delete altState;
	delete altWeapon;
}

void Werewolf::attack(Unit* enemy) {
	if(this->getDistance(enemy) <= this->getWeapon()->radius ) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	} else {
    	std::cout << "The enemy is too far" << std::endl;
    }
}

void Werewolf::transform() {
	int newHp = (state->hp * altState->maxHp) / state->maxHp;

	State* tempState;
	Weapon* tempWeapon;

	tempState = state;
	state = altState;
	altState = tempState;
	tempWeapon = weapon;
	weapon = altWeapon;
	altWeapon = tempWeapon;

	state->hp = newHp;
}
void Werewolf::takeMagicDamage(int dmg) {
  	takeDamage(dmg);
}