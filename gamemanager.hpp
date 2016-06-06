
#ifndef gamemanager_hpp
#define gamemanager_hpp

#include <stdio.h>
#include <vector>
#include "map.hpp"
#include "unit.hpp"

using namespace std;


class GameManager {
protected:
    Map         map;
    Knight      hero;
    int         wave;
public:
    GameManager(): wave(1), map(20), hero(Point(2,2)) {
        Map map = *new Map(20);
        Knight hero = *new Knight(Point(2,2));
    };
    ~GameManager() {};
    
    void startGame();
    void playGame();
    void finishGame();
private:
    void drawHeroStats();
    void makeTurn();
    Point getWayPoint(int aKey);
    
};

#endif
