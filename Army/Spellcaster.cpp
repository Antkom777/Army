#include <string>
#include "Spellcaster.h"
#include "Staff.h"

#define DEBUG 0

Spellcaster::Spellcaster(MagicState* magicState) : Unit(state, weapon) {
	this->magicState = magicState;
	this->weapon = new Staff(this);
	if (DEBUG) std::cout << "Spellcaster constructor works" << std::endl;
}

Spellcaster::~Spellcaster() {
	delete magicState;
}

const std::map<std::string, Spell*>& Spellcaster::getSpellbook() const {
	return spellbook;
}

void Spellcaster::cast(const std::string& spellName, Unit* target) {

	if (DEBUG) std::cout << "Point1 = " << target->getLocation()->getAddress() << std::endl;
	if (DEBUG) std::cout << "Point2 = " << this->getLocation()->getAddress() << std::endl;
	if (DEBUG) std::cout << "distance = " << this->getDistance(target) << std::endl;
	if (DEBUG) std::cout << "radius = " << spellbook[spellName]->getRadius() << std::endl;
	if (this->getDistance(target) <= spellbook[spellName]->getRadius()) {
		this->getMagicState()->spendMana(spellbook[spellName]->getCost());
		spellbook[spellName]->action(target);
	}
	else {
		std::cout << "The enemy is too far" << std::endl;
	}
}

void Spellcaster::addSpell(Spell* newSpell) {
	this->spellbook.insert(std::pair<std::string, Spell*>(newSpell->getName(), newSpell));
}

MagicState* Spellcaster::getMagicState() const {
	return magicState;
};

void Spellcaster::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}


std::ostream& operator<< (std::ostream& out, Spellcaster& sc) {
	out << *((Unit*)(&sc));
	out << " MP(" << sc.getMagicState()->mana << '/';
	out << sc.getMagicState()->manaMax << ") \n";
	out << "**Spellbook:** \n";

	for (std::map<std::string, Spell*>::const_iterator
		it = sc.getSpellbook().begin(); it != sc.getSpellbook().end(); it++) {
		out << "Has spell => " << it->first << std::endl;
	}

	return out;
}
