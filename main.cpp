
#include <iostream>
#include "map.hpp"

int main(int argc, const char * argv[]) {
    int q = -1;
    
    Map arena = *new Map(20);
    
    initscr();
    noecho();
    erase();
    
    arena.drawMap();
    q = getch();
    return 0;
}
