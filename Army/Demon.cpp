#include "Demon.h"
#define DEBUG 0

Demon::Demon(Warlock* master)
	: Soldier() {
	this->master = master;
	state->name = "Demon";
	state->label = "Dm";
	state->hp = 110;
	state->maxHp = 110;
}

Demon::~Demon() {}

void Demon::takeDamage(int dmg) {
	state->isAlive();

	if (dmg >= state->hp) {
		state->hp = 0;
		master->freeSlave();
		return;
	}
	state->hp -= dmg;
}
void Demon::takeMagicDamage(int dmg) {
	takeDamage(dmg);
}
