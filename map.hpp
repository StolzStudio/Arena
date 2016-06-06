
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
    
    void clearMap();
    void drawUnit(char aUnitSkin, Point aUnitPosition);
    void drawMap();
    
    void LENGTH(int aLENGTH);
    int  LENGTH();
private:
    void bildArena();
};

#endif
