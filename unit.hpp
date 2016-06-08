
#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>
#include "map.hpp"
#include "point.hpp"

#define SKIN_KNIGHT 'K'
#define SKIN_ZOMBIE 'Z'


class Unit {
protected:
    int   hp;
    int   dmg;
    Point position;
    char  skin;
    
public:
    Unit(int aHp, int aDmg, char aSkin, Point aPos): hp(aHp), dmg(aDmg), skin(aSkin), position(aPos) {};
    
    virtual int   HP();
    virtual void  HP(int aHP);
    
    virtual int   DMG();
    virtual void  DMG(int aDMG);
    
    virtual Point POS();
    virtual void  POS(Point aPOS);
    
    virtual char  SKIN();
    virtual void  SKIN(char aSKIN);
    
    virtual void  move(Point aUserWay, char aMapElement);
    virtual int   getDamage(int aDamage);
};

class Knight: public Unit {
protected:
    int maxHealth;
    int level;
    int experience;
    int needExperienceToNextLevel;
    
public:
    Knight(Point aPos): Unit(20, 15, SKIN_KNIGHT, aPos), level(1), experience(0),
                        needExperienceToNextLevel(10), maxHealth(20) {};
    
    void LEVEL(int aLEVEL);
    int  LEVEL();
    
    void EXP(int aEXP);
    int  EXP();
    
    void NEEDEXP(int aNEEDEXP);
    int  NEEDEXP();
    
private:
    void levelUp();

};

class Mob: public Unit {
protected:
    int  countEXP;
    bool isDead;
    
public:
    Mob(Point aPos): Unit(10, 2, SKIN_ZOMBIE, aPos), countEXP(10), isDead(false) {};
    
    int  EXP();
    
    bool ISDEAD();
    void ISDEAD(bool aISDEAD);
};

#endif
