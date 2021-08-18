#ifndef MAGICSTATE_H
#define MAGICSTATE_H

#include "State.h"

class Spellcaster;
class State;

enum class MagicType {
	BATTLE, // 0
	PEACE   // 1
};

class MagicState : public State {
public:

	int mana;
	int manaMax;
	MagicType magicType;

	MagicState(int mana, MagicType magicType);
	~MagicState();

	void spendMana(int cost);
};


#endif