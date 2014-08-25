#ifndef LEVEL_H
#define LEVEL_H

#include "../Game.h"
#include "Tile.h"

class Level {

public:
    Level(std::string);
    
private:
    std::vector<Tile> tiles;


};

#endif
