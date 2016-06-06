
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

Point Unit::POS() {
    return this->position;
}

void Unit::POS(Point aPOS) {
    position = aPOS;
}

char Unit::SKIN() {
    return this->skin;
}

void Unit::SKIN(char aSKIN) {
    skin = aSKIN;
}

void Unit::move(Point aUserWay) {
    this->position = this->position + aUserWay;
}