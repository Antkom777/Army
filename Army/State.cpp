#include "State.h"
#include "Exceptions.h"
#include <iostream>

#define DEBUG 0

State::State(const std::string& label, const std::string& name, int hp, UnitType type, int speed) 
: label(label), name(name), hp(hp), maxHp(hp), type(type), speed(speed) {
	if (DEBUG) std::cout << "State constructor works" << std::endl;
}
State::~State() {}

void State::isAlive() {
	if( hp == 0 ) {
		throw UnitIsDeadException();
	}
}
