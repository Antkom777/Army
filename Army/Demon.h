#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"
#include "Warlock.h"

class Warlock;

class Demon : public Soldier {
    private:
        Warlock* master;

    public:
        Demon(Warlock* master);
        ~Demon();

        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif // DEMON_H
