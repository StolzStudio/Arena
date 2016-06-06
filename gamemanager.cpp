
#include "gamemanager.hpp"


void GameManager::startGame() {
    initscr();
    noecho();
    erase();
}

void GameManager::playGame() {
    while(hero.HP() > 0) {
        erase();
        map.clearMap();
        map.drawUnit(hero.SKIN(), hero.POS());
        map.drawMap();
        drawHeroStats();
        makeTurn();
    }
}

void GameManager::finishGame() {
    endwin();
}

void GameManager::drawHeroStats() {
    printw("wave number: %d\n", wave);
    printw("health: %d\n", hero.HP());
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
