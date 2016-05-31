
#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>

class Unit {
protected:
    int hp;
    int dmg;
public:
    Unit(int aHp, int aDmg): hp(aHp), dmg(aDmg) {};
    
};

#endif
