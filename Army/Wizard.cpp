#include "Wizard.h"
#define DEBUG 0


Wizard::Wizard(const Point& point)
	:Spellcaster(new MagicState(100, MagicType::BATTLE),point) {
	state = new State("Wz", "Wizard", 60, UnitType::WIZARD);
	this->location->setToken(this);
	if (DEBUG) std::cout << "Wizard constructor works" << std::endl;
	addSpell(new FireBall("FIREBALL", 30, 30));
	addSpell(new Heal("HEAL", 30, 15));
}

Wizard::~Wizard() {}

void Wizard::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	}
}
void Wizard::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}