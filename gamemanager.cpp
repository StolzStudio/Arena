
#include "gamemanager.hpp"


void GameManager::startGame() {
    initscr();
    noecho();
    erase();
}

void GameManager::playGame() {
    int q = -1;
    map.drawMap();
    q = getch();
}

void GameManager::finishGame() {
    endwin();
}