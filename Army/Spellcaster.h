#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "Unit.h"
#include "Spell.h"
#include "MagicState.h"
//#include "Location.h"

#include <map>

class Spell;
class MagicState;

class Spellcaster : public Unit {
    protected:
        std::map<std::string,Spell*> spellbook;
        MagicState* magicState;    

    public:
        Spellcaster(MagicState* magicState);
        ~Spellcaster();

        const std::map<std::string,Spell*>& getSpellbook() const;

        virtual void attack(Unit* enemy) = 0;
        void cast(const std::string& spellName, Unit* target);
        void addSpell(Spell* newSpell);
        MagicState* getMagicState() const;
        void takeMagicDamage(int dmg);
        
};

std::ostream& operator<<(std::ostream& out, Spellcaster& sc);

#endif
