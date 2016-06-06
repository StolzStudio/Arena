
#include "gamemanager.hpp"


void GameManager::startGame() {
    initscr();
    noecho();
    erase();
}

void GameManager::playGame() {
    while(true) {
        erase();
        map.drawUnit(hero.SKIN(), hero.POS());
        map.drawMap();
        makeTurn();
    }
}

void GameManager::finishGame() {
    endwin();
}

void GameManager::makeTurn() {
    int q = -1;
    q = getch();
    hero.move(getWayPoint(q));
}

Point GameManager::getWayPoint(int aKey) {
    switch (aKey) {
        case 'w': return Point( 0, -1);
        case 'a': return Point(-1,  0);
        case 's': return Point( 0,  1);
        case 'd': return Point( 1,  0);
        default:  return Point( 0,  0);
    }
}
