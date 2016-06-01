
#ifndef map_hpp
#define map_hpp

#define CHAR_BLOCK '#'
#define CHAR_EMPTY ' '

#include <stdio.h>
#include <ncurses.h>

class Map {
protected:
    int length;
    
public:
    char **mapData;
    
    Map(int aLength);
    ~Map();
    
    void drawMap();
    
private:
    void bildArena();
};

#endif
