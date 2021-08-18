#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <set>
#include "Exceptions.h"
#include "Unit.h"

class Unit;

enum UnitType {
	SOLDIER, // 0
	ARCHER,
	DEMON,// 1
	ROGUE,// 2
	BERSERKER,// 3
	VAMPIRE, // 4
	WEREWOLF, //5
	WIZARD,
	HEALER,
	PRIEST,
	WARLOCK,
	NECROMANCER,
	SPELLCASTER
};

class State {
public:
	int hp;
	int maxHp;
	std::string name;
	std::string label;
	UnitType type;
	int speed;

	State(const std::string& label, const std::string& name, int hp, UnitType type, int speed = 1);
	~State();

	void isAlive();

};

#endif