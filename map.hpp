
#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include <ncurses.h>
#include "point.hpp"

#define CHAR_BLOCK '#'
#define CHAR_EMPTY ' '


class Map {
protected:
    int length;
    
public:
    char **mapData;
    
    Map(int aLength);
    ~Map();
    
    void drawUnit(char aUnitSkin, Point aUnitPosition);
    void drawMap();
    
private:
    void bildArena();
};

#endif
