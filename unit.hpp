
#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>

class Unit {
protected:
    int hp;
    int dmg;
public:
    Unit(int aHp, int aDmg): hp(aHp), dmg(aDmg) {};
    ~Unit();
    
    virtual int  HP();
    virtual void HP(int aHP);
    
    virtual int  DMG();
    virtual void DMG(int aDMG);
};

#endif
