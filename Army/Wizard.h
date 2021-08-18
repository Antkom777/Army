#ifndef WIZARD_H
#define WIZARD_H

#include "Spellcaster.h"
#include "Fireball.h"
#include "Heal.h"

class Wizard : public Spellcaster {
    public:
        Wizard(const Point& point = Point(0,0));
        ~Wizard();
        void attack(Unit* enemy);
        void takeMagicDamage(int dmg); 
};

#endif // WIZARD_H
