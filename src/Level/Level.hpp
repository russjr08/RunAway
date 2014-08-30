#ifndef LEVEL_H
#define LEVEL_H

#include "../Game.hpp"
#include "Tile.hpp"

class Level {

public:
    Level(std::string);

private:
    std::vector<Tile> tiles;


};

#endif
