
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
        if (deadCount == wave) {
            newWave();
        }
        map.drawUnit(hero.SKIN(), hero.POS());
        
        for (int i = 0; i < wave; i++) {
            if (!zombie[i]->ISDEAD()) {
                map.drawUnit(zombie[i]->SKIN(), zombie[i]->POS());
            }
        }
        
        map.drawMap();
        drawHeroStats();
        makeHeroTurn();
        makeMobsTurn();
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
    
    Point userWay     = getWayPoint(q);
    Point userNextPos = hero.POS() + userWay;
    
    int i = findUnit(userNextPos);
    
    if (i == -1) {
        hero.move(userWay, map.mapData[userNextPos.Y()][userNextPos.X()]);
    } else {
        collide(i);
    }
}

void GameManager::makeMobsTurn() {
    Point mobNextPos;
    Point mobWay;
    for (int i = 0; i < wave; i++) {
        mobWay     = getMobWayToHero(i);
        mobNextPos = zombie[i]->POS() + mobWay;
        zombie[i]->move(mobWay, map.mapData[mobNextPos.Y()][mobNextPos.X()]);
    }
}

void GameManager::newWave() {
    for (int i = 0; i < wave; i++) {
        delete zombie[i];
    }
    wave++;
    for (int i = 0; i < wave; i++) {
        zombie[i] = new Mob(Point(random() % 38 + 1, random() % 18 + 1));
    }
    deadCount = 0;
}

Point GameManager::getMobWayToHero(int i) {
    int x = hero.POS().X() - zombie[i]->POS().X();
    int y = hero.POS().Y() - zombie[i]->POS().Y();
    
    if (x < 0) {
         return Point(-1,  0);
    }
    else if (x > 0) {
         return Point( 1,  0);
    }
    else if (y < 0) {
         return Point( 0, -1);
    }
    else if (y > 0) {
         return Point( 0,  1);
    }
    else return Point( 0,  0);
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

int GameManager::findUnit(Point aNextPos) {
    for (int i = 0; i < wave; i++) {
        if ((aNextPos == zombie[i]->POS())&&(!zombie[i]->ISDEAD())) {
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
        deadCount++;
    }
}