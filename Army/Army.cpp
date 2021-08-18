#include <iostream>
#include "Berserker.h"
#include "Soldier.h"
#include "Demon.h"
#include "Rogue.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Healer.h"
#include "Necromancer.h"
#include "Warlock.h"
#include "Wizard.h"
#include "Exceptions.h"

#define DEBUG 0

using namespace std;

int main()
{

	if (DEBUG) std::cout << "---- Werewolf--------" << std::endl;
	if (DEBUG) std::cout << "---- Test--------" << std::endl;
	Werewolf* ww1 = new Werewolf(Point(2, 2));
	if (DEBUG) std::cout << "---- Vampire--------" << std::endl;
	Vampire* v1 = new Vampire(Point(3, 1));
	if (DEBUG) std::cout << "---- Soldier--------" << std::endl;
	Soldier* s1 = new Soldier(Point(3, 3));
	Soldier* s2 = new Soldier(Point(4, 2));
	if (DEBUG) std::cout << "---- Rogue--------" << std::endl;
	Rogue* r1 = new Rogue(Point(4, 2));
	if (DEBUG) std::cout << "---- Berserker--------" << std::endl;
	Berserker* b1 = new Berserker(Point(5, 7));
	std::cout << *b1 << std::endl;
	std::cout << b1->getLocation()->getAddress() << std::endl;

	if (DEBUG) std::cout << "---- Wizard--------" << std::endl;
	Wizard* wz1 = new Wizard(Point(4, 6));
	if (DEBUG) std::cout << "---- Healer --------" << std::endl;
	Healer* h1 = new Healer(Point(5, 2));
	if (DEBUG) std::cout << "---- Necromancer --------" << std::endl;
	Necromancer* n1 = new Necromancer(Point(5, 6));
	if (DEBUG) std::cout << "---- Warlock --------" << std::endl;
	Warlock* wk1 = new Warlock(Point(6, 1));

	std::cout << *ww1 << std::endl;
	// std::cout << ww1->getLocation()->getAddress() << std::endl;
	std::cout << *v1 << std::endl;
	// std::cout << v1->getLocation()->getAddress() << std::endl;
	std::cout << *s1 << std::endl;
	// std::cout << s1->getLocation()->getAddress() << std::endl;
	std::cout << *r1 << std::endl;
	// std::cout << r1->getLocation()->getAddress() << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *wz1 << std::endl;
	std::cout << *h1 << std::endl;
	std::cout << *n1 << std::endl;
	std::cout << *wk1 << std::endl;

	// n1->attack(s1);
	std::cout << *n1 << std::endl;
	std::cout << *ww1 << std::endl;
	ww1->transform();

	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;

	std::cout << *ww1 << std::endl;
	n1->cast("FIREBALL", b1);
	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *s1 << std::endl;
	// b1->attack(s1);
	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *s1 << std::endl;



	try {
		b1->attack(s1);
	}
	catch (UnitIsDeadException e) {
		std::cout << "He is dead" << std::endl;
		delete s1;
	}
	b1->attack(s1);
	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;



	try {
		b1->attack(s1);
	}
	catch (UnitIsDeadException e) {
		std::cout << "------" << s1->getState()->name
			<< " is DEAD  ------" << std::endl;
		delete s1;
	}
	try {
		b1->attack(s1);
	}
	catch (UnitIsDeadException e) {

		std::cout << "------" << s1->getState()->name << " is DEAD  ------" << std::endl;

		delete s1;
	}

	std::cout << *n1 << std::endl;
	std::cout << *ww1 << std::endl;
	ww1->transform();
	std::cout << *ww1 << std::endl;
	b1->attack(ww1);
	std::cout << *ww1 << std::endl;
	ww1->transform();
	std::cout << *ww1 << std::endl;
	ww1->transform();
	std::cout << *ww1 << std::endl;


	std::cout << *h1 << std::endl;
	h1->cast("HEAL", v1);
	std::cout << *h1 << std::endl;
	std::cout << *v1 << std::endl;

	std::cout << "-------------" << std::endl;
	Berserker* b3 = new Berserker();
	std::cout << *b3 << std::endl;
	std::cout << *wz1 << std::endl;
	wz1->cast("FIREBALL", b3);
	std::cout << *b3 << std::endl;
	std::cout << *wz1 << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << *wk1 << std::endl;
	wk1->summon();
	std::cout << *wk1 << std::endl;

	s1->attack(r1);
	ww1->attack(s1);

	ww1->transform();

	std::cout << "-----------------------------------------"
		<< std::endl;
	std::cout << *ww1 << std::endl;
	std::cout << *s2 << std::endl;
	s2->changeWeapon();
	std::cout << *s2 << std::endl;

	std::cout << *r1 << std::endl;
	r1->saddle();
	std::cout << *r1 << std::endl;


	std::cout << "\n--Berserker attacks Necromancer ---" << std::endl;
	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;
	b1->attack(n1);
	std::cout << *n1 << std::endl;
	std::cout << *b1 << std::endl;

	std::cout << "\n--Berserker attacks Healer ---" << std::endl;
	std::cout << *b1 << std::endl;
	std::cout << *h1 << std::endl;
	b1->attack(h1);
	std::cout << *b1 << std::endl;
	std::cout << *h1 << std::endl;
	Location::printLocation();

	delete ww1;
	delete v1;
	delete r1;
	delete b1;
	delete wz1;
	delete h1;
	delete n1;
	delete b3;
	delete wk1;
	delete s1;
	delete s2;

	cin.get();
	return 0;
}
