#include <string>
#include "Warlock.h"
#include "Staff.h"

#define DEBUG 0

Warlock::Warlock(const Point& point)
	: Spellcaster(new MagicState(100, MagicType::PEACE),point)
{
	state = new State("Wk", "Warlock", 60, UnitType::WARLOCK);
	weapon = new Staff(this);
	this->location->setToken(this);
	this->slave = nullptr;
	addSpell(new FireBall("FIREBALL", 30, 15));
	if (DEBUG) std::cout << "Warlock constructor works" << std::endl;
}

Warlock::~Warlock() {
	if (slave != nullptr) {
		delete slave;
	}
}

void Warlock::summon() {
	if (slave != nullptr) {
		return;
	}
	getMagicState()->spendMana(getMagicState()->manaMax / 2);
	if (DEBUG) std::cout << "I'll create demon" << std::endl;
	this->slave = new Demon(this);
}

void Warlock::freeSlave() {
	if (slave != nullptr) {
		delete slave;
	}
}

Demon* Warlock::getDemon() {
	return slave;
}

void Warlock::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
	}
}
void Warlock::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}

std::ostream& operator<< (std::ostream& out, Warlock& sc) {
	out << *((Unit*)(&sc));
	out << " MP(" << sc.getMagicState()->mana << '/';
	out << sc.getMagicState()->manaMax << ") \n";
	out << "**Spellbook:** \n";

	for (std::map<std::string, Spell*>::const_iterator
		it = sc.getSpellbook().begin(); it != sc.getSpellbook().end(); it++) {
		out << "Has spell => " << it->first << std::endl;
	}

	if (sc.getDemon() != nullptr) {
		out << "Has slave =>";
		out << sc.getDemon()->getState()->name << ": HP(";
		out << sc.getDemon()->getState()->hp << '/';
		out << sc.getDemon()->getState()->maxHp << ") DMG(";
		out << sc.getDemon()->getWeapon()->damage << ") WPN(";
		out << sc.getDemon()->getWeapon()->name << ") LOC(";
		out << sc.getLocation()->getAddress().getX() << ',';
		out << sc.getLocation()->getAddress().getY() << ')';
	}

	return out;
}
