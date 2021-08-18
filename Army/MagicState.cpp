#include "MagicState.h"
#define DEBUG 0

MagicState::MagicState(int mana, MagicType magicType)
	: State ("Sc","Spellcaster", 50, UnitType::SPELLCASTER) {
	this->magicType = magicType;
	this->mana = mana;
	this->manaMax = mana;
	if (DEBUG) std::cout << "MagicState constructor works" << std::endl;
}	 

MagicState::~MagicState() {}

void MagicState::spendMana(int cost) {
	if (this->mana < cost) {
		throw new NotEnoughManaException();
	}
	mana -= cost; 
}	
