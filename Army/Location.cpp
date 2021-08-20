#include <string>
#include "Location.h"
#include "Exceptions.h"

#define DEBUG 0

Location::Location(const Point& point, Unit* unit) {
	if (DEBUG) std::cout << "Location constructor works" << std::endl;
	this->address = point;
	this->token = unit;
};

Location::~Location() {};

bool Location::isFreeAddress() {
	if (DEBUG) std::cout << "isFreeAddress works" << std::endl;
	if (this->getToken() == nullptr) {
		if (DEBUG)  std::cout << "isFreeAddress works TRUE" << std::endl;
		return true;
	}
	else {
		if (DEBUG) std::cout << "isFreeAddress works FALSE" << std::endl;
		return false;
	}
};

Unit* Location::getToken() {
	return this->token;
};

void Location::setToken(Unit* unit) {
	this->token = unit;
};

const Point& Location::getAddress() {
	return this->address;
};

std::ostream& operator<<(std::ostream& out, Location& location)
{
	if (location.getToken() == nullptr) {
		out << "[  ]";
	}
	else {
		std::cout << "[" << location.getToken()->getState()->label << "]";
	}
	return out;
}