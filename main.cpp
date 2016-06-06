
#include <iostream>
#include "gamemanager.hpp"


int main(int argc, const char * argv[]) {
    GameManager game = *new GameManager;
    game.startGame();
    game.playGame();
    game.finishGame();
    return 0;
}
