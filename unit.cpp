
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
    this->position = aPOS;
}

char Unit::SKIN() {
    return this->skin;
}

void Unit::SKIN(char aSKIN) {
    this->skin = aSKIN;
}

void Unit::move(Point aUserWay, char aMapElement) {
    if (aMapElement != CHAR_BLOCK) {
        this->position = this->position + aUserWay;
    }
}

int Unit::getDamage(int aDamage) {
    this->hp -= aDamage;
    return this->hp;
}





void Knight::LEVEL(int aLEVEL) {
    this->level = aLEVEL;
}

int Knight::LEVEL() {
    return this->level;
}

void Knight::EXP(int aEXP) {
    this->experience += aEXP;
    if (this->experience >= this->needExperienceToNextLevel) {
        levelUp();
    }
}

int Knight::EXP() {
    return this->experience;
}

void Knight::NEEDEXP(int aNEEDEXP) {
    this->needExperienceToNextLevel = aNEEDEXP;
}

int Knight::NEEDEXP() {
    return this->needExperienceToNextLevel;
}

void Knight::levelUp() {
    this->level++;
    this->experience -= this->needExperienceToNextLevel;
    this->needExperienceToNextLevel *= 2;
    this->maxHealth += 10;
    this->hp = this->maxHealth;
}





int Mob::EXP() {
    return this->countEXP;
}

bool Mob::ISDEAD() {
    return this->isDead;
}

void Mob::ISDEAD(bool aISDEAD) {
    this->isDead = aISDEAD;
}