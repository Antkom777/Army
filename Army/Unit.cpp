#include <string>
#include "Unit.h"
#define DEBUG 0

Unit::Unit(State* state, Weapon* weapon, const Point& point, Mount* mount) {
	this->state = state;
	this->weapon = weapon;
	this->location = NULL;
	this->mount = mount;
	this->observers = new std::set<Unit*>();
    this->observables = new std::set<Unit*>();
	if (DEBUG) std::cout << "Unit constructor works" << std::endl;
}
Unit::~Unit() {
	delete state;
	delete weapon;
	delete mount;
	location->setToken(NULL);
	notifyObservers();
    notifyObservables();

    delete observers;
    delete observables;
}

State* Unit::getState() {
	return state;
}
Weapon* Unit::getWeapon() {
	return weapon;
}

Location* Unit::getLocation(){
	return location;
};
Mount* Unit::getMount(){
	return mount;
};


void Unit::setName(const std::string& newName) {
    state->name += newName;
}

void Unit::setState(State* newState) {
	if( state != NULL ) {
		delete state;
	}
	this->state = newState;
}
void Unit::setWeapon(Weapon* newWeapon) {
	if( weapon != NULL ) {
		delete weapon;
	}
	this->weapon = newWeapon;
}
void Unit::addHp(int amount) {
	if( amount + state->hp <= state->maxHp ) {
		state->hp += amount;
	} else {
		state->hp = state->maxHp;
	}
}

void Unit::takeDamage(int dmg) {
	state->isAlive();
	state->hp -= dmg;
	if( state->hp <= 0 ) {
		state->hp = 0;
		state->isAlive();
	}
}

void Unit::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}


void Unit::changeWeapon(Weapon* newWeapon) {
    delete weapon;
    this->weapon = newWeapon;
}

double Unit::getDistance (Unit* target) {
	double distance = this->getLocation()->getAddress().
		distance(target->getLocation()->getAddress());
	
	if (DEBUG) std::cout << "Point1 = " << target->getLocation()->getAddress() << std::endl;
	if (DEBUG) std::cout << "Point2 = " << this->getLocation()->getAddress() << std::endl;
	if (DEBUG) std::cout << "distance = " << distance << std::endl;
	return distance;
};

const std::set<Unit*>& Unit::getObservers() const {
    return *observers;
}

const std::set<Unit*>& Unit::getObservables() const {
    return *observables;
}

void Unit::addObserver(Unit* observer) {
    observers->insert(observer);
}

void Unit::removeObserver(Unit* observer) {
    observers->erase(observer);
}

void Unit::addObservable(Unit* observable) {
    observables->insert(observable);
}

void Unit::removeObservable(Unit* observable) {
    observables->erase(observable);
}

void Unit::notifyObservers() {
    std::set<Unit*>::iterator it = observers->begin();

    for ( ; it != observers->end(); it++ ) {
        (*it)->addHp(getState()->maxHp/10);
        (*it)->removeObservable(this);
    }
    observers->clear();
}

void Unit::notifyObservables() {
    std::set<Unit*>::iterator it = observables->begin();

    for ( ; it != observables->end(); it++ ) {
        (*it)->removeObserver(this);
    }
}

void Unit::saddle(){
	this->mount = new Mount(this);
};

std::ostream& operator<<(std::ostream& out, Unit& unit) {
	out << unit.getState()->label << " ";
	out << unit.getState()->name << ": HP(";
	out << unit.getState()->hp << '/';
	out << unit.getState()->maxHp << ") DMG(";
	out << unit.getWeapon()->damage << ") WPN(";
	out << unit.getWeapon()->name << ") LOC (" ;
	out << unit.getLocation()->getAddress().getX() <<',';
	out	<< unit.getLocation()->getAddress().getY() <<')';
		
	if (unit.getMount() != NULL) {
		out << " MOUNT (" << unit.getMount()->name << ')'; 
	}
	return out;
}