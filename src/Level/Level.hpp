#ifndef LEVEL_H
#define LEVEL_H

#include "../Game.hpp"
#include "Tile.hpp"

class Level {

public:
    Level(std::string);

    void render(sf::RenderTarget*);
    void update(sf::Window&);

    bool colliding(sf::FloatRect, sf::Vector2i);

    Tile* getTile(sf::Vector2i);

private:
    std::vector<Tile *> _tiles;
};

#endif
