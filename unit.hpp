
#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>
#include "point.hpp"


class Unit {
protected:
    int   hp;
    int   dmg;
    Point position;
public:
    Unit(int aHp, int aDmg): hp(aHp), dmg(aDmg) {};
    ~Unit();
    
    virtual int  HP();
    virtual void HP(int aHP);
    
    virtual int  DMG();
    virtual void DMG(int aDMG);
    
    virtual Point POS();
    virtual void  POS(Point aPOS);
};

#endif
