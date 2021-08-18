#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <set>
#include "State.h"
#include "Weapon.h"
#include "Location.h"
#include "Mount.h"
#include "Point.h"

class Weapon;
class State;
class Location;
class Mount;

enum Direction {
	up, dowr, right, left
};

class Unit {
protected:
	State* state;
	Weapon* weapon;
	Location* location;
	Mount* mount;

public:
	Unit(State* state, Weapon* weapon, const Point& point = Point(0, 0), Mount* mount = nullptr);
	~Unit();

	std::set<Unit*>* observers;
	std::set<Unit*>* observables;

	State* getState();
	Weapon* getWeapon();
	Location* getLocation();
	Mount* getMount();


	void setName(const std::string& newName);
	void setState(State* newState);
	void setWeapon(Weapon* newWeapon);
	void addHp(int amount);
	void takeDamage(int dmg);
	virtual void takeMagicDamage(int dmg);

	void changeWeapon(Weapon* newWeapon);
	void move(Direction direction = right, int distance = 1);
	double getDistance(Unit* target);

	virtual void attack(Unit* enemy) = 0;

	const std::set<Unit*>& getObservers() const;
	const std::set<Unit*>& getObservables() const;

	void addObserver(Unit* observer);
	void removeObserver(Unit* observer);
	void addObservable(Unit* observable);
	void removeObservable(Unit* observable);

	void notifyObservers();
	void notifyObservables();
	void saddle();

};

std::ostream& operator<<(std::ostream& out, Unit& unit);

#endif