#include "Spell.h"
#define DEBUG 0

Spell::Spell(const std::string& name, int cost, int power, int radius)
	: name(name), cost(cost), power(power), radius(radius) {
		if (DEBUG) std::cout << "Spell constructor works" << std::endl;
	}

Spell::~Spell() {}

int Spell::getCost() const {
    return cost;
}

int Spell::getPower() const {
    return power;
}

int Spell::getRadius() const {
    return radius;
}

const std::string& Spell::getName() const {
	return name;
};

void Spell::setPower(int newPower) {
    this->power = newPower;
}