#include <string>
#include "Necromancer.h"
#include "FireBall.h"

#define DEBUG 0

Necromancer::Necromancer(const Point& point)
	: Spellcaster(new MagicState(100, MagicType::PEACE),point)
{
	state = new State("Nc", "Necromancer", 60, UnitType::NECROMANCER);
	this->location->setToken(this);

	if (DEBUG) std::cout << "Necromancer constructor works" << std::endl;
	addSpell(new FireBall("FIREBALL", 30, 15));
}

Necromancer::~Necromancer() {}

void Necromancer::cast(const std::string& spellName, Unit* enemy) {
	Spellcaster::cast(spellName, enemy);
	if (this->getDistance(enemy) <= spellbook[spellName]->getRadius()) {
		addObservable(enemy);
		enemy->addObserver(this);
	}
}

void Necromancer::attack(Unit* enemy) {
	if (this->getDistance(enemy) <= this->getWeapon()->radius) {
		enemy->getState()->isAlive();
		this->getWeapon()->action(enemy);
		addObservable(enemy);
		enemy->addObserver(this);
	}
	else {
		std::cout << "The enemy is too far" << std::endl;
	}
}

void Necromancer::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}
std::ostream& operator<<(std::ostream& out, Necromancer& sc) {
	out << *((Unit*)(&sc));
	out << " MP(" << sc.getMagicState()->mana << '/';
	out << sc.getMagicState()->manaMax << ")\n";
	out << "**Spellbook: \n";

	for (std::map<std::string, Spell*>::const_iterator
		it = sc.getSpellbook().begin(); it != sc.getSpellbook().end(); it++) {
		out << "Has spell => " << it->first << std::endl;
	}
	std::set<Unit*> observables = sc.getObservables();
	if (observables.size() == 0) {
		return out;
	}
	std::set<Unit*>::iterator it = observables.begin();
	out << " Observables: [ ";
	for (; it != observables.end(); it++) {
		out << (*it)->getState()->name << " ";
	}
	out << "] \n";

	return out;
}
