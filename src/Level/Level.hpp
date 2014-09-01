#ifndef LEVEL_H
#define LEVEL_H

#include "../Game.hpp"
#include "Tile.hpp"

class Level {

public:
    Level(std::string);

    void render(sf::RenderTarget*);
    void update();

private:
    std::vector<Tile *> _tiles;    
};

#endif
