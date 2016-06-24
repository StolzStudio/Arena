
#ifndef gamemanager_hpp
#define gamemanager_hpp

#include <stdio.h>
#include <vector>
#include <random>
#include "map.hpp"
#include "unit.hpp"

using namespace std;


class GameManager {
protected:
    Map     map;
    Knight  hero;
    Mob*    zombie[20];
    int     deadCount;
    int     wave;
    
public:
    GameManager(): wave(1), deadCount(0), map(20), hero(Point(2,2)) {
        Map map       = *new Map(20);
        Knight hero   = *new Knight(Point(2,2));
        
        for (int i = 0; i < wave; i++) {
            zombie[i] = new Mob(Point(random() % 40, random() % 20));
        }
    };
    ~GameManager() {};
    
    void startGame();
    void playGame();
    void finishGame();
    
private:
    void  drawHeroStats();
    void  makeHeroTurn();
    void  makeMobsTurn();
    Point getMobWayToHero(int i);
    Point getWayPoint(int aKey);
    void  newWave();
    int   findUnit(Point aNextPos);
    void  collide(int aZombieCount);
    void  collide();
};

#endif
