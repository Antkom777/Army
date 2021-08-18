#ifndef DAGGER_H
#define DAGGER_H

#include "Weapon.h"

class Dagger : public Weapon {
    public:
        Dagger(Unit* owner);
        ~Dagger();

        void action(Unit* target);
};

#endif
