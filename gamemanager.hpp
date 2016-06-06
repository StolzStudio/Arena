
#ifndef gamemanager_hpp
#define gamemanager_hpp

#include <stdio.h>
#include "map.hpp"
#include "unit.hpp"

class GameManager {
protected:
    Map    map;
    Knight hero;
public:
    GameManager(): map(20), hero(Point(2,2)) {
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
