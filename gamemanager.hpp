
#ifndef gamemanager_hpp
#define gamemanager_hpp

#include <stdio.h>
#include "map.hpp"

class GameManager {
protected:
    Map map;
public:
    GameManager(): map(20) {
        Map map = *new Map(20);
    };
    ~GameManager() {};
    
    void startGame();
    void playGame();
    void finishGame();
};

#endif
