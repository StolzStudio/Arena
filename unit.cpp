
#include "unit.hpp"


int Unit::HP() {
    return this->hp;
}

void Unit::HP(int aHP) {
    this->hp = aHP;
}

int Unit::DMG() {
    return this->dmg;
}

void Unit::DMG(int aDMG) {
    this->dmg = aDMG;
}

