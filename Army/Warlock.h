#ifndef WARLOCK_H
#define WARLOCK_H

#include "Spellcaster.h"
#include "FireBall.h"
#include "Demon.h"

class Demon;

class Warlock : public Spellcaster {
private:
	Demon* slave;
public:
	Warlock(const Point& point = Point(0, 0));
	~Warlock();

	void summon();
	Demon* getDemon();
	void freeSlave();
	void attack(Unit* enemy);
	void takeMagicDamage(int dmg);
};
std::ostream& operator<< (std::ostream& out, Warlock& sc);

#endif // WARLOCK_H
