
#include "map.hpp"


Map::Map(int aLength) {
    this->length = aLength;
    bildArena();
}

Map::~Map() {
    delete mapData;
}


void Map::clearMap() {
    for (int i = 1; i < this->length - 1; i ++) {
        for (int j = 1; j < this->length * 2 - 1; j++) {
            this->mapData[i][j] = CHAR_EMPTY;
        }
    }
}

void Map::drawUnit(char aUnitSkin, Point aUnitPosition) {
    mapData[aUnitPosition.Y()][aUnitPosition.X()] = aUnitSkin;
}

void Map::drawMap() {
    for (int i = 0; i < this->length; i++) {
        for (int j = 0; j < this->length * 2; j++) {
            addch(this->mapData[i][j]);
        }
        addch('\n');
    }
}

void Map::bildArena() {
    this->mapData = new char*[this->length];
    
    for (int i = 0; i < this->length; i++) {
        this->mapData[i] = new char[this->length * 2];
    }
    
    for (int i = 0; i < this->length; i++) {
        this->mapData[i][0]                    = CHAR_BLOCK;
        this->mapData[i][this->length * 2 - 1] = CHAR_BLOCK;
    }
    
    for (int i = 0; i < this->length * 2; i++) {
        this->mapData[0][i]                    = CHAR_BLOCK;
        this->mapData[this->length - 1][i]     = CHAR_BLOCK;
    }
    
    clearMap();
}

void Map::LENGTH(int aLENGTH) {
    this->length = aLENGTH;
}

int Map::LENGTH() {
    return this->length;
}