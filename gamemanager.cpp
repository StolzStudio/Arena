
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
        
        for (int i = 0; i < wave; i++) {
            if (!zombie[i]->ISDEAD()) {
                map.drawUnit(zombie[i]->SKIN(), zombie[i]->POS());
            }
        }
        
        map.drawMap();
        drawHeroStats();
        makeHeroTurn();
    }
}

void GameManager::finishGame() {
    endwin();
}

void GameManager::drawHeroStats() {
    printw("wave number: %d\n", wave);
    printw("hero:\n");
    printw("     level : %d\n", hero.LEVEL());
    printw("     health: %d\n", hero.HP());
    printw("     exp   : %d/%d\n", hero.EXP(), hero.NEEDEXP());
}

void GameManager::makeHeroTurn() {
    int q = -1;
    q = getch();
    
    Point userWay = getWayPoint(q);
    int i = findUnit(hero.POS(), userWay);
    if (i == -1) {
        hero.move(getWayPoint(q));
    } else {
        collide(i);
    }
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

int GameManager::findUnit(Point aUnitPos, Point aWay) {
    Point NowPos = aUnitPos + aWay;
    for (int i = 0; i < wave; i++) {
        if ((NowPos == zombie[i]->POS())&&(!zombie[i]->ISDEAD())) {
            return i;
        }
    }
    return -1;
}

void GameManager::collide(int aZombieCount) {
    zombie[aZombieCount]->getDamage(hero.DMG());
    if (zombie[aZombieCount]->HP() <= 0) {
        hero.EXP(zombie[aZombieCount]->EXP());
        zombie[aZombieCount]->ISDEAD(true);
    }
}