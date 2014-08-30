#ifndef ENTITY_H
#define ENTITY_H

#include "../Game.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Entity {
protected:
    Game* game;
    sf::Vector2f pos;


public:
    Entity(Game* game){ this->game = game; }
    virtual void render(sf::RenderTarget*);
    virtual void update(float);

};


#endif
