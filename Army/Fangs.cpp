#include "Fangs.h"
#define DEBUG 0

Fangs::Fangs(Unit* owner) : Weapon(owner, "Fangs", 30) {
    this->chanceToInfect = 1;
    if (DEBUG) std::cout << "Fangs constructor works" << std::endl;
}

Fangs::~Fangs() {}

void Fangs::action(Unit* target) {
    target->takeDamage(damage);
    this->owner->addHp(damage / 3);
    if( chanceToInfect % 2 == 0 && (target->getState()->type != UnitType::WEREWOLF) && (target->getState()->type != UnitType::VAMPIRE)) {
        target->getState()->type = UnitType::VAMPIRE;
        target->setName("(Vampire)");
        target->changeWeapon(new Fangs(target));
    }
    chanceToInfect += 1;
    if (owner->getDistance(target) <= target->getWeapon()->radius) {
            owner->takeDamage(target->getWeapon()->damage / 2);
    } else {
        std::cout << "The enemy can't contrattack, too far" << std::endl;
    }
}
