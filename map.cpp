
#include "map.hpp"


Map::Map(int aLength) {
    this->length = aLength;
    bildArena();
}

void Map::drawMap() {
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->length; j++) {
            addch(this->mapData[i][j]);
        }
        addch('\n');
    }
}

void Map::bildArena() {
    this->mapData = new char*[this->length];
    
    for (int i = 0; i < this->length; i++) {
        this->mapData[i] = new char[this->length];
    }
    
    for (int i = 0; i < this->length; i++) {
        this->mapData[i][0]                = CHAR_BLOCK;
        this->mapData[i][this->length - 1] = CHAR_BLOCK;
        this->mapData[0][i]                = CHAR_BLOCK;
        this->mapData[this->length - 1][i] = CHAR_BLOCK;
    }
    
    for (int i = 1; i < this->length - 1; i ++) {
        for (int j = 1; j < this->length - 1; j++) {
            this->mapData[i][j] = CHAR_EMPTY;
        }
    }

}